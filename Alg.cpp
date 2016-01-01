/*
file: Alg.cpp
author: Nat Baylon
modified: 10/27/2015 1:53 AM
description: implemetation of Alg class
*/

#include "Alg.h"

Alg::Alg(vector<string> m){
moves = m;
}
void Alg::showAlg(){
	for(unsigned int i = 0; i < moves.size(); i++){
		cout << moves[i] << ' ';
	}
	cout << endl;
}			

void Alg::showStats(){
	cout << "\tQTM: " << QTM
		<< " HTM: " << HTM
		<< " regrips: " << numRegrips
		<< " dominant hand usage: " << domRatio
		<< " total grade: " << grade << endl;
}				
string Alg::getMove(int i){
	return moves[i];
}
vector<string> Alg::getMoves(){
	return moves;
}
int Alg::getQTM(){
	return QTM;
}
int Alg::getHTM(){
	return HTM;
}
int Alg::getNumRegrips(){
	return numRegrips;
}
float Alg::getDomRatio(){
	return domRatio;
}
float Alg::getGrade(){
	return grade;
}
void Alg::addMove(string m){
	moves.push_back(m);
}
void Alg::setMoves(vector<string> m){
	moves = m;
}
void Alg::setQTM(int q){
	QTM = q;
}
void Alg::setHTM(int h){
	HTM = h;
}
void Alg::setNumRegrips(int n){
	numRegrips = n;
}
void Alg::setDomRatio(float r){
	domRatio = r ;
}
void Alg::setGrade(float g){
	grade = g;
}