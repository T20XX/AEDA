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
: nome(nome), email(email), contacto(contacto);
{}

Contacto::~Contacto() {
	// TODO Auto-generated destructor stub
}

//ANUNCIO

int Anuncio::nextID = 0;

Anuncio::Anuncio(int data, string titulo, string categoria, string descricao, bool mostraNome, bool mostraTelemovel, bool mostraEmail) {
	this->data= data;
	this->titulo = titulo;
	this->categoria = categoria;
	this->descricao = descricao;
	this->mostraEmail = mostraEmail;
	this->mostraNome = mostraNome;
	this->mostraTelemovel = mostraTelemovel;
	ID = nextID;
	nextID++;
}

Anuncio::~Anuncio() {
	// TODO Auto-generated destructor stub
}

int Anuncio::getID() const{
	return ID;
}

int Anuncio::getData() const{
	return data;
}

string Anuncio::getTitulo() const{
	return titulo;
}

string Anuncio::getCategoria() const{
	return categoria;
}

string Anuncio::getDescricao() const{
	return descricao;
}


//AnuncioVenda

AnuncioVenda::AnuncioVenda(int data, string titulo, string categoria, string descricao, bool mostraNome, bool mostraTelemovel, bool mostraEmail, string estado, int preco, bool negociavel) :
				Anuncio(data, titulo, categoria, descricao, mostraNome, mostraTelemovel, mostraEmail) {
	this->preco = preco;
	this->negociavel = negociavel;

	if(estado == "novo" || estado == "usando como novo" || estado == "funcional" || estado == "para peças")
		this->estado == estado;
	else this->estado == "indisponivel";
}

void AnuncioVenda::verAnuncio() const {
	cout << "ID: " << getID() << endl << "Data: " << getData() << endl << "Estado do Produto: " << estado << endl << "Preço Pretendido: " << preco << endl;
	if(negociavel)
		cout << "Possibilidade de Negócio." << endl;
}

string AnuncioVenda::getEstado() const{
	return estado;
}

int AnuncioVenda::getPreco() const{
	return preco;
}


//AnuncioCompra

AnuncioCompra::AnuncioCompra(int data, string titulo, string categoria, string descricao, bool mostraNome, bool mostraTelemovel, bool mostraEmail, Anuncio * anuncio) :
				Anuncio(data, titulo, categoria, descricao, mostraNome, mostraTelemovel, mostraEmail) {
	this->anuncio=anuncio;
}

void AnuncioCompra::verAnuncio() const{
	cout << "ID: " << getID() << endl << "Data: " << getData() << endl;
	//FALTA MOSTRAR O ANUNCIOCOMPRA SE QUISER.
}
