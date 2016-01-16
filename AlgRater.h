/*
file: AlgRater.h
author: Nat Baylon
modified: 1/2/2015
description: definition of AlgRater
*/

#ifndef ALGRATER_H
#define ALGRATER_H

#include "Alg.h"
#include "TwoHands.h"
//#include <algorithm>
//#include <vector>
//#include <stdlib.h>
//#include <stdio.h>
//#include <iostream>

//using namespace std;

class AlgRater{
	public:
		void addAlg(Alg a);			//push alg into allAlgs
		void showAllAlgs();
		void showPreferences();
		void showTopX(unsigned int x);		//display top x algs with their stats
		int  getNumAlgs();			//get number of algs in allAlgs
		void gradeAlgs();			//calc stats for all algs: QTM, HTM, numRegrips, lrRatio, grade
		void sortAlgs();			//sort algs descending using grade
		void clearAlgs();			//delete contents of allAlgs, reset numAlgs
	private:
		vector<Alg> allAlgs;
		int numAlgs;
		void updateHTM(int &hCount);
		void updateQTM(int &qCount, string m);
		void updateRegrips(int &regripCount, TwoHands &T);
		void updateRLMoves(int &rMoves, int &lMoves, TwoHands &T);
		float calcDomRatio(int rMoves, int lMoves, int htmCount);
		void calcGrade(int qCount, int hCount, int regripCount, float domRatio, 
			float &qtmGrade, float &htmGrade, float &domGrade, float &regripGrade, float &totalGrade);
		struct compareAlgs{
			bool operator() (Alg alg1, Alg alg2) const{
				return alg1.getGrade() > alg2.getGrade();
			}
		};
};

#endif 