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

//weight for each category, must add up to 1!
#define REGRIP_WT 0.2
#define ROTATION_WT 0.2
#define DOM_WT 0.2
#define QTM_WT 0.4
#define HTM_WT 0

//perferences 
#define PREFERRED_QTM 15
#define PREFERRED_HTM 12
#define PREFERRED_DOM_RATIO 0.75
#define PREFERRED_REGRIPS 3
#define PREFERRED_ROTATIONS 0

//penalties to be deducted from 100 points for each category
#define QTM_PENALTY 10
#define HTM_PENALTY 0
#define REGRIP_PENALTY 10
#define DOM_PENALTY 4				//per .01 below preferred ratio
#define ROTATION_PENALTY 25			//rotations suck

//other preferences
#define BEGIN_END_ROT_COUNT false	//first/last move as regrip counts: true/false
#define DOM_LR_ONLY true 			// only look for L/R moves for dominant usage
#define DOM_HAND 'r'				// 'r' or 'l'

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
		void updateHTM(int &hCount, string m);
		void updateQTM(int &qCount, string m);
		void updateRotations(int &rotationCount, TwoHands &T, int j, int l);
		void updateRegrips(int &regripCount, TwoHands &T);
		void updateRLMoves(int &rMoves, int &lMoves, TwoHands &T,string m);
		float calcDomRatio(int rMoves, int lMoves);
		void calcGrade(int qCount, int hCount, int regripCount, int rotationCount, float domRatio, 
			float &qtmGrade, float &htmGrade, float &domGrade, float &regripGrade, float &rotationGrade, float &totalGrade);
		//callable struct, for comparing two algs
		struct compareAlgs{
			bool operator() (Alg alg1, Alg alg2) const{
				return alg1.getGrade() > alg2.getGrade();
			}
		};
};

#endif 