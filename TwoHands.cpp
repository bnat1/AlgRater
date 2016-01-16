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
	lh = Hand({{-1,{"B", "B2","F'","F2"}},
				{0,{"U'",/* "U2", */"D", "D2"}},
				{1,{/*"F", "F2", */"B'", "B2"}}});
	rh = Hand({{-1,{"B'", "B2", "F", "F'", "F2"}},
				{0,{"U", "U2", "D'", "D2"}},
				{1,{/*"F'","F2", */"B", "B2"}}});
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
/*
Hand* TwoHands::getLeftHand(){
	return &lh;
}
Hand* TwoHands::getRightHand(){
	return &rh;
}
*/
bool TwoHands::handleLR(std::string move){
	int lOffset = 0;
	int rOffset = 0;

	if(move == "L"){
		lOffset = -1;
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
	if(abs(lh.getPosition() + lOffset) >= POS_EXTREME || abs(rh.getPosition() + rOffset) >= POS_EXTREME	//end up in illegal position: regrip, do move, end up in starting position
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
void TwoHands::doMove(std::string move){
	lastMoveRegrip = false;
	if(move[0] == 'L'){
		lastMoveRegrip = handleLR(move);
		lastHand = 'l';
	}
	else if(move[0] == 'R'){
		lastMoveRegrip = handleLR(move);
		lastHand = 'r';
	}
	else if(lh.isAvail(lh.getPosition(), move)){			//no regrip required
		lastHand = 'l';
	}
	else if(rh.isAvail(rh.getPosition(), move)){
		lastHand = 'r';
	}
	else{
		int lhRegripPos = lh.getRegripPosition(move);		//not available for either hand: choose easiest regrip
		int rhRegripPos = rh.getRegripPosition(move);
		int lhDistance = abs(lh.getPosition() - lhRegripPos);
		int rhDistance = abs(rh.getPosition() - rhRegripPos);
		//cout << "lhDistance:" << lhDistance << endl;
		//cout << "rhDistance:" << rhDistance << endl;
		if(lhDistance <= rhDistance){
			lh.setPosition(lhRegripPos);
			lastHand = 'l';
		}
		else{
			rh.setPosition(rhRegripPos);
			lastHand = 'r';
		}
		lastMoveRegrip = true;
	}
}