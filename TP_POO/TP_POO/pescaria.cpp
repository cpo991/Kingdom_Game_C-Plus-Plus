//
//  Created by Carolina Oliveira & Isabel Castro on 21/11/2020
//
#include "pescaria.h"
int pescaria::id = 1;
pescaria::pescaria(const string name) :territorio(name+to_string(id++), 9,0,1, 2) {
	
}

pescaria::~pescaria() {
}

void pescaria::setName(string name)
{
	static int a = 0;
	territorio::setName(getName() + std::to_string(a));
	name = (name + std::to_string(a));
	a++;
}