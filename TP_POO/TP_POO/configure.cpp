//
//  Created by Carolina Oliveira & Isabel Castro on 14/11/2020
//
#include "configure.h"

configure::configure(game& g) {
	newGame = &g;
}

// Abre o ficheiro menu.txt e imprime
// Chama a função commands()
void configure::initMenu() {
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

//Recebe uma string e separa para ver se é um comando
//Se for, chama a respetiva função
//Termina esta função quando endConfig=1 ou então certas condições do jogo atingidas
void configure::commands() {
	int endConfig = 0, turnos = 0, endTurno = 0, por_conquistar = 0, recolha_prod = 0, compras = 0;
	int endFase3 = 0,endFase1=0;
	string teste;
	game NewGame;

	NewGame.addTerritory("territorioInicial");
	NewGame = cmdConquista(NewGame, "territorioInicial");

	help("helpconfig.txt");

	//Ciclo de comandos antes do jogo começar --> obrigatório ter territórios
	do {
		istringstream iss;
		cout << "\nInsira um comando:  ";
		getline(cin, phrase);
		iss.str(phrase);
		iss >> command;
		param1 = param2 = param3 = param4 = param5 = param6 = param7 = "";

		//COMANDOS CARREGA, CRIA , LISTA , AVANÇA E HELP
		if (!command.compare("carrega")) {
			iss >> param1; //param1 = comandos2.txt por exemplo
			if (!param1.compare("")) {
				needParam(1, command);
			}
			else {
				iss >> param2;
				if (param2.compare("")) {
					lessParam(1, command);
				}
				else {
					//verificação para erro de tipo de territorio n permitido
					const int nVetor = NewGame.getSizeTerritorios();
					NewGame = cmdCarrega(NewGame, param1);
					int newNVetor = NewGame.getSizeTerritorios();
					if (nVetor == newNVetor)
						cout << "ERROR: O ficheiro <" << param1 << "> esta vazio ou nao existe." << endl;
				}
			}
		}
		if (!command.compare("cria")) {
			iss >> param1; // param1= cria
			iss >> param2; // param2= mina
			if (!param1.compare("")) { // Tipo de territorio
				needParam(2, command);
			}
			else if (!param2.compare("")) { // Quantidade a criar
				needParam(1, command);
			}
			else {
				if (param1 != "territorioInicial") {
					int num = stoi(param2); //2
					size_t nVetor = NewGame.getSizeTerritorios();
					for (int i = 0; i < num; i++) {
						NewGame.addTerritory(param1); //cria x territorios de nome y
					}
					size_t newNVetor = NewGame.getSizeTerritorios();
					if (nVetor == newNVetor)
						cout << "ERROR: O tipo de territorio <" << param1 << "> nao e permitido." << endl;
				}
				else {
					cout << "\n>>> AVISO: nao podem ser criados <territorioInicial>" << endl;
				}
			}
		}
		if (!command.compare("lista")) {
			iss >> param1;
			if (!param1.compare("")) { // lista --> imprime descrição geral do jogo
				cout << NewGame.listaTerritorios();
			}
			else {
				cout << cmdLista(NewGame, param1); // lista x --> imprime descrição de um territorio
			}
		}
		if (!command.compare("avanca")) {
			cout << "\n>>> AVISO: FASE DE CONFIGURACOES NAO PODE TERMINAR SEM TERRITORIOS CRIADOS." << endl;
		}
		if (!command.compare("help")) {
			cout << endl;
			help("helpconfig.txt");
		}
	} while (NewGame.getSizeTerritorios() == 0);

	//Ciclo de comandos antes do jogo começar enquanto carrega mais que um territorio
	do {
		istringstream iss;
		cout << "\nInsira um comando:  ";
		getline(cin, phrase);
		iss.str(phrase);
		iss >> command;
		param1 = param2 = param3 = param4 = param5 = param6 = param7 = "";

		//COMANDOS CARREGA, CRIA , LISTA , AVANÇA E HELP
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
					NewGame = cmdCarrega(NewGame, param1);
				}
			}
		}
		if (!command.compare("cria")) {
			iss >> param1;
			iss >> param2;
			if (!param1.compare("")) {
				needParam(2, command);
			}
			else if (!param2.compare("")) {
				needParam(1, command);
			}
			else {
				if (param1 != "territorioInicial") {
					int num = stoi(param2); //2
					for (int i = 0; i < num; i++) {
						NewGame.addTerritory(param1);
					}
				}
				else {
					cout << "\n>>> AVISO: nao podem ser criados <territorioInicial>" << endl;
				}
			}
		}
		if (!command.compare("lista")) {
			iss >> param1;
			if (!param1.compare("")) {
				cout << NewGame.listaTerritorios();
			}
			else {
				cout << cmdLista(NewGame, param1);
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
		
		cout << "\n>>>>>>>>>>>>>>> TURNO " << turnos + 1 << "<<<<<<<<<<<<<<<" << endl;
		//FASE 1 DO TURNO 
		do {
			istringstream iss;
			cout << "\n------FASE 1 ----" << endl;
			cout << "Conquistar ou Passar?" << endl;
			cout << "\nInsira um comando: ";
			por_conquistar = 0;
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
						if (NewGame.existTerritory(param1) == true) {
							NewGame = cmdConquista(NewGame, param1);
							//cout << "\n>>>> A recolher produtos e ouro!" << endl;
							//NewGame.recolheProdGold();
							por_conquistar = 1;

							//turnos++;
						}
						else {
							cout << "\n>>> AVISO: o territorio " << param1 << "nao existe logo nao pode ser conquistado." << endl;
						}
					}
				}
			}
			if (!command.compare("passa")) {
				cout << "\nAVISO: Nao acrescentou nada ao imperio nem perdeu forca militar!" << endl;
				por_conquistar = 1;
			}
			if (!command.compare("lista")) {
				iss >> param1;
				if (!param1.compare("")) {
					cout << NewGame.listaTerritorios();
				}
				else {
					cout << cmdLista(NewGame, param1);
				}
			}
			if (!command.compare("help")) {
				cout << endl;
				help("helpfase1.txt");
			}
			if (!command.compare("sair")) {
				/*endTurno = 1;
				endFase1 = 1;*/
				return;
			}

			if (NewGame.getSizeTerritorios() == 0) {
				cout << "\nAVISO: Nao ha territorios para conquistar mais!" << endl;
				endTurno = 1;

			}
		} while (por_conquistar != 1 && endFase1!=1);


		//FASE 2 DO TURNO
		do {
			cout << "\n------FASE 2 ----" << endl;
			cout << "\n>>>> A recolher produtos e ouro!" << endl;
			NewGame.recolheProdGold();
			recolha_prod = 1;
		} while (recolha_prod != 1);
		
		//FASE 3 DO TURNO
		do {
			istringstream iss3;
			cout << "\n------FASE 3 ----" << endl;
			cout << "Aumentar a forca militar ou Adquirir tecnologia ?" << endl;
			cout << "\nInsira um comando: ";
			compras = 0;
			phrase = command = param1 = param2 = "";
			getline(cin, phrase);
			iss3.str(phrase);
			iss3 >> command;
			if (!command.compare("maismilitar")) {
				NewGame = cmdAumenta(NewGame);
				compras = 1;
			}
			
			if (!command.compare("adquire")) {
				iss3 >> param1;
				if (!param1.compare("")) {
					needParam(1, command);
				}
				else {
					iss3 >> param2;
					if (param2.compare("")) {
						lessParam(1, command);
					}
					else {
						/*if (NewGame.existTerritory(param1) == true) {*/
						NewGame=cmdCompra(NewGame,param1);

							
						}
						
					}
				}


			if (!command.compare("lista")) {
				iss3 >> param1;
				if (!param1.compare("")) {
					cout << NewGame.listaTerritorios();
				}
				else {
					cout << cmdLista(NewGame, param1);
				}
			}
			if (!command.compare("help")) {
				cout << endl;
				help("helpfase3.txt");
			}
			if (!command.compare("sair")) {
				/*endTurno = 1;
				endFase3 = 1;*/
				return;
			}
		}while (compras != 1 && endFase3!=1);
		
		
		turnos++;
		
	} while (endTurno != 1 && turnos < 12 && NewGame.getSizeTerritorios() != 0);

	cout << "\n>>> SAINDO... " << endl;
}

// Abre o ficheiro help
void configure::help(string file) {
	ifstream fhelp(file);
	ostringstream oss;
	//String str;
	if (!fhelp) {
		oss << "ERRO: Nao conseguiu abrir o ficheiro" << endl;
		return;
	}

	if (!fhelp) {
		cout << "ERRO: Nao conseguiu abrir o ficheiro" << endl;
	}
	else {
		cout << fhelp.rdbuf() << endl;
	}
	fhelp.close();
}

//Recebe uma string e um numero e imprime o numero de parametros que falta
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

//Recebe uma string e um numero e imprime avisos sobre parametros a mais
void configure::lessParam(int num, string command) {
	if (num == 1) {
		cout << "ERRO: Foi inserido 1 parametro que nao e necessario no comando <" << command << ">." << endl;
	}
	else {
		cout << "ERRO: Foram inseridos " << num << " parametros nao necessarios no comando <" << command << ">." << endl;
	}
}

//Funcao que recebe comando carrega ficheiro
game configure::cmdCarrega(game NewGame, string ficheiro) {
	string str;
	ostringstream oss;
	ifstream fCarrega(ficheiro);
	int count = 0;

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

		if (name != "territorioInicial") {
			for (int i = 0; i < N; i++) {
				oss << NewGame.addTerritory(name);
			}
		}
		else {
			count++;
			count = count + N;
		}
	}
	if (count != 0) {
		cout << "\n>>> AVISO: nao podem ser criados <territorioInicial>" << endl;
		cout << "\t foi ignorada a criacao de " << count - 1 << " territorioInicial no ficheiro <" << ficheiro << ">." << endl;
	}

	return NewGame;
}

//Funcao que recebe comando conquista territorio
game configure::cmdConquista(game NewGame, string name) {
	if (name == "territorioInicial") {
		NewGame.conquistaTerritorios("territorioInicial");
	}
	else {
		cout << NewGame.conquistaTerritorios(name);
	}
	return NewGame;
}

//Funcao que recebe comando lista algo
string configure::cmdLista(game NewGame, string name) {
	ostringstream oss;
	oss << NewGame.listaTerritorios(name);
	return oss.str();
}

game configure::cmdAumenta(game NewGame) {
	NewGame.AumentaForca();
	return NewGame;
}
game configure::cmdCompra(game NewGame, string name) {
	NewGame.AdicionaTecnologias(name);
	return NewGame;
}