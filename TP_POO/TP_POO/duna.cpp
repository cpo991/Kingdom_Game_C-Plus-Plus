//
//  Created by Carolina Oliveira & Isabel Castro on 19/12/2020
//
#include "duna.h"
int duna::id = 1;

duna::duna(const string name) :territorio(name+to_string(id++), 4, 0, 1, 1) {
	
}

