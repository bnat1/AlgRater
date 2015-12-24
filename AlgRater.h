/*
file: AlgRater.h
author: Nat Baylon
modified: 10/24/2015 10:26 AM
description: definition of AlgRater
*/

#ifndef ALGRATER_H
#define ALGRATER_H

#include "Alg.h"
#include <vector>
#include <stdlib>
#include <stdio>
#include <iostream>

using namespace std;

class AlgRater{
	public:
		void addAlg(const Alg *a);		//push alg into allAlgs
		void showTopX(const int x);		//display top x algs with their stats
		void gradeAlgs();			//calc stats for all algs: QTM, HTM, numRegrips, lrRatio, grade
		void sortAlgs();			//sort algs descending using grade
		void clearAlgs();			//delete contents of allAlgs, reset numAlgs
	private:
		vector<Alg> allAlgs;
		int numAlgs;
};

#endif 