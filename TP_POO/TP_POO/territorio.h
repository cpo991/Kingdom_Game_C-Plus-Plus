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
    //Construtor default
    territorio(string name);

    //Construtor por c�pia
    territorio(const territorio& territori);

    //Destrutor
    ~territorio();

    //Tipo de territ�rio
    string getType(string name) const;

    //Nome do territ�rio
    string getName() const;
    void setName(string name);

    //Resistencia do territ�rio
    int getRes() const;
    void setRes(int res);

    //Produ��o de produtos do territ�rio
    int getCreateProd() const;
    void setCreateProd(int createProd);

    //Produ��o de ouro do territ�rio
    int getCreateGold() const;
    void setCreateGold(int createGold);

    //Pontos de conquista do territ�rio
    int getVictoryPoints() const;
    void setVictoryPoints(int victoryPoints);

    //Descri��o Textual do territ�rio
    string getAsString() const;
};


#endif //TP_POO_CONFIGURE_H
