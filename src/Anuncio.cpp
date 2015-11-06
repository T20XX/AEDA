/*
 * Anuncio.cpp
 *
 *  Created on: 12/10/2015
 *      Author: Telmo
 */

#include "Anuncio.h"
#include <string>
#include <vector>
#include <sstream>

//CONTACTO

Contacto::Contacto(string nome, string email,string contacto)
: nome(nome), email(email), contacto(contacto)
{}

Contacto::~Contacto() {
	// TODO Auto-generated destructor stub
}

//ANUNCIO

int Anuncio::nextID = 0;

Anuncio::Anuncio(Utilizador * utilizador, int data, string titulo, string categoria, string descricao, bool mostraEmail, bool mostraNome, bool mostraTelemovel)
: utilizador(utilizador), data(data), titulo(titulo), categoria(categoria), descricao(descricao),mostraEmail(mostraEmail),mostraNome(mostraNome), mostraTelemovel(mostraTelemovel)
{
	ID = nextID;
	nextID++;
	numCliques = 0;
}

Anuncio::~Anuncio() {
	// TODO Auto-generated destructor stub
}

void Anuncio::setNextID(int ID) {nextID=ID;}

int Anuncio::getNextID() {return nextID;}

void Anuncio::setUtilizador(Utilizador * u) {utilizador = u;}

void Anuncio::setNumCliques(int numCliques) {this->numCliques=numCliques;}

int Anuncio::getID() const {return ID;}

int Anuncio::getData() const {return data;}

string Anuncio::getTitulo() const {return titulo;}

string Anuncio::getCategoria() const {return categoria;}

string Anuncio::getDescricao() const {return descricao;}

Utilizador* Anuncio::getUtilizador() const {return utilizador;}

int Anuncio::getnumCliques() const {return numCliques;}

bool Anuncio::getmostraNome() const {return mostraNome;}

bool Anuncio::getmostraTelemovel() const {return mostraTelemovel;}

bool Anuncio::getmostraEmail() const {return mostraEmail;}

//AnuncioVenda

AnuncioVenda::AnuncioVenda(Utilizador * utilizador,int data, string titulo, string categoria, string descricao, bool mostraEmail, bool mostraNome, bool mostraTelemovel, string estado, int preco, bool negociavel) :
Anuncio(utilizador, data, titulo, categoria, descricao, mostraEmail, mostraNome, mostraTelemovel) {
	this->preco = preco;
	this->negociavel = negociavel;

	if(estado == "novo" || estado == "usando como novo" || estado == "funcional" || estado == "para pe�as")
		this->estado = estado;
	else this->estado = "indisponivel";
}

void AnuncioVenda::verAnuncio() const {
	cout << "ID: " << getID() << endl << "Data: " << getData() << endl << "Estado do Produto: " << estado << endl << "Pre�o Pretendido: " << preco << endl;
	if(negociavel)
		cout << "Possibilidade de Neg�cio." << endl;
}

string AnuncioVenda::getEstado() const {return estado;}

int AnuncioVenda::getPreco() const {return preco;}

bool AnuncioVenda::getTipo() const {return true;}

int AnuncioVenda::getVendaID() const {return 0;}

bool AnuncioVenda::getNegociavel() const {return negociavel;}


//AnuncioCompra

AnuncioCompra::AnuncioCompra(Utilizador * utilizador,int data, string titulo, string categoria, string descricao,bool mostraEmail, bool mostraNome, bool mostraTelemovel, int vendaID) :
												Anuncio(utilizador, data, titulo, categoria, descricao, mostraEmail, mostraNome, mostraTelemovel) {
	this->vendaID=vendaID;;
}

void AnuncioCompra::verAnuncio() const{
	cout << "ID: " << getID() << endl << "Data: " << getData() << endl;
	//FALTA MOSTRAR O ANUNCIOCOMPRA SE QUISER.
}

bool AnuncioCompra::getTipo() const {return false;}

int AnuncioCompra::getVendaID() const {return vendaID;}

string AnuncioCompra::getEstado() const {return "nulo";}

int AnuncioCompra::getPreco() const {return 0;}

bool AnuncioCompra::getNegociavel() const {return false;}

//data

data::data(string data){
	stringstream s1;
	char tempchar;
	s1 << data;
	s1 >> dia >> tempchar >> mes >> tempchar >> ano;
}

data:data(int dia, int mes, int ano): dia(dia), mes(mes), ano(ano){}

int data::getAno() const{return ano;}
int data::getMes() const{return mes;}
int data::getDia() const{return dia;}

ostream& operator<<(std::ostream& os, const data d1)
{
  os << d1.getDia() << "/ " << d1.getMes() << " /" << d1.getAno();
  return os;
}
