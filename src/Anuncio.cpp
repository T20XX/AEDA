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

Anuncio::Anuncio(int data, string titulo, string categoria, string descricao) {
	this->data= data;
	this->titulo = titulo;
	this->categoria = categoria;
	this->descricao = descricao;
	ID = nextID;
	nextID++;
}

Anuncio::~Anuncio() {
	// TODO Auto-generated destructor stub
}

//AnuncioVenda

AnuncioVenda::AnuncioVenda(int data, string titulo, string categoria, string descricao, string estado, int preco, bool negociavel) :
		Anuncio(data, titulo, categoria, descricao) {
	this->preco = preco;
	this->negociavel = negociavel;

	if(estado == "novo")
		this->estado = estado;
	else if(estado == "usando como novo")
		this->estado = estado;
	else if(estado == "funcional")
		this->estado = estado;
	else if(estado == "para peças")
		this->estado = estado;
	else this->estado = "Inválido";
}

AnuncioCompra::AnuncioCompra(int data, string titulo, string categoria, string descricao, string ref) :
		Anuncio(data, titulo, categoria, descricao) {
	this->ref=ref;
}
