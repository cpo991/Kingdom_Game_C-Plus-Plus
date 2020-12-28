//
//  Created by Carolina Oliveira & Isabel Castro on 21/11/2020
//
#include "pescaria.h"

pescaria::pescaria(const string name) : territorio(name) {
	this->setName(name);
	this->setRes(9);
	this->setCreateGold(0);
	this->setCreateProd(1);
	this->setVictoryPoints(2);
}

pescaria::~pescaria() {

}

void pescaria::setName(string name)
{
	static int a = 0;
	territorio::setName(getName() + std::to_string(a));
	name = (name + std::to_string(a));
	a++;
}


