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


//DATA

Data::Data(string data){
	stringstream s1;
	char tempchar;
	s1 << data;
	s1 >> dia >> tempchar >> mes >> tempchar >> ano;
}

Data::Data(int dia, int mes, int ano): dia(dia), mes(mes), ano(ano){}

int Data::getAno() const{return ano;}
int Data::getMes() const{return mes;}
int Data::getDia() const{return dia;}

ostream& operator<<(std::ostream& os, const Data d1)
{
	os << d1.getDia() << "/" << d1.getMes() << "/" << d1.getAno();
	return os;
}

bool Data::operator <(const Data d1){
	if(ano < d1.getAno())
		return true;
	else if(ano > d1.getAno())
		return false;
	else {
		if(mes < d1.getMes())
			return true;
		else if(mes > d1.getMes())
			return false;
		else{
			if(dia < d1.getDia())
				return true;
			else return false;
		}
	}
}
bool Data::operator >(const Data d1){
	if(ano > d1.getAno())
		return true;
	else if(ano < d1.getAno())
		return false;
	else {
		if(mes > d1.getMes())
			return true;
		else if(mes < d1.getMes())
			return false;
		else{
			if(dia > d1.getDia())
				return true;
			else return false;
		}
	}
}

bool Data::operator ==(const Data d1){
	if(ano == d1.getAno())
	{
		if(mes == d1.getMes())
		{
			if(dia == d1.getDia())
				return true;
			else return false;
		}
		else return false;
	}
	else return false;
}
//CONTACTO

Contacto::Contacto(Anuncio * anuncio, Data data, string email,string contacto)
: anuncio(anuncio), data(data), email(email), contacto(contacto)
{}

Contacto::~Contacto() {
	// TODO Auto-generated destructor stub
}


void Contacto::setAnuncio(Anuncio * a) {anuncio = a;}

Anuncio * Contacto::getAnuncio() {return anuncio;}

string Contacto::getEmail(){return email;}

string Contacto::getContacto() {return contacto;}

Data Contacto::getData() {return data;}

void Contacto::verContacto() const{

}

void Contacto::setEmail(string em){	this->email = em;}

void Contacto::setContacto(string c){this->contacto = c;}
//ANUNCIO

int Anuncio::nextID = 0;

Anuncio::Anuncio(Utilizador * utilizador, Data data, string titulo, string categoria, string descricao, bool mostraEmail, bool mostraNome, bool mostraTelemovel)
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

void Anuncio::addContacto(Contacto * c) {contactos.push_back(c);}

void Anuncio::setUtilizador(Utilizador * u) {utilizador = u;}

void Anuncio::setNumCliques(int numCliques) {this->numCliques=numCliques;}

int Anuncio::getID() const {return ID;}

Data Anuncio::getData() const {return data;}

void Anuncio::setData(Data d) {data =d;}

string Anuncio::getTitulo() const {return titulo;}

void Anuncio::setTitulo(string t) {titulo = t;}

string Anuncio::getCategoria() const {return categoria;}

void Anuncio::setCategoria(string c) {categoria = c;}

string Anuncio::getDescricao() const {return descricao;}

void Anuncio::setDescricao(string des) {descricao = des;}

Utilizador* Anuncio::getUtilizador() const {return utilizador;}

vector<Contacto*> Anuncio::getContactos() const {return contactos;}

int Anuncio::getnumCliques() const {return numCliques;}

bool Anuncio::getmostraNome() const {return mostraNome;}

void Anuncio::setmostraNome() {
	(mostraNome = !mostraNome);
}

bool Anuncio::getmostraTelemovel() const {return mostraTelemovel;}

void Anuncio::setmostraTelemovel() {
	(mostraTelemovel = !mostraTelemovel);
}

bool Anuncio::getmostraEmail() const {return mostraEmail;}

void Anuncio::setmostraEmail() {
	(mostraEmail = !mostraEmail);
}

//AnuncioVenda

AnuncioVenda::AnuncioVenda(Utilizador * utilizador,Data data, string titulo, string categoria, string descricao, bool mostraEmail, bool mostraNome, bool mostraTelemovel, string estado, int preco, bool negociavel) :
		Anuncio(utilizador, data, titulo, categoria, descricao, mostraEmail, mostraNome, mostraTelemovel) {
	this->preco = preco;
	this->negociavel = negociavel;

	if(estado == "novo" || estado == "usando como novo" || estado == "funcional" || estado == "para peças")
		this->estado = estado;
	else this->estado = "indisponivel";
}

void AnuncioVenda::verAnuncio() const {
	cout << "Informação do Anuncio: " << getTitulo() << "criado a " << getData() << " Número de Visitantes: " << getnumCliques() << endl;
	cout << "ID: " << getID() << " Categoria: " << getCategoria() << " Descrição: " << getDescricao() << endl;
	cout << "Estado do Produto: " << estado << "Preço Pretendido: " << preco << endl;
	if(negociavel)
		cout << "Possibilidade de Negócio." << endl;
	/*if (getmostraEmail())
		cout << getUtilizador()->getEmail();
	if (getmostraNome())
		cout << getUtilizador()->getNome();
	if (getmostraTelemovel())
		cout << getUtilizador()->getTelemovel();*/
}

string AnuncioVenda::getEstado() const {return estado;}

int AnuncioVenda::getPreco() const {return preco;}

bool AnuncioVenda::getTipo() const {return true;}

int AnuncioVenda::getVendaID() const {return 0;}

bool AnuncioVenda::getNegociavel() const {return negociavel;}


//AnuncioCompra

AnuncioCompra::AnuncioCompra(Utilizador * utilizador,Data data, string titulo, string categoria, string descricao,bool mostraEmail, bool mostraNome, bool mostraTelemovel, int vendaID) :
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
