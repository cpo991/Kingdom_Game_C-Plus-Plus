//
//  Created by Carolina Oliveira & Isabel Castro on 21/11/2020
//
#ifndef TP_POO_MINA_H
#define TP_POO_MINA_H

#include "territorio.h"

class mina : public territorio {
public:
	//Construtor default
	mina(const string nome);

	//Destrutor
	~mina();
	void setName(string name) override;
};

#endif
