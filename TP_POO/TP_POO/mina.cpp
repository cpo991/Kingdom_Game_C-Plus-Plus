//
//  Created by Carolina Oliveira & Isabel Castro on 19/12/2020
//
#include "mina.h"

mina::mina(const string name) : territorio(name) {
	this->res = 5;
	this->createProd = 0;
	this->createGold = 1; // só nos primeiros 3 turnos de cada ano (?) passa para 2 nos seguundos 3 turnos do ano
	this->victoryPoints = 1;
}

mina::~mina() {

}

int mina::getRes() const
{
	return res;
}

int mina::getCreateProd() const
{
	return createProd;
}

int mina::getCreateGold() const
{
	return createGold;
}

int mina::getVictoryPoints() const
{
	return victoryPoints;
}
