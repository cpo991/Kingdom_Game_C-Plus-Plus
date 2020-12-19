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


using namespace std;

class game {
    vector<territorio*> territorios;
    imperio imperioU;
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
};


#endif //TP_POO_GAME_H
