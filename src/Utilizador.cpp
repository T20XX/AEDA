/*
 * Utilizador.cpp
 *
 *  Created on: 12/10/2015
 *      Author: Telmo
 */

#include "Utilizador.h"
#include <string>
#include <vector>
#include <iostream>


Localizacao::Localizacao(string freguesia, string concelho, string distrito) {

}

string Localizacao::getFreguesia(){
	return freguesia;
}

string Localizacao::getConcelho(){
	return concelho;
}

string Localizacao::getDistrito(){
	return distrito;
}

Localizacao::~Localizacao() {

}

/*Utilizador::Utilizador(string email, string nome, int telemovel,Localizacao localizacao){
	// TODO Auto-generated constructor stub

}*/

string Utilizador::getEmail(){
	return email;
}

string Utilizador::getNome(){
	return nome;
}

int Utilizador::getTelemovel(){
	return telemovel;
}

Utilizador::~Utilizador() {
	// TODO Auto-generated destructor stub
}
