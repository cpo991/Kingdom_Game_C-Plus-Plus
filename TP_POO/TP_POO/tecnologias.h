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
	//Construtor
	tecnologias();
	
	//Destrutor
	~tecnologias();

	//Retorna o numero de drones
	int getDrones() const;

	//Altera o numero de drones
	void setDrones(int drones);

	//Retorna o numero de misseis
	int getMisseis() const;

	//Altera o numero de misseis
	void setMisseis(int misseis);

	//Retorna o numero de defesas
	int getDefesas() const;

	//Altera o numero de defesas
	void setDefesas(int defesas);

	//Retorna o numero de bolsa
	int getBolsa() const;

	//Altera o numero de bolsa
	void setBolsa(int bolsa);

	//Retorna o numero de banco
	int getBanco() const;

	//Altera o numero de banco
	void setBanco(int banco);

	//Imprime a informacao sobre as tecnologias adquiridas
	string getAsString() const;
};

#endif //TP_POO_TECNOLOGIAS_H
