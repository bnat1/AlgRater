/*
file: testDrover2.cpp
author: Nat Baylon
modified: 1/2/2016
description: test of AlgRater: grading, sorting, showing algs
*/
#include "Alg.h"
#include "AlgRater.h"
#include "TwoHands.h"

int main(){
	AlgRater algRater;
	TwoHands twoHands;

	Alg r8 ({"R","R","R","R","R","R","R","R"});
	Alg fPerm;
	fPerm.setMoves({"R'","U'","F'","R","U","R'","U'","R'","F","R2","U'","R'","U'","R","U","R'","U","R"});
	Alg uPerm;
	uPerm.addMove("R2"); uPerm.addMove("U"); uPerm.addMove("R"); uPerm.addMove("U"); uPerm.addMove("R'"); uPerm.addMove("U'"); uPerm.addMove("R'"); uPerm.addMove("U'");uPerm.addMove("R'"); uPerm.addMove("U"); uPerm.addMove("R'");
	Alg yPerm ({"F","R","U'","R'","U'","R","U","R'","F'","R","U","R'","U'","R'","F","R","F'"});
	Alg sexy6 ({"R","U","R'","U'","R","U","R'","U'","R","U","R'","U'","R","U","R'","U'","R","U","R'","U'","R","U","R'","U'"});
	Alg jPerm ({"R", "U2", "R'", "U'", "R", "U2", "L'", "U", "R'", "U'", "L"});

	algRater.addAlg(sexy6);
	algRater.addAlg(fPerm);
	algRater.addAlg(uPerm);
	algRater.addAlg(yPerm);
	algRater.addAlg(r8);
	algRater.addAlg(jPerm);
	algRater.showPreferences();
	algRater.gradeAlgs();
	algRater.sortAlgs();
	algRater.showAllAlgs();
	algRater.showTopX(2);
}