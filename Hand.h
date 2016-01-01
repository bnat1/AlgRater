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
//#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Hand{
	public:
		Hand();
		Hand(map <int, std::vector<string> > avMoves);
		void reset();
		int getPosition();
		int getRegripPosition(string move);
		void setPosition(int p);
		bool isAvail(int mapIndex, string move);
	private:
		int position;
		map<int, std::vector<string> > availableMoves;
};

#endif