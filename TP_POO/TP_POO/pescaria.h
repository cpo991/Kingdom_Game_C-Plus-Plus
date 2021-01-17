//
//  Created by Carolina Oliveira & Isabel Castro on 21/11/2020
//
#ifndef TP_POO_PESCARIA_H
#define TP_POO_PESCARIA_H

#include "territorio.h"

class pescaria : public territorio {
	static int id;
public:
	//Construtor default
	pescaria(const string nome);

	//Destrutor
	 ~pescaria();
	//virtual ~pescaria();

	void setName(string name) override;
};

#endif
