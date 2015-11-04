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

class Contacto {
	string nome, email, contacto;
public:
	Contacto(string nome, string email,string contacto);
	virtual ~Contacto();
};

class Anuncio {
	static int nextID;
	string titulo, categoria, descricao; //imagens?
	int ID, numCliques;
	int data;
	Utilizador * utilizador;
	bool mostraNome, mostraTelemovel, mostraEmail;
	vector<Contacto> contactos;
public:
	Anuncio(int data, string titulo, string categoria, string descricao, bool mostraEmail, bool mostraNome, bool mostraTelemovel);
	virtual ~Anuncio();
	virtual void verAnuncio() const = 0;
	int getID() const;
	int getData() const;
	string getTitulo() const;
	string getCategoria() const;
	string getDescricao() const;
	virtual bool getTipo() const = 0;
};


class AnuncioVenda: public Anuncio {
	string estado;
	int preco;
	bool negociavel;
public:
	AnuncioVenda(int data, string titulo, string categoria, string descricao, bool mostraEmail,bool mostraNome, bool mostraTelemovel,  string estado, int preco, bool negociavel);
	void verAnuncio() const;
	string getEstado() const;
	int getPreco() const;
	bool getTipo() const;
};

class AnuncioCompra: public Anuncio {
	int ID;
public:
	AnuncioCompra(int data, string titulo, string categoria, string descricao,  bool mostraEmail, bool mostraNome, bool mostraTelemovel, int ID);
	void verAnuncio() const;
	bool getTipo() const;
};

#endif /* ANUNCIO_H_ */
