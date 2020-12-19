//
//  Created by Carolina Oliveira & Isabel Castro on 19/12/2020
//
#include "montanha.h"

montanha::montanha(const string name) : territorio(name) {
	this->res = 6;
	this->createProd = 0; // 0 nos primeiros 2 turnos, depois passa a 1
	this->createGold = 0;
	this->victoryPoints = 1;
}

montanha::~montanha() {

}

int montanha::getRes() const
{
	return res;
}

int montanha::getCreateProd() const
{
	return createProd;
}

int montanha::getCreateGold() const
{
	return createGold;
}

int montanha::getVictoryPoints() const
{
	return victoryPoints;
}
