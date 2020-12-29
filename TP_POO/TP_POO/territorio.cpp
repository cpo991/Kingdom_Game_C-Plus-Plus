//
//  Created by Carolina Oliveira & Isabel Castro on 21/11/2020
//
#include "territorio.h"

territorio::territorio(const string name) : name(name) {
	this->setRes(1);
	this->setCreateGold(1);
	this->setCreateProd(1);
	this->setVictoryPoints(1);
}

territorio::territorio(const territorio& territori)
{
	this->setName(territori.getName());
	this->setRes(territori.getRes());
	this->setCreateProd(territori.getCreateProd());
	this->setCreateGold(territori.getCreateGold());
	this->setVictoryPoints(territori.getVictoryPoints());
}

territorio::~territorio()
{
}

string territorio::getType(string name) const {
	string type;
	name.pop_back();//elimina ultimo caracter
	type = name;
	return  type;
}

string territorio::getName() const
{
	return name;
}
void territorio::setName(string name)
{
	if (name == "territorioInicial") {
		this->name = "territorioInicial";
	}
	else {
		static int a = 0;
		this->name = name;
		a++;
	}
}

int territorio::getRes() const
{
	return res;
}
void territorio::setRes(int res)
{
	if (getType(this->name) == "territorioInicial") {
		this->res = 0;
	}
	else
		this->res = res;
}

int territorio::getCreateProd() const
{
	return createProd;
}
void territorio::setCreateProd(int prod)
{
	if (getType(this->name) == "territorioInicial") {
		this->createProd = 0;
	}
	else
		this->createProd = prod;
}

int territorio::getCreateGold() const
{
	return createGold;
}
void territorio::setCreateGold(int gold)
{
	if (getType(this->name) == "territorioInicial") {
		this->createGold = 0;
	}
	else
		this->createGold = gold;
}

int territorio::getVictoryPoints() const
{
	return victoryPoints;
}
void territorio::setVictoryPoints(int victoryPoints)
{
	if (getType(this->name) == "territorioInicial") {
		this->victoryPoints = victoryPoints;
	}
	else
		this->victoryPoints = victoryPoints;
}

string territorio::getAsString() const
{
	ostringstream oss;
	oss << "\no Nome do Territorio: " << name
		<< "\no Tipo de Territorio: " << this->getType(name)
		<< "\no Resistencia de conquista: " << res
		<< "\no Criacao de produtos: " << createProd
		<< "\no Criacao de ouro: " << createGold
		<< "\no Pontos que da: " << victoryPoints << endl;
	return oss.str();
}