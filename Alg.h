/*
file: Alg.h
author: Nat Baylon
modified: 10/24/2015 10:16 AM
description: definition of Alg class
*/

#ifndef ALG_H
#define ALG_H

#include <vector>
#include <string>
#include <stdio>
#include <iostream>

using namespace std;

class Alg{
public:
	void showAlg();					//display moves
	void showStats();				//display stats

	int getQTM();
	int getHTM();
	int getNumRegrips();
	float getRLratio();
	float getGrade();

	void setMoves(vector<string> m);
	void setQTM(int q);
	void setHTM(int h);
	void setNumRegrips(int n);
	void setRLratio(float r);
	void setGrade(float g);

private:
	vector<string> moves;
	int QTM;
	int HTM;
	int numRegrips;
	float rlRatio;
	float grade;

};
#endif