//
//  Created by Carolina Oliveira & Isabel Castro on 21/11/2020
//
#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "territorio.h"


using namespace std;
extern int max_militar;

class imperio
{
	int arm = 0, militar = 0, cofre = 0;
	vector <territorio*> t;
	//tecnologias

public:
	//construtor default
	imperio() :arm(0), militar(0), cofre(0) {};
	//construtror de territorio copia
	imperio(const imperio& a);
	//destrutor
	~imperio();

	int getArm() const;
	void setArm(int arm);

	int getMilitar() const;
	void setMilitar(int militar);

	int getCofre() const;
	void setCofre(int cofre);
	const string conquistaTerritorio(string name);
	string getAsString();
};

//ostream& operator<<(ostream& out, const territorio& ref);