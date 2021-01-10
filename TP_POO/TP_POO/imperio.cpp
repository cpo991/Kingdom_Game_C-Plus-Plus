//
//  Created by Carolina Oliveira & Isabel Castro on 21/11/2020
//
#include "imperio.h"

imperio::~imperio()
{
}

int imperio::getMaxMilitar() const {
	return MAX_MILITAR;
}

int imperio::getMaxCofre()const {
	return MAX_COFRE;
}

int imperio::getMaxArm()const {
	return MAX_ARM;
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

void imperio::setArm2(int num) {
	this->arm = num;
}

void imperio::removeProd(int prod)
{
	if (arm > 0)
		this->arm -= prod;
	else
		arm = 0;
}

//set/get de força militar
int imperio::getMilitar() const
{
	return militar;
}
void imperio::setMilitar(int militar)
{
	if ((this->militar + militar) >= MAX_MILITAR) {
		this->militar = MAX_MILITAR;
	}
	else {
		this->militar += militar;
	}
	//if (militar < MAX_MILITAR)
		
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

void imperio::setCofre2(int num) {
	this->cofre = num;
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
	this->setArm2(getArm());
	this->setCofre2(getCofre());

	oss << "\n>>> Territorio " << a->getName() << " conquistado!" << endl;
	return oss.str();
}

//Obtem descrição textual do império
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

//Obtem descrição textual das tecnologias do império APENAS
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

//Adiciona tecnologia <nome> ao império
/*string imperio::compraTecnologias(string nome)
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
}*/

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

bool imperio::perdeTerritorio(string name)
{
	ostringstream oss;
	for (auto it = territorio_imperio.begin(); it != territorio_imperio.end(); (it++)) {
		if ((*it)->getName() == name) {
			territorio_imperio.erase(it);
			return true;
		}
	}
	return false;
}

bool imperio::incRes(string name)
{
	ostringstream oss;
	int actualRes = 0;
	for (auto it = territorio_imperio.begin(); it != territorio_imperio.end(); (it++)) {
		if ((*it)->getName() == name) {
			actualRes = (*it)->getRes();
			(*it)->setRes(actualRes + 1);
			return true;
		}
	}
	return false;
}

//Adiciona tecnologia <nome> ao império
int imperio::compraTecnologia(string nome) {
	static int nrCompras = 0;
	ostringstream oss;
	if (nome == "drones") {
		if (getCofre() >= 3) {
			a.setDrones(a.getDrones() + 1);
			pontos++;
			MAX_MILITAR = 5;
			cofre = getCofre() - 3;
			return 999;
		}
		else return (3-getCofre());
	}
	if (nome == "misseis") {
		if (getCofre() >= 4) {
			a.setMisseis(a.getMisseis() + 1);
			pontos++;
			cofre = getCofre() - 4;
			return 999;
		}
		else return getCofre();
	}
	if (nome == "defesas") {
		if (getCofre() >= 4) {
			a.setDefesas(a.getDefesas() + 1);
			pontos++;
			cofre = getCofre() - 4;
			return 999;
		}
		else return (4 - getCofre());
		
	}
	if (nome == "bolsa") {
		if (getCofre() >= 2) {
			a.setBolsa(a.getBolsa() + 1);
			pontos++;
			cofre = getCofre() - 2;
			return 999;
		}
		else return (2 - getCofre());
	}
	if (nome == "banco") {
		if (getCofre() >= 3) {
			a.setBanco(1);
			MAX_COFRE = 5;
			MAX_ARM = 5;
			pontos++;
			cofre = getCofre() - 3;
			return 999;
		}
		else return (3 - getCofre());
	}
	return 0;
}

//Adiciona tecnologia <nome> ao império Fase 4
int imperio::tomaTecnologia(string nome) {
	static int nrCompras = 0;
	ostringstream oss;
	if (nome == "drones") {
		a.setDrones(a.getDrones() + 1);
		pontos++;
		MAX_MILITAR = 5;
		return 1;
	}
	if (nome == "misseis") {
		a.setMisseis(a.getMisseis() + 1);
		pontos++;
		return 1;
	}
	if (nome == "defesas") {
		a.setDefesas(a.getDefesas() + 1);
		pontos++;
		return 1;
	}
	if (nome == "bolsa") {
		a.setBolsa(a.getBolsa() + 1);
		pontos++;
		return 1;
	}
	if (nome == "banco") {
		a.setBanco(1);
		MAX_COFRE = 5;
		MAX_ARM = 5;
		pontos++;
		return 1;
	}
	return 0;
}

int imperio::contaTecnologias()
{
	int total = 0;
	total = a.getDrones() + a.getMisseis() + a.getDefesas() + a.getBolsa() + a.getBanco();
	return total;
}

void imperio::altera(int ano, int turno) {
	string name;
	//Castelo passa a produzir 1
	if ((ano == 1 && (turno <= 2 && turno >=1 )) || (ano == 2 && (turno <= 2 && turno >= 1))) {
		for (int i = 0; i < territorio_imperio.size(); i++) {
			name = territorio_imperio[i]->getName();
			if (territorio_imperio[i]->getType(name) == "castelo") {
				territorio_imperio[i]->setCreateGold(1);
			}
		}
	}
	//Castelo passa a produzir 0
	if ((ano == 1 && (turno <= 6 && turno >= 3)) || (ano == 2 && (turno <= 6 && turno >= 3))) {
		for (int i = 0; i < territorio_imperio.size(); i++) {
			name = territorio_imperio[i]->getName();
			if (territorio_imperio[i]->getType(name) == "castelo") {
				territorio_imperio[i]->setCreateGold(0);
			}
		}
	}
	//Mina passa a produzir 1
	if ((ano == 1 && (turno <= 3 && turno >= 1)) || (ano == 2 && (turno <= 3 && turno >= 1))) {
		for (int i = 0; i < territorio_imperio.size(); i++) {
			name = territorio_imperio[i]->getName();
			if (territorio_imperio[i]->getType(name) == "mina") {
				territorio_imperio[i]->setCreateGold(1);
			}
		}
	}
	//Mina passa a produzir 2
	if (ano == 1 && (turno <= 6 && turno >= 4) || (ano == 2 && (turno <= 6 && turno >= 4))) {
		for (int i = 0; i < territorio_imperio.size(); i++) {
			name = territorio_imperio[i]->getName();
			if (territorio_imperio[i]->getType(name) == "mina") {
				territorio_imperio[i]->setCreateGold(2);
			}
		}
	}
}