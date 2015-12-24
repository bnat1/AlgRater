/*
*Author: Nat Baylon
*Modified: 12/19/2015
*
*File: TwoHands.cpp
*Description: implementation of TwoHands
*/

#include "TwoHands.h"
#define MAX_HAND_DIFF 2
#define POS_EXTREME	2


TwoHands::TwoHands(){
resetHands();
}

char TwoHands::getLastHand(){
	return lastHand;
}
bool TwoHands::getLastMoveRegrip(){
	return lastMoveRegrip;
}
void TwoHands::resetHands(){
	lh.reset();
	rh.reset();
}

bool TwoHands::handleLR(string move){
	int lOffset = 0;
	int rOffset = 0;

	if(move == "L"){
		lOffset = -1;
		lastHand = 'lh';
	}
	else if(move == "L'"){
		lOffset = 1;
	}
	else if (move == "L2"){
		if(lh.getPosition() == -1){		//L2 Vs L2'
			lOffset = 2;
		}
		else{
			lOffset = -2;
		}
	}
	else if(move == "R'"){
		rOffset = -1;
	}
	else if(move == "R"){
		rOffset = 1;
	}
	else if (move == "R2"){
		if(rh.getPosition() == 1){
			rOffset = -2;
		}
		else{
			rOffset = 2;
		}
	}
	
	//check if offset leads to regrip
	if(abs(lh.getPosition() + lOffset) > POS_EXTREME || abs(rh.getPosition() + rOffset) > POS_EXTREME	//end up in illegal position: regrip, do move, end up in starting position
		|| abs((lh.getPosition() + lOffset) - (rh.getPosition() + rOffset)) > MAX_HAND_DIFF){			//awk hand position: same
		return true;											
	} 
	else{
		//regular move
		lh.setPosition(lh.getPosition() + lOffset);
		rh.setPosition(rh.getPosition() + rOffset);
		return false;											
	}
	
}
void TwoHands::doMove(string move){
	lastMoveRegrip = false;
	if(move[0] == 'L'){
		lastHandRegrip = handleLR(move);
		lastHand = 'l';
	}
	else if(move[0] == 'R'){
		lastHandRegrip = hadleLR(move);
		lasthand = 'r';
	}
	else if(lh.checkRegrip(move) && rh.checkRegrip(move)){												//not available for either hand: choose easiest regrip
		lhDistance = lh.getRegripDistance(move);
		rhDistance = rh.getRegripDistance(move);
		if(abs(lhDistance) <= abs(rhDistance)){
			lh.doRegrip(lhDistance);
			lasthand = 'l';
		}
		else{
			rh.doRegrip(rhDistance);
			lasthand = 'r';
		}
		lastMoveRegrip = true;
	}
	//else move is good, no regrip
}