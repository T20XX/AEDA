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
:freguesia(freguesia), concelho(concelho), distrito(distrito) {}

Localizacao::~Localizacao() {}

void Localizacao::setFreguesia(string f) {freguesia = f;}

void Localizacao::setConcelho(string c) {concelho = c;}

void Localizacao::setDistrito(string d) {distrito = d;}

string Localizacao::getFreguesia() const {return freguesia;}

string Localizacao::getConcelho() const {return concelho;}

string Localizacao::getDistrito() const {return distrito;}

ostream& operator<<(std::ostream& os, const Localizacao l)
{
  os << l.getFreguesia() << ", " << l.getConcelho() << ", " << l.getDistrito();
  return os;
}

//UTILIZADOR

Utilizador::Utilizador(string email, string nome, int telemovel,Localizacao localizacao)
: email(email), nome(nome),telemovel(telemovel),localizacao(localizacao) {}

Utilizador::~Utilizador() {}

void Utilizador::verUtilizador()
{
	cout << "Informação do Utilizador:" << endl << "Email: " << email << endl <<
			"Nome: " << nome << endl <<
			"Telemóvel: " << telemovel << endl <<
			"Localizaçãoo: " << localizacao << endl <<
			"Número de Anúncios: " << anuncios.size() << endl;

}

void Utilizador::setEmail(string e) {email = e;}

void Utilizador::setNome(string n) {nome = n;}

void Utilizador::setTelemovel(int t) {telemovel = t;}

void Utilizador::setLocalizacao(Localizacao l) {localizacao = l;}

void Utilizador::addAnuncio(Anuncio * a) {anuncios.push_back(a);}

string Utilizador::getEmail() const {return email;}

string Utilizador::getNome() const {return nome;}

int Utilizador::getTelemovel() const {return telemovel;}

Localizacao Utilizador::getLocalizacao() const {return localizacao;}

vector<Anuncio *> Utilizador::getAnuncios() const {return anuncios;}
