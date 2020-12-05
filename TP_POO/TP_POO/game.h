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
#include "territorio.h"
#include "imperio.h"


using namespace std;

class game {
    vector<territorio*> territorios;
    imperio imperioU;
public:
    game();
    const string addTerritory(string name);
    const string  removeTerritory(string name);
    const vector<territorio*> getTerritorios();
     //int getSizeTerritorios();
    const string conquistaTerritorios(string name);
};


#endif //TP_POO_GAME_H
