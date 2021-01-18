//
//  Created by Carolina Oliveira & Isabel Castro on 14/11/2020
//
#include "configure.h"

//configure::configure(game& g) {
//	newGame = &g;
//}


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
	int endConfig = 0, turnos = 0, endTurno = 0, recolha_prod = 0;
	int endFase3 = 0, endFase1 = 0, endFase2 = 0, ano = 1;
	int evento = 0;
	int randEvent = 0;
	string teste;
	//game newGame;
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
					const size_t nVetor = newGame.getSizeTerritorios();
					
					cmdCarrega(param1);
					const size_t nVetor1 = newGame.getSizeTerritorios();

					size_t newNVetor = newGame.getSizeTerritorios();
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
					size_t nVetor =  newGame.getSizeTerritorios();
					for (int i = 0; i < num; i++) {
						newGame.addTerritory(param1); //cria x territorios de nome y
					}
					size_t newNVetor = newGame.getSizeTerritorios();
					if (nVetor == newNVetor)
						cout << "ERRO: O tipo de territorio <" << param1 << "> nao e permitido." << endl;
				}
				else {
					cout << "\n>>> AVISO: nao podem ser criados <territorioInicial>" << endl;
				}
			}
		}
		if (!command.compare("lista")) {
			iss >> param1;
			if (!param1.compare("")) { // lista --> imprime descrição geral do jogo
				cout << newGame.listaTerritorios(ano, turnos,0);
			}
			else {
				cout << cmdLista(param1); // lista x --> imprime descrição de um territorio
			}
		}
		if (!command.compare("avanca")) {
			cout << "\n>>> AVISO: FASE DE CONFIGURACOES NAO PODE TERMINAR SEM TERRITORIOS CRIADOS." << endl;
		}
		if (!command.compare("help")) {
			cout << endl;
			help("helpconfig.txt");
		}
		if (!command.compare("sair")) {
			sair();
		}
	} while (newGame.getSizeTerritorios() == 0);

	//Ciclo de comandos antes do jogo começar enquanto carrega mais que um territorio
	do {
		istringstream iss;
		cout << "\nInsira um comando:  ";
		phrase = command = param1 = param2 = "";
		getline(cin, phrase);
		iss.str(phrase);
		iss >> command;

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
					 cmdCarrega(param1);
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
						newGame.addTerritory(param1);
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
				cout << newGame.listaTerritorios(ano, turnos,randEvent);
			}
			else {
				cout << cmdLista( param1);
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
		if (!command.compare("sair")) {
			sair();
		}
	} while (endConfig != 1);

	// ::::::::::::::::::::::: JOGAR :::::::::::::::::::::::::::::::

	help("helpfase1.txt");

	//Ciclo de comandos depois do jogo começar

	do {
		turnos = 0;
		do {
			newGame.altera(ano, turnos);
			randEvent = newGame.sorteiaEvento();
			cout << "\n>>>>>>>>>>>>>>> ANO " << ano << "<<<<<<<<<<<<<<<" << endl;
			cout << ">>>>>>>>>>>>>>>  TURNO " << turnos + 1 << "<<<<<<<<<<<<<<<" << endl;
			//FASE 1 DO TURNO
			int comandoCP = 0;
			do {
				phrase = command = param1 = param2 = "";
				istringstream iss;
				cout << "\n------FASE 1 ----" << endl;
				cout << "Conquistar ou Passar?" << endl;
				cout << "\nInsira um comando: ";
				endFase1 = 0;
				getline(cin, phrase);
				iss.str(phrase);
				iss >> command;

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
							if (comandoCP == 1) {
								cout << "\nAVISO: O comando passa ou conquista ja foi introduzido neste turno." << endl;
							}
							else {
								if (newGame.existeTecnologia("misseis") == true && newGame.territoriosConquistados()>5) {
									cmdConquista(param1);
									comandoCP = 1;
								}
								if (newGame.existTerritory(param1) == true) {
									cmdConquista(param1);
									comandoCP = 1;
								}
								else {
									cout << "\n>>> AVISO: o territorio " << param1 << "nao existe logo nao pode ser conquistado." << endl;
								}
							}
						}
					}
				}
				if (!command.compare("passa")) {
					if (comandoCP == 1) {
						cout << "\nAVISO: O comando passa ou conquista ja foi introduzido neste turno." << endl;
					}
					else {
						cout << "\nAVISO: Nao acrescentou nada ao imperio nem perdeu forca militar!" << endl;
						comandoCP = 1;
					}
				}
				if (!command.compare("lista")) {
					iss >> param1;
					if (!param1.compare("")) {
						cout << newGame.listaTerritorios(ano, turnos,randEvent);
					}
					else {
						cout << cmdLista( param1);
					}
				}
				if (!command.compare("sair")) {
					sair();
				}
				if (!command.compare("help")) {
					cout << endl;
					help("helpfase1.txt");
				}
				if (!command.compare("avanca")) {
					if (comandoCP == 0) {
						cout << "\nAVISO: O comando passa ou conquista ainda nao foi introduzido neste turno." << endl;
					}
					else {
						cout << "\n>>> AVISO: A AVANCAR PARA FASE 2...\n\n" << endl;
						endFase1 = 1;
					}
				}
				if (!command.compare("grava")) {
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
							if (existNomeSave(param1) == false) {
								addSave(param1, newGame, ano, turnos);
								cout << ">>> AVISO: O jogo foi gravado com sucesso com o nome <" << param1 << ">." << endl;
								cout << getAsStringSave() << endl;
							}
							else { //nao pode criar
								cout << ">>> AVISO: O nome <" << param1 << "> que tentou atribuir ao save ja existe." << endl;
							}
						}
					}
				}
				if (!command.compare("apaga")) {
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
							if (existNomeSave(param1) == true) {
								removeSave(param1);
								cout << ">>> AVISO: O save <" << param1 << "> foi apagado com sucesso." << endl;
								cout << getAsStringSave() << endl;
							}
							else { //nao existe pra apagar
								cout << ">>> AVISO: O nome <" << param1 << "> que tentou apagar nao existe." << endl;
								cout << getAsStringSave() << endl;
							}
						}
					}
				}
				if (!command.compare("ativa")) {
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
							if (existNomeSave(param1) == true) {
								//ativa
								ativaSave(param1);
								ano = ativaAno(param1);
								turnos = ativaTurno(param1);
								cout << ">>> AVISO: O save <" << param1 << "> foi carregado com sucesso." << endl;
								cout << "\n\n\n>>> AVISO: A RETOMAR JOGO COM OS DADOS GUARDADOS" << endl;
							}
							else { //nao existe pra ativar
								cout << ">>> AVISO: O nome <" << param1 << "> que tentou carregar nao existe." << endl;
								cout << getAsStringSave() << endl;
							}
						}
					}
				}
				//>>>>>>> DEBUG COMMANDS - START <<<<<<
				if (!command.compare("toma")) {
					iss >> param1;
					if (!param1.compare("")) {
						needParam(2, command);
					}
					else {
						iss >> param2;
						if (!param2.compare("")) {
							needParam(1, command);
						}
						else {
							if ((param1 == "terr") || (param1 == "tec")) {
								bool exist = false;
								if (param1 == "terr") {
									exist = newGame.existTerritory(param2);
									if (exist)
										cmdDebug(command, param1, param2, ano, turnos);
									else
										cout << "\n >>> AVISO: O territorio <" << param2 << "> a assaltar nao existe." << endl;
								}
								if (param1 == "tec") {
									exist = newGame.existeTecnologia(param2);
									if (!exist)
										cmdDebug( command, param1, param2, ano, turnos);
									else
										cout << "\n >>> AVISO: A tecnologia <" << param2 << "> a assaltar nao existe." << endl;
								}
							}
							else
								cout << "\n >>> AVISO: O tipo de parametro <" << param1 << "> a assaltar nao existe." << endl;
						}
					}
				}
				if (!command.compare("modifica")) {
					iss >> param1;
					if (!param1.compare("")) {
						needParam(2, command);
					}
					else {
						iss >> param2;
						if (!param2.compare("")) {
							needParam(1, command);
						}
						else {
							if ((param1 == "ouro") || (param1 == "prod")) {
								int NDigit = 0;
								for (int i = 0; i < param2.length(); i++) {
									if (!isdigit(param2[i]))
										NDigit++;
								}
								if (NDigit == 0)
									 cmdDebug(command, param1, param2, ano, turnos);
								else
									cout << "\n >>> AVISO: Nao introduziu um inteiro como quantidade a modificar." << endl;
							}
							else
								cout << "\n >>> AVISO: O tipo de dado <" << param1 << "> a modificar nao existe." << endl;
						}
					}
				}
				if (!command.compare("fevento")) {
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
							if ((param1 == "recurso-abandonado") || (param1 == "invasao")
								|| (param1 == "alianca-diplomatica") || (param1 == "sem-evento"))
								 cmdDebug(command, param1, param2, ano, turnos);
							else
								cout << "\n >>> AVISO: O evento <" << param1 << "> nao existe." << endl;
						}
					}
				}
				//>>>>>>>> DEBUG COMMANDS - END <<<<<<

				if (newGame.getSizeTerritorios() == 0) {
					cout << "\nAVISO: Nao ha territorios para conquistar mais!" << endl;
					endTurno = 1;
					fimJogo();
				}
			} while (endFase1 != 1);

	//FASE 2 DO TURNO
			do {
				cout << "\n------FASE 2 ----" << endl;
				cout << "\n>>>> A recolher produtos e ouro!" << endl;
				newGame.recolheProdGold();
				endFase2 = 0;
				if (newGame.existeTecnologia("bolsa") == true) {
					endFase2 = 0;
					do {
						istringstream iss2;
						phrase = command = param1 = param2 = "";
						cout << "\n>>> AVISO: E POSSIVEL FAZER TROCAS DE PRODUTOS/OURO " << endl;
						cout << "\nPretende avancar ou fazer trocas?" << endl;
						cout << "\nInsira um comando: ";
						getline(cin, phrase);
						iss2.str(phrase);
						iss2 >> command;

						if (!command.compare("maisouro")) {
							iss2 >> param1;
							if (param1.compare("")) {
								lessParam(1, command);
							}
							else {
								if (newGame.maisOuro() == true)
									cout << "Trocou uma unidade de ouro por duas de produtos!" << endl;
								else
									cout << "Nao tem produtos suficientes para trocar!" << endl;
								endFase2 = 1;
								recolha_prod = 1;
							}
						}
						if (!command.compare("maisprod")) {
							iss2 >> param1;
							if (param1.compare("")) {
								lessParam(1, command);
							}
							else {
								if (newGame.maisProd() == true)
									cout << "Trocou duas unidades de ouro por uma de produtos!" << endl;
								else
									cout << "Nao tem ouro suficiente para trocar!" << endl;
								endFase2 = 1;
								recolha_prod = 1;
							}
						}
						if (!command.compare("avanca")) {
							iss2 >> param1;
							if (param1.compare("")) {
								lessParam(1, command);
							}
							else {
								cout << "\n>>> AVISO: A AVANCAR PARA A FASE 3...\n\n" << endl;
								endFase2 = 1;
								recolha_prod = 1;
							}
						}
						if (!command.compare("help")) {
							iss2 >> param1;
							if (param1.compare("")) {
								lessParam(1, command);
							}
							else {
								cout << endl;
								help("helpfase2.txt");
							}
						}
						if (!command.compare("lista")) {
							iss2 >> param1;
							if (!param1.compare("")) {
								cout << newGame.listaTerritorios(ano, turnos,randEvent);
							}
							else {
								cout << cmdLista(param1);
							}
						}
						if (!command.compare("grava")) {
							iss2 >> param1;
							if (!param1.compare("")) {
								needParam(1, command);
							}
							else {
								iss2 >> param2;
								if (param2.compare("")) {
									lessParam(1, command);
								}
								else {
									if (existNomeSave(param1) == false) {
										addSave(param1, newGame, ano, turnos);
										cout << ">>> AVISO: O jogo foi gravado com sucesso com o nome <" << param1 << ">." << endl;
										cout << getAsStringSave() << endl;
									}
									else { //nao pode criar
										cout << ">>> AVISO: O nome <" << param1 << "> que tentou atribuir ao save ja existe." << endl;
									}
								}
							}
						}
						if (!command.compare("apaga")) {
							iss2 >> param1;
							if (!param1.compare("")) {
								needParam(1, command);
							}
							else {
								iss2 >> param2;
								if (param2.compare("")) {
									lessParam(1, command);
								}
								else {
									if (existNomeSave(param1) == true) {
										removeSave(param1);
										cout << ">>> AVISO: O save <" << param1 << "> foi apagado com sucesso." << endl;
										cout << getAsStringSave() << endl;
									}
									else { //nao existe pra apagar
										cout << ">>> AVISO: O nome <" << param1 << "> que tentou apagar nao existe." << endl;
										cout << getAsStringSave() << endl;
									}
								}
							}
						}
						if (!command.compare("ativa")) {
							iss2 >> param1;
							if (!param1.compare("")) {
								needParam(1, command);
							}
							else {
								iss2 >> param2;
								if (param2.compare("")) {
									lessParam(1, command);
								}
								else {
									if (existNomeSave(param1) == true) {
										//ativa
										 ativaSave(param1);
										ano = ativaAno(param1);
										turnos = ativaTurno(param1);
										cout << ">>> AVISO: O save <" << param1 << "> foi carregado com sucesso." << endl;
										cout << "\n\n\n>>> AVISO: A RETOMAR JOGO COM OS DADOS GUARDADOS" << endl;
									}
									else { //nao existe pra ativar
										cout << ">>> AVISO: O nome <" << param1 << "> que tentou carregar nao existe." << endl;
										cout << getAsStringSave() << endl;
									}
								}
							}
						}
						//>>>>>>> DEBUG COMMANDS - START <<<<<<
						if (!command.compare("toma")) {
							iss2 >> param1;
							if (!param1.compare("")) {
								needParam(2, command);
							}
							else {
								iss2 >> param2;
								if (!param2.compare("")) {
									needParam(1, command);
								}
								else {
									if ((param1 == "terr") || (param1 == "tec")) {
										bool exist = false;
										if (param1 == "terr") {
											exist = newGame.existTerritory(param2);
											if (exist)
												cmdDebug( command, param1, param2, ano, turnos);
											else
												cout << "\n >>> AVISO: O territorio <" << param2 << "> a assaltar nao existe ou ja faz parte do imperio." << endl;
										}
										if (param1 == "tec") {
											exist = newGame.existeTecnologia(param2);
											if (!exist) // se não tiver tecnologia ganha-a
												cmdDebug(command, param1, param2, ano, turnos);
											else
												cout << "\n >>> AVISO: A tecnologia <" << param2 << "> a assaltar nao existe." << endl;
										}
									}
									else
										cout << "\n >>> AVISO: O tipo de parametro <" << param1 << "> a assaltar nao existe." << endl;
								}
							}
						}
						if (!command.compare("modifica")) {
							iss2 >> param1;
							if (!param1.compare("")) {
								needParam(2, command);
							}
							else {
								iss2 >> param2;
								if (!param2.compare("")) {
									needParam(1, command);
								}
								else {
									if ((param1 == "ouro") || (param1 == "prod")) {
										int NDigit = 0;
										for (int i = 0; i < param2.length(); i++) {
											if (!isdigit(param2[i]))
												NDigit++;
										}
										if (NDigit == 0)
											cmdDebug(command, param1, param2, ano, turnos);
										else
											cout << "\n >>> AVISO: Nao introduziu um inteiro como quantidade a modificar." << endl;
									}
									else
										cout << "\n >>> AVISO: O tipo de dado <" << param1 << "> a modificar nao existe." << endl;
								}
							}
						}
						if (!command.compare("fevento")) {
							iss2 >> param1;
							if (!param1.compare("")) {
								needParam(1, command);
							}
							else {
								iss2 >> param2;
								if (param2.compare("")) {
									lessParam(1, command);
								}
								else {
									if ((param1 == "recurso-abandonado") || (param1 == "invasao")
										|| (param1 == "alianca-diplomatica") || (param1 == "sem-evento"))
										cmdDebug(command, param1, param2, ano, turnos);
									else
										cout << "\n >>> AVISO: O evento <" << param1 << "> nao existe." << endl;
								}
							}
						}
						//>>>>>>>> DEBUG COMMANDS - END <<<<<<
					} while (endFase2 != 1);
				}
				do {
					istringstream iss2b;
					phrase = command = param1 = param2 = "";
					cout << "\nInsira um comando: ";
					getline(cin, phrase);
					iss2b.str(phrase);
					iss2b >> command;
					if (!command.compare("avanca")) {
						iss2b >> param1;
						if (param1.compare("")) {
							lessParam(1, command);
						}
						else {
							cout << "\n>>> AVISO: A AVANCAR PARA A FASE 3...\n\n" << endl;
							endFase2 = 1;
							recolha_prod = 1;
						}
					}
					if (!command.compare("help")) {
						iss2b >> param1;
						if (param1.compare("")) {
							lessParam(1, command);
						}
						else {
							cout << endl;
							help("helpfase2.txt");
						}
					}
					if (!command.compare("lista")) {
						iss2b >> param1;
						if (!param1.compare("")) {
							cout << newGame.listaTerritorios(ano, turnos,randEvent);
						}
						else {
							cout << cmdLista(param1);
						}
					}
					if (!command.compare("grava")) {
						iss2b >> param1;
						if (!param1.compare("")) {
							needParam(1, command);
						}
						else {
							iss2b >> param2;
							if (param2.compare("")) {
								lessParam(1, command);
							}
							else {
								if (existNomeSave(param1) == false) {
									addSave(param1, newGame, ano, turnos);
									cout << ">>> AVISO: O jogo foi gravado com sucesso com o nome <" << param1 << ">." << endl;
									cout << getAsStringSave() << endl;
								}
								else { //nao pode criar
									cout << ">>> AVISO: O nome <" << param1 << "> que tentou atribuir ao save ja existe." << endl;
								}
							}
						}
					}
					if (!command.compare("apaga")) {
						iss2b >> param1;
						if (!param1.compare("")) {
							needParam(1, command);
						}
						else {
							iss2b >> param2;
							if (param2.compare("")) {
								lessParam(1, command);
							}
							else {
								if (existNomeSave(param1) == true) {
									removeSave(param1);
									cout << ">>> AVISO: O save <" << param1 << "> foi apagado com sucesso." << endl;
									cout << getAsStringSave() << endl;
								}
								else { //nao existe pra apagar
									cout << ">>> AVISO: O nome <" << param1 << "> que tentou apagar nao existe." << endl;
									cout << getAsStringSave() << endl;
								}
							}
						}
					}
					if (!command.compare("ativa")) {
						iss2b >> param1;
						if (!param1.compare("")) {
							needParam(1, command);
						}
						else {
							iss2b >> param2;
							if (param2.compare("")) {
								lessParam(1, command);
							}
							else {
								if (existNomeSave(param1) == true) {
									//ativa
									ativaSave(param1);
									ano = ativaAno(param1);
									turnos = ativaTurno(param1);
									cout << ">>> AVISO: O save <" << param1 << "> foi carregado com sucesso." << endl;
									cout << "\n\n\n>>> AVISO: A RETOMAR JOGO COM OS DADOS GUARDADOS" << endl;
								}
								else { //nao existe pra ativar
									cout << ">>> AVISO: O nome <" << param1 << "> que tentou carregar nao existe." << endl;
									cout << getAsStringSave() << endl;
								}
							}
						}
					}
					//>>>>>>> DEBUG COMMANDS - START <<<<<<
					if (!command.compare("toma")) {
						iss2b >> param1;
						if (!param1.compare("")) {
							needParam(2, command);
						}
						else {
							iss2b >> param2;
							if (!param2.compare("")) {
								needParam(1, command);
							}
							else {
								if ((param1 == "terr") || (param1 == "tec")) {
									bool exist = false;
									if (param1 == "terr") {
										exist = newGame.existTerritory(param2);
										if (exist)
											cmdDebug(command, param1, param2, ano, turnos);
										else
											cout << "\n >>> AVISO: O territorio <" << param2 << "> a assaltar nao existe ou ja faz parte do imperio." << endl;
									}
									if (param1 == "tec") {
										exist = newGame.existeTecnologia(param2);
										if (!exist) // se não tiver tecnologia ganha-a
											cmdDebug(command, param1, param2, ano, turnos);
										else
											cout << "\n >>> AVISO: A tecnologia <" << param2 << "> a assaltar nao existe." << endl;
									}
								}
								else
									cout << "\n >>> AVISO: O tipo de parametro <" << param1 << "> a assaltar nao existe." << endl;
							}
						}
					}
					if (!command.compare("modifica")) {
						iss2b >> param1;
						if (!param1.compare("")) {
							needParam(2, command);
						}
						else {
							iss2b >> param2;
							if (!param2.compare("")) {
								needParam(1, command);
							}
							else {
								if ((param1 == "ouro") || (param1 == "prod")) {
									int NDigit = 0;
									for (int i = 0; i < param2.length(); i++) {
										if (!isdigit(param2[i]))
											NDigit++;
									}
									if (NDigit == 0)
										cmdDebug(command, param1, param2, ano, turnos);
									else
										cout << "\n >>> AVISO: Nao introduziu um inteiro como quantidade a modificar." << endl;
								}
								else
									cout << "\n >>> AVISO: O tipo de dado <" << param1 << "> a modificar nao existe." << endl;
							}
						}
					}
					if (!command.compare("fevento")) {
						iss2b >> param1;
						if (!param1.compare("")) {
							needParam(1, command);
						}
						else {
							iss2b >> param2;
							if (param2.compare("")) {
								lessParam(1, command);
							}
							else {
								if ((param1 == "recurso-abandonado") || (param1 == "invasao")
									|| (param1 == "alianca-diplomatica") || (param1 == "sem-evento"))
									cmdDebug(command, param1, param2, ano, turnos);
								else
									cout << "\n >>> AVISO: O evento <" << param1 << "> nao existe." << endl;
							}
						}
					}
					//>>>>>>>> DEBUG COMMANDS - END <<<<<<
				} while (endFase2 != 1);
				recolha_prod = 1;
			} while (recolha_prod != 1 && endFase2 != 1);

			//FASE 3 DO TURNO
			int compras = 0, compra_tecnologia = 0, compra_militar = 0;
			endFase3 = 0;
			do {
				istringstream iss3;
				phrase = command = param1 = param2 = "";
				cout << "\n------FASE 3 ----" << endl;
				cout << "Aumentar a forca militar ou Adquirir tecnologia ?" << endl;
				cout << "\nInsira um comando: ";
				getline(cin, phrase);
				iss3.str(phrase);
				iss3 >> command;
				if (!command.compare("maismilitar")) {
					iss3 >> param1;
					if (param1.compare("")) {
						lessParam(1, command);
					}
					else {
						if (compra_militar < 1) {
							newGame.AumentaForca();
							compras++;
							compra_militar++;
							cout << "\tCOMPRAS FEITAS = " << compras << endl;
						}
						else
							cout << "\n>>> AVISO: Ja nao pode comprar mais militar." << endl;
					}
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
							if ((param1 == "drones") || (param1 == "misseis") || (param1 == "defesas") ||
								(param1 == "bolsa") || (param1 == "banco")) {
								if (compra_tecnologia < 1) {
									int result = 0;
									result = newGame.getCompraTecnologia(param1);
									if (result == 1) {
										cout << "\n>>> AVISO: A tecnologia <" << param1 << "> foi adquirida com sucesso." << endl;
										compra_tecnologia++;
										compras++;
										cout << "\tCOMPRAS FEITAS = " << compras << endl;
									}
									else if (result == 0)
										cout << "\n>>> AVISO: Erro na compra da tecnologia <" << param1 << ">" << endl;
									else {
										cout << "\n>>> AVISO: A tecnologia <" << param1 << "> nao foi adquirida com sucesso." << endl;
										cout << ">>> AVISO: Falta <" << result << "> de ouro no cofre para a adquirir." << endl;
									}
								}
								else
									cout << "\n>>> AVISO: Ja nao pode adquirir mais tecnologias." << endl;
							}
							else
								cout << "\n>>> AVISO: A tecnologia <" << param1 << "> nao existe." << endl;
						}
					}
				}
				if (!command.compare("grava")) {
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
							if (existNomeSave(param1) == false) {
								addSave(param1, newGame, ano, turnos);
								cout << ">>> AVISO: O jogo foi gravado com sucesso com o nome <" << param1 << ">." << endl;
								cout << getAsStringSave() << endl;
							}
							else { //nao pode criar
								cout << ">>> AVISO: O nome <" << param1 << "> que tentou atribuir ao save ja existe." << endl;
							}
						}
					}
				}
				if (!command.compare("apaga")) {
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
							if (existNomeSave(param1) == true) {
								removeSave(param1);
								cout << ">>> AVISO: O save <" << param1 << "> foi apagado com sucesso." << endl;
								cout << getAsStringSave() << endl;
							}
							else { //nao existe pra apagar
								cout << ">>> AVISO: O nome <" << param1 << "> que tentou apagar nao existe." << endl;
								cout << getAsStringSave() << endl;
							}
						}
					}
				}
				if (!command.compare("ativa")) {
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
							if (existNomeSave(param1) == true) {
								//ativa
								 ativaSave(param1);
								ano = ativaAno(param1);
								turnos = ativaTurno(param1);
								cout << ">>> AVISO: O save <" << param1 << "> foi carregado com sucesso." << endl;
								cout << "\n\n\n>>> AVISO: A RETOMAR JOGO COM OS DADOS GUARDADOS" << endl;
							}
							else { //nao existe pra ativar
								cout << ">>> AVISO: O nome <" << param1 << "> que tentou carregar nao existe." << endl;
								cout << getAsStringSave() << endl;
							}
						}
					}
				}
				if (!command.compare("lista")) {
					iss3 >> param1;
					if (!param1.compare("")) {
						cout << newGame.listaTerritorios(ano, turnos,randEvent);
					}
					else {
						cout << cmdLista(param1);
					}
				}
				if (!command.compare("grava")) { // teste falta outro parametro
					iss3 >> param1;
					if (!param1.compare("")) {
						newGame.saveData("data.txt");
					}
					else {
						cout << cmdLista( param1);
					}
				}
				if (!command.compare("help")) {
					cout << endl;
					help("helpfase3.txt");
				}
				if (!command.compare("avanca")) {
					cout << "\n>>> AVISO: A AVANCAR PARA FASE 4...\n\n" << endl;
					compras = 2;
					endFase3 = 1;
				}
				if (!command.compare("sair")) {
					sair();
				}
				//>>>>>>> DEBUG COMMANDS - START <<<<<<
				if (!command.compare("toma")) {
					iss3 >> param1;
					if (!param1.compare("")) {
						needParam(2, command);
					}
					else {
						iss3 >> param2;
						if (!param2.compare("")) {
							needParam(1, command);
						}
						else {
							if ((param1 == "terr") || (param1 == "tec")) {
								bool exist = false;
								if (param1 == "terr") {
									exist = newGame.existTerritory(param2);
									if (exist)
										cmdDebug(command, param1, param2, ano, turnos);
									else
										cout << "\n >>> AVISO: O territorio <" << param2 << "> a assaltar nao existe ou ja faz parte do imperio." << endl;
								}
								if (param1 == "tec") {
									exist = newGame.existeTecnologia(param2);
									if (!exist) // se não tiver tecnologia ganha-a
										cmdDebug(command, param1, param2, ano, turnos);
									else
										cout << "\n >>> AVISO: A tecnologia <" << param2 << "> a assaltar nao existe." << endl;
								}
							}
							else
								cout << "\n >>> AVISO: O tipo de parametro <" << param1 << "> a assaltar nao existe." << endl;
						}
					}
				}
				if (!command.compare("modifica")) {
					iss3 >> param1;
					if (!param1.compare("")) {
						needParam(2, command);
					}
					else {
						iss3 >> param2;
						if (!param2.compare("")) {
							needParam(1, command);
						}
						else {
							if ((param1 == "ouro") || (param1 == "prod")) {
								int NDigit = 0;
								for (int i = 0; i < param2.length(); i++) {
									if (!isdigit(param2[i]))
										NDigit++;
								}
								if (NDigit == 0)
									cmdDebug(command, param1, param2, ano, turnos);
								else
									cout << "\n >>> AVISO: Nao introduziu um inteiro como quantidade a modificar." << endl;
							}
							else
								cout << "\n >>> AVISO: O tipo de dado <" << param1 << "> a modificar nao existe." << endl;
						}
					}
				}
				if (!command.compare("fevento")) {
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
							if ((param1 == "recurso-abandonado") || (param1 == "invasao")
								|| (param1 == "alianca-diplomatica") || (param1 == "sem-evento"))
								cmdDebug(command, param1, param2, ano, turnos);
							else
								cout << "\n >>> AVISO: O evento <" << param1 << "> nao existe." << endl;
						}
					}
				}
				//>>>>>>>> DEBUG COMMANDS - END <<<<<<
				if (compras == 2)
					endFase3 = 1;
			} while (compras != 2 && endFase3 != 1);

			//FASE 4 DO TURNO
			evento = 0;
			do {
				cout << "\n------FASE 4 ----" << endl;
				int forcaInv = 0, randSorte = 0, resNome = 0, ataque = 0;
				string nome;
				switch (randEvent)
				{
				case 1: // Recurso abandonado
					cout << "\n >>> AVISO DE EVENTO: Um recurso abandonado foi encontrado." << endl;
					if (ano == 1) {
						if (newGame.maisProdFase4() == true)
							cout << "              + 1 unidade de produtos" << endl;
						else
							cout << "\n >>> AVISO DE EVENTO: 1 unidade de produtos desperdiçada pois o armazem atingiu a capacidade maxima." << endl;
					}
					if (ano == 2) {
						if (newGame.maisOuroFase4() == true)
							cout << "              + 1 unidade de ouro" << endl;
						else
							cout << "\n >>> AVISO DE EVENTO: 1 unidade de ouro desperdiçada pois o cofre atingiu a capacidade maxima." << endl;
					}
					evento = 1;
					break;
				case 2: // Invasão
					randSorte = newGame.random(1, 6);
					nome = newGame.getLastTerritorioConquistado();
					resNome = newGame.getResLastTerritorioConquistado();
					cout << "\n >>> AVISO DE EVENTO: Invasao ao territorio " << nome << "." << endl;
					if (ano == 1) {
						forcaInv = 2;
						ataque = forcaInv + randSorte;
						if (newGame.existeTecnologia("defesas") == true) {
							cout << "\n >>> AVISO DE EVENTO: Foi encontrada a tecnologia defesas, o territorio " << nome << " foi defendido." << endl;
							cout << "              + 1 unidade de resistencia no territorio " << nome << "." << endl;
							newGame.incrementaRes(nome); // incrementa resistencia do ultimo territorio
						}
						if (nome == "territorioInicial") { // nao tem mais territorios logo perde o jogo
							cout << "\n >>> AVISO DE EVENTO: Perdeu o jogo pois o imperio era apenas constituido pelo territorioInicial." << endl;
							fimJogo();
						}
						if (ataque >= resNome) {
							cout << "\n >>> AVISO DE EVENTO: Invasao ao territorio " << nome << " com sucesso." << endl; // territorio perde invasao
							cout << "              Territorio " << nome << " removido do seu imperio." << endl;
							newGame.removeTerritoryImperio(nome); //remove territorio que sofreu invasão
						}
						if (ataque < resNome) {
							cout << "\n >>> AVISO DE EVENTO: Invasao ao territorio " << nome << " falhou." << endl; // territorio ganha invasao
						}
					}
					if (ano == 2) {
						forcaInv = 3;
						ataque = forcaInv + randSorte;
						if (newGame.existeTecnologia("defesas") == true) {
							cout << "\n >>> AVISO DE EVENTO: Foi encontrada a tecnologia defesas, o territorio " << nome << " foi defendido." << endl;
							cout << "              + 1 unidade de resistencia no territorio " << nome << "." << endl;
							newGame.incrementaRes(nome); // incrementa resistencia do ultimo territorio
						}
						if (nome == "territorioInicial") { // nao tem mais territorios logo perde o jogo
							cout << "\n >>> AVISO DE EVENTO: Perdeu o jogo pois o imperio era apenas constituido pelo territorioInicial." << endl;
							fimJogo();
						}
						if (ataque >= resNome) {
							cout << "\n >>> AVISO DE EVENTO: Invasao ao territorio " << nome << " com sucesso." << endl; // territorio perde invasao
							cout << "              Territorio " << nome << " removido do seu imperio." << endl;
							newGame.removeTerritoryImperio(nome); //remove territorio que sofreu invasão
						}
						if (ataque < resNome) {
							cout << "\n >>> AVISO DE EVENTO: Invasao ao territorio " << nome << " falhou." << endl; // territorio ganha invasao
						}
					}
					evento = 1;
					break;
				case 3: // Aliança diplomática
					cout << "\n >>> AVISO DE EVENTO: Foi assinada uma alianca com um outro imperio do qual tambem nao existe nenhum registo." << endl;
					cout << "              + 1 unidade de forca militar" << endl;
					newGame.AumentaForcaFase4();
					evento = 1;
					break;
				case 4: // Sem evento
					cout << "\n >>> AVISO DE EVENTO: Nada ocorreu, todos podem dormir descansados" << endl;
					evento = 1;
					break;
				}
				int endFase4 = 0;
				do {
					istringstream iss4;
					phrase = command = param1 = param2 = "";
					cout << "\nInsira um comando: ";
					getline(cin, phrase);
					iss4.str(phrase);
					iss4 >> command;
					if (!command.compare("lista")) {
						iss4 >> param1;
						if (!param1.compare("")) {
							cout << newGame.listaTerritorios(ano, turnos,randEvent);
						}
						else {
							cout << cmdLista(param1);
							cout << newGame.listaTerritorios(param1);
						}
					}
					if (!command.compare("help")) {
						cout << endl;
						help("helpfase4.txt");
					}
					if (!command.compare("grava")) {
						iss4 >> param1;
						if (!param1.compare("")) {
							needParam(1, command);
						}
						else {
							iss4 >> param2;
							if (param2.compare("")) {
								lessParam(1, command);
							}
							else {
								if (existNomeSave(param1) == false) {
									addSave(param1, newGame, ano, turnos);
									cout << ">>> AVISO: O jogo foi gravado com sucesso com o nome <" << param1 << ">." << endl;
									cout << getAsStringSave() << endl;
								}
								else { //nao pode criar
									cout << ">>> AVISO: O nome <" << param1 << "> que tentou atribuir ao save ja existe." << endl;
								}
							}
						}
					}
					if (!command.compare("apaga")) {
						iss4 >> param1;
						if (!param1.compare("")) {
							needParam(1, command);
						}
						else {
							iss4 >> param2;
							if (param2.compare("")) {
								lessParam(1, command);
							}
							else {
								if (existNomeSave(param1) == true) {
									removeSave(param1);
									cout << ">>> AVISO: O save <" << param1 << "> foi apagado com sucesso." << endl;
									cout << getAsStringSave() << endl;
								}
								else { //nao existe pra apagar
									cout << ">>> AVISO: O nome <" << param1 << "> que tentou apagar nao existe." << endl;
									cout << getAsStringSave() << endl;
								}
							}
						}
					}
					if (!command.compare("ativa")) {
						iss4 >> param1;
						if (!param1.compare("")) {
							needParam(1, command);
						}
						else {
							iss4 >> param2;
							if (param2.compare("")) {
								lessParam(1, command);
							}
							else {
								if (existNomeSave(param1) == true) {
									//ativa
									cmdDebug(command, param1, param2, ano, turnos);
									ano = ativaAno(param1);
									turnos = ativaTurno(param1);
									cout << ">>> AVISO: O save <" << param1 << "> foi carregado com sucesso." << endl;
									cout << "\n\n\n>>> AVISO: A RETOMAR JOGO COM OS DADOS GUARDADOS" << endl;
								}
								else { //nao existe pra ativar
									cout << ">>> AVISO: O nome <" << param1 << "> que tentou carregar nao existe." << endl;
									cout << getAsStringSave() << endl;
								}
							}
						}
					}
					if (!command.compare("avanca")) {
						cout << "\n>>> AVISO: A AVANCAR PARA O TURNO SEGUINTE...\n\n" << endl;
						endFase4 = 1;
					}
					//>>>>>>> DEBUG COMMANDS - START <<<<<<
					if (!command.compare("toma")) {
						iss4 >> param1;
						if (!param1.compare("")) {
							needParam(2, command);
						}
						else {
							iss4 >> param2;
							if (!param2.compare("")) {
								needParam(1, command);
							}
							else {
								if ((param1 == "terr") || (param1 == "tec")) {
									bool exist = false;
									if (param1 == "terr") {
										exist = newGame.existTerritory(param2);
										if (exist)
											cmdDebug(command, param1, param2, ano, turnos);
										else
											cout << "\n >>> AVISO: O territorio <" << param2 << "> a assaltar nao existe ou ja faz parte do imperio." << endl;
									}
									if (param1 == "tec") {
										exist = newGame.existeTecnologia(param2);
										if (!exist) // se não tiver tecnologia ganha-a
											cmdDebug(command, param1, param2, ano, turnos);
										else
											cout << "\n >>> AVISO: A tecnologia <" << param2 << "> a assaltar nao existe." << endl;
									}
								}
								else
									cout << "\n >>> AVISO: O tipo de parametro <" << param1 << "> a assaltar nao existe." << endl;
							}
						}
					}
					if (!command.compare("modifica")) {
						iss4 >> param1;
						if (!param1.compare("")) {
							needParam(2, command);
						}
						else {
							iss4 >> param2;
							if (!param2.compare("")) {
								needParam(1, command);
							}
							else {
								if ((param1 == "ouro") || (param1 == "prod")) {
									int NDigit = 0;
									for (int i = 0; i < param2.length(); i++) {
										if (!isdigit(param2[i]))
											NDigit++;
									}
									if (NDigit == 0)
										cmdDebug(command, param1, param2, ano, turnos);
									else
										cout << "\n >>> AVISO: Nao introduziu um inteiro como quantidade a modificar." << endl;
								}
								else
									cout << "\n >>> AVISO: O tipo de dado <" << param1 << "> a modificar nao existe." << endl;
							}
						}
					}
					if (!command.compare("fevento")) {
						iss4 >> param1;
						if (!param1.compare("")) {
							needParam(1, command);
						}
						else {
							iss4 >> param2;
							if (param2.compare("")) {
								lessParam(1, command);
							}
							else {
								if ((param1 == "recurso-abandonado") || (param1 == "invasao")
									|| (param1 == "alianca-diplomatica") || (param1 == "sem-evento"))
									cmdDebug(command, param1, param2, ano, turnos);
								else
									cout << "\n >>> AVISO: O evento <" << param1 << "> nao existe." << endl;
							}
						}
					}
				} while (endFase4 != 1);
			} while (evento != 1);
			turnos++;
		} while (endTurno != 1 && turnos < 6 && newGame.getSizeTerritorios() != 0);
		ano++;
	} while (ano != 3);

	//FUNCAO PARA FAZER E MOSTRAR PONTUAÇÕES FINAIS (METER TB NA FASE4)

	fimJogo();
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
		cout << "ERROR: Faltam " << num << " parametros no comando <" << command << ">." << endl;
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
bool configure::cmdCarrega(string ficheiro) {
	string str;
	ifstream fCarrega(ficheiro);
	int count = 0;

	if (!fCarrega) {
		cout << "ERRO: Nao conseguiu abrir o ficheiro" << endl;
		return false;
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
				newGame.addTerritory(name);
				
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

	return true;
}

//Funcao que recebe comando conquista territorio
bool configure::cmdConquista( string name) {
	if (name == "territorioInicial") {
		newGame.conquistaTerritorios("territorioInicial");
		return true;
	}
	else {
		cout << newGame.conquistaTerritorios(name);
		return true;
	}
	return false;
}

//Funcao que recebe comando lista algo
string configure::cmdLista( string name) {
	ostringstream oss;
	oss <<newGame.listaTerritorios(name);
	return oss.str();
}

//Funcao que apresenta dados do fim de jogo
void configure::fimJogo() {
	int bonus1 = 0, bonus2 = 0, total = 0;
	cout << "\n\n\n>>> FIM DO JOGO " << endl;
	cout << ">>> Pontuacao: " << newGame.getPontos() << endl;
	if (newGame.contaTecnologias() >= 5) {
		cout << ">>> Bonus cientifico: +1" << endl;
		bonus1 = 1;
	}
	else
		cout << ">>> Bonus cientifico: +0" << endl;
	if (newGame.getSizeTerritorios() == 0) {
		cout << ">>> Bonus imperador supremo: +3" << endl;
		bonus2 = 3;
	}
	else
		cout << ">>> Bonus imperador supremo: +0" << endl;
	total = bonus1 + bonus2 + newGame.getPontos();
	cout << ">>> PONTUACAO FINAL: " << total << endl;
	sair();
}

////Comando para sair
int configure::sair() {
	cout << "\n>>> SAINDO DO KINGDOM... " << endl;
	exit(EXIT_SUCCESS);
}
int game::sorteiaEvento() {
	int random;
	srand(time_t(0));
	random = rand() % 4;
	return random;
}
//Funcao para comandos debug
void configure::cmdDebug( string command, string param1, string param2, int ano, int turno) {
	int randSorte = 0, resNome = 0, forcaInv = 0, ataque = 0, num = 0;
	string nome;
	if (command == "toma") {
		if (param1 == "terr") {
			newGame.tomaTerritorio(param2);  //verificar se esta a fazer a recolha certa
			cout << "\n >>> AVISO: O territorio <" << param2 << "> foi conquistado." << endl;
		}
		if (param1 == "tec") {
			newGame.getTomaTecnologia(param2);
			cout << "\n >>> AVISO: A tecnologia <" << param2 << "> foi adquirida." << endl;
		}
	}
	if (command == "modifica") {
		num = stoi(param2);
		if (param1 == "ouro") {
			if (newGame.modificaOuro(num) == true)
				cout << "\n >>> AVISO: Ouro no cofre alterado para " << num << " com sucesso." << endl;
			else
				cout << "\n >>> AVISO: O cofre atingiu o limite de ouro e o restante foi desperdicado." << endl;
		}
		if (param1 == "prod") {
			if (newGame.modificaProd(num) == true)
				cout << "\n >>> AVISO: Produtos no cofre alterado para " << num << " com sucesso." << endl;
			else
				cout << "\n >>> AVISO: O armazem atingiu o limite de produtos e o restante foi desperdicado." << endl;
		}
	}
	if (command == "fevento") {
		if (param1 == "recurso-abandonado") {
			cout << "\n >>> AVISO DE EVENTO: Um recurso abandonado foi encontrado." << endl;
			if (ano == 1) {
				if (newGame.maisProdFase4() == true)
					cout << "              + 1 unidade de produtos" << endl;
				else
					cout << "\n >>> AVISO DE EVENTO: 1 unidade de produtos desperdiçada pois o armazem atingiu a capacidade maxima." << endl;
			}
			if (ano == 2) {
				if (newGame.maisOuroFase4() == true)
					cout << "              + 1 unidade de ouro" << endl;
				else
					cout << "\n >>> AVISO DE EVENTO: 1 unidade de ouro desperdiçada pois o cofre atingiu a capacidade maxima." << endl;
			}
		}
		if (param1 == "invasao") {
			randSorte = rand() % (1 - 6 + 1) + 1;
			nome = newGame.getLastTerritorioConquistado();
			resNome = newGame.getResLastTerritorioConquistado();
			cout << "\n >>> AVISO DE EVENTO: Invasao ao territorio " << nome << "." << endl;
			if (ano == 1) {
				forcaInv = 2;
				ataque = forcaInv + randSorte;
				if (newGame.existeTecnologia("defesas") == true) {
					cout << "\n >>> AVISO DE EVENTO: Foi encontrada a tecnologia defesas, o territorio " << nome << " foi defendido." << endl;
					cout << "              + 1 unidade de resistencia no territorio "<< nome <<"." << endl;
					newGame.incrementaRes(nome); // incrementa resistencia do ultimo territorio
				}
				if (nome == "territorioInicial") { // nao tem mais territorios logo perde o jogo
					cout << "\n >>> AVISO DE EVENTO: Perdeu o jogo pois o imperio era apenas constituido pelo territorioInicial." << endl;
					 fimJogo();
				}
				if (ataque >= resNome) {
					cout << "\n >>> AVISO DE EVENTO: Invasao ao territorio " << nome << " com sucesso." << endl; // territorio perde invasao
					cout << "              Territorio " << nome << " removido do seu imperio." << endl;
					newGame.removeTerritoryImperio(nome); //remove territorio que sofreu invasão
				}
				if (ataque < resNome) {
					cout << "\n >>> AVISO DE EVENTO: Invasao ao territorio " << nome << " falhou." << endl; // territorio ganha invasao
				}
			}
			if (ano == 2) {
				forcaInv = 3;
				ataque = forcaInv + randSorte;
				if (newGame.existeTecnologia("defesas") == true) {
					cout << "\n >>> AVISO DE EVENTO: Foi encontrada a tecnologia defesas, o territorio " << nome << " foi defendido." << endl;
					cout << "              + 1 unidade de resistencia no territorio " << nome << "." << endl;
					newGame.incrementaRes(nome); // incrementa resistencia do ultimo territorio
				}
				if (nome == "territorioInicial") { // nao tem mais territorios logo perde o jogo
					cout << "\n >>> AVISO DE EVENTO: Perdeu o jogo pois o imperio era apenas constituido pelo territorioInicial." << endl;
					fimJogo();
				}
				if (ataque >= resNome) {
					cout << "\n >>> AVISO DE EVENTO: Invasao ao territorio " << nome << " com sucesso." << endl; // territorio perde invasao
					cout << "              Territorio " << nome << " removido do seu imperio." << endl;
					newGame.removeTerritoryImperio(nome); //remove territorio que sofreu invasão
				}
				if (ataque < resNome) {
					cout << "\n >>> AVISO DE EVENTO: Invasao ao territorio " << nome << " falhou." << endl; // territorio ganha invasao
				}
			}
		}
		if (param1 == "alianca-diplomatica") {
			cout << "\n >>> AVISO DE EVENTO: Foi assinada uma alianca com um outro imperio do qual tambem nao existe nenhum registo." << endl;
			cout << "              + 1 unidade de forca militar" << endl;
			newGame.AumentaForcaFase4();
		}
		if (param1 == "sem-evento") {
			cout << "\n >>> AVISO DE EVENTO: Nada ocorreu, todos podem dormir descansados" << endl;
		}
	}
}

//Adiciona um Save
const string configure::addSave(string nomeSave, game gameSave, int ano, int turno) {
	ostringstream oss;
	saves.push_back(new save(nomeSave, gameSave, ano, turno));
	return oss.str();
}

//Apaga um Save
bool configure::removeSave(const string name) {
	ostringstream oss;
	for (auto it = saves.begin(); it != saves.end(); (it++)) {
		if ((*it)->getNomeSave() == name) {
			delete (*it);
			saves.erase(it);
			return true;
		}
	}
	return false;
}

//Ativa um save
void configure::ativaSave(const string name) {
	for (auto it = saves.begin(); it != saves.end(); (it++)) {
		if ((*it)->getNomeSave() == name) {
			newGame = (*it)->getGameSave();
			
		}
	}
}

//Ativa ano
int configure::ativaAno(const string name) {
	int ano = 0;
	for (auto it = saves.begin(); it != saves.end(); (it++)) {
		if ((*it)->getNomeSave() == name) {
			ano = (*it)->getAnoSave();
			return ano;
		}
	}
	return ano = 0;
}

//Ativa turno
int configure::ativaTurno(const string name) {
	int turno = 0;
	for (auto it = saves.begin(); it != saves.end(); (it++)) {
		if ((*it)->getNomeSave() == name) {
			turno = (*it)->getTurnoSave();
			return turno;
		}
	}
	return turno = 0;
}

//Verifica se existe um save com o nome indicado
const bool configure::existNomeSave(string name) {
	for (auto it = saves.begin(); it != saves.end(); (it++)) {
		if ((*it)->getNomeSave() == name) {
			return true;
		}
	}
	return false;
}

//Lista os saves feitos no jogo
string configure::getAsStringSave()
{
	ostringstream oss;
	oss << "\n_____________________________________" << endl;
	oss << ">>>>>>> SaveGames existentes: " << endl;
	for (int i = 0; i < saves.size(); i++) {
		int aux = i + 1;
		oss << "   " << aux << ". " << saves[i]->getNomeSave() << endl;
	}
	oss << "_____________________________________" << endl;
	return oss.str();
}

configure::~configure()
{
	/*for (auto it = saves.begin(); it < saves.end(); it++) {
		delete(*it);
	}*/
}
