//
//  Created by Carolina Oliveira & Isabel Castro on 19/12/2020
//
#include "territorioInicial.h"

territorioInicial::territorioInicial(const string name) : territorio(name){
	this->res = 9;
	this->createProd = 1;
	this->createGold = 1;
	this->victoryPoints = 0;
}

territorioInicial::~territorioInicial(){

}

int territorioInicial::getRes() const
{
	return res;
}

int territorioInicial::getCreateProd() const
{
	return createProd;
}

int territorioInicial::getCreateGold() const
{
	return createGold;
}

int territorioInicial::getVictoryPoints() const
{
	return victoryPoints;
}
