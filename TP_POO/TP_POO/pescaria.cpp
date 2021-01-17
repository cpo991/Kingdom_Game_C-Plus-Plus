//
//  Created by Carolina Oliveira & Isabel Castro on 21/11/2020
//
#include "pescaria.h"
int pescaria::id = 1;
pescaria::pescaria(const string name) :territorio(name+to_string(id++), 9,0,1, 2) {
	
}
