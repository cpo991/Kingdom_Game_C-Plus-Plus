//
//  Created by Carolina Oliveira & Isabel Castro on 21/11/2020
//
#include "territorio.h"

//Construtor default
territorio::territorio(const string name) : name(name) {
	this->setRes(1);
	this->setCreateGold(1);
	this->setCreateProd(1);
	this->setVictoryPoints(1);
}

//Construtor por cópia
territorio::territorio(const territorio& territori)
{
	this->setName(territori.getName());
	this->setRes(territori.getRes());
	this->setCreateProd(territori.getCreateProd());
	this->setCreateGold(territori.getCreateGold());
	this->setVictoryPoints(territori.getVictoryPoints());
}

//Destrutor
territorio::~territorio()
{
}

//Tipo de território
string territorio::getType(string name) const {
	string type;
	name.pop_back();//elimina ultimo caracter
	type = name;
	return  type;
}

//Retorna o nome do territorio
string territorio::getName() const
{
	return name;
}

//Altera o nome do territorio
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

//Retorna o valor da resistencia do territorio
int territorio::getRes() const
{
	return res;
}

//Altera o valor da resistencia do territorio
void territorio::setRes(int res)
{
	if (getType(this->name) == "territorioInicial") {
		this->res = 0;
	}
	else
		this->res = res;
}

//Retorna o valor da criacao de produtos no territorio
int territorio::getCreateProd() const
{
	return createProd;
}

//Altera o valor da criacao de produtos no territorio
void territorio::setCreateProd(int prod)
{
	if (getType(this->name) == "territorioInicial") {
		this->createProd = 0;
	}
	else
		this->createProd = prod;
}

//Retorna o valor da criacao de ouro no territorio
int territorio::getCreateGold() const
{
	return createGold;
}

//Altera o valor da criacao de ouro no territorio
void territorio::setCreateGold(int gold)
{
	if (getType(this->name) == "territorioInicial") {
		this->createGold = 0;
	}
	else
		this->createGold = gold;
}

//Retorna o valor da pontuacao no territorio
int territorio::getVictoryPoints() const
{
	return victoryPoints;
}

//Altera o valor da pontuacao no territorio
void territorio::setVictoryPoints(int victoryPoints)
{
	if (getType(this->name) == "territorioInicial") {
		this->victoryPoints = victoryPoints;
	}
	else
		this->victoryPoints = victoryPoints;
}

//Descrição Textual do território
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