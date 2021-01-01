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
	//tecnologias* a;
public:
	game();
	//bool  addTerritory(string name);
	const string addTerritory(string nome);
	bool  removeTerritory(string name);
	const string listaTerritorios();
	const string listaTerritorios(string name);
	const size_t getSizeTerritorios();
	const string conquistaTerritorios(string name);
	const string setTerritorioDefault(string name);
	bool existTerritory(const string name);
	bool recolheProdGold();
	const bool AumentaForca();
	const void AdicionaTecnologias(string nome);
	//bool existeTecnologia(const string name);
};

#endif //TP_POO_GAME_H
