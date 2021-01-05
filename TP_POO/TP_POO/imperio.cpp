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
	if (getArm() < MAX_ARM)

		this->arm += arm;
}
void imperio::removeProd(int prod)
{
	if (arm > 0)
		this->arm -= prod;
	else
		arm = 0;
}

//set/get de for�a militar
int imperio::getMilitar() const
{
	return militar;
}
void imperio::setMilitar(int militar)
{
	if (militar < MAX_MILITAR)
		this->militar += militar;
}
void imperio::removeMilitar(int forca) {
	if (militar > 0)
		this->militar -= forca;
	else
		militar = 0; //this->militar = 0;
}

//set/get de ouro no cofre
int imperio::getCofre() const
{
	return cofre;
}
void imperio::setCofre(int cofre)
{
	if (getCofre() < MAX_COFRE)
		this->cofre += cofre;
}

void imperio::removeOuro(int ouro)
{
	if (cofre > 0)
		this->cofre -= ouro;
	else
		cofre = 0;
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
string imperio::adicionaTerritorioInicial(territorio* a) {
	ostringstream oss;
	if (a == nullptr) {
		oss << "\n >>> Territorio inicial invalido!" << endl;
		return oss.str();
	}

	territorio_imperio.push_back(a);
	this->setArm(getArm() + a->getCreateProd());
	this->setCofre(getCofre() + a->getCreateGold());
	this->setPontos(getPontos() + a->getVictoryPoints());
	return oss.str();
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
	this->setPontos(getPontos() + a->getVictoryPoints());

	oss << "\n>>> Territorio " << a->getName() << " conquistado!" << endl;
	return oss.str();
}

//Obtem descri��o textual do imp�rio
string imperio::getAsString()
{
	ostringstream oss;
	oss << "::::::::::::::::::::::::::::::::::::::::::::::::::::::::";
	oss << "\n:::::::::::::::: O SEU IMPERIO :::::::::::::::::::::::::" << endl;
	oss << "::::::::::::::::::::::::::::::::::::::::::::::::::::::::" << endl;
	oss << "\no Produtos em armazem: " << getArm() << endl;
	oss << "_____________________________________" << endl;
	oss << "o Produtos no cofre: " << getCofre() << endl;
	oss << "_____________________________________" << endl;
	oss << "o Forca militar: " << getMilitar() << endl;
	oss << "_____________________________________" << endl;
	oss << "o Total de pontos: " << getPontos() << endl;
	oss << "_____________________________________" << endl;
	oss << "o Territorios conquistados: " << endl;
	for (int i = 0; i < territorio_imperio.size(); i++) {
		oss << "   o " << territorio_imperio[i]->getName() << endl;
	}
	oss << "_____________________________________" << endl;
	oss << "o Tecnologias: ";
	oss << this->getAsStringT();
	oss << "_____________________________________" << endl;
	return oss.str();
}

//Obtem descri��o textual das tecnologias do imp�rio APENAS
string imperio::getAsStringT()
{
	ostringstream oss;
	oss << a.getAsString() << endl;
	return oss.str();
}

bool imperio::tecnologiasCompradas(string nome)
{
	if (nome == "drones") {
		if (a.getDrones() == 1)
			return true;
	}
	else if (nome == "misseis") {
		if (a.getMisseis() > 0)
			return true;
	}
	else if (nome == "defesas") {
		if (a.getDefesas() > 0)
			return true;
	}
	else if (nome == "bolsa") {
		if (a.getBolsa() == 1)
			return true;
	}
	else if (nome == "banco") {
		if (a.getBanco() == 1)
			return true;
	}
	return false;
}

//Recolhe produtos e ouro para cada turno
void imperio::recolheProd()
{
	for (int i = 0; i < territorio_imperio.size(); i++) {
		setCofre(territorio_imperio[i]->getCreateGold());
		setArm(territorio_imperio[i]->getCreateProd());
	}
	if (this->getArm() == MAX_ARM)
		cout << "\nAVISO: Produtos a serem desperdicados!" << endl;
	if (this->getCofre() == MAX_COFRE)
		cout << "\nAVISO: Ouro a ser desperdicado!" << endl;
	if (this->getMilitar() == MAX_MILITAR)
		cout << "\nAVISO: Nao ha capacidade para aumentar a forca militar" << endl;
}

//Adiciona tecnologia <nome> ao imp�rio
string imperio::compraTecnologias(string nome)
{
	static int nrCompras = 0;
	ostringstream oss;
	if (nome == "drones" && getCofre() >= 3) {
		a.setDrones(a.getDrones() + 1);
		pontos++;
		MAX_MILITAR = 5;
		nrCompras++;
		cofre = getCofre() - 3;
	}

	if (nome == "misseis" && getCofre() > 4) {
		a.setMisseis(a.getMisseis() + 1);
		pontos++;
		nrCompras++;
		cofre = getCofre() - 4;
	}

	if (nome == "defesas" && this->getCofre() > 4) {
		a.setDefesas(a.getDefesas() + 1);
		pontos++;
		nrCompras++;
		cofre = getCofre() - 4;
	}
	//AUMENTAR RESISTENCIA A TERRITORIO QUE FOR INVADIDO

	if (nome == "bolsa" && getCofre() > 2) {
		a.setBolsa(a.getBolsa() + 1);
		pontos++;
		nrCompras++;
		cofre = getCofre() - 2;
	}
	if (nome == "banco" && getCofre() > 3) {
		a.setBanco(1);
		MAX_COFRE = 5;
		MAX_ARM = 5;
		pontos++;
		nrCompras++;
		cofre = getCofre() - 3;
	}

	if (nrCompras == 5)
		setPontos(getPontos() + 1);
	oss << this->getAsStringT();
	return oss.str();
}

string imperio::getAsStringLastTerritorio()
{
	ostringstream oss;
	int aux = 0;
	for (int i = 0; i < territorio_imperio.size(); i++) {
		aux = i;
	}
	return territorio_imperio[aux]->getName();
}

int imperio::getintResLastTerritorio()
{
	ostringstream oss;
	int aux = 0;
	for (int i = 0; i < territorio_imperio.size(); i++) {
		aux = i;
	}
	return territorio_imperio[aux]->getRes();
}