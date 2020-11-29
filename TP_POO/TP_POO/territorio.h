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
    //Constructor of territory
    territorio(string name);
    //Constructor of territory by copy
    territorio(const territorio& territori);
    //Destructor of territory
    ~territorio();
    //Get type of territory
    string getType(string name);
    //
    string getName() const;
    void setName(string name);
    int getRes() const;
    void setRes(int res);
    int getCreateProd() const;
    void setCreateProd(int createProd);
    int getCreateGold() const;
    void setCreateGold(int createGold);
    int getVictoryPoints() const;
    void setVictoryPoints(int victoryPoints);
};


#endif //TP_POO_CONFIGURE_H
