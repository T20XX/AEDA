/*
 * Utilizador.h
 *
 *  Created on: 12/10/2015
 *      Author: Telmo
 */


#ifndef UTILIZADOR_H_
#define UTILIZADOR_H_

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Anuncio;

class Localizacao {
	string freguesia, concelho, distrito;
public:
	/**
	 * Construtor da classe Localizacao
	 */
	Localizacao(string freguesia, string concelho, string distrito);
	virtual ~Localizacao();
	string getFreguesia() const;
	void setFreguesia(string f);
	string getConcelho() const;
	void setConcelho(string c);
	string getDistrito() const;
	void setDistrito(string d);
	friend ostream& operator<<(std::ostream& os, const Localizacao l);

};

class Utilizador {
	string email, nome;
	int telemovel;
	Localizacao localizacao;
	vector<Anuncio *> anuncios;
public:
	Utilizador(string email, string nome, int telemovel,Localizacao localizacao);
	virtual ~Utilizador();
	void verUtilizador();
	string getEmail() const;
	void setEmail(string e);
	string getNome() const;
	void setNome(string n);
	int getTelemovel() const;
	void setTelemovel(int t);
	Localizacao getLocalizacao() const;
	vector<Anuncio *> getAnuncios() const;
	void addAnuncio(Anuncio * a);
};


#endif /* UTILIZADOR_H_ */
