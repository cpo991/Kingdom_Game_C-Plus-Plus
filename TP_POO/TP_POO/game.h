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
#include "configure.h"

using namespace std;

class game {
    vector<territorio*> territorios;
    //vector<imperio> imperio;
public:
    game();
    const string addTerritory(string name);

};


#endif //TP_POO_GAME_H
