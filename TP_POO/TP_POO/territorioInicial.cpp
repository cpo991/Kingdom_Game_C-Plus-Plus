//
//  Created by Carolina Oliveira & Isabel Castro on 19/12/2020
//
#include "territorioInicial.h"

territorioInicial::territorioInicial(const string name) : territorio(name) {
	this->setRes(9);
	this->setCreateGold(1);
	this->setCreateProd(1);
	this->setVictoryPoints(0);
}

territorioInicial::~territorioInicial() {
}

void territorioInicial::setName(string name)
{
	static int a = 0;
	territorio::setName(getName() + std::to_string(a));
	name = (name + std::to_string(a));
	a++;
}