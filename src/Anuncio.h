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
	static void setNextID();
	void setNumCliques(int numCliques);
	int getID() const;
	int getData() const;
	int getnumCliques() const;
	string getTitulo() const;
	string getCategoria() const;
	string getDescricao() const;
	bool getmostraNome() const;
	bool getmostraTelemovel() const;
	bool getmostraEmail() const;
	virtual bool getTipo() const = 0;
	Utilizador* getUtilizador() const;
	virtual string getEstado() const = 0;
	virtual int getPreco() const = 0;
	virtual bool getTipo() const = 0;
	virtual bool getNegociavel() const = 0;
	virtual int getID() const = 0;
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
	bool getNegociavel() const;
};

class AnuncioCompra: public Anuncio {
	int ID;
public:
	AnuncioCompra(int data, string titulo, string categoria, string descricao,  bool mostraEmail, bool mostraNome, bool mostraTelemovel, int ID);
	void verAnuncio() const;
	bool getTipo() const;
	int getID() const;
};

#endif /* ANUNCIO_H_ */
