//
//  Created by Carolina Oliveira & Isabel Castro on 14/11/2020
//
#ifndef TP_POO_GAME_H
#define TP_POO_GAME_H

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "territorio.h"
#include "imperio.h"
#include "tecnologias.h"

using namespace std;

class game {
	int sorte_last = 0;
	vector<territorio*> territorios;
	imperio imperioU;
public:
	game();
	const string addTerritory(string nome);
	bool  removeTerritory(string name);
	const string listaTerritorios();
	const string listaTerritorios(string name);
	const size_t getSizeTerritorios();
	const string conquistaTerritorios(string name);
	const string setTerritorioDefault(string name);
	const bool existTerritory(const string name);
	const void recolheProdGold();
	const bool AumentaForca();
	const void AdicionaTecnologias(string nome);
	const bool existeTecnologia(const string name);
	const bool maisOuro();
	const bool maisProd();
	const void recursoAbandonado(int turnos);
	const string alianca();
};

#endif //TP_POO_GAME_H
