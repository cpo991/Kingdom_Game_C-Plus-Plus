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
