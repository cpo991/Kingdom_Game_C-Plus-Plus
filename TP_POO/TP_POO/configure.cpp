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
	commands(); // chama a função que recebe/le comandos
}

//Recebe uma string e separa para ver se é um comando
//Se for, chama a respetiva função
//Termina esta função quando endConfig=1 ou então certas condições do jogo atingidas
void configure::commands() {
	int endConfig = 0, turnos=0 , endTurno = 0, recolha_prod = 0;
	int endFase3 = 0, endFase1 = 0, endFase2 = 0;
	string teste;
	game NewGame;

	//Adiciona o territorio inicial ao império
	NewGame.addTerritory("territorioInicial");
	NewGame = cmdConquista(NewGame, "territorioInicial");

	// ::::::::::::::::FASE DE CONFIGURACAO :::::::::::::::::::::::

	help("helpconfig.txt");
	//Ciclo de comandos antes do jogo começar --> obrigatório ter territórios
	do {
		istringstream iss;
		cout << "\nInsira um comando:  ";
		getline(cin, phrase);
		iss.str(phrase);
		iss >> command;
		param1 = param2 = "";

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
					const size_t nVetor = NewGame.getSizeTerritorios();
					NewGame = cmdCarrega(NewGame, param1);
					size_t newNVetor = NewGame.getSizeTerritorios();
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
		param1 = param2 = "";

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

	// ::::::::::::::::::::::: JOGAR :::::::::::::::::::::::::::::::

	help("helpfase1.txt");

	//Ciclo de comandos depois do jogo começar
	int ano = 1;
	do {
		do {
			int compras = 0, compra_tecnologia = 0;
			cout << "\n>>>>>>>>>>>>>>> ANO " << ano << "<<<<<<<<<<<<<<<" << endl;
			cout << ">>>>>>>>>>>>>>> TURNO " << turnos + 1 << "<<<<<<<<<<<<<<<" << endl;
			//FASE 1 DO TURNO
			do {
				istringstream iss;
				cout << "\n------FASE 1 ----" << endl;
				cout << "Conquistar ou Passar?" << endl;
				cout << "\nInsira um comando: ";
				endFase1 = 0;
				getline(cin, phrase);
				iss.str(phrase);
				iss >> command;
				param1 = param2 = "";

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
								endFase1 = 1;
							}
							else {
								cout << "\n>>> AVISO: o territorio " << param1 << "nao existe logo nao pode ser conquistado." << endl;
							}
						}
					}
				}
				if (!command.compare("passa")) {
					cout << "\nAVISO: Nao acrescentou nada ao imperio nem perdeu forca militar!" << endl;
					endFase1 = 1;
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
					sair();
				}

				if (NewGame.getSizeTerritorios() == 0) {
					cout << "\nAVISO: Nao ha territorios para conquistar mais!" << endl;
					endTurno = 1;
				}
			} while (endFase1 != 1);

			//FASE 2 DO TURNO
			do {
				istringstream iss2;

				cout << "\n------FASE 2 ----" << endl;
				cout << "\n>>>> A recolher produtos e ouro!" << endl;
				NewGame.recolheProdGold();

				if (NewGame.existeTecnologia("bolsa") == true) {
					cout << "\n>>> AVISO: E POSSIVEL FAZER TROCAS DE PRODUTOS/OURO " << endl;
					cout << "\nPretende avancar ou fazer trocas?" << endl;
					cout << "\nInsira um comando: ";
					endFase2 = 0;
					getline(cin, phrase);
					iss2.str(phrase);
					iss2 >> command;
					param1 = param2 = "";

					if (!command.compare("maisouro")) {
						if (NewGame.maisOuro() == true)
							cout << "Trocou uma unidade de ouro por duas de produtos!" << endl;
						else
							cout << "Nao tem produtos suficientes para trocar!" << endl;
						endFase2 = 1;
						recolha_prod = 1;
					}
					if (!command.compare("maisprod")) {
						if (NewGame.maisProd() == true)
							cout << "Trocou duas unidades de ouro por uma de produtos!" << endl;
						else
							cout << "Nao tem ouro suficiente para trocar!" << endl;
						endFase2 = 1;
						recolha_prod = 1;
					}
					if (!command.compare("avanca")) {
						cout << "\n>>> AVISO: AVANCARA PARA A PROXIMA FASE\n\n" << endl;
						endFase2 = 1;
						recolha_prod = 1;
					}
				}
				recolha_prod = 1;
			} while (recolha_prod != 1 && endFase2 != 1);

			//FASE 3 DO TURNO
			compras = 0;
			do {
				istringstream iss3;
				cout << "\n------FASE 3 ----" << endl;
				cout << "Aumentar a forca militar ou Adquirir tecnologia ?" << endl;
				cout << "\nInsira um comando: ";
				phrase = command = param1 = param2 = "";
				getline(cin, phrase);
				iss3.str(phrase);
				iss3 >> command;
				if (!command.compare("maismilitar")) {
					//tb podia ter ficado sem chamar funcao mas nao me apeteceu mudar agora xd
					NewGame = cmdAumenta(NewGame);
					compras++;
					cout << "COMPRAS FEITAS = " << compras << endl;
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
							/*if (NewGame.existeTecnologia(param1) == true) {*/
							if (compra_tecnologia < 1) {
								NewGame = cmdCompra(NewGame, param1);
								compra_tecnologia++;
							}
							compras++;
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
				if (!command.compare("grava")) { // teste falta outro parametro
					iss3 >> param1;
					if (!param1.compare("")) {
						NewGame.saveData("data.txt");
					}
					else {
						cout << cmdLista(NewGame, param1);
					}
				}
				if (!command.compare("help")) {
					cout << endl;
					help("helpfase3.txt");
				}
				if (!command.compare("avanca")) {
					cout << "\n>>> AVISO: AVANCARA PARA O PROXIMO TURNO\n\n" << endl;
					compras = 2;
					endFase3 = 1;
				}
				if (!command.compare("sair")) {
					sair();
				}
				if (compras == 2)
					endFase3 = 1;
			} while (compras != 2 && endFase3 != 1);

			//FASE 4 DO TURNO 
			int evento = 0;
			do {
				cout << "\n------FASE 4 ----" << endl;
				int forcaInv = 0, randSorte = 0, resNome = 0, ataque = 0;
				int randEvent = rand() % (1 - 4 + 1) + 1;
				string nome;
				cout << randEvent << endl;
				evento = 1;
				//randEvent = 2; // <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< FOR TESTING SPECIFICS EVENTS
				switch (randEvent)
				{
				case 1: // Recurso abandonado
					cout << "\n >>> AVISO: Um recurso abandonado foi encontrado." << endl;
					if (ano == 1) {
						NewGame.maisProdFase4();
						cout << "              + 1 unidade de produtos" << endl;
					}
					if (ano == 2) {
						NewGame.maisOuroFase4();
						cout << "              + 1 unidade de ouro" << endl;
					}
					break;
				case 2: // Invasão
					randSorte = rand() % (1 - 6 + 1) + 1;
					nome = NewGame.getLastTerritorioConquistado();
					resNome = NewGame.getResLastTerritorioConquistado();
					cout << "\n >>> AVISO: Invasao ao territorio "<< nome << "." << endl;
					if (ano == 1) {
						forcaInv = 2;
						ataque = forcaInv + randSorte;
						if (NewGame.existeTecnologia("defesas") == true) {
							NewGame.incrementaRes(nome); // incrementa resistencia do ultimo territorio
						}
						if (nome == "territorioInicial") { // nao tem mais territorios logo perde o jogo
							cout << "\n >>> AVISO: Perdeu o jogo." << endl; 
							sair();
						}
						if (ataque >= resNome) {
							NewGame.removeTerritoryImperio(nome); //remove territorio que sofreu invasão
						}
						if (ataque < resNome){
							cout << "\n >>> AVISO: Invasao ao territorio " << nome << " falhou." << endl; // territorio ganha invasao
						}
					}
					if (ano == 2) {
						forcaInv = 3;
					}
					evento = 1;
					break;
				case 3: // Aliança diplomática
					cout << "\n >>> AVISO: Foi assinada uma alianca com um outro imperio do qual tambem não existe nenhum registo." << endl;
					cout << "              + 1 unidade de forca militar" << endl;
					NewGame.AumentaForcaFase4();
					evento = 1;
					break;
				case 4: // Sem evento
					cout << "\n >>> AVISO: Nada ocorreu, todos podem dormir descansados" << endl;
					evento = 1;
					break;
				}
			} while (evento != 1);
			turnos++;
		} while (endTurno != 1 && turnos < 12 && NewGame.getSizeTerritorios() != 0);
		ano++;
	} while (ano != 2);
	
}

// Abre o ficheiro help
void configure::help(string file) {
	ifstream fhelp(file);
	ostringstream oss;
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
		cout << "foi ignorada a criacao de " << count - 1 << " territorioInicial no ficheiro <" << ficheiro << ">." << endl;
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

//Funcao que recebe comando maismilitar
game configure::cmdAumenta(game NewGame) {
	if (NewGame.AumentaForca() == true)
		return NewGame;
	return NewGame;
}

//Funcao que recebe comando compra tecnologia
game configure::cmdCompra(game NewGame, string name) {
	NewGame.AdicionaTecnologias(name);
	return NewGame;
}

//Funcoes para os eventos
game configure::recursoAbandonado(game NewGame,int turnos) {
	NewGame.recursoAbandonado(turnos);
	return NewGame;
}
game configure::alianca(game NewGame) {
	NewGame.alianca();
	return NewGame;
}

//Comando para sair e chamar destrutores acabar
int configure::sair() {
	cout << "\n>>> SAINDO DO KINGDOM... " << endl;

	exit(EXIT_SUCCESS); //inacabado
	//chamar destrutores etc
}