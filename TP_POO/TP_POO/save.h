//
//  Created by Carolina Oliveira & Isabel Castro on 11/01/2021
//
#ifndef TP_POO_SAVE_H
#define TP_POO_SAVE_H

#include "game.h"

using namespace std;

class save {
	string nomeSave;
	game gameSave;
	int turno, ano;
	
public:
	//Construtor
	//save(string nomeSave, game gameSave, int ano, int turno) :nomeSave(nomeSave), gameSave(gameSave), ano(ano), turno(turno) {};
	
	////Destrutor

	save(string nomeSave, game gameSave, int ano, int turno);

	//Retorna o nome do save
	const string getNomeSave();

	//Retorna o vetor do jogo
	game getGameSave();

	//Retorna o ano
	const int getAnoSave();

	//Retorna o turno
	const int getTurnoSave();

};

#endif //TP_POO_SAVE_H
