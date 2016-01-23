/*
file: Alg.cpp
author: Nat Baylon
modified: 10/24/2015 10:26 AM
description: implentation of AlgRater class
*/

#include "AlgRater.h"

void AlgRater::addAlg(Alg a){
	allAlgs.push_back(a);
}
void AlgRater::showPreferences(){
	cout << "User Preferences: " << endl << endl
		<< "Dominant hand: " << DOM_HAND << endl
		<< "Regrip weight: " << REGRIP_WT << endl
		<< "Dominant hand weight: " << DOM_WT << endl
		<< "QTM weight: " << QTM_WT << endl
		<< "HTM weight: " << HTM_WT << endl
		<< "Preferred QTM: " << PREFERRED_QTM << endl
		<< "Preferred HTM: " << PREFERRED_HTM << endl
		<< "Preferred dominant hand usage: " << PREFERRED_DOM_RATIO << endl
		<< "Preferred regrips: " << PREFERRED_REGRIPS << endl
		<< "QTM penalty: " << QTM_PENALTY << endl
		<< "HTM penalty: " << HTM_PENALTY << endl
		<< "Regrip penalty: " << REGRIP_PENALTY << endl
		<< "Rotation penalty: " << ROTATION_PENALTY << endl
		<< "Non-dominant hand penalty: " << DOM_PENALTY << endl
		<< "Begin/end rotations count?: " << BEGIN_END_ROT_COUNT << endl
		<< "Check dominant hand for R/L moves only?: " << DOM_LR_ONLY << endl << endl;
}		
void AlgRater::showAllAlgs(){
	cout << "All algs: " << endl << endl;
	for(unsigned int i = 0; i < allAlgs.size(); i++){
		cout << "Alg " << i + 1 << ":\t";
		allAlgs[i].showAlg();
		cout << endl;
	}
	cout << endl;
}
void AlgRater::showTopX(unsigned int x){
	cout << "Top " << x << " algs: " <<endl << endl;
	for(unsigned int i = 0; i < x; i++){
		cout << "Alg " << i + 1 << ":\t";
		allAlgs[i].showAlg();
		cout << endl;
	}
	cout << endl;
}
int AlgRater::getNumAlgs(){
	return allAlgs.size();
}
void AlgRater::gradeAlgs(){
	TwoHands TH;
	int htmCount;	
	int qtmCount;
	int numRegrips;
	int numRotations;
	int rMoves;
	int lMoves;
	float domRatio;
	float qtmGrade; 
	float htmGrade;
	float domGrade;
	float regripGrade;
	float rotationGrade;
	float grade;

	for(unsigned int i = 0;  i < allAlgs.size(); i++){
		//only grade ungraded algs
		if(!allAlgs[i].getGradedStatus()){
			TH.resetHands();
			htmCount = 0;	
			qtmCount = 0;
			numRegrips = 0;
			numRotations = 0;
			rMoves = 0;
			lMoves = 0;
			string move;

			for(unsigned int j = 0; j < allAlgs[i].getMoves().size(); j++){
				move = allAlgs[i].getMove(j);
				
				TH.doMove(move);
				
				updateHTM(htmCount, move);
				updateQTM(qtmCount, move);
				updateRotations(numRotations, TH, j, allAlgs[i].getMoves().size() - 1);
				updateRegrips(numRegrips, TH);
				updateRLMoves(rMoves, lMoves, TH, move);
			}
			domRatio = calcDomRatio(rMoves, lMoves);
			calcGrade(qtmCount, htmCount, numRegrips, numRotations, domRatio, qtmGrade, htmGrade, domGrade, regripGrade, rotationGrade, grade);

			allAlgs[i].setHTM(htmCount);
			allAlgs[i].setQTM(qtmCount);
			allAlgs[i].setNumRegrips(numRegrips);
			allAlgs[i].setNumRotations(numRotations);
			allAlgs[i].setDomRatio(domRatio);
			allAlgs[i].setQTMGrade(qtmGrade);
			allAlgs[i].setHTMGrade(htmGrade);
			allAlgs[i].setDomGrade(domGrade);
			allAlgs[i].setRotationGrade(rotationGrade);
			allAlgs[i].setRegripGrade(regripGrade);
			allAlgs[i].setGrade(grade);
			allAlgs[i].setGradedStatus();
		}
	}
}
void AlgRater::updateHTM(int &hCount, string m){
	char char1 = toupper(m[0]);
	if(char1 != 'X' && char1 != 'Y' && char1 != 'Z')
		hCount++;
}

void AlgRater::updateQTM(int &qCount, string m){
	char char1 = toupper(m[0]);
	if(char1 != 'X' && char1 != 'Y' && char1 != 'Z'){
		if(m.length() == 1){
			qCount++;
		}
		else if(m[1] == '2'){
			qCount+=2;
		}
		else{
			// '\''
			qCount++;
		}
	}
}
void AlgRater::updateRegrips(int &regripCount, TwoHands &T){
	if(T.getLastMoveRegrip()){
		regripCount++;
	}
}
void AlgRater::updateRotations(int &rotationCount, TwoHands &T, int j, int l){
	if(BEGIN_END_ROT_COUNT){
	 	if(T.getLastMoveRotation()){
			rotationCount++;
		}
	}
	else{
		if(j != 0 && j != l && T.getLastMoveRotation())
			rotationCount++;
	}
}
void AlgRater::updateRLMoves(int &rMoves, int &lMoves, TwoHands &T, string m){
	if(DOM_LR_ONLY){
		if(m[0] == 'L' || m[0] == 'R'){
			if(T.getLastHand() == 'r'){
				rMoves++;
			}
			else{
				lMoves++;
			}
		}
	}
	else{
		if(T.getLastHand() == 'r'){
			rMoves++;
		}
		else{
			lMoves++;
		}
	}
}
float AlgRater::calcDomRatio(int rMoves, int lMoves){
	if(DOM_HAND == 'r'){
		return (float)rMoves/(float)(rMoves + lMoves);
	}
	else{
		return (float)lMoves/(float)(rMoves + lMoves);
	}
}
void AlgRater::calcGrade(int qCount, int hCount, int regripCount, int rotationCount, float domRatio, 
						float &qtmGrade, float &htmGrade, float &domGrade, float &regripGrade, float &rotationGrade, float &totalGrade){
	regripGrade = 100;
	rotationGrade = 100;
	qtmGrade = 100;
	htmGrade = 100;
	domGrade = 100;

	//lose points for every violation past preferred number
	//regrips
	if(regripCount > PREFERRED_REGRIPS){
		for(int r = regripCount - PREFERRED_REGRIPS; r > 0 && regripGrade > 0; r--){
			regripGrade -= REGRIP_PENALTY;
		}
	}
	//rotations
	if(rotationCount > PREFERRED_ROTATIONS){
		for(int r = rotationCount - PREFERRED_ROTATIONS; r > 0 && rotationGrade > 0; r--){
			rotationGrade -= ROTATION_PENALTY;
		}
	}
	//qtm
	if(qCount > PREFERRED_QTM){
		for(int q = qCount - PREFERRED_QTM; q > 0 && qtmGrade > 0; q--){
			qtmGrade -= QTM_PENALTY;
		}
	}
	//htm
	if(hCount > PREFERRED_HTM){
		for(int h = hCount - PREFERRED_HTM; h > 0 && htmGrade > 0; h--){
			htmGrade -= HTM_PENALTY;
		}
	}
	//domRatio
	if(domRatio < PREFERRED_DOM_RATIO){
		for(float d = PREFERRED_DOM_RATIO - domRatio; d > 0 && domGrade > 0; d -= .01){
			domGrade -= DOM_PENALTY;
		}
	}
	//apply weight to categories
	regripGrade *= REGRIP_WT;
	rotationGrade *= ROTATION_WT;
	qtmGrade *= QTM_WT;
	htmGrade *= HTM_WT;
	domGrade *= DOM_WT;

	//sum categories
	totalGrade = regripGrade + rotationGrade + qtmGrade + htmGrade + domGrade;
}
/*
bool AlgRater::compareAlgs(Alg a, Alg b){
	return a.getGrade() > b.getGrade();
}
//g++ doesn't like this comp function for sorting :(
 */
void AlgRater::sortAlgs(){
	std::sort(allAlgs.begin(), allAlgs.end(), compareAlgs());
}			
void AlgRater::clearAlgs(){
	allAlgs.clear();
}			