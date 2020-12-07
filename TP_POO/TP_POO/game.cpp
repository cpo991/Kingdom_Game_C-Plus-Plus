//
//  Created by Carolina Oliveira & Isabel Castro on 29/11/2020
//
#include "game.h"


game::game(){
	
}

//Adiciona territorio ao NewGame (mundo)
const string game::addTerritory(string name){
	ostringstream oss;

	territorios.push_back(new territorio(name));

	return oss.str();
}

//Remove territorio ao NewGame(mundo)
const string game::removeTerritory(const string name){
	ostringstream oss;
	for (auto it = territorios.begin(); it != territorios.end();) {
		if ((*it)->getName() == name) {
			territorios.erase(it); 
			return oss.str();	   
		}
		else {
			*(it++);
		}
	}
	return oss.str();
}

//Obter descrição textual do NewGame
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
	

	//oss << "--ANO E TURNO DO JOGO--" << endl;
	//oss << "ULTIMO FATOR SORTE--" << endl;
	//oss << "--TECNOLOGIAS EXISTENTES--" << endl;
	//oss << "--PROXIMO EVENTO--" << endl;
	//oss << "--TOTAL PONTOS--" << endl;

	return oss.str();
}

//Obter descrição textual de Territorio x
const string game::listaTerritorios(string name) {
	ostringstream oss;
	vector <territorio*> aux;
	oss << "::::: DADOS DO TERRITORIO " << name << " :::::" << endl;
	for (territorio* it : territorios) {
		if ((it)->getName() == name){
		oss << it->getAsString() << endl; // 
		aux.push_back(it);
		}
	}
	return oss.str();
}

//Obter quantidade de territorios no mundo por conquistar
const size_t game::getSizeTerritorios() { return territorios.size();}

//Adiciona um Territorio x do NewGame ao imperio
const string game::conquistaTerritorios(const string name)
{
	srand((unsigned)time(0));
	int sorte;
	for (int z = 0; z < 6; z++) {
		sorte = (rand() % 10) + 1;
	}

	ostringstream oss;

	for(territorio* it: territorios){
	

			if ((it)->getName() == name) {

				//if (imperioU.getMilitar() + sorte >= it->getRes()) {

					oss << imperioU.conquistaTerritorio(it) << endl;; //copia o territorio para o imperio
					oss << removeTerritory(name); //elimina o territorio do vector do gamesa
					oss << imperioU.getAsString();
					//oss << "TAMNHO DO VECTOR TERRITORIOS DO GAME: " << this->territorios.size() << endl; //está a aparecer bem dps de eliminar

					return oss.str();
				}
				/*else {
					imperioU.setMilitar(imperioU.getMilitar() - 1);
					oss << "Nao conquistou e reduziu em uma unidade a forca militar" << endl;*/
				}
			//}
	

	imperioU.setMilitar(imperioU.getMilitar() - 1);
	oss << "\n>>> Reduziu em uma unidade a forca militar" << endl; 
		//}
	oss << "\n>>> Nao conquistou  " << name << endl;
	return oss.str();
}
