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

	oss << "\n:::::: LISTAGEM DE DADOS DO JOGO ATE AO MOMENTO ::::::::" << endl;
	oss << "\n:::::: TERRITORIOS NO MUNDO POR CONQUISTAR :::::::::" << endl;
	for (territorio* it : territorios) {
		oss << it->getAsString() << endl;
	}
	oss << "\n";
	oss << imperioU.getAsString() << endl;

	oss << "--ANO E TURNO DO JOGO--" << endl;
	oss << "ULTIMO FATOR SORTE--" << sorte_last << endl;
	//oss << "--TECNOLOGIAS EXISTENTES--" << endl;
	//oss << "--PROXIMO EVENTO--" << endl;
	//oss << "--TOTAL PONTOS--" << endl;

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

//Adiciona um Territorio x do NewGame ao imperio
const string game::conquistaTerritorios(const string name)
{
	srand((unsigned)time(0));
	int sorte;
	for (int z = 0; z < 6; z++) {
		sorte = (rand() % 10) + 1;
	}

	sorte_last = sorte;
	ostringstream oss;

	for (territorio* it : territorios) {
		if ((it)->getName() == name) {
			if (imperioU.getMilitar() + sorte >= it->getRes()) {
				oss << imperioU.conquistaTerritorio(it) << endl;; //copia o territorio para o imperio
				oss << removeTerritory(name); //elimina o territorio do vector do game
				oss << imperioU.getAsString();

				return oss.str();
			}
			else {
				imperioU.setMilitar(imperioU.getMilitar() - 1);
				if (imperioU.getMilitar() < 0)
					imperioU.setMilitar((imperioU.getMilitar() < 0) ? 0 : imperioU.getMilitar());
				oss << "Nao conquistou e reduziu em uma unidade a forca militar" << endl;
			}
		}
	}
	oss << "\n>>> Nao conquistou  " << name << endl;
	return oss.str();
}

//Adiciona um territorio inicial ao imp�rio
const string game::setTerritorioDefault(const string name)
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

//Confirma a existencia de um territorio x no mundo
bool game::existTerritory(const string name) {
	for (territorio* it : territorios) {
		if ((it)->getName() == name) {
			return true;
		}
	}
	return false;
}

//Recolhe Produtos e Ouro de territorios conquistados por turno
bool game::recolheProdGold()
{
	imperioU.recolheProd();
	return true;
}

//Aumentar a for�a militar via compra
const bool game::AumentaForca() {
	imperioU.setMilitar(imperioU.getMilitar() + 1);
	//Nao me lembro do porque de ter posto isto embaixo
	imperioU.setArm(imperioU.getArm() - 1);
	imperioU.setCofre(imperioU.getCofre() - 1);
	return true;
}

//Compra Tecnologia <nome> para o imp�rio
const void game::AdicionaTecnologias(string nome) {
	imperioU.compraTecnologias(nome);
}
//
//bool game::existeTecnologia(const string name) {
//
//	a.
//	return false;
//}