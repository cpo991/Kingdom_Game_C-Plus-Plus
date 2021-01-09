//
//  Created by Carolina Oliveira & Isabel Castro on 01/12/2020
//
#include "tecnologias.h"

tecnologias::tecnologias()
{
	this->setBanco(0);
	this->setBolsa(0);
	this->setDefesas(0);
	this->setDrones(0);
	this->setMisseis(0);
}

tecnologias::~tecnologias()
{
}

int tecnologias::getDrones() const
{
	return drones;
}

void tecnologias::setDrones(int drones)
{
	this->drones = drones;
}

int tecnologias::getMisseis() const
{
	return misseis;
}

void tecnologias::setMisseis(int misseis)
{
	this->misseis = misseis;
}

int tecnologias::getDefesas() const
{
	return defesas;
}

void tecnologias::setDefesas(int defesas)
{
	this->defesas = defesas;
}

int tecnologias::getBolsa() const
{
	return bolsa;
}

void tecnologias::setBolsa(int bolsa)
{
	this->bolsa = bolsa;
}

int tecnologias::getBanco() const
{
	return banco;
}

void tecnologias::setBanco(int banco)
{
	this->banco = banco;
}

string tecnologias::getAsString() const
{
	ostringstream oss;
	oss << "\n   o Drones: " << getDrones() << endl
		<< "   o Misseis: " << getMisseis() << endl
		<< "   o Defesas:  " << getDefesas() << endl
		<< "   o Bolsa: " << getBolsa() << endl
		<< "   o Banco: " << getBanco();
	return oss.str();
}