/*
file: Alg.cpp
author: Nat Baylon
modified: 10/24/2015 10:26 AM
description: implentation of AlgRater class
*/

#include "AlgRater.h"

#define REGRIP_WT 25
#define RL_WT 40
#define QTM_WT 25
#define HTM_WT 10
#define PREFERRED_QTM 15
#define PREFERRED_QTMHTM_RATIO 10

void AlgRater::addAlg(Alg *a){
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
	Alg* algPtr;

	for(unsigned int i = 0;  i < allAlgs.size(); i++){
		htmCount = 0;	
		qtmCount = 0;
		numRegrips = 0;
		rMoves = 0;
		lMoves = 0;
		string move;
		algPtr = allAlgs[i];

		for(unsigned int j = 0; j < algPtr->getMoves().size(); j++){
			move = algPtr->getMove(j);
			//cout << "move: "<< move << endl;
			TH.doMove(move);
			/*
			cout << "\tlast hand: " << TH.getLastHand() << endl;
			cout << "\tregrip: "<< TH.getLastMoveRegrip() << endl;
			cout<< "\tleft hand position: " << TH.getLeftHand()->getPosition() << endl;
			cout<< "\tright hand position: " << TH.getRightHand()->getPosition() << endl;
			*/

			//update qtm/htm
			htmCount++;
			if(move.size() == 0){
				qtmCount++;
			}
			else if(move[1] == '2'){
				qtmCount+=2;
			}
			else{
				qtmCount++;
			}
			//update numRegrips
			if(TH.getLastMoveRegrip()){
				numRegrips++;
			}
			//update rl moves
			if(TH.getLastHand() == 'r'){
				rMoves++;
			}
			else{
				lMoves++;
			}

		}
		
		//cout << "numL: " << lMoves << endl;
		//cout << "numR: " << rMoves << endl;

		//set alg's instance variables
		algPtr->setHTM(htmCount);
		algPtr->setQTM(qtmCount);
		algPtr->setNumRegrips(numRegrips);
		algPtr->setRLratio((float)rMoves/(float)lMoves);
	
		//todo: make a grading system
	}
}			
void AlgRater::sortAlgs(){

}			
void AlgRater::clearAlgs(){

}			