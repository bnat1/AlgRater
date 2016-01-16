/*
file: Alg.cpp
author: Nat Baylon
modified: 10/24/2015 10:26 AM
description: implentation of AlgRater class
*/

#include "AlgRater.h"

#define DOM_HAND 'r'			// 'r' or 'l'
#define REGRIP_WT 0.25
#define DOM_WT 0.40
#define QTM_WT 0.35
#define HTM_WT 0
#define PREFERRED_QTM 15
#define PREFERRED_HTM 12
#define PREFERRED_DOM_RATIO 0.75
#define PREFERRED_REGRIPS 3
#define QTM_PENALTY 0.1
#define HTM_PENALTY 0
#define REGRIP_PENALTY 0.15
#define DOM_PENALTY 0.03		//per .01 below

void AlgRater::addAlg(Alg a){
	allAlgs.push_back(a);
}
void AlgRater::showPreferences(){
	//cout << "\n==========================================================================\n";
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
		<< "Non-dominant hand penalty: " << DOM_PENALTY << endl << endl; 
}		
void AlgRater::showAllAlgs(){
	//cout << "\n==========================================================================\n";
	cout << "All algs: " << endl << endl;
	for(unsigned int i = 0; i < allAlgs.size(); i++){
		cout << "Alg " << i + 1 << ":\t";
		allAlgs[i].showAlg();
		cout << endl;
	}
	cout << endl;
}
void AlgRater::showTopX(unsigned int x){
	//cout << "\n==========================================================================\n";
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
	int rMoves;
	int lMoves;
	float domRatio;
	float qtmGrade; 
	float htmGrade;
	float domGrade;
	float regripGrade;
	float grade;

	for(unsigned int i = 0;  i < allAlgs.size(); i++){
		//only grade ungraded algs
		if(!allAlgs[i].getGradedStatus()){
			TH.resetHands();
			htmCount = 0;	
			qtmCount = 0;
			numRegrips = 0;
			rMoves = 0;
			lMoves = 0;
			string move;

			for(unsigned int j = 0; j < allAlgs[i].getMoves().size(); j++){
				move = allAlgs[i].getMove(j);
				
				TH.doMove(move);
				
				updateHTM(htmCount);
				updateQTM(qtmCount, move);
				updateRegrips(numRegrips, TH);
				updateRLMoves(rMoves, lMoves, TH);
			}
			domRatio = calcDomRatio(rMoves, lMoves, htmCount);
			calcGrade(qtmCount, htmCount, numRegrips, domRatio, qtmGrade, htmGrade, domGrade, regripGrade, grade);

			allAlgs[i].setHTM(htmCount);
			allAlgs[i].setQTM(qtmCount);
			allAlgs[i].setNumRegrips(numRegrips);
			allAlgs[i].setDomRatio(domRatio);
			allAlgs[i].setQTMGrade(qtmGrade);
			allAlgs[i].setHTMGrade(htmGrade);
			allAlgs[i].setDomGrade(domGrade);
			allAlgs[i].setRegripGrade(regripGrade);
			allAlgs[i].setGrade(grade);
			allAlgs[i].setGradedStatus();
		}
	}
}
void AlgRater::updateHTM(int &hCount){
	hCount++;
}

void AlgRater::updateQTM(int &qCount, string m){
	if(m.size() == 0){
		qCount++;
	}
	else if(m[1] == '2'){
		qCount+=2;
	}
	else{
		qCount++;
	}
}
void AlgRater::updateRegrips(int &regripCount, TwoHands &T){
	if(T.getLastMoveRegrip()){
		regripCount++;
	}
}
void AlgRater::updateRLMoves(int &rMoves, int &lMoves, TwoHands &T){
	if(T.getLastHand() == 'r'){
		rMoves++;
	}
	else{
		lMoves++;
	}
}
float AlgRater::calcDomRatio(int rMoves, int lMoves, int htmCount){
	if(DOM_HAND == 'r'){
		return (float)rMoves/(float)htmCount;
	}
	else{
		return (float)lMoves/(float)htmCount;
	}
}
void AlgRater::calcGrade(int qCount, int hCount, int regripCount, float domRatio, float &qtmGrade, float &htmGrade, float &domGrade, float &regripGrade, float &totalGrade){
	regripGrade = 100;
	qtmGrade = 100;
	htmGrade = 100;
	domGrade = 100;

	//lose points for every violation past preferred number
	//regrips
	if(regripCount > PREFERRED_REGRIPS){
		for(int r = regripCount - PREFERRED_REGRIPS; r > 0; r--){
			regripGrade *= 1 - REGRIP_PENALTY;
		}
	}
	//qtm
	if(qCount > PREFERRED_QTM){
		for(int q = qCount - PREFERRED_QTM; q > 0; q--){
			qtmGrade *= 1 - QTM_PENALTY;
		}
	}
	//htm
	if(hCount > PREFERRED_HTM){
		for(int h = hCount - PREFERRED_HTM; h > 0; h--){
			htmGrade *= 1 - HTM_PENALTY;
		}
	}
	//domRatio
	//cout << "dom ratio: "<< domRatio << endl;
	//cout << "preferred dom ratio: " << PREFERRED_DOM_RATIO <<  endl;
	if(domRatio < PREFERRED_DOM_RATIO){
		for(float d = PREFERRED_DOM_RATIO - domRatio; d > 0; d -= .01){
			domGrade *= 1 - DOM_PENALTY;
		}
	}
	//weight categories
	regripGrade *= REGRIP_WT;
	qtmGrade *= QTM_WT;
	htmGrade *= HTM_WT;
	domGrade *= DOM_WT;

	//sum categories
	totalGrade = regripGrade + qtmGrade + htmGrade + domGrade;
}
/*
bool AlgRater::compareAlgs(Alg a, Alg b){
	return a.getGrade() > b.getGrade();
}
 */
void AlgRater::sortAlgs(){
	std::sort(allAlgs.begin(), allAlgs.end(), compareAlgs());
}			
void AlgRater::clearAlgs(){
	allAlgs.clear();
}			