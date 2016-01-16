/*
Nat Baylon
1/8/2015
File: Aux.cpp
implementation of aux functions
*/
#include "Aux.h"
void greeting(){
	cout << "Welcome to AlgRater v1.0" << endl;
}
void showPrompt() {
    cout << endl <<
	"   Alg Rater Menu\n"
	" 1 - Add Algs From File\n"
	" 2 - Add Alg From Command Line\n"
	" 3 - Grade Algs\n"
	" 4 - Sort Algs\n"
	" 5 - Show All Algs\n"
	" 6 - Show Top X Algs\n"
	" 7 - Clear Algs\n"
	" 8 - Show User Preferences\n"
	"99 - Quit\n";
}
bool doOneCommand(AlgRater &algRater){
	bool doExit = false;
	string inputstr;
    int cmd;
    showPrompt();
    inputstr = getInput("Enter your choice: ");
    cmd = atoi(inputstr.c_str());
    
    switch(cmd){
    	case 1:
    		addAllAlgsFromFile(algRater);
    		break;
    	case 2:
    		addAlgFromPrompt(algRater);
    		break;
    	case 3:
    		gradeAlgs(algRater);
    		break;
    	case 4:
    		sortAlgs(algRater);
    		break;
    	case 5:
    		showAllAlgs(algRater);
    		break;
    	case 6:
    		showTopX(algRater);
    		break;
    	case 7:
    		clearAlgs(algRater);
    		break;
    	case 8:
    		showPreferences(algRater);
    		break;
    	case 99:
    		doExit = true; 
    		cout << "Exiting AlgRater\n";
    		break;
    	default:
			cout << "UNRECOGNIZED COMMAND??\n";
			break;
    }
    return doExit;
}
void addAllAlgsFromFile(AlgRater &algRater){
	string fileName;
	string inputLine;
	bool hasValidFile = false;
	do{
		fileName = getInput("Please enter the name of the input file, or type \"cancel\": ");
		if(fileName == "cancel"){
			return;
		}
		else{
			ifstream inputFile(fileName.c_str());
			if(!inputFile){
				cout << "Error: invalid file" << endl;
			}
			else{
				hasValidFile = true;
				while(inputFile){
					Alg theAlg;
					//inputLine = "";
					getline(inputFile, inputLine);
					if(inputLine.length() > 0 && inputLine.length() < 100){
						theAlg = stringToAlg(inputLine);
						if(theAlg.getMoves().size() != 0){
							algRater.addAlg(theAlg);
						}
					}
				}
				inputFile.close();
			}
		}
	} while (!hasValidFile);										
}
void addAlgFromPrompt(AlgRater &algRater){
	string algStr;
	do{
	 	algStr = getInput("Please enter an algorithm, or type \"cancel\": ");
	 	if(algStr == "cancel"){
	 		return;
	 	}
		else if(algStr.length() <= 0 || algStr.length() >= 100){
		 	cout << "Error: invalid amount of text entered" << endl;
		}
	} while(!(algStr.length() > 0 && algStr.length() < 100));

	Alg theAlg = stringToAlg(algStr);
	if(theAlg.getMoves().size() != 0){
		algRater.addAlg(theAlg);
	}
}
void gradeAlgs(AlgRater &algRater){
	if(algRater.getNumAlgs() == 0){
		cout << "Error: no algs currently in store" << endl;
	}
	else{
		algRater.gradeAlgs();
	}
}
void sortAlgs(AlgRater &algRater){
	if(algRater.getNumAlgs() == 0){
		cout << "Error: no algs currently in store" << endl;
	}
	else{
		algRater.sortAlgs();
	}
}
void showAllAlgs(AlgRater &algRater){
	if(algRater.getNumAlgs() == 0){
		cout << "Error: no algs currently in store" << endl;
	}
	else{
		algRater.showAllAlgs();
	}
}
void showTopX(AlgRater &algRater){
	if(algRater.getNumAlgs() == 0){
		cout << "Error: no algs currently in store" << endl;
	}
	else{
		int x;
		do{
			string numAlgsStr = getInput("Please enter the number of algs to display, or type \"cancel\": ");
			if(numAlgsStr == "cancel"){
				return;
			}
			x = atoi(numAlgsStr.c_str());
			if(x <= algRater.getNumAlgs() && x > 0){
				cout << "Error: number of algs must be greater than 0 and at most "<< algRater.getNumAlgs() << endl;
			}
		} while(!(x <= algRater.getNumAlgs() && x > 0));
		algRater.showTopX(x);
	}
}
void clearAlgs(AlgRater &algRater){
	if(algRater.getNumAlgs() == 0){
		cout << "Error: no algs currently in store" << endl;
	}
	else{
		algRater.clearAlgs();
	}
}
void showPreferences(AlgRater &algRater){
	algRater.showPreferences();
}
Alg stringToAlg(string s){
	string move = "";
	Alg theAlg;
	//cout << "algstr: " << s << endl;
	char character;
		unsigned int i = 0; 
		while(i < s.length()){
			character =s[i];
			if (isValidChar1(character)){
				//cout << "valid char1: " << character << endl;
				if (move.length() > 0){									//push move when two moves in row w/o second char
					theAlg.addMove(move);
					move = "";
				}
				move += character;
				i++;
			}
			else if(isValidChar2(character) && move.length() > 0){
				//cout << "valid char2: " << character << endl;
				move += character;
				theAlg.addMove(move);
				move = "";
				i++;
			}
			else if(character == '('){									//comment
				while(character != ')' && i < s.length()){
					character = s[i];							
					i++;	
				}
			}
			else{
				i++;
			}
		}
		if(move.length() > 0){
			theAlg.addMove(move);										//catch stray move 
		}
		return theAlg;
}
bool isValidChar1(char c){
	return c == 'R' || c == 'L' || c == 'F' || c == 'B' || c == 'U' || c == 'D';
}
bool isValidChar2(char c){
	return c == '2' || c == '\'';											//I've had problems with '\'' in c++ before
}
string getInput(string msg){
	string inputStr;
	cout << msg;
	getline(cin, inputStr);
	return inputStr;
}