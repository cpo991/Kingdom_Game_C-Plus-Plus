//
//  Created by Carolina Oliveira & Isabel Castro on 21/11/2020
//
#include "refugioPiratas.h"
int refugioPiratas::id = 1;
refugioPiratas::refugioPiratas(const string name) :territorio(name+to_string(id++),9, 1,0, 2) {

}


