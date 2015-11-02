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
	virtual void verAnuncio() const = 0;
};


class AnuncioVenda: public Anuncio {
	string estado;
	int preco;
	bool negociavel;
private:
	AnuncioVenda(int data, string titulo, string categoria, string descricao, string estado, int preco, bool negociavel, bool mostraNome, bool mostraTelemovel, bool mostraEmail);
	void verAnuncio() const;
};

class AnuncioCompra: public Anuncio {
	string ref;
private:
	AnuncioCompra(int data, string titulo, string categoria, string descricao, string ref,  bool mostraNome, bool mostraTelemovel, bool mostraEmail,);
	void verAnuncio() const;
};

#endif /* ANUNCIO_H_ */
