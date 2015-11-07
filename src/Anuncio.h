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

class Anuncio;

class Utilizador;

class Data{
	int ano, mes, dia;
public:
	Data(string data);
	Data(int dia, int mes, int ano);
	friend ostream& operator<<(std::ostream& os, const Data d1);
	int getAno() const;
	int getMes() const;
	int getDia() const;
	bool operator <(const Data d1);
	bool operator >(const Data d1);
	bool operator ==(const Data d1);
};

class Contacto {
	Anuncio * anuncio;
	string email, contacto;
	Data data;
public:
	Contacto(Anuncio * anuncio, Data data, string email,string contacto);
	virtual ~Contacto();
	void setAnuncio(Anuncio * a);
	Anuncio * getAnuncio();
	string getEmail();
	string getContacto();
	Data getData();
	void verContacto() const;
	void setEmail(string em);
	void setContacto(string c);
};

class Anuncio {
	static int nextID;
	string titulo, categoria, descricao; //imagens?
	int ID, numCliques;
	Data data;
	Utilizador * utilizador;
	bool mostraNome, mostraTelemovel, mostraEmail;
	vector<Contacto *> contactos;
public:
	Anuncio(Utilizador * utilizador, Data data, string titulo, string categoria, string descricao, bool mostraEmail, bool mostraNome, bool mostraTelemovel);
	virtual ~Anuncio();
	virtual void verAnuncio() const = 0;
	static void setNextID(int ID);
	static int getNextID();
	void addContacto(Contacto * c);
	void setUtilizador(Utilizador * u);
	void setNumCliques(int numCliques);
	int getID() const;
	Data getData() const;
	void setData(Data d);
	int getnumCliques() const;
	string getTitulo() const;
	string getCategoria() const;
	string getDescricao() const;
	void setTitulo(string t);
	void setCategoria(string c);
	void setDescricao(string des);
	bool getmostraNome() const;
	void setmostraNome();
	void setmostraEmail();
	bool getmostraTelemovel() const;
	void setmostraTelemovel();
	bool getmostraEmail() const;
	Utilizador* getUtilizador() const;
	vector<Contacto *> getContactos() const;
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
	AnuncioVenda(Utilizador * utilizador, Data data, string titulo, string categoria, string descricao, bool mostraEmail,bool mostraNome, bool mostraTelemovel,  string estado, int preco, bool negociavel);
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
	AnuncioCompra(Utilizador * utilizador, Data data, string titulo, string categoria, string descricao,  bool mostraEmail, bool mostraNome, bool mostraTelemovel, int vendaID);
	void verAnuncio() const;
	bool getTipo() const;
	string getEstado() const;
	int getPreco() const;
	bool getNegociavel() const;
	int getVendaID() const;
};

class AnuncioFinalizado: public Anuncio {
	int preco;
public:
	AnuncioFinalizado(Utilizador * utilizador, Data data, string titulo, string categoria, string descricao,  bool mostraEmail, bool mostraNome, bool mostraTelemovel, int preco);
	void verAnuncio() const;
	bool getTipo() const;
	string getEstado() const;
	int getPreco() const;
	bool getNegociavel() const;
	int getVendaID() const;
};
#endif /* ANUNCIO_H_ */
