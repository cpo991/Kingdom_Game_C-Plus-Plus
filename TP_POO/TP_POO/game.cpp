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

	cout << "teste func" << endl;
	for (territorio* it : territorios) {
		cout << it->getName() << endl;
		aux.push_back(it);
	}
	return aux;
}
