//
//  Created by Carolina Oliveira & Isabel Castro on 21/11/2020
//
#ifndef TP_POO_TERRITORIO_H
#define TP_POO_TERRITORIO_H

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

class territorio {
	int res, createProd, createGold, victoryPoints;
	string name;

public:
	//Construtor default
	territorio(const string name,int res,int createProd,int createGold,int victoryPoints);
	territorio(const string name);

	//Construtor por cópia
	territorio(const territorio& territori);

	//Destrutor
	~territorio();
	/*virtual territorio* duplica()const = 0;*/

	

	//Tipo de território
	string getType(string name) const;

	//Retorna o nome do territorio
	string getName() const;

	//Altera o nome do territorio
	virtual void setName(string name);

	//Retorna o valor da resistencia do territorio
	int getRes() const;

	//Altera o valor da resistencia do territorio
	void setRes(int res);

	//Retorna o valor da criacao de produtos no territorio
	int getCreateProd() const;

	//Altera o valor da criacao de produtos no territorio
	void setCreateProd(int createProd);

	//Retorna o valor da criacao de ouro no territorio
	int getCreateGold() const;

	//Altera o valor da criacao de ouro no territorio
	void setCreateGold(int createGold);

	//Retorna o valor da pontuacao no territorio
	int getVictoryPoints() const;

	//Altera o valor da pontuacao no territorio
	void setVictoryPoints(int victoryPoints);

	//Descrição Textual do território
	string getAsString() const;
};

#endif //TP_POO_TERRITORIO_H
