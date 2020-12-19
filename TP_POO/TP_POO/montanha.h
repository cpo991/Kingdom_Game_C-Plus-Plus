//
//  Created by Carolina Oliveira & Isabel Castro on 21/11/2020
//
#ifndef TP_POO_MONTANHA_H
#define TP_POO_MONTANHA_H

#include "territorio.h"

class montanha : public territorio {
    int res, createProd, createGold, victoryPoints;
public:
    //Construtor default
    montanha(const string nome);

    //Destrutor
    ~montanha();

    //Resistencia do territ�rio
    int getRes() const;

    //void setRes(int res);

    //Produ��o de produtos do territ�rio
    int getCreateProd() const;
    //void setCreateProd(int createProd);

    //Produ��o de ouro do territ�rio
    int getCreateGold() const;
    //void setCreateGold(int createGold);

    //Pontos de conquista do territ�rio
    int getVictoryPoints() const;
    //void setVictoryPoints(int victoryPoints);
};


#endif
