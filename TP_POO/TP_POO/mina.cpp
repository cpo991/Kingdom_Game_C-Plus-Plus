//
//  Created by Carolina Oliveira & Isabel Castro on 19/12/2020
//
#include "mina.h"
int mina::id = 1;
mina::mina(const string name) :territorio(name+to_string(id++),5, 0,1, 1) {
}

mina::~mina() {
}

void mina::setName(string name)
{
	static int a = 0;
	territorio::setName(getName() + std::to_string(a));
	name = (name + std::to_string(a));
	a++;
}

/*void mina::setCreateGold(int gold) {
	this->setCreateGold(gold);
}*/