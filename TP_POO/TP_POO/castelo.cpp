//
//  Created by Carolina Oliveira & Isabel Castro on 19/12/2020
//
#include "castelo.h"

castelo::castelo(const string name):territorio(name){
	setName(name);
	this->setRes(7);
	this->setCreateGold(1); // só nos primeiros 2 turnos de cada ano (?)
	this->setCreateProd(3);
	this->setVictoryPoints(1);
}

castelo::~castelo() {

}

void castelo::setName(string name)
{
	static int a = 0;
	territorio::setName(getName() + std::to_string(a));
	name=(name+std::to_string(a));
	a++;
}




