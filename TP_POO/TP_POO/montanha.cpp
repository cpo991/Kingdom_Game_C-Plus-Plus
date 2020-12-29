//
//  Created by Carolina Oliveira & Isabel Castro on 19/12/2020
//
#include "montanha.h"

montanha::montanha(const string name) : territorio(name) {
	this->setName(name);
	this->setRes(6);
	this->setCreateGold(0);
	this->setCreateProd(0);
	this->setVictoryPoints(1);
}

montanha::~montanha() {
}

void montanha::setName(string name)
{
	static int a = 0;
	territorio::setName(getName() + std::to_string(a));
	name = (name + std::to_string(a));
	a++;
}