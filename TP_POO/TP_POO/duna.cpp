//
//  Created by Carolina Oliveira & Isabel Castro on 19/12/2020
//
#include "duna.h"

duna::duna(const string name) : territorio(name) {
	setName(name);
	this->setRes(4);
	this->setCreateGold(0);
	this->setCreateProd(1);
	this->setVictoryPoints(1);
}

duna::~duna() {

}

void duna::setName(string name)
{
	static int a = 0;
	territorio::setName(getName() + std::to_string(a));
	name = (name + std::to_string(a));
	a++;
}
