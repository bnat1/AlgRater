/*
file: testDrover1.cpp
author: Nat Baylon
modified: 10/27/2015 1:53 AM
description: test of twohands, hand, alg, 
*/

#include "TwoHands.h"
#include "Alg.h"
//#include <string>
//#include <stdio.h>
//#include <iostream>
//#include <cstdlib>

using namespace std;

int main(){
	TwoHands TH;
	//Alg alg({"R", "U", "R'", "U'", "R'", "F", "R2", "U'", "R'", "U'", "R", "U", "R'", "F'"});
	Alg alg({"R", "U2", "R'", "U'", "R", "U2", "L'", "U", "R'", "U'", "L"});

	//Alg alg({"R", "U", "R'", "U'", "R'", "F", "R2", "U'", "R'", "U'", "R", "U", "R'", "F'"});


	std::string move;	
	int htmCount = 0;	
	int qtmCount = 0;
	int numRegrips = 0;
	int rMoves = 0;
	int lMoves = 0;

	for(unsigned int i = 0; i < alg.getMoves().size(); i++){
		move = alg.getMove(i);
		cout << "move: "<< move << endl;
		TH.doMove(move);
		cout << "\tlast hand: " << TH.getLastHand() << endl;
		cout << "\tregrip: "<< TH.getLastMoveRegrip() << endl;
		//cout<< "\tleft hand position: " << TH.getLeftHand()->getPosition() << endl;
		//cout<< "\tright hand position: " << TH.getRightHand()->getPosition() << endl;

		//todo: make functions for the following in Algrater class
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
	
	cout << "numL: " << lMoves << endl;
	cout << "numR: " << rMoves << endl;

	alg.setHTM(htmCount);
	alg.setQTM(qtmCount);
	alg.setNumRegrips(numRegrips);
	alg.setDomRatio((float)rMoves/(float)htmCount);
/*
	alg.showAlg();
	alg.showStats();*/
	//todo: make function to print summary in Aux
	
	cout << "\n********************************\n";
	cout << "Summary: " << endl;
	cout << "\thtm: " << alg.getHTM() << endl;
	cout << "\tqtm: " << alg.getQTM() << endl;
	cout << "\tR/L ratio: " << alg.getDomRatio() << endl;
	cout << "\tregrip count: " << alg.getNumRegrips() << endl;

	return 0;
}