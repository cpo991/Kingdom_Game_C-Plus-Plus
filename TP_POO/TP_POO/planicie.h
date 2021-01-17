//
//  Created by Carolina Oliveira & Isabel Castro on 21/11/2020
//
#ifndef TP_POO_PLANICIE_H
#define TP_POO_PLANICIE_H

#include "territorio.h"

class planicie : public territorio {
	static int id;
public:
	//Construtor default
	planicie(const string nome);

	//Destrutor
	~planicie();
	//virtual ~planicie();
	void setName(string name) override;
};

#endif
