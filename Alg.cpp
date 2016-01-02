/*
file: Alg.cpp
author: Nat Baylon
modified: 1/2/2015
description: implemetation of Alg class
*/

#include "Alg.h"
Alg::Alg(){}

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
	//show raw data
	cout << "\t|QTM: " << QTM
		<< "| HTM: " << HTM
		<< "| regrips: " << numRegrips
		<< "| dominant hand usage: " << domRatio << '|'<< endl
		<< "\t|QTM Grade: " << QTMGrade
		<< "|HTM Grade: " << HTMGrade
		<< "|Regrip grade: " << regripGrade
		<< "|Dominant hand grade: " << domGrade << '|' << endl
		<< "\t|Total grade: " << grade << "|" << endl;
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
float Alg::getQTMGrade(){
	return QTMGrade;
}
float Alg::getHTMGrade(){
	return HTMGrade;
}
float Alg::getRegripGrade(){
	return regripGrade;
}
float Alg::getDomGrade(){
	return domGrade;
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
void Alg::setQTMGrade(float q){
	QTMGrade = q;
}
void Alg::setHTMGrade(float h){
	HTMGrade = h;
}
void Alg::setRegripGrade(float r){
	regripGrade = r;
}
void Alg::setDomGrade(float d){
	domGrade = d;
}
void Alg::setGrade(float g){
	grade = g;
}
