//
//  Created by Carolina Oliveira & Isabel Castro on 21/11/2020
//
#ifndef TP_POO_MINA_H
#define TP_POO_MINA_H

#include "territorio.h"

class mina : public territorio {
	static int id;
public:


	virtual void alteraProd(int turno,int ano) {
		if (turno <3 && ano==1)
			setCreateGold(1);
		if (turno > 3 && ano==1)
			setCreateGold(2);
	}
	mina(const string name);
};

#endif
