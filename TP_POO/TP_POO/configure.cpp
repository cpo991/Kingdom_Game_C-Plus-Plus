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
		cout << "ERRO: Nao conseguiu abrir o ficheiro" << endl;
	}
	else {
		cout << file.rdbuf() << endl;
	}
	file.close();
	cout << "\nPressione [ENTER] para continuar...";
	cin.ignore();
	commands(); // calls the function to receive and read commands
}

/**
	Receives a string and separates it to see if it's a command.
	If it's a command, calls the respective function.
	Until the flag endProgram is set to 1 and the function ends.
*/
void configure::commands() {
	int endConfig = 0, turnos = 0, endTurno = 0,por_conquistar=0;
	string teste;
	game NewGame;

	help("helpconfig.txt");
	do {
		istringstream iss;
		cout << "\nInsira um comando:  ";
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
			}
		}
		if (!command.compare("lista")) {
			iss >> param1;
			if (!param1.compare("")) { //se tiver só lista imprime tudo
				cout << NewGame.listaTerritorios();
			}
			else {
				//senão vai para o cmd e imprime do territorio x
				cout << cmdLista(NewGame, param1);
			}
		}
		if (!command.compare("avanca")) {
			cout << "\n>>> AVISO: FASE DE CONFIGURACOES NAO PODE TERMINAR SEM TERRITORIOS CRIADOS." << endl;
		}
		if (!command.compare("help")) {
			cout << endl;
			help("helpconfig.txt");
		}
	} while (NewGame.getSizeTerritorios()==0);
	do {
		istringstream iss;
		cout << "\nInsira um comando:  ";
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
				cout << "\n>>> AVISO: FASE DE CONFIGURACOES TERMINOU... JOGO VAI COMECAR!\n\n" << endl;
				endConfig = 1;
			}
		if (!command.compare("help")) {
				cout << endl;
				help("helpconfig.txt");
			}
	} while (endConfig != 1);

//Ciclo de comandos depois do jogo começar
	help("helpfase1.txt");
	do {
		istringstream iss;
		cout << "\n>>>>>>>>>>>>>>> FASE 1 <<<<<<<<<<<<<<<<" << endl;
		cout << "\t Conquistar ou Passar?" << endl;
		cout << "\t\tTURNO " << turnos << endl;
		cout << "\nInsira um comando: ";
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
					NewGame = cmdConquista(NewGame, param1); //recebe bem qual a adicionar ao imperio e este ja foi construido
				}
			}
			turnos++;
		}
		if (!command.compare("passa")) {
			cout << "\nAVISO: NESTA META AS RESTANTES FASES NAO SE ENCONTRAM IMPLEMENTADAS." << endl;
			cout << "\t E PASSADO PARA O TURNO SEGUINTE." << endl;
			turnos++;
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
		if (!command.compare("help")) {
			cout << endl;
			help("helpfase1.txt");
		}
		if (!command.compare("sair")) {
			endTurno = 1;
		}
	
	} while (endTurno!=1 && turnos<12 && NewGame.getSizeTerritorios()!=0);
	cout << "\n>>> SAINDO... " << endl;
}

//Opens the file help.txt and prints everything inside it
void configure::help(string file){
	ifstream fhelp(file);
	ostringstream oss;
	//String str;
	if (!fhelp) {
		oss << "ERRO: Nao conseguiu abrir o ficheiro" << endl;
		return ;
	}

	/*while (getline(fCarrega, str)) {
	file.open("helpconfig.txt");*/

	if (!fhelp) {
		cout << "ERRO: Nao conseguiu abrir o ficheiro" << endl;
	}
	else {
		cout << fhelp.rdbuf() << endl;
	}
	fhelp.close();
}

/**
	Receives the string command and a number and prints that there are num parameters 
	missing in the command
	@param num the number of parameters missing
	@param command string of the command typed by the user
*/
void configure::needParam(int num, string command) {
	if (num == 0) {
		cout << "ERRO: O comando <" << command << "> necessita de mais parametros." << endl;
		  
	}
	else if (num == 1) {
		cout << "ERRO: Falta apenas 1 parametro no comando <" << command << ">." << endl;
	}
	else {
		cout << "ERROR: Ha " << num << " parametros no comando <" << command << ">." << endl;
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
		cout << "ERRO: Foi inserido 1 parametro que nao e necessario no comando <" << command << ">." << endl;
	}
	else {
		cout << "ERRO: Foram inseridos " << num << " parametros nao necessarios no comando <" << command << ">." << endl;
	}
}

game configure::cmdCarrega(game NewGame, string ficheiro) {
	string str;
	ostringstream oss;
	ifstream fCarrega(ficheiro);

	if (!fCarrega) {
		oss << "ERRO: Nao conseguiu abrir o ficheiro" << endl;
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

string configure::cmdLista(game NewGame, string name){
	ostringstream oss;
	oss << NewGame.listaTerritorios(name);
	return oss.str();
}