	/*
	*Author: Nat Baylon
	*Modified: 12/19/2015
	*File: RightHand.cpp
	*Description: implementation of RightHand
	*/
#include "RightHand.h"
RightHand::RightHand(){
	position = 0;
	//availableMoves[-2] = {"D", "D2", "U'", "U2"};
	availableMoves[-1] = {"B'", "B2", "F", "F'", "F2"};
	availableMoves[0] = {"U", "U2", "D'", "D2"};
	availableMoves[1] = {"F'","F2", "B", "B2"};
	//availableMoves[2] = {"D", "D2", "U'", "U2"};
}


