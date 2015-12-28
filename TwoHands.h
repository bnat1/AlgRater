/*
file: TwoHands.cpp
author: Nat Baylon
modified: 10/27/2015 1:53 AM
description: def of TwoHands
*/
#ifndef TWOHANDS_H
#define TWOHANDS_H

#include <stdio.h>
//#include <iostream>
//#include <cstdlib>
#include "LeftHand.h"
#include "RightHand.h"

using namespace std;

class TwoHands{
	public:
		TwoHands();
		void resetHands();
		void doMove(string move);
		Hand* getLeftHand();
		Hand* getRightHand();
		char getLastHand();
		bool getLastMoveRegrip();
	private:
		bool handleLR(string move);
		bool lastMoveRegrip;		//yes: true, no: false
		char lastHand;				//'l' or 'r'
		LeftHand lh;
		RightHand rh;
};

#endif