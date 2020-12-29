//
//  Created by Carolina Oliveira & Isabel Castro on 21/11/2020
//
#include "imperio.h"

imperio::~imperio()
{
}

//set/get de produtos no armazem
int imperio::getArm() const
{
	return arm;
}
void imperio::setArm(int arm)
{
	if (getArm() < 3)
		this->arm = arm;
	else
		cout << "Produtos a serem desperdicados!" << endl;
}

//set/get de for�a militar
int imperio::getMilitar() const
{
	return militar;
}
void imperio::setMilitar(int militar)
{
	if (militar <= MAX_MILITAR)
		this->militar = militar;
}

//set/get de ouro no cofre
int imperio::getCofre() const
{
	return cofre;
}
void imperio::setCofre(int cofre)
{
	if (getCofre() < 3)
		this->cofre = cofre;
	else
		cout << "Produtos a serem desperdicados!" << endl;
}

//set/get de pontos totais
int imperio::getPontos() const
{
	return pontos;
}
void imperio::setPontos(int pontos)
{
	this->pontos = pontos;
}

//Obtem territorio conquistado
string imperio::conquistaTerritorio(territorio* a)
{
	ostringstream oss;
	if (a == nullptr) {
		oss << "\n >>> Territorio invalido!" << endl;
		return oss.str();
	}

	territorio_imperio.push_back(a);
	this->setArm(getArm() + a->getCreateProd());
	this->setCofre(getCofre() + a->getCreateGold());
	this->setPontos(getPontos() + a->getVictoryPoints());

	oss << "\n>>> Territorio " << a->getName() << " conquistado!" << endl;
	return oss.str();
}

//Obtem descri��o textual do imp�rio
string imperio::getAsString()
{
	ostringstream oss;
	oss << ":::: O SEU IMPERIO :::::" << endl;
	oss << "\no Produtos em armazem: " << getArm() << endl;
	oss << "o Produtos no cofre: " << getCofre() << endl;
	oss << "o Forca militar: " << getMilitar() << endl;
	oss << "o Total de pontos: " << getPontos() << endl;
	oss << "o Territorios conquistados: " << endl;
	for (int i = 0; i < territorio_imperio.size(); i++) {
		oss << "   o " << territorio_imperio[i]->getName() << endl;
	}
	return oss.str();
}

//Obtem descri��o textual das tecnologias do imp�rio APENAS
string imperio::getAsStringT()
{
	ostringstream oss;
	a.getAsString();
	return oss.str();
}

//Recolhe produtos e ouro para cada turno
void imperio::recolheProd()
{
	for (int i = 0; i < territorio_imperio.size(); i++) {
		this->setCofre(getCofre() + territorio_imperio[i]->getCreateGold());
		this->setArm(getArm() + territorio_imperio[i]->getCreateProd());
	}
}

//Adiciona tecnologia <nome> ao imp�rio
string imperio::compraTecnologias(string nome)
{
	static int nrCompras = 0;
	ostringstream oss;
	if (nome == "Drones" && this->getCofre() > 3) {
		a.setDrones(a.getDrones() + 1);
		pontos++;
		MAX_MILITAR = 5;
		nrCompras++;
	}

	if (nome == "Misseis" && this->getCofre() > 4) {
		a.setMisseis(a.getMisseis() + 1);
		pontos++;
		nrCompras++;
	}

	if (nome == "Defesas" && this->getCofre() > 4) {
		a.setDefesas(a.getDefesas() + 1);
		pontos++;
		nrCompras++;
	}
	//AUMENTAR RESISTENCIA A TERRITORIO QUE FOR INVADIDO

	if (nome == "Bolsa" && this->getCofre() > 2) {
		a.setBolsa(a.getBolsa() + 1);
		pontos++;
		nrCompras++;
	}
	if (nome == "Banco" && this->getCofre() > 3) {
		a.setBanco(1);
		MAX_COFRE = 5;
		MAX_ARM = 5;
		pontos++;
		nrCompras++;
	}

	if(nrCompras==5)
		setPontos(this->getPontos() + 1);
	oss << this->getAsStringT();
	return oss.str();
}
