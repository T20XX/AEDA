/*
 * Anuncio.h
 *
 *  Created on: 12/10/2015
 *      Author: Telmo
 */


#include <string>
#include <vector>
#include <iostream>
using namespace std;

#ifndef ANUNCIO_H_
#define ANUNCIO_H_

class Anuncio {
	static int nextID;
	string titulo, categoria, descricao; //imagens?
	int ID;
	int data;
public:
	Anuncio(int data, string titulo, string categoria, string descricao);
	virtual ~Anuncio();
};


class AnuncioVenda: public Anuncio {
	string estado;
	int preco;
	bool negociavel;
private:
	AnuncioVenda(int data, string titulo, string categoria, string descricao, string estado, int preco, bool negociavel);
};

class AnuncioCompra: public Anuncio {
	string ref;
private:
	AnuncioCompra(int data, string titulo, string categoria, string descricao, string ref);
};

#endif /* ANUNCIO_H_ */
