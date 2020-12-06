//
//  Created by Carolina Oliveira & Isabel Castro on 21/11/2020
//
#include "imperio.h"

int max_militar = 5;

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

string imperio::conquistaTerritorio(territorio* a)
{
	ostringstream oss;
	if (a == nullptr) {
		oss << "Territorio invalido!" << endl;
		return oss.str();
	}

	setArm(getArm() + (a->getCreateProd()));
	setCofre(getCofre() + (a->getCreateGold()));
	territorio_imperio.push_back(a);
	oss << "Territorio " << a->getName() << " movido para o imperio" << endl;
	return oss.str();
}

string imperio::getAsString()
{
	ostringstream oss;
	
	oss<< "Produtos em armazem:" << getArm() << endl;
	oss<< "Forca militar:" << getMilitar() << endl;
	oss<< "Produtos no cofre:" << getCofre() << endl;
	for (int i =0; i< territorio_imperio.size(); i++) {
		oss <<"Territorios conquistados: " <<territorio_imperio[i]->getName() << endl;
	}
	return oss.str();
}
