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

    //Construtor por cópia
    territorio(const territorio& territori);

    //Destrutor
    ~territorio();

    //Tipo de território
    string getType(string name) const;

    //Nome do território
    string getName() const;
    void setName(string name);

    //Resistencia do território
    int getRes() const;
    void setRes(int res);

    //Produção de produtos do território
    int getCreateProd() const;
    void setCreateProd(int createProd);

    //Produção de ouro do território
    int getCreateGold() const;
    void setCreateGold(int createGold);

    //Pontos de conquista do território
    int getVictoryPoints() const;
    void setVictoryPoints(int victoryPoints);

    //Descrição Textual do território
    string getAsString() const;
};


#endif //TP_POO_CONFIGURE_H
