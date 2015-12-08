/**
 * Utilizador.cpp
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
: email(email), nome(nome),telemovel(telemovel),localizacao(localizacao),num_finalizados(0) {}

Utilizador::~Utilizador() {}

void Utilizador::verUtilizador()
{
	cout << "Informação do Utilizador" << endl
			<< "Email: " << email << endl
			<< "Nome: " << nome << endl
			<<"Telemóvel: " << telemovel << endl
			<< "Localização: " << localizacao << endl
			<< "Número de Anúncios: " << anuncios.size() << endl;

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

int Utilizador::getNum_Finalizados() const {return num_finalizados;}

void Utilizador::setNum_Finalizados(int n) {num_finalizados = n;}

void Utilizador::eliminaAnuncio(int index) {anuncios.erase(anuncios.begin()+index);}

bool Utilizador::operator < (const  Utilizador &u) const{
	return num_finalizados < u.num_finalizados;
}

bool  Utilizador::operator == (const  Utilizador &u) const{
	return num_finalizados == u.num_finalizados;
}
