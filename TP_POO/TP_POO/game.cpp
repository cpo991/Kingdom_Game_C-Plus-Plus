//
//  Created by Carolina Oliveira & Isabel Castro on 29/11/2020
//
#include "game.h"


game::game(){
	
}


const string game::addTerritory(string name){
	ostringstream oss;

	territorios.push_back(new territorio(name));

	return oss.str();
}

const string game::removeTerritory(const string name)
{
	ostringstream oss;

	for (auto it = territorios.begin(); it != territorios.end();) {
		if ((*it)->getName() == name) {
			oss << "TERRITORIO " << (*it)->getName() << " FOI REMOVIDO" << endl;
			territorios.erase(it); 
			return oss.str();	   
		}
		else {
			*(it++);
		}
	}
	return oss.str();
}

const string game::listaTerritorios() {
	ostringstream oss;

	//imperio* aux1;

	oss << "\nLISTAGEM DE DADOS DO JOGO ATE AO MOMENTO" << endl;
	oss << "\n--TERRITORIOS NO MUNDO POR CONQUISTAR--" << endl;
	for (territorio* it : territorios) {
	
		oss << it->getAsString() << endl; 
	}
		oss << "--O SEU IMPERIO--" << endl;
		oss << imperioU.getAsString() << endl;
	

	//oss << "--ANO E TURNO DO JOGO--" << endl;
	//oss << "ULTIMO FATOR SORTE--" << endl;
	//oss << "--TECNOLOGIAS EXISTENTES--" << endl;
	//oss << "--PROXIMO EVENTO--" << endl;
	//oss << "--TOTAL PONTOS--" << endl;

	return oss.str();
}
const string game::listaTerritorios(string name) {
	ostringstream oss;
	vector <territorio*> aux;
	for (territorio* it : territorios) {
		if ((it)->getName() == name){
		oss << it->getAsString() << endl; // 
		aux.push_back(it);
		}
	}
	return oss.str();
}

const size_t game::getSizeTerritorios() {
	 /*int size = 0;
	 size = territorios.size();
	 return size;*/
	return territorios.size();
}

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
					oss << removeTerritory(name) << endl; //elimina o territorio do vector do game
					oss << imperioU.getAsString();
					oss << "TAMNHO DO VECTOR TERRITORIOS DO GAME: " << this->territorios.size() << endl; //está a aparecer bem dps de eliminar

					return oss.str();
				}
				else {
					imperioU.setMilitar(imperioU.getMilitar() - 1);
					oss << "Nao conquistou e reduziu em uma unidade a forca militar" << endl;
				}
			//}
			
		}
		//}
	oss << "Não conquistou  " << name << endl;
	return oss.str();
}
