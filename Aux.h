#ifndef AUX_H
#define AUX_H

#include <fstream>
#include "Alg.h"
#include "AlgRater.h"

void greeting();
void showPrompt();
bool doOneCommand(AlgRater &algRater);
void addAlgFromPrompt(AlgRater &algRater);
void gradeAlgs(AlgRater &algRater);
void sortAlgs(AlgRater &algRater);
void showAllAlgs(AlgRater &algRater);
void showTopX(AlgRater &algRater);
void clearAlgs(AlgRater &algRater);
void showPreferences(AlgRater &algRater);
Alg stringToAlg(string s);
string getInput(string msg);
void addAllAlgsFromFile(AlgRater &algRater);
bool isValidChar1(char c);
bool isValidChar2(char c);

#endif