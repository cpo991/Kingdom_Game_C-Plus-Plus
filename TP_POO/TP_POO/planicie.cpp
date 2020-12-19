//
//  Created by Carolina Oliveira & Isabel Castro on 19/12/2020
//
#include "planicie.h"

planicie::planicie(const string name) : territorio(name) {
	this->res = 5;
	this->createProd = 1; // nos turnos do primeiro ano depois passa a 2
	this->createGold = 1;
	this->victoryPoints = 1;
}

planicie::~planicie() {

}

int planicie::getRes() const
{
	return res;
}

int planicie::getCreateProd() const
{
	return createProd;
}

int planicie::getCreateGold() const
{
	return createGold;
}

int planicie::getVictoryPoints() const
{
	return victoryPoints;
}
