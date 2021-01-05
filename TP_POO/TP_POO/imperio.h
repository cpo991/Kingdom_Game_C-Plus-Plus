//
//  Created by Carolina Oliveira & Isabel Castro on 21/11/2020
//
#ifndef TP_POO_IMPERIO_H
#define TP_POO_IMPERIO_H

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "territorio.h"
#include "tecnologias.h"
static int MAX_MILITAR = 3;
static int MAX_COFRE = 3;
static int MAX_ARM = 3;

using namespace std;

class imperio
{
	int arm = 0, militar = 0, cofre = 0, pontos = 0;
	vector <territorio*> territorio_imperio;
	tecnologias a;

public:
	//construtor
	imperio() :arm(0), militar(0), cofre(0) {
		for (auto it = territorio_imperio.begin(); it != territorio_imperio.end(); it++) {
			(*it)->getName();
		}
	};

	//destrutor
	~imperio();

	//set/get de produtos no armazem
	int getArm() const;
	void setArm(int arm);
	void removeProd(int prod);

	//set/get de força militar
	int getMilitar() const;
	void setMilitar(int militar);
	void removeMilitar(int forca);

	//set/get de ouro no cofre
	int getCofre() const;
	void setCofre(int cofre);
	void removeOuro(int ouro);

	//set/get de pontos totais
	int getPontos() const;
	void setPontos(int pontos);

	//Cria o territorioInicial no imperio
	string adicionaTerritorioInicial(territorio* a);

	//Obtem territorio conquistado
	string conquistaTerritorio(territorio* a);

	//Recolhe produtos e ouro
	void recolheProd();

	//Adiciona tecnologias compradas ao imperio
	string compraTecnologias(string nome);

	string getAsStringLastTerritorio();

	int getintResLastTerritorio();

	//Devolve true se houver tecnologia x comprada
	bool tecnologiasCompradas(string nome);

	//Obtem descrição textual do império
	string getAsString();

	//Obtem descrição textual apenas dos territorios no imperio
	string getAsStringT();
};

#endif //TP_POO_IMPERIO_H