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
			return oss.str();
		}
		/*else {
			oss << "Nao foi possivel encontrar o territorio " << name << endl;
			return oss.str();*/

		else {
			*(it++); 
		}
	}
	oss << "NAO FOI POSSIVEL REMOVER" << endl;
	return oss.str();
	
}

const vector<territorio*> game::getTerritorios()
{
	vector<territorio*> aux;

	for (territorio* it : territorios) {
		cout << it->getAsString();
		aux.push_back(it);
	}
	return aux;
}

// int game::getSizeTerritorios() {
//	 int size = 0;
//	 size = territorios.size();
//	 return size;
//}

const string game::conquistaTerritorios(const string name)
{
	int sorte = 0;
	ostringstream oss;
	for (auto it = territorios.begin(); it != territorios.end();) {

		if ((*it)->getName() == name) {

			if (imperioU.getMilitar() + sorte >= 0) {
				
				oss << this->removeTerritory(name);
				oss << imperioU.conquistaTerritorio(name);
				oss << imperioU.getAsString();
				return oss.str();
			}
		}
		else { (*it)++; }
		
		}
	
	
	oss << "BLEH BLEH  " << name << endl;
	return oss.str();
}
		/* }
		 else {
			 oss << "Nao há match com " << name << endl;
			 return oss.str();*/

		 
	 //}
 //}

