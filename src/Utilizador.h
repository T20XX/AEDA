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
	Localizacao(string freguesia, string concelho, string distrito);
	virtual ~Localizacao();
	string getFreguesia() const;
	string getConcelho() const;
	string getDistrito() const;
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
	string getNome() const;
	int getTelemovel() const;
	Localizacao getLocalizacao() const;
	vector<Anuncio *> getAnuncios() const;
	void addAnuncio(Anuncio * a);
};


#endif /* UTILIZADOR_H_ */
