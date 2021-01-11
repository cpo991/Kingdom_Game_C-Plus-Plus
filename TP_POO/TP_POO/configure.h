//
//  Created by Carolina Oliveira & Isabel Castro on 14/11/2020
//
#ifndef TP_POO_CONFIGURE_H
#define TP_POO_CONFIGURE_H

#include "game.h"
#include "save.h"
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

class configure {
	game* newGame;
	string phrase, command, param1, param2, param3, param4, param5, param6, param7;
	vector <save*> saves;
public:
	//Construtor
	configure(game& g);

	// Abre o ficheiro menu.txt e imprime
	void initMenu();

	//Manipulacao de todos os comandos
	void commands();

	// Abre o ficheiro help
	void help(string file);

	//Recebe uma string e um numero e imprime o numero de parametros que falta

	void needParam(int num, string command);

	//Recebe uma string e um numero e imprime avisos sobre parametros a mais
	void lessParam(int num, string command);

	//Funcao que recebe comando carrega ficheiro
	game cmdCarrega(game NewGame, string ficheiro);

	//Funcao que recebe comando conquista territorio
	game  cmdConquista(game NewGame, string name);

	//Funcao que recebe comando lista algo
	string cmdLista(game NewGame, string name);

	//Funcao que recebe comando maismilitar
	game cmdAumenta(game NewGame);

	//Funcao que apresenta dados do fim de jogo
	game fimJogo(game NewGame);

	//Comando para sair
	int sair();

	//Funcao para comandos debug
	game cmdDebug(game NewGame, string command, string param1, string param2, int ano, int turno);

	//Adiciona um Save
	const string addSave(string nomeSave, game gameSave, int ano, int turno);
	
	//Apaga um Save
	bool removeSave(const string name);

	//Ativa um Save
	game ativaSave(const string name, game NewGame);
	//Ativa o ano
	int ativaAno(const string name);
	//Ativa turno
	int ativaTurno(const string name);

	//Verifica se existe um save com o nome indicado
	const bool existNomeSave(string name);

	//Lista os saves feitos no jogo
	string getAsStringSave();
};

#endif //TP_POO_CONFIGURE_H
