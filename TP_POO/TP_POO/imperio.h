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

	//Retorna o valor do MAX_MILITAR
	int getMaxMilitar() const;

	//Retorna o valor do MAX_COFRE
	int getMaxCofre() const;

	//Retorna o valor do MAX_ARM
	int getMaxArm() const;

	//Retorna o numero de produtos no armazem
	int getArm() const;

	//Incrementa o numero de produtos no armazem
	void setArm(int arm);

	//Altera o numero de produtos no armazem
	void setArm2(int num);

	//Decrementa o numero de produtos no armazem
	void removeProd(int prod);

	//Retorna o numero de forca militar
	int getMilitar() const;

	//Incrementa o numero de forca militar
	void setMilitar(int militar);

	//Decrementa o numero de forca militar
	void removeMilitar(int forca);

	//Retorna o numero de ouro no cofre
	int getCofre() const;

	//Incrementa o numero de ouro no cofre
	void setCofre(int cofre);

	//Altera o numero de ouro no cofre
	void setCofre2(int num);

	//Decrementa o numero de ouro no cofre
	void removeOuro(int ouro);

	//Retorna o numero de pontos totais
	int getPontos() const;

	//Retorna o numero de pontos totais
	void setPontos(int pontos);

	//Cria o territorioInicial no imperio
	string adicionaTerritorioInicial(territorio* a);

	//Obtem territorio conquistado
	string conquistaTerritorio(territorio* a);

	//Recolhe produtos e ouro para cada turno
	void recolheProd();

	//Devolve true se houver tecnologia x comprada
	bool tecnologiasCompradas(string nome);

	//Obtem descrição textual do império
	string getAsString();

	//Obtem descrição textual apenas dos territorios no imperio
	string getAsStringT();

	//Obtem nome do ultimo territorio conquistado
	string getAsStringLastTerritorio();

	//Obtem resistencia do ultimo territorio conquistado
	int getintResLastTerritorio();

	//Remove territorio do imperio com o nome que recebe
	bool perdeTerritorio(string name);

	//Incrementa a resistencia do territorio
	bool incRes(string name);

	//Adiciona tecnologia <nome> ao império
	int compraTecnologia(string nome);

	//Adquire tecnologia fase 4 sem custos
	int tomaTecnologia(string nome);

	//Retorna o numero de tecnologias adquiridas
	int contaTecnologias();

	//Altera a quantidade de ouro produzida pelo castelo e mina
	void altera(int ano, int turno);

	//devolve o numero de territorios conquistados
	int territoriosConquistados();
};

#endif //TP_POO_IMPERIO_H