//
//  Created by Carolina Oliveira & Isabel Castro on 19/12/2020
//
#include "duna.h"

duna::duna(const string name) : territorio(name) {
	this->res = 4;
	this->createProd = 1; 
	this->createGold = 0;
	this->victoryPoints = 1;
}

duna::~duna() {

}

int duna::getRes() const
{
	return res;
}

int duna::getCreateProd() const
{
	return createProd;
}

int duna::getCreateGold() const
{
	return createGold;
}

int duna::getVictoryPoints() const
{
	return victoryPoints;
}
