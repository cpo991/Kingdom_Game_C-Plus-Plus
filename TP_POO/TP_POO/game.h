//
//  Created by Carolina Oliveira & Isabel Castro on 14/11/2020
//
#ifndef TP_POO_GAME_H
#define TP_POO_GAME_H
//class territorio;
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "territorio.h"
#include "imperio.h"
#include "tecnologias.h"

using namespace std;

class game {
	int sorte_last = 0;
	vector<territorio*> territorios;
	imperio imperioU;
public:
	//Construtor
	game();

	// Adiciona territorio à lista de territorios por conquistar
	const void addTerritory(string nome);

	// Remove territorio à lista de territorios por conquistar
	bool  removeTerritory(string name);

	const string listaTerritorios(int ano, int turno);

	//Obter descrição textual do NewGame
	//const string listaTerritorios();

	//Obter descrição textual de Territorio x
	const string listaTerritorios(string name);

	//Obter quantidade de territorios no mundo por conquistar
	const size_t getSizeTerritorios();

	int random(int low, int high);

	//Adiciona um Territorio x do NewGame ao imperio
	const string conquistaTerritorios(string name);

	//Adiciona um territorio inicial ao império
	const string setTerritorioDefault(string name);

	//Confirma a existencia de um territorio x no mundo
	const bool existTerritory(const string name);

	//Recolhe Produtos e Ouro de territorios conquistados por turno
	const void recolheProdGold();

	//Aumentar a força militar via compra
	const bool AumentaForca();

	//Compra Tecnologia <nome> para o império
	//const void AdicionaTecnologias(string nome);

	//Verifica se há tecnologia <nome> no império comprada
	const bool existeTecnologia(const string name);

	//Troca 2 unidades de prod por 1 de ouro
	const bool maisOuro();

	//Troca 2 unidades de ouro por 1 de prod
	const bool maisProd();

	//Guarda os dados do jogo num ficheiro de texto
	void saveData(string file);

	//Carrega os dados do jogo num ficheiro de texto
	void loadData(string filename);

	//Aumentar a força militar via evento de alianca diplomatica
	const bool AumentaForcaFase4();

	//Aumenta o ouro em 1 unidade no evento recurso abandonado
	const bool maisOuroFase4();
	
	//Aumenta o produto em 1 unidade no evento recurso abandonado
	const bool maisProdFase4();

	//Obtem nome do ultimo territorio conquistado
	const string getLastTerritorioConquistado();

	//Obtem resistencia do ultimo territorio conquistado
	const int getResLastTerritorioConquistado();

	//Remove territorio do imperio com o nome que recebe
	const bool removeTerritoryImperio(string name);

	//Incrementa Resistencia do territorio que tem tecnologia de defesa
	const bool incrementaRes(string name);

	//Adiciona um Territorio x do NewGame ao imperio sem fator sorte
	const string tomaTerritorio(const string name);

	//Compra tecnologia
	const int getCompraTecnologia(string nome);

	//Adquire tecnologia fase 4 sem custos
	const int getTomaTecnologia(string nome);

	//Retorna os pontos do imperio
	const int getPontos();

	//Retorna o numero de tecnologias adquiridas
	const int contaTecnologias();

	//Modifica num de ouro 
	const bool modificaOuro(int num);

	//Modifica num de prod
	const bool modificaProd(int num);
	
	//Altera a quantidade de ouro produzida pelo castelo e mina
	void altera(int ano, int turno);

	////Destrutor
	~game();

	int sorteiaEvento();

};

#endif //TP_POO_GAME_H
