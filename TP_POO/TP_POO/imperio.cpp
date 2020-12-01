//
//  Created by Carolina Oliveira & Isabel Castro on 21/11/2020
//
#include "imperio.h"

int max_militar = 5;

imperio::imperio(const imperio& a)
{
	for (auto it = t.begin(); it < t.end(); it++) {
		this->setCofre((*it)->getCreateGold());
		this->setArm((*it)->getCreateProd());
	}
	this->setMilitar(0);
}

imperio::~imperio()
{
}

int imperio::getArm() const
{
	return arm;
}

void imperio::setArm(int arm)
{
	this->arm = arm;
}

int imperio::getMilitar() const
{
	return militar;
}

void imperio::setMilitar(int militar)
{
	if (militar <= max_militar)
		this->militar = militar;
}

int imperio::getCofre() const
{
	return cofre;
}

void imperio::setCofre(int cofre)
{
	this->cofre = cofre;
}
