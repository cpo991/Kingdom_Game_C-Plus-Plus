//
//  Created by Carolina Oliveira & Isabel Castro on 19/12/2020
//
#include "castelo.h"

castelo::castelo(const string name) : territorio(name) {
	this->res = 7;
	this->createProd = 3; // só nos primeiros 2 turnos de cada ano (?)
	this->createGold = 1;
	this->victoryPoints = 1;
}

castelo::~castelo() {

}

int castelo::getRes() const
{
	return res;
}

int castelo::getCreateProd() const
{
	return createProd;
}

int castelo::getCreateGold() const
{
	return createGold;
}

int castelo::getVictoryPoints() const
{
	return victoryPoints;
}
