	/*
	*Author: Nat Baylon
	*Modified: 12/19/2015
	*
	*File: Hand.cpp
	*Description: implementation of Hand
	*/

#include "Hand.h"
#define NOT_FOUND 10

Hand::Hand(){}

Hand::Hand(map<int, vector<string> > avMoves){
	availableMoves = avMoves;
	position = 0;
}

void Hand::reset(){
	position = 0;
}
int Hand::getPosition(){
	return position;
}
void Hand::setPosition(int p){
	position = p;
}

bool Hand::isAvail(int mapIndex, string move){
	bool result = false;
	if(std::find(availableMoves[mapIndex].begin(), //if move is not in currrent grip
		availableMoves[mapIndex].end(),
		move) != availableMoves[mapIndex].end()){
			result = true;
	}
	return result;
}

int Hand::getRegripPosition(string move){
	for(int i = -1; i < 1; i++){
		if(isAvail(i, move)){
			return i;
		}	
	}
	return NOT_FOUND;
}