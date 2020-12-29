//
//  Created by Carolina Oliveira & Isabel Castro on 19/12/2020
//
#include "fortaleza.h"

fortaleza::fortaleza(const string name) : territorio(name) {
	this->setName(name);
	this->setRes(8);
	this->setCreateProd(0);
	this->setCreateGold(0);
	this->setVictoryPoints(1);
}

fortaleza::~fortaleza() {
}

void fortaleza::setName(string name)
{
	static int a = 0;
	territorio::setName(getName() + std::to_string(a));
	name = (name + std::to_string(a));
	a++;
}