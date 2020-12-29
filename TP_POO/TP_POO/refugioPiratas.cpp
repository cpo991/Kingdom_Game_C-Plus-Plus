//
//  Created by Carolina Oliveira & Isabel Castro on 21/11/2020
//
#include "refugioPiratas.h"

refugioPiratas::refugioPiratas(const string name) : territorio(name) {
	this->setName(name);
	this->setRes(9);
	this->setCreateGold(1);
	this->setCreateProd(0);
	this->setVictoryPoints(2);
}

refugioPiratas::~refugioPiratas() {
}

void refugioPiratas::setName(string name)
{
	static int a = 0;
	territorio::setName(getName() + std::to_string(a));
	name = (name + std::to_string(a));
	a++;
}