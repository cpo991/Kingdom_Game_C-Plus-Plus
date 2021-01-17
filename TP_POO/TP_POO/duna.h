//
//  Created by Carolina Oliveira & Isabel Castro on 21/11/2020
//
#ifndef TP_POO_DUNA_H
#define TP_POO_DUNA_H

#include "territorio.h"

class duna : public territorio {
	static int id;
public:
	//Construtor default
	duna(const string nome);

	//Destrutor
	//virtual ~duna();
	 //~duna();
	void setName(string name) override;
};

#endif
