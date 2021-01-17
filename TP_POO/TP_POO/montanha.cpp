//
//  Created by Carolina Oliveira & Isabel Castro on 19/12/2020
//
#include "montanha.h"
int montanha::id = 1;
montanha::montanha(const string name) :territorio(name+to_string(id++), 6,0,0, 1) {
	
}

montanha::~montanha() {
}

void montanha::setName(string name)
{
	static int a = 0;
	territorio::setName(getName() + std::to_string(a));
	name = (name + std::to_string(a));
	a++;
}