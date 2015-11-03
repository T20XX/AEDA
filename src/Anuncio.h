/*
 * Anuncio.h
 *
 *  Created on: 12/10/2015
 *      Author: Telmo
 */


#ifndef ANUNCIO_H_
#define ANUNCIO_H_


#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Utilizador;

class Anuncio {
	static int nextID;
	string titulo, categoria, descricao; //imagens?
	int ID;
	int data;
	Utilizador * utilizador;
	bool mostraNome, mostraTelemovel, mostraEmail;
public:
	Anuncio(int data, string titulo, string categoria, string descricao, bool mostraNome, bool mostraTelemovel, bool mostraEmail);
	virtual ~Anuncio();
	virtual void verAnuncio() const = 0;
	int getID() const;
	int getData() const;
	string getTitulo() const;
	string getCategoria() const;
	string getDescricao() const;
};


class AnuncioVenda: public Anuncio {
	string estado;
	int preco;
	bool negociavel;
public:
	AnuncioVenda(int data, string titulo, string categoria, string descricao,bool mostraNome, bool mostraTelemovel, bool mostraEmail,  string estado, int preco, bool negociavel);
	void verAnuncio() const;
	string getEstado() const;
	int getPreco() const;
};

class AnuncioCompra: public Anuncio {
	Anuncio * anuncio;
public:
	AnuncioCompra(int data, string titulo, string categoria, string descricao, bool mostraNome, bool mostraTelemovel, bool mostraEmail, Anuncio * anuncio);
	void verAnuncio() const;
};

#endif /* ANUNCIO_H_ */
