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

const string game::removeTerritory(string name)
{
	ostringstream oss;

	for (auto it = territorios.begin(); it != territorios.end();) {
		if ((*it)->getName() == name) {
			oss << "TERRITORIO " << (*it)->getName() << " FOI REMOVIDO" << endl;
			delete(*it);
			territorios.erase(it); // está a eliminar corretamente ao vector territorios
			return oss.str();	   // mas quando volta a pedir para listar no configure aparece na mm 
		}

		else {
			*(it++);
		}
	}
	
	return oss.str();
}

//territorio* game::removeTerritory(const string name)
//{
//	ostringstream oss;
//
//	for (auto it = territorios.begin(); it != territorios.end();) {
//		if ((*it)->getName() == name) {
//			oss << "TERRITORIO " << (*it)->getName() << " FOI REMOVIDO" << endl;
//			//delete(*it)
//			territorios.erase(it); 		}
//
//		else {
//			*(it++);
//		}
//	}
//
//	return nullptr;
//}

//const vector<territorio*> game::getTerritorios()
//{
//	vector<territorio*> aux;
//
//	for (territorio* it : territorios) {
//		cout << it->getAsString();
//		aux.push_back(it);
//	}
//	return aux;
//}

const string game::listaTerritorios() {
	ostringstream oss;
	vector <territorio*> aux;
	for (territorio* it : territorios) {
		oss << it->getAsString()<<endl; // estava a ir até ao tamanho de vector correto, por exemplo dps da eliminação
		aux.push_back(it);
	}
	return oss.str();
}
const string game::listaTerritorios(string name) {
	ostringstream oss;
	vector <territorio*> aux;
	for (territorio* it : territorios) {
		if ((it)->getName() == name){
		oss << it->getAsString() << endl; // estava a ir até ao tamanho de vector correto, por exemplo dps da eliminação
		aux.push_back(it);
		}
	}
	return oss.str();
}

const int game::getSizeTerritorios() {
	 int size = 0;
	 size = territorios.size();
	 return size;
}

const string game::conquistaTerritorios(const string name)
{
	srand((unsigned)time(0));
	int sorte;
	for (int z = 0; z < 6; z++) {
		sorte = (rand() % 10) + 1;
	}

	ostringstream oss;

	vector<territorio*> aux;
	for(territorio* it: territorios){
		//for (auto it = territorios.begin(); it != territorios.end();) {

			if ((it)->getName() == name) {

				if (imperioU.getMilitar() + sorte >= it->getRes()) {

					/*oss << this->removeTerritory(name);
					oss << "TAMNHO DO VECTOR TERRITORIOS DO GAME: " << this->territorios.size() << endl;*/
					oss << imperioU.conquistaTerritorio(name);
					oss << removeTerritory(name);
					oss << imperioU.getAsString();
					oss << "TAMNHO DO VECTOR TERRITORIOS DO GAME: " << this->territorios.size() << endl; 

					return oss.str();
				}
			}
			aux.push_back(it);
			//else { (*it)++; }
		}
		//}
	oss << "BLEH BLEH Não conquistou  " << name << endl;
	return oss.str();
}
	

