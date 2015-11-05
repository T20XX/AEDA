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
	Anuncio(Utilizador * utilizador, int data, string titulo, string categoria, string descricao, bool mostraEmail, bool mostraNome, bool mostraTelemovel);
	virtual ~Anuncio();
	virtual void verAnuncio() const = 0;
	static void setNextID();
	void setUtilizador(Utilizador * u);
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
	Utilizador* getUtilizador() const;
	virtual string getEstado() const = 0;
	virtual int getPreco() const = 0;
	virtual bool getTipo() const = 0;
	virtual bool getNegociavel() const = 0;
	virtual int getVendaID() const = 0;
};


class AnuncioVenda: public Anuncio {
	string estado;
	int preco;
	bool negociavel;
public:
	AnuncioVenda(Utilizador * utilizador, int data, string titulo, string categoria, string descricao, bool mostraEmail,bool mostraNome, bool mostraTelemovel,  string estado, int preco, bool negociavel);
	void verAnuncio() const;
	string getEstado() const;
	int getPreco() const;
	bool getTipo() const;
	bool getNegociavel() const;
	int getVendaID() const;
};

class AnuncioCompra: public Anuncio {
	int vendaID;
public:
	AnuncioCompra(Utilizador * utilizador, int data, string titulo, string categoria, string descricao,  bool mostraEmail, bool mostraNome, bool mostraTelemovel, int vendaID);
	void verAnuncio() const;
	bool getTipo() const;
	string getEstado() const;
	int getPreco() const;
	bool getNegociavel() const;
	int getVendaID() const;
};

#endif /* ANUNCIO_H_ */
