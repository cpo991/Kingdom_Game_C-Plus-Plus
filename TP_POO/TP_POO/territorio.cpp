//
//  Created by Carolina Oliveira & Isabel Castro on 21/11/2020
//
#include "territorio.h"

territorio::territorio(const string name, int res, int createProd, int createGold, int victoryPoints) :name(name), res(res), createGold(createGold), createProd(createProd), victoryPoints(victoryPoints)
{
}

//Construtor por cópia
territorio::territorio(const territorio& territori)
{
	setName(territori.getName());
	setRes(territori.getRes());
	setCreateProd(territori.getCreateProd());
	setCreateGold(territori.getCreateGold());
	setVictoryPoints(territori.getVictoryPoints());
}

//Tipo de território
string territorio::getType(string name) const {
	string type = "";
	int last = name.size();
	if (isdigit(last) == 0)
		type = name;
	else
		name.pop_back();//elimina ultimo caracter
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

//Destrutor
territorio::~territorio()
{
}