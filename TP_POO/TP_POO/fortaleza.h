//
//  Created by Carolina Oliveira & Isabel Castro on 21/11/2020
//
#ifndef TP_POO_FORTALEZA_H
#define TP_POO_FORTALEZA_H

#include "territorio.h"

class fortaleza : public territorio {
public:
	//Construtor default
	fortaleza(const string nome);

	//Destrutor
	~fortaleza();
	void setName(string name) override;
};

#endif
