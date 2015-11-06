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

void Localizacao::setFreguesia(string f) {freguesia = f;}

string Localizacao::getConcelho() const{
	return concelho;
}

void Localizacao::setConcelho(string c) {concelho = c;}

string Localizacao::getDistrito() const{
	return distrito;
}

void Localizacao::setDistrito(string d) {distrito = d;}

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
	cout << "Informação do Utilizador:" << endl << "Email: " << email << endl <<
			"Nome: " << nome << endl <<
			"Telemóvel: " << telemovel << endl <<
			"Localizaçãoo: " << localizacao << endl <<
			"Número de Anúncios: " << anuncios.size() << endl;

}

string Utilizador::getEmail() const {return email;}

void Utilizador::setEmail(string e) {email = e;}

string Utilizador::getNome() const {return nome;}

void Utilizador::setNome(string n) {nome = n;}

int Utilizador::getTelemovel() const {return telemovel;}

void Utilizador::setTelemovel(int t) {telemovel = t;}

vector<Anuncio *> Utilizador::getAnuncios() const {return anuncios;}


Localizacao Utilizador::getLocalizacao() const {return localizacao;}

Utilizador::~Utilizador() {
	// TODO Auto-generated destructor stub
}

void Utilizador::addAnuncio(Anuncio * a) {
	anuncios.push_back(a);
}
