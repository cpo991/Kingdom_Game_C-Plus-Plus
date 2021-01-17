//
//  Created by Carolina Oliveira & Isabel Castro on 21/11/2020
//
#ifndef TP_POO_PESCARIA_H
#define TP_POO_PESCARIA_H

#include "territorio.h"

class pescaria : public territorio {
	static int id;
public:

	virtual void alteraProd(int turno,int ano) {
		if (ano==1)
			setCreateProd(3);
		if (ano == 2)
			setCreateProd(4);
	}
	pescaria(const string name);
};

#endif
