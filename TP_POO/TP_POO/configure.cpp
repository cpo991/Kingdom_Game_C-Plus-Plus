//
//  Created by Carolina Oliveira & Isabel Castro on 14/11/2020
//
#include "configure.h"

configure::configure(){

}

/**
	Opens the file menu.txt and prints everything inside it
	Calls the function commands()
*/
void configure::initMenu(){
	fstream file;
	file.open("menu.txt");

	if (!file) {
		cout << "ERROR: Opening file." << endl;
	}
	else {
		cout << file.rdbuf() << endl;
	}
	file.close();
	cout << "\nPress any key to continue..." << endl;
	cin.ignore();
	commands(); // calls the function to receive and read commands
}

/**
	Receives a string and separates it to see if it's a command.
	If it's a command, calls the respective function.
	Until the flag endProgram is set to 1 and the function ends.
*/
void configure::commands(){
	int endProgram = 0;

	do {
		istringstream iss;
		cout << "\nEnter a command: ";
		getline(cin, phrase);
		iss.str(phrase);
		iss >> command;
		param1 = param2 = param3 = param4 = param5 = param6 = param7 = "";
		if (!command.compare("carrega")) {
			iss >> param1;
			if (!param1.compare("")) {
				needParam(1, command);
			}
			else {
				iss >> param2;
				if (param2.compare("")) {
					lessParam(1, command);
				}
				else {
					ifstream ficheiro(param1);
					if (ficheiro) {
						//FUNCTION CRIA HERE
					}
					else {
						cout << "ERROR: File not found." << endl;
					}
				}
			}
		}
		if (!command.compare("cria")) {
			iss >> param1;
			iss >> param2; 
			if (!param1.compare("")) { // tipo
				needParam(2, command);
			}
			else if (!param2.compare("")) { // n (mundo N)
				needParam(1, command);
			}
			else {
				// FUNCTION VERIFIE IF PARAM1 IS A TYPE
				// FUNCTION VERIFIE IF PARAM2 IS AN EXISTING WORLD
				// IF BOTH ARE TRUE THEN CREATE
			}
		}
		if (!command.compare("lista")) {
			iss >> param1;
			if (param1.compare("")) {
				lessParam(1, command);
			}
			else {
				//FUNCTION SHOW LIST HERE
			}
		}
		if (!command.compare("sair")) {
			cout << "\nWARNING: The program will exit." << endl;
			endProgram = 1;
		}
		if (!command.compare("help")) {
			cout << endl;
			help();
		}
	} while (endProgram != 1);

}
/**
	Opens the file help.txt and prints everything inside it
*/
void configure::help(){
	fstream file;
	file.open("help.txt");

	if (!file) {
		cout << "ERROR: Opening file." << endl;
	}
	else {
		cout << file.rdbuf() << endl;
	}
	file.close();
}

/**
	Receives the string command and a number and prints that there are num parameters 
	missing in the command
	@param num the number of parameters missing
	@param command string of the command typed by the user
*/
void configure::needParam(int num, string command) {
	if (num == 0) {
		cout << "ERROR: The command <" << command << "> needs more parameters." << endl;
	}
	else if (num == 1) {
		cout << "ERROR: There's 1 parameter missing in the command <" << command << ">." << endl;
	}
	else {
		cout << "ERROR: There are " << num << " parametros no comando <" << command << ">." << endl;
	}
}

/**
	Receives the string command and a number and prints that there are num parameters 
	that aren't needed in the command
	@param num the number of parameters that aren't needed
	@param command string of the command typed by the user
*/
void configure::lessParam(int num, string command) {
	if (num == 1) {
		cout << "ERROR: It was inserted 1 parameter that's not needed in the command <" << command << ">." << endl;
	}
	else {
		cout << "ERROR: It was inserted " << num << " parameter that's not needed in the command <" 
			<< command << ">." << endl;
	}
}