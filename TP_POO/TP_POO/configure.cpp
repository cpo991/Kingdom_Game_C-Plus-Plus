//
//  Created by Carolina Oliveira & Isabel Castro on 14/11/2020
//
#include "configure.h"

configure::configure(game& g){
	newGame = &g;
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
	cout << "\nPress any key to continue...";
	cin.ignore();
	commands(); // calls the function to receive and read commands
}

/**
	Receives a string and separates it to see if it's a command.
	If it's a command, calls the respective function.
	Until the flag endProgram is set to 1 and the function ends.
*/
void configure::commands() {
	int endConfig = 0, endFase1 = 0;
	string teste;
	game NewGame;
	do {
		istringstream iss;
		cout << "\nConfiguration Phase" << endl;
		cout << "\nEnter a command: ";
		getline(cin, phrase);
		iss.str(phrase);
		iss >> command;
		param1 = param2 = param3 = param4 = param5 = param6 = param7 = "";

		//COMANDOS CARREGA, CRIA , LISTA , AVANÇA E HELP
		if (!command.compare("carrega")) {
			iss >> param1;//PARMA1=comandos2.txt
			if (!param1.compare("")) {
				needParam(1, command);
			}
			else {
				iss >> param2;
				if (param2.compare("")) {
					lessParam(1, command);
				}
				else {
					cout << param1 << endl;
					NewGame = cmdCarrega(NewGame, param1);
				}
			}
		}
		if (!command.compare("cria")) {
			iss >> param1; //CRIA
			iss >> param2; //MINA
			if (!param1.compare("")) { // tipo
				needParam(2, command);
			}
			else if (!param2.compare("")) { // n (mundo N)
				needParam(1, command);
			}
			else {
				int num = stoi(param2); //2
				for (int i = 0; i < num; i++) {
					NewGame.addTerritory(param1); //PARAM 1= MINA
				}
				// FUNCTION VERIFIE IF PARAM1 IS A TYPE
				// FUNCTION VERIFIE IF PARAM2 IS AN EXISTING WORLD
				// IF BOTH ARE TRUE THEN CREATE
			}
		}
		//LISTA AQUI FUNCIONA BEM
		if (!command.compare("lista")) {
			iss >> param1;
			if (!param1.compare("")) { //se tiver só lista imprime tudo
				cout<<NewGame.listaTerritorios();
			}
			else {
				//senão vai para o cmd e imprime do territorio x
				cout<<cmdLista(NewGame, param1);
			}
		}
		if (!command.compare("avanca")) {
				cout << "\nWARNING: The configuration phase is over. Game will start soon..." << endl;
				endConfig = 1;
			}
		if (!command.compare("help")) {
				cout << endl;
				help();
			}
		} while (endConfig != 1);


	//CICLO DE COMANDOS DEPOIS DO JOGO COMEÇAR
	do {
		istringstream iss;
		cout << "\n Conquistar ou Passar?" << endl;

		cout << "\nEnter a command: ";
		getline(cin, phrase);
		iss.str(phrase);
		iss >> command;
		param1 = param2 = param3 = param4 = param5 = param6 = param7 = "";


		if (!command.compare("conquista")) {
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
					cmdConquista(NewGame, param1); //recebe bem qual a adicionar ao imperio e este ja foi construido
				}
			}

		}
		if (!command.compare("lista")) {
			iss >> param1;
			if (!param1.compare("")) { //se tiver só lista imprime tudo
				cout << NewGame.listaTerritorios();
			}
			else {
				//senão vai para o cmd e imprime do territorio x
				cout<<cmdLista(NewGame, param1);
			}
		}
		if (!command.compare("sair")) {
			endFase1 = 1;
		}
		
	} while (endFase1 != 1);

}
/**
	Opens the file help.txt and prints everything inside it
*/
void configure::help(){
	fstream file;
	file.open("helpconfig.txt");

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

game configure::cmdCarrega(game NewGame, string ficheiro) {
	string str;
	ostringstream oss;
	ifstream fCarrega(ficheiro);

	if (!fCarrega) {
		oss << "ERROR: Opening file." << endl;
		return NewGame;
	}

	while (getline(fCarrega, str)) {
		ostringstream oss;
		string command, name, num;
		int N;
		istringstream iss(str);
		getline(iss, command, ' ');
		getline(iss, name, ' ');
		getline(iss, num, ' ');
		N = stoi(num);
		

		for (int i = 0; i < N; i++) {
			oss <<NewGame.addTerritory(name);
		}
	}

	return NewGame;
}

game configure::cmdConquista(game NewGame, string name){
	ostringstream oss;
	cout<<NewGame.conquistaTerritorios(name);
	
	return NewGame;
	
}

string configure::cmdLista(game NewGame, string name)
{
	ostringstream oss;
	oss << NewGame.listaTerritorios(name);
	return oss.str();
}

//game configure::cmdLista(game NewGame, string name) {
//	
//	cout <<NewGame.listaTerritorios(name);
//	return NewGame;
//}

