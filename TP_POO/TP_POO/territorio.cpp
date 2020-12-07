//
//  Created by Carolina Oliveira & Isabel Castro on 21/11/2020
//
#include "territorio.h"

territorio::territorio(string name){
    this->setName(name);
    this->setRes(9);
    this->setCreateGold(1);
    this->setCreateProd(1);
    this->setVictoryPoints(0);
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
string territorio::getType(string name) const {

    string type;
    name.pop_back();// erases the last character [0...N]
    type = name;
    return  type;
}

string territorio::getName() const
{
    return name;
}

void territorio::setName(string name)
{
    if (name == "territorioInicial") {
        this->name = "territorioInicial";
    }
    else {
        static int a = 0;
        this->name = name + std::to_string(a);
        a++;
    }
}

int territorio::getRes() const
{
    return res;
}

void territorio::setRes(int res)
{
    if (getType(this->name) == "territorioInicial") {
        this->res = res;
    }
    else
        this->res = 0;
}

int territorio::getCreateProd() const
{
    return createProd;
}

void territorio::setCreateProd(int createProd)
{
    if (getType(this->name) == "territorioInicial") {
        this->createProd = createProd;
    }
    else
        this->createProd = 0;
}

int territorio::getCreateGold() const
{
    return createGold;
}

void territorio::setCreateGold(int createGold)
{
    if (getType(this->name) == "territorioInicial") {
        this->createGold = createGold;
    }
    else
        this->createGold = 0;
    
}

int territorio::getVictoryPoints() const
{
    return victoryPoints;
}

void territorio::setVictoryPoints(int victoryPoints)
{
    if (getType(this->name) == "territorioInicial") {
        this->victoryPoints = victoryPoints;
    }
    else
        this->victoryPoints = 1;
}

string territorio::getAsString() const
{
    ostringstream oss;
    oss << "\no Nome do Territorio: " << name
        << "\no Tipo de Territorio: " << this->getType(name)
        << "\no Resistencia de conquista: " << res 
        << "\no Criacao de produtos: " << createProd 
        << "\no Criacao de ouro: " << createGold
        << "\no Pontos: " << victoryPoints << endl;
    return oss.str();
}