//
//  Created by Carolina Oliveira & Isabel Castro on 21/11/2020
//
#ifndef TP_POO_CASTELO_H
#define TP_POO_CASTELO_H

#include "territorio.h"

class castelo : public territorio {
	static int id;
public:
	castelo(const string name);
	virtual void alteraProd(int turno) {
		if (turno <2)
			setCreateProd(3);
	}
};

#endif
