//
//  Created by Carolina Oliveira & Isabel Castro on 21/11/2020
//
#include "imperio.h"

int max_militar = 5;


imperio::imperio(const imperio& a)
{
	for (auto it = t.begin(); it < t.end(); it++) {
		this->setCofre((*it)->getCreateGold());
		this->setArm((*it)->getCreateProd());
	}
	this->setMilitar(0);
}

imperio::~imperio()
{
}

int imperio::getArm() const
{
	return arm;
}

void imperio::setArm(int arm)
{
	this->arm = arm;
}

int imperio::getMilitar() const
{
	return militar;
}

void imperio::setMilitar(int militar)
{
	if (militar <= max_militar)
		this->militar = militar;
}

int imperio::getCofre() const
{
	return cofre;
}

void imperio::setCofre(int cofre)
{
	this->cofre = cofre;
}


const string imperio::conquistaTerritorio(string name)
{
	ostringstream oss;
	//for (auto it = t.begin(); it != t.end(); it++)
			t.push_back(new territorio(name)); //está a adicionar ao vetor territorios do game pelo lista parece??
			
			return oss.str();

	 //só está a criar um territorio no imperio 
	//se fizer dois conquista seguidos
	//não guarda o primeiro
}

string imperio::getAsString()
{
	ostringstream oss;
	oss << "O seu imperio:"
		<< "\n-Armazem:" << getArm()
		<< "\n-Militar:" << getMilitar()
		<< "\n-Cofre:" << getCofre() << endl;
	for (int i =0; i< t.size(); i++) {
		oss <<"-Territorios: " <<t[i]->getName() << endl;
	}
	return oss.str();
}

//ostream& operator<<(ostream& out, const territorio& ref)
//{
//	out << ref.getAsString() << endl;
//	return out;
//
//}
