//
//  Created by Carolina Oliveira & Isabel Castro on 21/11/2020
//
#include "territorio.h"

territorio::territorio(string name){
    this->setName(name);
    this->res = 5;
    this->createProd = 1;
    this->createGold = 1;
    this->victoryPoints = 1;
}

territorio::territorio(const territorio& territori)
{
    this->setName(territori.getName());
    this->setRes(territori.getRes());
    this->setCreateProd(territori.getCreateProd());
    this->setCreateGold(territori.getCreateGold());
    this->setVictoryPoints(territori.getVictoryPoints());
}

territorio::~territorio()
{
}

/**
 * Returns the type of territory
 *
 * @param name - name of the territory that can contain numbers -- nometipoNum
 * @return type of territory
 */
string territorio::getType(string name) {

    string type;
    name.pop_back();// erases the last character [0...N]
    type = name;
    return  type;
   
    //int aux = 0, digit = 0;
    //string type;

    //for (int i = 0; i < name.length(); i++) {
    //    if (isdigit(name[i]) == true) {
    //        aux = i;
    //        digit = 1;
    //    }
    //}
    //if (digit == 1) // if string as numbers
    //    type = name.substr(0, aux); // copies the string without numbers
    //else // if string doesn't have numbers
    //    type = name.substr(0, name.length()); // copies entire string
    //return type;
}

string territorio::getName() const
{
   
    return name;
}

void territorio::setName(string name)
{
	/*int i = 0;
	if (name.compare("ilha") == true)
	{
        i++;
        this->name = name + std::to_string(i);
	}*/
    this->name = name;
}

int territorio::getRes() const
{
    return res;
}

void territorio::setRes(int res)
{
    this->res = res;
}

int territorio::getCreateProd() const
{
    return createProd;
}

void territorio::setCreateProd(int createProd)
{
    this->createGold = createGold;
}

int territorio::getCreateGold() const
{
    return createGold;
}

void territorio::setCreateGold(int createGold)
{
    this->createGold = createGold;
}

int territorio::getVictoryPoints() const
{
    return victoryPoints;
}

void territorio::setVictoryPoints(int victoryPoints)
{
    this->victoryPoints;
}
