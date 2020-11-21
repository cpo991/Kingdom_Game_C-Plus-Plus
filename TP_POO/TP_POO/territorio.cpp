//
//  Created by Carolina Oliveira & Isabel Castro on 21/11/2020
//
#include "territorio.h"

territorio::territorio(string name, int res, int, int createProd, int createGold, int victoryPoints){
    string str;
    this->name = name;
    str = getType(name);
    /*if(str.compare("Planicie"))
        //setPlanicie
    if(str.compare("Montanha"))
        //setMontanha*/
}

/**
 * Returns the type of territory
 *
 * @param name - name of the territory that can contain numbers -- nometipoNum
 * @return type of territory
 */
string territorio::getType(string name) {
    int aux = 0, digit = 0;
    string type;

    for (int i = 0; i < name.length(); i++) {
        if (isdigit(name[i]) == true) {
            aux = i;
            digit = 1;
        }
    }
    if (digit == 1) // if string as numbers
        type = name.substr(0, aux); // copies the string without numbers
    else // if string doesn't have numbers
        type = name.substr(0, name.length()); // copies entire string
    return type;
}
