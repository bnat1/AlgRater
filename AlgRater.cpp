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
#define QTM_WT 0.25
#define HTM_WT 0.10
#define PREFERRED_QTM 15
#define PREFERRED_HTM 12
#define PREFERRED_DOM_RATIO 0.75
#define PREFERRED_REGRIPS 3
#define QTM_PENALTY 0.9
#define HTM_PENALTY 0.8
#define REGRIP_PENALTY 0.85
#define DOM_PENALTY 0.95		//per .01 below

void AlgRater::addAlg(Alg a){
	allAlgs.push_back(a);
}		
void AlgRater::showTopX(int x){

}
void AlgRater::gradeAlgs(){
	TwoHands TH;
	int htmCount;	
	int qtmCount;
	int numRegrips;
	int rMoves;
	int lMoves;
	float domRatio;
	float grade;

	for(unsigned int i = 0;  i < allAlgs.size(); i++){
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
		grade = calcGrade(qtmCount, htmCount, numRegrips, domRatio);

		allAlgs[i].setHTM(htmCount);
		allAlgs[i].setQTM(qtmCount);
		allAlgs[i].setNumRegrips(numRegrips);
		allAlgs[i].setDomRatio(domRatio);
		allAlgs[i].setGrade(grade);
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
float AlgRater::calcGrade(int qCount, int hCount, int regripCount, int domRatio){
	float regripGrade = 100;
	float qtmGrade = 100;
	float htmGrade = 100;
	float domGrade = 100;
	float totalGrade;

	//lose points for every violation past preferred number
	//regrips
	if(regripCount > PREFERRED_REGRIPS){
		for(int r = regripCount - PREFERRED_REGRIPS; r > 0; r--){
			regripGrade *= REGRIP_PENALTY;
		}
	}
	//qtm
	if(qCount > PREFERRED_QTM){
		for(int q = qCount - PREFERRED_QTM; q > 0; q--){
			qtmGrade *= QTM_PENALTY;
		}
	}
	//htm
	if(hCount > PREFERRED_HTM){
		for(int h = hCount - PREFERRED_HTM; h > 0; h--){
			htmGrade *= HTM_PENALTY;
		}
	}
	//domRatio
	if(domRatio < PREFERRED_DOM_RATIO){
		for(float d = PREFERRED_DOM_RATIO - domRatio; d > 0; d -= .01){
			domGrade *= DOM_PENALTY;
		}
	}
	//weight categories
	regripGrade *= REGRIP_WT;
	qtmGrade *= QTM_WT;
	htmGrade *= HTM_WT;
	domGrade *= DOM_WT;

	//sum categories
	totalGrade = regripGrade + qtmGrade + htmGrade + domGrade;
	return totalGrade;
}
void AlgRater::sortAlgs(){

}			
void AlgRater::clearAlgs(){

}			