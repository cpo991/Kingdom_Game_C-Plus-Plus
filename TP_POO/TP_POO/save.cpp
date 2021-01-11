//
//  Created by Carolina Oliveira & Isabel Castro on 11/01/2021
//
#include "save.h"

//Construtor
save::save(string nomeSave, game gameSave, int ano, int turno) {
	this->nomeSave = nomeSave;
	this->gameSave = gameSave;
	this->ano = ano;
	this->turno = turno;
}

//Destrutor
save::~save() {

}

//Retorna o nome do save
const string save::getNomeSave() {
	return nomeSave;
}

//Retorna o vetor do jogo
game save::getGameSave() {
	return gameSave;
}

//Retorna o ano
const int save::getAnoSave() {
	return ano;
}

//Retorna o turno
const int save::getTurnoSave() {
	return turno;
}