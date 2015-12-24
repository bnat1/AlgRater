	/*
	*Author: Nat Baylon
	*Modified: 12/19/2015
	*
	*File: LeftHand.h
	*Description: definition of Hand
	*/

#ifndef HAND_H
#define HAND_H

#include <string>
#include <map>
#include <algorithm>

using namespace std;

class Hand{
	public:
		void reset();
		int getPosition();
		void setPosition(int p);
		bool inAvail(int mapIndex, string move);
		bool checkRegrip(string move);
		void doRegrip(int offset);	
	protected:
		int position;
		map <int, vector<string> > availableMoves;
};

#endif