//
//  Created by Carolina Oliveira & Isabel Castro on 21/11/2020
//
#ifndef TP_POO_TERRITORIO_H
#define TP_POO_TERRITORIO_H

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

class territorio {
    int res, createProd, createGold, victoryPoints;
    string name;

public:
    territorio(string name, int res, int, int createProd, int createGold, int victoryPoints);
    string getType(string name);
};


#endif //TP_POO_CONFIGURE_H
