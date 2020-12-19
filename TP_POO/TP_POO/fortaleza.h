//
//  Created by Carolina Oliveira & Isabel Castro on 21/11/2020
//
#ifndef TP_POO_FORTALEZA_H
#define TP_POO_FORTALEZA_H

#include "territorio.h"

class fortaleza : public territorio {
    int res, createProd, createGold, victoryPoints;
public:
    //Construtor default
    fortaleza(const string nome);

    //Destrutor
    ~fortaleza();

    //Resistencia do território
    int getRes() const;

    //void setRes(int res);

    //Produção de produtos do território
    int getCreateProd() const;
    //void setCreateProd(int createProd);

    //Produção de ouro do território
    int getCreateGold() const;
    //void setCreateGold(int createGold);

    //Pontos de conquista do território
    int getVictoryPoints() const;
    //void setVictoryPoints(int victoryPoints);
};


#endif
