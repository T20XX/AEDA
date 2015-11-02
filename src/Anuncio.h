/*
 * Anuncio.h
 *
 *  Created on: 12/10/2015
 *      Author: Telmo
 */


#include <string>
#include <vector>
#include <iostream>
#include "Utilizador.h"
using namespace std;

#ifndef ANUNCIO_H_
#define ANUNCIO_H_

class Anuncio {
	static int nextID;
	string titulo, categoria, descricao; //imagens?
	int ID, data;
	Utilizador * utilizador;
	bool mostraNome, mostraTelemovel, mostraEmail;
public:
	Anuncio(int data, string titulo, string categoria, string descricao, bool mostraNome, bool mostraTelemovel, bool mostraEmail);
	virtual ~Anuncio();
};


class AnuncioVenda: public Anuncio {
	string estado;
	int preco;
	bool negociavel;
private:
	AnuncioVenda(int data, string titulo, string categoria, string descricao,  bool mostraNome, bool mostraTelemovel, bool mostraEmail, string estado, int preco, bool negociavel);
};

class AnuncioCompra: public Anuncio {
	string ref;
private:
	AnuncioCompra(int data, string titulo, string categoria, string descricao,  bool mostraNome, bool mostraTelemovel, bool mostraEmail, string ref);
};

#endif /* ANUNCIO_H_ */
