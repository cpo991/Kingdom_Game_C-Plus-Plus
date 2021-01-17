//
//  Created by Carolina Oliveira & Isabel Castro on 21/11/2020
//
#ifndef TP_POO_MONTANHA_H
#define TP_POO_MONTANHA_H

#include "territorio.h"

class montanha : public territorio {
	static int id;
public:

	virtual void alteraProd(int turno,int ano) {
		if (turno > 2)
			setCreateProd(1);
	}
	montanha(const string name);
};

#endif
