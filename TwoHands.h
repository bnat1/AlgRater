/*
file: TwoHands.cpp
author: Nat Baylon
modified: 10/27/2015 1:53 AM
description: def of TwoHands
*/
#ifndef TWOHANDS_H
#define TWOHANDS_H

//#include <stdio.h>
//#include <iostream>
//#include <cstdlib>
//#include "LeftHand.h"
//#include "RightHand.h"
#include <iostream>
#include <ctype.h>
#include "Hand.h"

//using namespace std;

class TwoHands{
	public:
		TwoHands();
		void resetHands();
		void doMove(string move);
		//Hand* getLeftHand();
		//Hand* getRightHand();
		char getLastHand();
		bool getLastMoveRegrip();
		bool getLastMoveRotation();
	private:
		bool handleLR(string move);
		bool lastMoveRegrip;		//yes: true, no: false
		bool lastMoveRotation;
		char lastHand;				//'l' or 'r'
		Hand lh;
		Hand rh;
};

#endif