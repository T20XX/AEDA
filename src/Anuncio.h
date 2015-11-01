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
	string titulo, categoria, descricao; //imagens?
	static int ID;
	int data;
public:
	Anuncio(int data, string titulo, string categoria, string descricao);
	virtual ~Anuncio();
	static int nextID();
};


class AnuncioVenda: public Anuncio {
	string estado;
	int preco;
	bool negociavel;
private:
	AnuncioVenda(int data, string titulo, string categoria, string descricao, string estado, int preco, bool negociavel);
};

#endif /* ANUNCIO_H_ */

class AnuncioCompra: public Anuncio {
	string ref;
private:
	AnuncioCompra(int data, string titulo, string categoria, string descricao, string ref);
};
