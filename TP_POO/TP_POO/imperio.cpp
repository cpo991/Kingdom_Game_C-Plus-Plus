//
//  Created by Carolina Oliveira & Isabel Castro on 21/11/2020
//
#include "imperio.h"

imperio::~imperio()
{
}

//Retorna o valor do MAX_MILITAR
int imperio::getMaxMilitar() const {
	return MAX_MILITAR;
}

//Retorna o valor do MAX_COFRE
int imperio::getMaxCofre()const {
	return MAX_COFRE;
}

//Retorna o valor do MAX_ARM
int imperio::getMaxArm()const {
	return MAX_ARM;
}

//Retorna o numero de produtos no armazem
int imperio::getArm() const
{
	return arm;
}

//Incrementa o numero de produtos no armazem
void imperio::setArm(int arm)
{
	if (getArm() < MAX_ARM)

		this->arm += arm;
}

//Altera o numero de produtos no armazem
void imperio::setArm2(int num) {
	this->arm = num;
}

//Decrementa o numero de produtos no armazem
void imperio::removeProd(int prod)
{
	if (arm > 0)
		this->arm -= prod;
	else
		arm = 0;
}

//Retorna o numero de forca militar
int imperio::getMilitar() const
{
	return militar;
}

//Incrementa o numero de forca militar
void imperio::setMilitar(int militar)
{
	if ((this->militar + militar) >= MAX_MILITAR) {
		this->militar = MAX_MILITAR;
	}
	else
		this->militar += militar;
}

//Decrementa o numero de forca militar
void imperio::removeMilitar(int forca) {
	if (militar > 0)
		this->militar -= forca;
	else
		this->militar = 0;
}

//Retorna o numero de ouro no cofre
int imperio::getCofre() const
{
	return cofre;
}

//Incrementa o numero de ouro no cofre
void imperio::setCofre(int cofre)
{
	if (getCofre() < MAX_COFRE)
		this->cofre += cofre;
}

//Altera o numero de ouro no cofre
void imperio::setCofre2(int num) {
	this->cofre = num;
}

//Decrementa o numero de ouro no cofre
void imperio::removeOuro(int ouro)
{
	if (cofre > 0)
		this->cofre -= ouro;
	else
		cofre = 0;
}

//Retorna o numero de pontos totais
int imperio::getPontos() const
{
	return pontos;
}

//Retorna o numero de pontos totais
void imperio::setPontos(int pontos)
{
	this->pontos = pontos;
}

//Cria o territorioInicial no imperio
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

//Devolve true se houver tecnologia x comprada
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

//Obtem nome do ultimo territorio conquistado
string imperio::getAsStringLastTerritorio()
{
	ostringstream oss;
	int aux = 0;
	for (int i = 0; i < territorio_imperio.size(); i++) {
		aux = i;
	}
	return territorio_imperio[aux]->getName();
}

//Obtem resistencia do ultimo territorio conquistado
int imperio::getintResLastTerritorio()
{
	ostringstream oss;
	int aux = 0;
	for (int i = 0; i < territorio_imperio.size(); i++) {
		aux = i;
	}
	return territorio_imperio[aux]->getRes();
}

//Remove territorio do imperio com o nome que recebe
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

//Incrementa a resistencia do territorio
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
			return 1;
		}
		else return (3-getCofre());
	}
	if (nome == "misseis") {
		if (getCofre() >= 4) {
			a.setMisseis(a.getMisseis() + 1);
			pontos++;
			cofre = getCofre() - 4;
			return 1;
		}
		else return getCofre();
	}
	if (nome == "defesas") {
		if (getCofre() >= 4) {
			a.setDefesas(a.getDefesas() + 1);
			pontos++;
			cofre = getCofre() - 4;
			return 1;
		}
		else return (4 - getCofre());
		
	}
	if (nome == "bolsa") {
		if (getCofre() >= 2) {
			a.setBolsa(a.getBolsa() + 1);
			pontos++;
			cofre = getCofre() - 2;
			return 1;
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
			return 1;
		}
		else return (3 - getCofre());
	}
	return 0;
}

//Adquire tecnologia fase 4 sem custos
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

//Retorna o numero de tecnologias adquiridas
int imperio::contaTecnologias()
{
	int total = 0;
	total = a.getDrones() + a.getMisseis() + a.getDefesas() + a.getBolsa() + a.getBanco();
	return total;
}

//Altera a quantidade de ouro produzida pelo castelo e mina
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