//
//  Created by Carolina Oliveira & Isabel Castro on 19/12/2020
//
#include "mina.h"
int mina::id = 1;
mina::mina(const string name) :territorio(name+to_string(id++),5, 0,1, 1) {
}

