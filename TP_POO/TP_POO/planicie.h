//
//  Created by Carolina Oliveira & Isabel Castro on 21/11/2020
//
#ifndef TP_POO_PLANICIE_H
#define TP_POO_PLANICIE_H

#include "territorio.h"

class planicie : public territorio {
	static int id;
public:

	planicie(const string nome);

	virtual void alteraProd(int turno,int ano) {
		if (turno > 6)
			setCreateProd(2);
	}
};

#endif
