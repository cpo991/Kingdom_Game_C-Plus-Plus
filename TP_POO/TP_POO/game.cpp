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

const vector<territorio*> game::getTerritorios()
{
	vector<territorio*> aux;

	for (territorio* it : territorios) {
		cout << it->getAsString();
		aux.push_back(it);
	}
	return aux;
}

 int game::getSizeTerritorios() {
	return territorios.size();
}

 const string game::conquistaTerritorios(string name)
 {
	 ostringstream oss;
	// for (auto it = territorios.begin(); it !=territorios.end(); it++) {
		 //if ((*it)->getName()==name) { //ns pq não dá já experimentei ate c/ compare
			 oss<<imperioU.conquistaTerritorio(name);
			 oss<<imperioU.getAsString();
			 return oss.str();
		// }

	 //}
	 
 }

