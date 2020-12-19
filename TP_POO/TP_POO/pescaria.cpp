//
//  Created by Carolina Oliveira & Isabel Castro on 21/11/2020
//
#include "pescaria.h"

pescaria::pescaria(const string name) : territorio(name) {
	this->res = 9;
	this->createProd = 0;
	this->createGold = 1;
	this->victoryPoints = 2;
}

pescaria::~pescaria() {

}

int pescaria::getRes() const
{
	return res;
}

int pescaria::getCreateProd() const
{
	return createProd;
}

int pescaria::getCreateGold() const
{
	return createGold;
}

int pescaria::getVictoryPoints() const
{
	return victoryPoints;
}
