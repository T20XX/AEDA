/*
 * Utilizador.cpp
 *
 *  Created on: 12/10/2015
 *      Author: Telmo
 */

#include "Utilizador.h"
#include "Anuncio.h"
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

ostream& operator<<(std::ostream& os, const Localizacao l)
{
  os << l.getFreguesia() << ", " << l.getConcelho() << ", " << l.getDistrito();
  return os;
}

//Utilizador

Utilizador::Utilizador(string email, string nome, int telemovel,Localizacao localizacao)
: email(email), nome(nome),telemovel(telemovel),localizacao(localizacao) {}

void Utilizador::verUtilizador()
{
	cout << "Email: " << email << endl <<
			"Nome: " << nome << endl <<
			"Telem�vel: " << telemovel << endl <<
			"Localiza��oo: " << localizacao << endl <<
			"N�mero de An�ncios: " << anuncios.size() << endl;

}

string Utilizador::getEmail() const {return email;}

string Utilizador::getNome() const {return nome;}

int Utilizador::getTelemovel() const {return telemovel;}

vector<Anuncio *> Utilizador::getAnuncios() const {return anuncios;}


Localizacao Utilizador::getLocalizacao() const {return localizacao;}

Utilizador::~Utilizador() {
	// TODO Auto-generated destructor stub
}

void Utilizador::addAnuncio(Anuncio * a) {
	anuncios.push_back(a);
}
