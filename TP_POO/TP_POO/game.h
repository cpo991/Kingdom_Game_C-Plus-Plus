//
//  Created by Carolina Oliveira & Isabel Castro on 14/11/2020
//
#ifndef TP_POO_GAME_H
#define TP_POO_GAME_H

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
	game();

	// Adiciona territorio à lista de territorios por conquistar
	const string addTerritory(string nome);

	// Remove territorio à lista de territorios por conquistar
	bool  removeTerritory(string name);

	//Obter descrição textual do NewGame
	const string listaTerritorios();

	//Obter descrição textual de Territorio x
	const string listaTerritorios(string name);

	//Obter quantidade de territorios no mundo por conquistar
	const size_t getSizeTerritorios();

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
	const void AdicionaTecnologias(string nome);

	//Verifica se há tecnologia <nome> no império comprada
	const bool existeTecnologia(const string name);


	const bool maisOuro();

	const bool maisProd();

	//trocar para string e dizer aumentou x produtos/ouro 
	const void recursoAbandonado(int turnos);
	
	const string alianca();

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
};

#endif //TP_POO_GAME_H
