//
//  Created by Carolina Oliveira & Isabel Castro on 19/12/2020
//
#include "mina.h"

mina::mina(const string name) : territorio(name) {
	this->setName(name);
	this->setRes(5);
	this->setCreateProd(0);
	this->setCreateGold(1); // só nos primeiros 3 turnos de cada ano (?) passa para 2 nos seguundos 3 turnos do ano
	this->setVictoryPoints(1);
}

mina::~mina() {
}

void mina::setName(string name)
{
	static int a = 0;
	territorio::setName(getName() + std::to_string(a));
	name = (name + std::to_string(a));
	a++;
}

/*void mina::setCreateGold(int gold) {
	this->setCreateGold(gold);
}*/