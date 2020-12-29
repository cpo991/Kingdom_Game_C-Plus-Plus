//
//  Created by Carolina Oliveira & Isabel Castro on 19/12/2020
//
#include "planicie.h"

planicie::planicie(const string name) : territorio(name) {
	this->setName(name);
	this->setRes(5);
	this->setCreateGold(1);
	this->setCreateProd(1);
	this->setVictoryPoints(1);
}

planicie::~planicie() {
}

void planicie::setName(string name)
{
	static int a = 0;
	territorio::setName(getName() + std::to_string(a));
	name = (name + std::to_string(a));
	a++;
}