//
//  Created by Carolina Oliveira & Isabel Castro on 19/12/2020
//
#include "fortaleza.h"

fortaleza::fortaleza(const string name) : territorio(name) {
	this->res = 8;
	this->createProd = 0; 
	this->createGold = 0;
	this->victoryPoints = 1;
}

fortaleza::~fortaleza() {

}

int fortaleza::getRes() const
{
	return res;
}

int fortaleza::getCreateProd() const
{
	return createProd;
}

int fortaleza::getCreateGold() const
{
	return createGold;
}

int fortaleza::getVictoryPoints() const
{
	return victoryPoints;
}
