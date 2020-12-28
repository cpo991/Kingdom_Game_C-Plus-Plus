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


using namespace std;

class imperio
{
	int arm = 0, militar = 0, cofre = 0,pontos=0;
	vector <territorio*> territorio_imperio;
	//tecnologias

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

	//set/get de força militar
	int getMilitar() const;
	void setMilitar(int militar);

	//set/get de ouro no cofre
	int getCofre() const;
	void setCofre(int cofre);

	int getPontos() const;
	void setPontos(int pontos);

	//Obtem territorio conquistado
	string conquistaTerritorio(territorio* a);

	//Obtem descrição textual do império
	string getAsString();

	//Recolhe produtos e ouro
	int recolheProd();
};

#endif //TP_POO_IMPERIO_H