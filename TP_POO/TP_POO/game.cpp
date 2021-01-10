//
//  Created by Carolina Oliveira & Isabel Castro on 29/11/2020
//
#include "game.h"
#include "territorioInicial.h"
#include "castelo.h"
#include "duna.h"
#include "fortaleza.h"
#include "mina.h"
#include "montanha.h"
#include "pescaria.h"
#include "planicie.h"
#include "refugioPiratas.h"

game::game() {
}

game::~game() {

}
const string game::addTerritory(string nome) {
	ostringstream oss;

	if (nome == "territorioInicial") {
		territorios.push_back(new territorioInicial(nome));
		setTerritorioDefault(nome);
	}
	else if (nome == "castelo") {
		territorios.push_back(new castelo(nome));
	}
	else if (nome == "duna") {
		territorios.push_back(new duna(nome));
	}
	else if (nome == "fortaleza") {
		territorios.push_back(new fortaleza(nome));
	}
	else if (nome == "mina") {
		territorios.push_back(new mina(nome));
	}
	else if (nome == "montanha") {
		territorios.push_back(new montanha(nome));
	}
	else if (nome == "pescaria") {
		territorios.push_back(new pescaria(nome));
	}
	else if (nome == "planicie") {
		territorios.push_back(new planicie(nome));
	}
	else if (nome == "refugioPiratas") {
		territorios.push_back(new refugioPiratas(nome));
	}
	return oss.str();
}

//Remove territorio ao NewGame(mundo)
bool game::removeTerritory(const string name) {
	ostringstream oss;
	for (auto it = territorios.begin(); it != territorios.end(); (it++)) {
		if ((*it)->getName() == name) {
			territorios.erase(it);
			return true;
		}
	}
	return false;
}

//Obter descri��o textual do NewGame
const string game::listaTerritorios() {
	ostringstream oss;

	//imperio* aux1;
	oss << "\n\n::::::::::::::::::::::::::::::::::::::::::::::::::::::::";
	oss << "\n:::::: LISTAGEM DE DADOS DO JOGO ATE AO MOMENTO ::::::::" << endl;
	oss << "::::::::::::::::::::::::::::::::::::::::::::::::::::::::"<<endl;
	oss << "\n ANO E TURNO DO JOGO " << endl;
	oss << "_____________________________________" << endl;
	oss << " ULTIMO FATOR SORTE: " << sorte_last << endl;
	oss << "_____________________________________" << endl;
	oss << " PROXIMO EVENTO:" << endl;
	oss << "_____________________________________" << endl;
	oss << " TOTAL PONTOS:" <<imperioU.getPontos()<<endl;
	oss << "_____________________________________" << endl;
	oss << " TECNOLOGIAS EXISTENTES " << imperioU.getAsStringT();
	oss << "_____________________________________" << endl;
	oss << "::::::::::::::::::::::::::::::::::::::::::::::::::::::::";
	oss << "\n::::::: TERRITORIOS NO MUNDO POR CONQUISTAR ::::::::::::" << endl;
	oss << "::::::::::::::::::::::::::::::::::::::::::::::::::::::::"<<endl;
	for (territorio* it : territorios) {
		oss << it->getAsString() << endl;
	}
	oss << endl;
	oss << imperioU.getAsString() << endl;
	return oss.str();
}

//Obter descri��o textual de Territorio x
const string game::listaTerritorios(string name) {
	ostringstream oss;
	vector <territorio*> aux;
	oss << "::::: DADOS DO TERRITORIO " << name << " :::::" << endl;
	for (territorio* it : territorios) {
		if ((it)->getName() == name) {
			oss << it->getAsString() << endl; //
			aux.push_back(it);
		}
	}
	return oss.str();
}

//Obter quantidade de territorios no mundo por conquistar
const size_t game::getSizeTerritorios() { return territorios.size(); }

//Obter um numero random entre min e max
int game::random(int low, int high) {
	if (low > high) return high;
	return low + (std::rand() % (high - low + 1));
}

//Adiciona um Territorio x do NewGame ao imperio
const string game::conquistaTerritorios(const string name)
{
	ostringstream oss;
	int sorte = 0, asd = 0;
	unsigned seed = time_t(0);
	srand(seed);
	
	sorte = random(1, 6);

	for (territorio* it : territorios) {
		if ((it)->getName() == name) {
			if (imperioU.getMilitar() + sorte >= it->getRes()) {
				oss << imperioU.conquistaTerritorio(it) << endl;; //copia o territorio para o imperio
				oss << removeTerritory(name); //elimina o territorio do vector do game
				oss << imperioU.getAsString();

				return oss.str();
			}
			else {
				imperioU.removeMilitar(1);
				oss << "Nao conquistou e reduziu em uma unidade a forca militar" << endl;
			}
		}
	}
	return oss.str();
}

//Adiciona um territorio inicial ao imp�rio
const string game::setTerritorioDefault(const string name)
{
	ostringstream oss;

	for (territorio* it : territorios) {
		if ((it)->getName() == name) {
			oss << imperioU.adicionaTerritorioInicial(it) << endl;; //copia o territorio para o imperio
			oss << removeTerritory(name); //elimina o territorio do vector do game
			oss << imperioU.getAsString();
			return oss.str();
		}
	}
	return oss.str();
}

//Confirma a existencia de um territorio x no mundo
const bool game::existTerritory(const string name) {
	for (territorio* it : territorios) {
		if ((it)->getName() == name) {
			return true;
		}
	}
	return false;
}

//Recolhe Produtos e Ouro de territorios conquistados por turno
const void game::recolheProdGold()
{
	imperioU.recolheProd();
}

//Aumentar a for�a militar via compra
const bool game::AumentaForca() {
	imperioU.setMilitar(imperioU.getMilitar() + 1);
	imperioU.removeProd(1);
	imperioU.removeOuro(1);
	return true;
}

//Compra Tecnologia <nome> para o imp�rio
/*const void game::AdicionaTecnologias(string nome) {
	imperioU.compraTecnologias(nome);
}*/

//Verifica se h� tecnologia <nome> no imp�rio comprada
const bool game::existeTecnologia(const string nome)
{
	if (imperioU.tecnologiasCompradas(nome) == true)
		return true;
	return false;
}

const bool game::maisOuro() {
	if (imperioU.getArm() > 2) {
		imperioU.setCofre(1);
		imperioU.removeProd(2);
		return true;
	}
	return false;
}

const bool game::maisProd()
{
	if (imperioU.getCofre() > 2) {
		imperioU.setArm(1);
		imperioU.removeOuro(2);
		return true;
	}
	return false;
}

//trocar para string e dizer aumentou x produtos/ouro  
/*const void game::recursoAbandonado(int turnos) {
	if (turnos < 6)
		imperioU.setArm(1);
	else
		imperioU.setCofre(1);
}

const string game::alianca() {
	ostringstream oss;
	imperioU.setMilitar(1);
	oss << "Formou uma alianca e ganhou uma unidade de forca militar" << endl;
	return oss.str();
}*/

//Guarda os dados do jogo num ficheiro de texto
void game::saveData(string filename) {
	ofstream file(filename);
	ostringstream oss;
	if (!file) {
		oss << "ERRO: Nao conseguiu abrir o ficheiro" << endl;
		return;
	}
	else {
		for (territorio* it : territorios) {
			file << it->getName() << endl;
			//oss << it->getAsString() << endl;
		}
		file << "" << endl;
		//imperioU.get     //get territorios do imperio
		file << "" << endl;
		file << imperioU.getArm() << endl;
		file << imperioU.getCofre() << endl;
		file << imperioU.getMilitar() << endl;
		file << imperioU.getPontos() << endl;
	}
	file.close();
}

//Carrega os dados do jogo num ficheiro de texto
void game::loadData(string filename) {
	ifstream file(filename);
	ostringstream oss;
	string line, type;
	int aux = 0;
	if (!file) {
		oss << "ERRO: Nao conseguiu abrir o ficheiro" << endl;
		return;
	}
	else {
		for (territorio* it : territorios) {
			removeTerritory(it->getName()); // apaga todos os territorios
		}
		while (getline(file, line))
		{
			do {
				line.pop_back();//elimina ultimo caracter
				type = line; // tem de se alterar a funcao setName para isto funcionar corretamente
				addTerritory(type);
				if (line.compare(""))
					aux++;
			} while (aux == 0); // ou com !
			do {
				//imperioU.conquistaTerritorio(line); //funcao cria em vez de conquista
				if (line.compare(""))
					aux++;
			} while (aux == 1);
			if (aux == 2) {
				imperioU.setArm(stoi(line));
				aux++;
			}
			if (aux == 3) {
				imperioU.setCofre(stoi(line));
				aux++;
			}
			if (aux == 4) {
				imperioU.setMilitar(stoi(line));
				aux++;
			}
			if (aux == 5) {
				imperioU.setPontos(stoi(line));
				aux++;
			}
		}
	}
	file.close();
}

//Aumentar a for�a militar via evento de alianca diplomatica
const bool game::AumentaForcaFase4() {
	if (imperioU.getMilitar() + 1 <= imperioU.getMaxMilitar()) {
		imperioU.setMilitar(imperioU.getMilitar() + 1);
		return true;
	}
	else
		return false;
}

//Aumenta o ouro em 1 unidade no evento recurso abandonado
const bool game::maisOuroFase4() {
	if (imperioU.getCofre() + 1 <= imperioU.getMaxCofre()) {
		imperioU.setCofre2(imperioU.getCofre() + 1);
		return true;
	}
	else
		return false;
}

//Aumenta o produto em 1 unidade no evento recurso abandonado
const bool game::maisProdFase4()
{
	if (imperioU.getArm() + 1 <= imperioU.getMaxArm()) {
		imperioU.setArm2(imperioU.getArm() + 1);
		return true;
	}
	else
		return false;
}

//Obtem nome do ultimo territorio conquistado
const string game::getLastTerritorioConquistado()
{
	return imperioU.getAsStringLastTerritorio();
}

//Obtem resistencia do ultimo territorio conquistado
const int game::getResLastTerritorioConquistado()
{
	return imperioU.getintResLastTerritorio();
}

//Remove territorio do imperio com o nome que recebe
const bool game::removeTerritoryImperio(string name)
{
	return imperioU.perdeTerritorio(name);
}

//Incrementa Resistencia do territorio que tem tecnologia de defesa
const bool game::incrementaRes(string name)
{
	return imperioU.incRes(name);
}

//Adiciona um Territorio x do NewGame ao imperio sem fator sorte
const string game::tomaTerritorio(const string name)
{
	ostringstream oss;
	for (territorio* it : territorios) {
		if ((it)->getName() == name) {
			oss << imperioU.conquistaTerritorio(it) << endl;; //copia o territorio para o imperio
			oss << removeTerritory(name); //elimina o territorio do vector do game
			oss << imperioU.getAsString();
			return oss.str();
		}
	}
	return oss.str();
}

//Compra tecnologia
const int game::getCompraTecnologia(string nome)
{
	return imperioU.compraTecnologia(nome);
}

//Adquire tecnologia fase 4 sem custos
const int game::getTomaTecnologia(string nome)
{
	return imperioU.tomaTecnologia(nome);
}

const int game::getPontos() {
	return imperioU.getPontos();
}

const int game::contaTecnologias() {
	return imperioU.contaTecnologias();
}

const bool game::modificaOuro(int num) {
	if (imperioU.getMaxCofre() < num) {
		imperioU.setCofre2(imperioU.getMaxCofre());
		return false;
	}
	else {
		imperioU.setCofre2(num);
		return true;
	}
}

const bool game::modificaProd(int num) {
	if (imperioU.getMaxArm() < num) {
		imperioU.setArm2(imperioU.getMaxCofre());
		return false;
	}
	else {
		imperioU.setArm2(num);
		return true;
	}
}

void game::altera(int ano, int turno) {
	return imperioU.altera(ano, turno+1);
}