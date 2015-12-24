/*
file: Alg.cpp
author: Nat Baylon
modified: 10/24/2015 10:16 AM
description: implemetation of Alg class
*/

#include "Alg.h"

void showAlg(){
	for(int i = 0; i < moves.size(); i++){
		cout << moves[i] << ' ';
	}
	cout << endl;
}			

void showStats(){
	cout << "QTM: " << QTM
		<< "HTM: " << HTM
		<< "regrips: " << numRegrips
		<< "hand ratio r/l: " << rlRatio
		<< "total score: " << grade << endl;
}				

int getQTM(){
	return QTM;
}
int getHTM(){
	return HTM;
}
int getNumRegrips(){
	return numRegrips;
}
float getRLratio(){
	return rlRatio;
}
float getGrade(){
	return grade;
}
void setMoves(vector<string> m){
	moves = m;
}
void setQTM(int q){
	QTM = q;
}
void setHTM(int h){
	HTM = h;
}
void setNumRegrips(int n){
	numRegrips = n;
}
void setRLratio(float r){
	lrRatio = r ;
}
void setGrade(float g){
	grade = g;
}