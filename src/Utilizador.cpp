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


Localizacao::Localizacao(string freguesia, string concelho, string distrito)
	:freguesia(freguesia), concelho(concelho), distrito(distrito){}


Localizacao::~Localizacao() {

}

string Localizacao::getFreguesia() const{
	return freguesia;
}

string Localizacao::getConcelho() const{
	return concelho;
}

string Localizacao::getDistrito() const{
	return distrito;
}

//Utilizador

Utilizador::Utilizador(string email, string nome, int telemovel,Localizacao localizacao){
	this->email = email;
	this->nome = nome;
	this->telemovel = telemovel;
	this->localizacao = localizacao;
}

string Utilizador::getEmail() const{
	return email;
}

string Utilizador::getNome() const{
	return nome;
}

int Utilizador::getTelemovel() const{
	return telemovel;
}

vector<Anuncio *> Utilizador::getAnuncios() const{
	return anuncios;
}

Utilizador::~Utilizador() {
	// TODO Auto-generated destructor stub
}
