//
//  Created by Carolina Oliveira & Isabel Castro on 19/12/2020
//
#include "castelo.h"
int castelo::id = 1;

castelo::castelo(const string name) :territorio(name+to_string(id++),7,1,3,1){
}

 castelo::~castelo() {
}

void castelo::setName(string name)
{
	static int a = 1;
	territorio::setName(getName() + std::to_string(a));
	name = (name + std::to_string(a));
	a++;
}
