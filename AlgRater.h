/*
file: AlgRater.h
author: Nat Baylon
modified: 10/24/2015 10:26 AM
description: definition of AlgRater
*/

#ifndef ALGRATER_H
#define ALGRATER_H

#include "Alg.h"
#include "TwoHands.h"
//#include <vector>
//#include <stdlib.h>
//#include <stdio.h>
//#include <iostream>

//using namespace std;

class AlgRater{
	public:
		void addAlg(Alg a);			//push alg into allAlgs
		void showTopX(int x);		//display top x algs with their stats
		void gradeAlgs();			//calc stats for all algs: QTM, HTM, numRegrips, lrRatio, grade
		void sortAlgs();			//sort algs descending using grade
		void clearAlgs();			//delete contents of allAlgs, reset numAlgs
		void updateHTM(int &hCount);
		void updateQTM(int &qCount, string m);
		void updateRegrips(int &regripCount, TwoHands &T);
		void updateRLMoves(int &rMoves, int &lMoves, TwoHands &T);
		float calcDomRatio(int rMoves, int lMoves, int htmCount);
		float calcGrade(int qCount, int hCount, int regripCount, int domRatio);
	private:
		vector<Alg> allAlgs;
		int numAlgs;
};

#endif 