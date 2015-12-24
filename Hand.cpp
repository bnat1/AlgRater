	/*
	*Author: Nat Baylon
	*Modified: 12/19/2015
	*
	*File: Hand.cpp
	*Description: implementation of Hand
	*/

#include Hand.h
#define NOT_FOUND 10

void Hand::reset(){
	posiiton = 0;
}
void Hand::getPosition(){
	return position;
}
void setPosition(int p){
	position = p;
}

bool Hand::inAvail(int mapIndex, string move){
	bool result = false;
	if(std::find(availableMoves[mapIndex].begin(), //if move is not in currrent grip
		availableMoves[mapIndex].end(),
		m) != availableMoves[mapIndex].end()){
			result = true;
	}
	return result;
}

bool Hand::checkRegrip(string move){
	bool badMove = true;
	if(inAvail(position, move)){
		badMove = false;
	}
	return badMove;
}

int getRegripPos(string move){
	for(int i = -1; i < 1; i++){
		if(inAvail(i, move)){
			return i;
		}	
	}
	return NOT_FOUND;
}
void Hand::doRegrip(int offset){
	position += offset;
}

int Hand::getRegripDistance(string move){
	int regripPos = getRegripPos(move);
	if(regripPos == NOT_FOUND){
		return regripPos;
	}
	else{
		return position - regripPos;
	}	
}