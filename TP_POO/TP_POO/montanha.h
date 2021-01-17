//
//  Created by Carolina Oliveira & Isabel Castro on 21/11/2020
//
#ifndef TP_POO_MONTANHA_H
#define TP_POO_MONTANHA_H

#include "territorio.h"

class montanha : public territorio {
	static int id;
public:
	//Construtor default
	montanha(const string nome);

	//Destrutor
	//virtual ~montanha();
	~montanha();

	void setName(string name) override;
};

#endif
