//
//  Created by Carolina Oliveira & Isabel Castro on 14/11/2020
//
#ifndef TP_POO_CONFIGURE_H
#define TP_POO_CONFIGURE_H

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "game.h"

using namespace std;

class configure {
    
    string phrase, command, param1, param2, param3, param4, param5, param6, param7;

public:
    configure();
    void initMenu();
    void commands();
    void help();
    void needParam(int num, string command);
    void lessParam(int num, string command);
    const string cmdCarrega(string ficheiro);
};


#endif //TP_POO_CONFIGURE_H
