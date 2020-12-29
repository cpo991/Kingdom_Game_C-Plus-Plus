//
//  Created by Carolina Oliveira & Isabel Castro on 01/12/2020
//
#ifndef TP_POO_TECNOLOGIAS_H
#define TP_POO_TECNOLOGIAS_H

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

class tecnologias
{
	int drones=0; //custa 3
	int misseis = 0; //custa 4
	int defesas = 0; //custa 4
	int bolsa = 0; //custa 2
	int banco = 0; //custa 3
public:
	tecnologias();
	~tecnologias();

	int getDrones() const;
	void setDrones(int drones);

	int getMisseis() const;
	void setMisseis(int misseis);

	int getDefesas() const;
	void setDefesas(int defesas);

	int getBolsa() const;
	void setBolsa(int bolsa);

	int getBanco() const;
	void setBanco(int banco);

	string getAsString() const;
};

#endif //TP_POO_TECNOLOGIAS_H
