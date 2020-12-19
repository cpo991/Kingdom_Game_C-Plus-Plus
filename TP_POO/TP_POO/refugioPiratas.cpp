//
//  Created by Carolina Oliveira & Isabel Castro on 21/11/2020
//
#include "refugioPiratas.h"

refugioPiratas::refugioPiratas(const string name) : territorio(name) {
	this->res = 9;
	this->createProd = 2; // só no primeiro ano depois passa para 4 
	this->createGold = 0;
	this->victoryPoints = 2;
}

refugioPiratas::~refugioPiratas() {

}

int refugioPiratas::getRes() const
{
	return res;
}

int refugioPiratas::getCreateProd() const
{
	return createProd;
}

int refugioPiratas::getCreateGold() const
{
	return createGold;
}

int refugioPiratas::getVictoryPoints() const
{
	return victoryPoints;
}
