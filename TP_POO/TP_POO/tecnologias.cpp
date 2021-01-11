//
//  Created by Carolina Oliveira & Isabel Castro on 01/12/2020
//
#include "tecnologias.h"

//Construtor
tecnologias::tecnologias()
{
	this->setBanco(0);
	this->setBolsa(0);
	this->setDefesas(0);
	this->setDrones(0);
	this->setMisseis(0);
}

//Destrutor
tecnologias::~tecnologias()
{
}

//Retorna o numero de drones
int tecnologias::getDrones() const
{
	return drones;
}

//Altera o numero de drones
void tecnologias::setDrones(int drones)
{
	this->drones = drones;
}

//Retorna o numero de misseis
int tecnologias::getMisseis() const
{
	return misseis;
}

//Altera o numero de misseis
void tecnologias::setMisseis(int misseis)
{
	this->misseis = misseis;
}

//Retorna o numero de defesas
int tecnologias::getDefesas() const
{
	return defesas;
}

//Altera o numero de defesas
void tecnologias::setDefesas(int defesas)
{
	this->defesas = defesas;
}

//Retorna o numero de bolsa
int tecnologias::getBolsa() const
{
	return bolsa;
}

//Altera o numero de bolsa
void tecnologias::setBolsa(int bolsa)
{
	this->bolsa = bolsa;
}

//Retorna o numero de banco
int tecnologias::getBanco() const
{
	return banco;
}

//Altera o numero de banco
void tecnologias::setBanco(int banco)
{
	this->banco = banco;
}

//Imprime a informacao sobre as tecnologias adquiridas
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