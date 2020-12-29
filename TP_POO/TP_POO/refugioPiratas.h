//
//  Created by Carolina Oliveira & Isabel Castro on 21/11/2020
//
#ifndef TP_POO_REFUGIOPIRATAS_H
#define TP_POO_REFUGIOPIRATAS_H

#include "territorio.h"

class refugioPiratas : public territorio {
public:
	//Construtor default
	refugioPiratas(const string nome);

	//Destrutor
	~refugioPiratas();
	void setName(string name) override;
};

#endif
