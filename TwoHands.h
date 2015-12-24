#ifndef TWOHANDS_H
#define TWOHANDS_H

#include "LeftHand.h"
#include "RightHand.h"

using namespace std;

class TwoHands{
	public:
		TwoHands();
		void resetHands();
		void doMove(string move);
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