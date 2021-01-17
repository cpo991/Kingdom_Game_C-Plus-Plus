//
//  Created by Carolina Oliveira & Isabel Castro on 19/12/2020
//
#include "planicie.h"
int planicie::id = 1;
planicie::planicie(const string name) :territorio(name+to_string(id++),5, 1,1, 1) {
	
}
