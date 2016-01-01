/*
file: Alg.h
author: Nat Baylon
modified: 10/27/2015 1:53 AM
description: definition of Alg class
*/

#ifndef ALG_H
#define ALG_H

#include <vector>
#include <string>
#include <stdio.h>
#include <iostream>

using namespace std;

class Alg{
public:
	Alg(vector<string> m);			//constructor with moves vector as param
	void showAlg();					//display moves
	void showStats();				//display stats

	string getMove(int i);
	vector<string> getMoves();
	int getQTM();
	int getHTM();
	int getNumRegrips();
	float getDomRatio();
	float getGrade();

	void addMove(string m);			//add individual move to end of moves
	void setMoves(vector<string> m);//set all moves
	void setQTM(int q);
	void setHTM(int h);
	void setNumRegrips(int n);
	void setDomRatio(float r);
	void setGrade(float g);

private:
	vector<string> moves;
	int QTM;
	int HTM;
	int numRegrips;
	float domRatio;
	float grade;
};
#endif