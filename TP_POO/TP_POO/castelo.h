//
//  Created by Carolina Oliveira & Isabel Castro on 21/11/2020
//
#ifndef TP_POO_CASTELO_H
#define TP_POO_CASTELO_H

#include "territorio.h"

class castelo : public territorio {

public:
    //Construtor default
    castelo(const string nome);

    //Destrutor
    ~castelo();
    void setName(string name) override;

};


#endif
