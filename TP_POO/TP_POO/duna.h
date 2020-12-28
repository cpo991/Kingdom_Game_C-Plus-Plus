//
//  Created by Carolina Oliveira & Isabel Castro on 21/11/2020
//
#ifndef TP_POO_DUNA_H
#define TP_POO_DUNA_H

#include "territorio.h"

class duna : public territorio {

public:
    //Construtor default
    duna(const string nome);

    //Destrutor
    ~duna();
    void setName(string name) override;
};


#endif
