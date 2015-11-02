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

int Anuncio::nextID = 0;

Anuncio::Anuncio(int data, string titulo, string categoria, string descricao, bool mostraNome, bool mostraTelemovel, bool mostraEmail) {
	this->data= data;
	this->titulo = titulo;
	this->categoria = categoria;
	this->descricao = descricao;
	ID = nextID;
	nextID++;
	this->mostraEmail = mostraEmail;
	this->mostraNome = mostraNome;
	this->mostraTelemovel = mostraTelemovel;
}

Anuncio::~Anuncio() {
	// TODO Auto-generated destructor stub
}

//AnuncioVenda

AnuncioVenda::AnuncioVenda(int data, string titulo, string categoria, string descricao, string estado, int preco, bool negociavel, bool mostraNome, bool mostraTelemovel, bool mostraEmail) :
		Anuncio(data, titulo, categoria, descricao, mostraNome, mostraTelemovel, mostraEmail) {
	this->preco = preco;
	this->negociavel = negociavel;

	if(estado == "novo" || estado == "usando como novo" || estado == "funcional" || estado == "para peças")
		this->estado == estado;
	else this->estado == "indisponivel";
}

void AnuncioVenda::verAnuncio() const {
	cout << "ID: " << ID << endl << "Data: " << data << endl << "Estado do Produto: " << estado << endl << "Preço Pretendido: " << preco << endl;
	if(negociavel)
		cout << "Possibilidade de Negócio." << endl;
}

//AnuncioCompra

AnuncioCompra::AnuncioCompra(int data, string titulo, string categoria, string descricao, string ref, bool mostraNome, bool mostraTelemovel, bool mostraEmail) :
		Anuncio(data, titulo, categoria, descricao, mostraNome, mostraTelemovel, mostraEmail) {
	this->ref=ref;
}

void AnuncioCompra::verAnuncio() const{

}
