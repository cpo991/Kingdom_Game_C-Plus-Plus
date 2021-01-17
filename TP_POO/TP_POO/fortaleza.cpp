//
//  Created by Carolina Oliveira & Isabel Castro on 19/12/2020
//
#include "fortaleza.h"
int fortaleza::id = 1;
fortaleza::fortaleza(const string name) :territorio(name + to_string(id++), 8, 0, 0, 1) {
}

fortaleza::~fortaleza() {
}

void fortaleza::setName(string name)
{
	static int a = 0;
	territorio::setName(getName() + std::to_string(a));
	name = (name + std::to_string(a));
	a++;
}