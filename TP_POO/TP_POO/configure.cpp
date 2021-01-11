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
		turnos = 0;
		do {
			NewGame.altera(ano, turnos);
			cout << "\n>>>>>>>>>>>>>>> ANO " << ano << "<<<<<<<<<<<<<<<" << endl;
			cout << ">>>>>>>>>>>>>>> TURNO " << turnos + 1 << "<<<<<<<<<<<<<<<" << endl;
			//FASE 1 DO TURNO
			int comandoCP = 0;
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
							if (comandoCP == 1) {
								cout << "\nAVISO: O comando passa ou conquista ja foi introduzido neste turno." << endl;
							}
							else{
								if (NewGame.existTerritory(param1) == true) {
									NewGame = cmdConquista(NewGame, param1);
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
								addSave(param1, NewGame, ano, turnos);
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
								cout << ">>> AVISO: O save <"<<param1<<"> foi apagado com sucesso." << endl;
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
								NewGame = ativaSave(param1, NewGame);
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
							if ((param1 == "terr") | (param1 == "tec")) {
								bool exist = false;
								if (param1 == "terr") {
									exist = NewGame.existTerritory(param2);
									if (exist)
										NewGame = cmdDebug(NewGame, command, param1, param2, ano, turnos);
									else
										cout << "\n >>> AVISO: O territorio <" << param2 << "> a assaltar nao existe." << endl;
								}
								if (param1 == "tec") {
									exist = NewGame.existeTecnologia(param2);
									if(!exist)
										NewGame = cmdDebug(NewGame, command, param1, param2, ano, turnos);
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
							if ((param1 == "ouro") | (param1 == "prod")) {
								int NDigit = 0;
								for (int i = 0; i < param2.length(); i++) {
									if (!isdigit(param2[i]))
										NDigit++;
								}
								if (NDigit == 0) 
									NewGame = cmdDebug(NewGame, command, param1, param2, ano, turnos);
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
								NewGame = cmdDebug(NewGame, command, param1, param2, ano, turnos);
							else
								cout << "\n >>> AVISO: O evento <" << param1 << "> nao existe." << endl;
						}
					}
				}
				//>>>>>>>> DEBUG COMMANDS - END <<<<<<

				if (NewGame.getSizeTerritorios() == 0) {
					cout << "\nAVISO: Nao ha territorios para conquistar mais!" << endl;
					endTurno = 1;
				}
			} while (endFase1 != 1);

			//FASE 2 DO TURNO
			do {
				cout << "\n------FASE 2 ----" << endl;
				cout << "\n>>>> A recolher produtos e ouro!" << endl;
				NewGame.recolheProdGold();

				if (NewGame.existeTecnologia("bolsa") == true) {
					endFase2 = 0;
					do {
						istringstream iss2;
						cout << "\n>>> AVISO: E POSSIVEL FAZER TROCAS DE PRODUTOS/OURO " << endl;
						cout << "\nPretende avancar ou fazer trocas?" << endl;
						cout << "\nInsira um comando: ";
						getline(cin, phrase);
						iss2.str(phrase);
						iss2 >> command;
						param1 = "";

						if (!command.compare("maisouro")) {
							iss2 >> param1;
							if (param1.compare("")) {
								lessParam(1, command);
							}
							else {
								if (NewGame.maisOuro() == true)
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
							else{
								if (NewGame.maisProd() == true)
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
								cout << NewGame.listaTerritorios();
							}
							else {
								cout << cmdLista(NewGame, param1);
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
									if ((param1 == "terr") | (param1 == "tec")) {
										bool exist = false;
										if (param1 == "terr") {
											exist = NewGame.existTerritory(param2);
											if (exist)
												NewGame = cmdDebug(NewGame, command, param1, param2, ano, turnos);
											else
												cout << "\n >>> AVISO: O territorio <" << param2 << "> a assaltar nao existe ou ja faz parte do imperio." << endl;
										}
										if (param1 == "tec") {
											exist = NewGame.existeTecnologia(param2);
											if (!exist) // se não tiver tecnologia ganha-a
												NewGame = cmdDebug(NewGame, command, param1, param2, ano, turnos);
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
									if ((param1 == "ouro") | (param1 == "prod")) {
										int NDigit = 0;
										for (int i = 0; i < param2.length(); i++) {
											if (!isdigit(param2[i]))
												NDigit++;
										}
										if (NDigit == 0)
											NewGame = cmdDebug(NewGame, command, param1, param2, ano, turnos);
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
										NewGame = cmdDebug(NewGame, command, param1, param2, ano, turnos);
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
					cout << "\nInsira um comando: ";
					getline(cin, phrase);
					iss2b.str(phrase);
					iss2b >> command;
					param1 = "";
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
							cout << NewGame.listaTerritorios();
						}
						else {
							cout << cmdLista(NewGame, param1);
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
								if ((param1 == "terr") | (param1 == "tec")) {
									bool exist = false;
									if (param1 == "terr") {
										exist = NewGame.existTerritory(param2);
										if (exist)
											NewGame = cmdDebug(NewGame, command, param1, param2, ano, turnos);
										else
											cout << "\n >>> AVISO: O territorio <" << param2 << "> a assaltar nao existe ou ja faz parte do imperio." << endl;
									}
									if (param1 == "tec") {
										exist = NewGame.existeTecnologia(param2);
										if (!exist) // se não tiver tecnologia ganha-a
											NewGame = cmdDebug(NewGame, command, param1, param2, ano, turnos);
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
								if ((param1 == "ouro") | (param1 == "prod")) {
									int NDigit = 0;
									for (int i = 0; i < param2.length(); i++) {
										if (!isdigit(param2[i]))
											NDigit++;
									}
									if (NDigit == 0)
										NewGame = cmdDebug(NewGame, command, param1, param2, ano, turnos);
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
									NewGame = cmdDebug(NewGame, command, param1, param2, ano, turnos);
								else
									cout << "\n >>> AVISO: O evento <" << param1 << "> nao existe." << endl;
							}
						}
					}
					//>>>>>>>> DEBUG COMMANDS - END <<<<<<
				}while (endFase2 != 1);
				recolha_prod = 1;
			} while (recolha_prod != 1 && endFase2 != 1);

			//FASE 3 DO TURNO
			int compras = 0, compra_tecnologia = 0 , compra_militar = 0; 
			endFase3 = 0;
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
					iss3 >> param1;
					if (param1.compare("")) {
						lessParam(1, command);
					}
					else {
						if (compra_militar < 1) {
							NewGame = cmdAumenta(NewGame);
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
									result = NewGame.getCompraTecnologia(param1);
									if (result == 999) {
										cout << "\n>>> AVISO: A tecnologia <" << param1 << "> foi adquirida com sucesso." << endl;
										compra_tecnologia++;
										compras++;
										cout << "\tCOMPRAS FEITAS = " << compras << endl;
									}
									else if(result == 0)
										cout << "\n>>> AVISO: Erro na coompra da tecnologia <" << param1 << ">" << endl;
									else {
										cout << "\n>>> AVISO: A tecnologia <" << param1 << "> nao foi adquirida com sucesso." << endl;
										cout << ">>> AVISO: Falta <" <<result<< "> de ouro no cofre para a adquirir." << endl;
									}	
								}
								else
									cout << "\n>>> AVISO: Ja nao pode adquirir mais tecnologias." << endl;
							}
							else
								cout << "\n>>> AVISO: A tecnologia <"<< param1 <<"> nao existe." << endl;
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
					cout << "\n>>> AVISO: A AVANCAR PARA FASE 4...\n\n" << endl;
					compras = 2;
					endFase3 = 1;
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
							if ((param1 == "terr") | (param1 == "tec")) {
								bool exist = false;
								if (param1 == "terr") {
									exist = NewGame.existTerritory(param2);
									if (exist)
										NewGame = cmdDebug(NewGame, command, param1, param2, ano, turnos);
									else
										cout << "\n >>> AVISO: O territorio <" << param2 << "> a assaltar nao existe ou ja faz parte do imperio." << endl;
								}
								if (param1 == "tec") {
									exist = NewGame.existeTecnologia(param2);
									if (!exist) // se não tiver tecnologia ganha-a
										NewGame = cmdDebug(NewGame, command, param1, param2, ano, turnos);
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
							if ((param1 == "ouro") | (param1 == "prod")) {
								int NDigit = 0;
								for (int i = 0; i < param2.length(); i++) {
									if (!isdigit(param2[i]))
										NDigit++;
								}
								if (NDigit == 0)
									NewGame = cmdDebug(NewGame, command, param1, param2, ano, turnos);
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
								NewGame = cmdDebug(NewGame, command, param1, param2, ano, turnos);
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
			int evento = 0;
			int randEvent = 0;
			do {
				cout << "\n------FASE 4 ----" << endl;
				int forcaInv = 0, randSorte = 0, resNome = 0, ataque = 0;
				unsigned seed = time_t(0);
				srand(seed);
				randEvent = NewGame.random(1, 4);
				string nome;
				switch (randEvent)
				{
				case 1: // Recurso abandonado
					cout << "\n >>> AVISO DE EVENTO: Um recurso abandonado foi encontrado." << endl;
					if (ano == 1) {
						if (NewGame.maisProdFase4() == true)
							cout << "              + 1 unidade de produtos" << endl;
						else
							cout << "\n >>> AVISO DE EVENTO: 1 unidade de produtos desperdiçada pois o armazem atingiu a capacidade maxima." << endl;
					}
					if (ano == 2) {
						if (NewGame.maisOuroFase4() == true)
							cout << "              + 1 unidade de ouro" << endl;
						else
							cout << "\n >>> AVISO DE EVENTO: 1 unidade de ouro desperdiçada pois o cofre atingiu a capacidade maxima." << endl;
					}
					evento = 1;
					break;
				case 2: // Invasão
					randSorte = NewGame.random(1, 6);
					nome = NewGame.getLastTerritorioConquistado();
					resNome = NewGame.getResLastTerritorioConquistado();
					cout << "\n >>> AVISO DE EVENTO: Invasao ao territorio "<< nome << "." << endl;
					if (ano == 1) {
						forcaInv = 2;
						ataque = forcaInv + randSorte;
						if (NewGame.existeTecnologia("defesas") == true) {
							NewGame.incrementaRes(nome); // incrementa resistencia do ultimo territorio
						}
						if (nome == "territorioInicial") { // nao tem mais territorios logo perde o jogo
							cout << "\n >>> AVISO DE EVENTO: Perdeu o jogo pois o imperio era apenas constituido pelo territorioInicial." << endl;
							NewGame = fimJogo(NewGame);
						}
						if (ataque >= resNome) {
							NewGame.removeTerritoryImperio(nome); //remove territorio que sofreu invasão
						}
						if (ataque < resNome){
							cout << "\n >>> AVISO DE EVENTO: Invasao ao territorio " << nome << " falhou." << endl; // territorio ganha invasao
						}
					}
					if (ano == 2) {
						forcaInv = 3;
						ataque = forcaInv + randSorte;
						if (NewGame.existeTecnologia("defesas") == true) {
							NewGame.incrementaRes(nome); // incrementa resistencia do ultimo territorio
						}
						if (nome == "territorioInicial") { // nao tem mais territorios logo perde o jogo
							cout << "\n >>> AVISO DE EVENTO: Perdeu o jogo pois o imperio era apenas constituido pelo territorioInicial." << endl;
							NewGame = fimJogo(NewGame);
						}
						if (ataque >= resNome) {
							NewGame.removeTerritoryImperio(nome); //remove territorio que sofreu invasão
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
					NewGame.AumentaForcaFase4();
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
					cout << "\nInsira um comando: ";
					phrase = command = param1 = "";
					getline(cin, phrase);
					iss4.str(phrase);
					iss4 >> command;
					if (!command.compare("lista")) {
						iss4 >> param1;
						if (!param1.compare("")) {
							cout << NewGame.listaTerritorios();
						}
						else {
							cout << cmdLista(NewGame, param1);
						}
					}
					if (!command.compare("help")) {
						cout << endl;
						help("helpfase4.txt");
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
								if ((param1 == "terr") | (param1 == "tec")) {
									bool exist = false;
									if (param1 == "terr") {
										exist = NewGame.existTerritory(param2);
										if (exist)
											NewGame = cmdDebug(NewGame, command, param1, param2, ano, turnos);
										else
											cout << "\n >>> AVISO: O territorio <" << param2 << "> a assaltar nao existe ou ja faz parte do imperio." << endl;
									}
									if (param1 == "tec") {
										exist = NewGame.existeTecnologia(param2);
										if (!exist) // se não tiver tecnologia ganha-a
											NewGame = cmdDebug(NewGame, command, param1, param2, ano, turnos);
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
								if ((param1 == "ouro") | (param1 == "prod")) {
									int NDigit = 0;
									for (int i = 0; i < param2.length(); i++) {
										if (!isdigit(param2[i]))
											NDigit++;
									}
									if (NDigit == 0)
										NewGame = cmdDebug(NewGame, command, param1, param2, ano, turnos);
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
									NewGame = cmdDebug(NewGame, command, param1, param2, ano, turnos);
								else
									cout << "\n >>> AVISO: O evento <" << param1 << "> nao existe." << endl;
							}
						}
					}
				} while (endFase4 != 1);
			} while (evento != 1);
			turnos++;
		} while (endTurno != 1 && turnos < 6 && NewGame.getSizeTerritorios() != 0);
		ano++;
	} while (ano != 3);
	
	//FUNCAO PARA FAZER E MOSTRAR PONTUAÇÕES FINAIS (METER TB NA FASE4)

	NewGame = fimJogo(NewGame);
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

//Funcao que apresenta dados do fim de jogo
game configure::fimJogo(game NewGame) {
	int bonus1 = 0, bonus2 = 0, total = 0;
	cout << "\n\n\n>>> FIM DO JOGO " << endl;
	cout << ">>> Pontuacao: " << NewGame.getPontos() << endl;
	if (NewGame.contaTecnologias() >= 5) {
		cout << ">>> Bonus cientifico: +1" << endl;
		bonus1 = 1;
	}
	else
		cout << ">>> Bonus cientifico: +0" << endl;
	if (NewGame.getSizeTerritorios() == 0) {
		cout << ">>> Bonus imperador supremo: +3" << endl;
		bonus2 = 3;
	}
	else
		cout << ">>> Bonus imperador supremo: +0" << endl;
	total = bonus1 + bonus2 + NewGame.getPontos();
	cout << ">>> PONTUACAO FINAL: " << total << endl;
	sair();
	return NewGame;
}

//Comando para sair
int configure::sair() {
	
	cout << "\n>>> SAINDO DO KINGDOM... " << endl;
	exit(EXIT_SUCCESS); //inacabado
}

//Funcao para comandos debug
game configure::cmdDebug(game NewGame, string command, string param1, string param2, int ano, int turno) {
	int randSorte = 0, resNome = 0, forcaInv = 0, ataque = 0, num = 0;
	string nome;
	if (command == "toma") {
		if (param1 == "terr") {
			NewGame.tomaTerritorio(param2);  //verificar se esta a fazer a recolha certa
			cout << "\n >>> AVISO: O territorio <"<< param2 <<"> foi conquistado." << endl;
		}
		if (param1 == "tec") {
			NewGame.getTomaTecnologia(param2);
			cout << "\n >>> AVISO: A tecnologia <" << param2 << "> foi adquirida." << endl;
		}
	}
	if (command == "modifica") {
		num = stoi(param2);
		if (param1 == "ouro") {
			if(NewGame.modificaOuro(num) == true)
				cout << "\n >>> AVISO: Ouro no cofre alterado para " << num << " com sucesso." << endl;
			else
				cout << "\n >>> AVISO: O cofre atingiu o limite de ouro e o restante foi desperdicado." << endl;
		}
		if (param1 == "prod") {
			if (NewGame.modificaProd(num) == true)
				cout << "\n >>> AVISO: Produtos no cofre alterado para " << num << " com sucesso." << endl;
			else
				cout << "\n >>> AVISO: O armazem atingiu o limite de produtos e o restante foi desperdicado." << endl;
		}
	}
	if (command == "fevento") {
		if (param1 == "recurso-abandonado") {
			cout << "\n >>> AVISO DE EVENTO: Um recurso abandonado foi encontrado." << endl;
			if (ano == 1) {
				if(NewGame.maisProdFase4() == true)
					cout << "              + 1 unidade de produtos" << endl;
				else
					cout << "\n >>> AVISO DE EVENTO: 1 unidade de produtos desperdiçada pois o armazem atingiu a capacidade maxima." << endl;
			}
			if (ano == 2) {
				if(NewGame.maisOuroFase4() == true)
					cout << "              + 1 unidade de ouro" << endl;
				else
					cout << "\n >>> AVISO DE EVENTO: 1 unidade de ouro desperdiçada pois o cofre atingiu a capacidade maxima." << endl;
			}
		}
		if (param1 == "invasao") {
			randSorte = rand() % (1 - 6 + 1) + 1;
			nome = NewGame.getLastTerritorioConquistado();
			resNome = NewGame.getResLastTerritorioConquistado();
			cout << "\n >>> AVISO DE EVENTO: Invasao ao territorio " << nome << "." << endl;
			if (ano == 1) {
				forcaInv = 2;
				ataque = forcaInv + randSorte;
				if (NewGame.existeTecnologia("defesas") == true) {
					NewGame.incrementaRes(nome); // incrementa resistencia do ultimo territorio
				}
				if (nome == "territorioInicial") { // nao tem mais territorios logo perde o jogo
					cout << "\n >>> AVISO DE EVENTO: Perdeu o jogo pois o imperio era apenas constituido pelo territorioInicial." << endl;
					NewGame = fimJogo(NewGame);
				}
				if (ataque >= resNome) {
					NewGame.removeTerritoryImperio(nome); //remove territorio que sofreu invasão
				}
				if (ataque < resNome) {
					cout << "\n >>> AVISO DE EVENTO: Invasao ao territorio " << nome << " falhou." << endl; // territorio ganha invasao
				}
			}
			if (ano == 2) {
				forcaInv = 3;
				ataque = forcaInv + randSorte;
				if (NewGame.existeTecnologia("defesas") == true) {
					NewGame.incrementaRes(nome); // incrementa resistencia do ultimo territorio
				}
				if (nome == "territorioInicial") { // nao tem mais territorios logo perde o jogo
					cout << "\n >>> AVISO DE EVENTO: Perdeu o jogo pois o imperio era apenas constituido pelo territorioInicial." << endl;
					NewGame = fimJogo(NewGame);
				}
				if (ataque >= resNome) {
					NewGame.removeTerritoryImperio(nome); //remove territorio que sofreu invasão
				}
				if (ataque < resNome) {
					cout << "\n >>> AVISO DE EVENTO: Invasao ao territorio " << nome << " falhou." << endl; // territorio ganha invasao
				}
			}
		}
		if (param1 == "alianca-diplomatica") {
			cout << "\n >>> AVISO DE EVENTO: Foi assinada uma alianca com um outro imperio do qual tambem não existe nenhum registo." << endl;
			cout << "              + 1 unidade de forca militar" << endl;
			NewGame.AumentaForcaFase4();
		}
		if (param1 == "sem-evento") {
			cout << "\n >>> AVISO DE EVENTO: Nada ocorreu, todos podem dormir descansados" << endl;
		}
	}
	return NewGame;
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
game configure::ativaSave(const string name, game NewGame) {
	for (auto it = saves.begin(); it != saves.end(); (it++)) {
		if ((*it)->getNomeSave() == name) {
			NewGame = (*it)->getGameSave();
			return NewGame;
		}
	}
	return NewGame;
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
		int aux = i+1;
		oss << "   "<<aux<<". " << saves[i]->getNomeSave() << endl;
	}
	oss << "_____________________________________" << endl;
	return oss.str();
}