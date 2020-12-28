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
	this->arm = arm;
}

//set/get de força militar
int imperio::getMilitar() const
{
	return militar;
}
void imperio::setMilitar(int militar)
{
	static int max_militar = 5;
	if (militar <= max_militar)
		this->militar = militar;
}

//set/get de ouro no cofre
int imperio::getCofre() const
{
	return cofre;
}
void imperio::setCofre(int cofre)
{
	this->cofre = cofre;
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

//Obtem descrição textual do império
string imperio::getAsString()
{
	ostringstream oss;
	oss << ":::: O SEU IMPERIO :::::" << endl;
	oss<< "\no Produtos em armazem: " << getArm() << endl;
	oss << "o Produtos no cofre: " << getCofre() << endl;
	oss<< "o Forca militar: " << getMilitar() << endl;
	oss<< "o Total de pontos: " << getPontos() << endl;
	oss << "o Territorios conquistados: " << endl;
	for (int i =0; i< territorio_imperio.size(); i++) {
		oss<<"   o "<< territorio_imperio[i]->getName() << endl;
	}
	return oss.str();
}

int imperio::recolheProd()
{
	ostringstream oss;
	int num = 0;
	for (int i = 0; i < territorio_imperio.size(); i++) {
		this->setCofre(getCofre()+territorio_imperio[i]->getCreateGold());
		this->setArm(getArm() + territorio_imperio[i]->getCreateProd());
		//num = num + territorio_imperio[i]->getCreateProd();
	}
	//cout << "\n\n TESTE DE PRODUTOS RECOLHIDOS NESTE TURNO: " << num << "\n\n" << endl;
	return num;
}
