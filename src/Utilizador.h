/*
 * Utilizador.h
 *
 *  Created on: 12/10/2015
 *      Author: Telmo
 */

#include <string>
#include <vector>
#include <iostream>

#include "Anuncio.h"
using namespace std;

#ifndef UTILIZADOR_H_
#define UTILIZADOR_H_


class Localizacao {
	string freguesia, concelho, distrito;
public:
	Localizacao(string freguesia, string concelho, string distrito);
	virtual ~Localizacao();
	string getFreguesia() const;
	string getConcelho() const;
	string getDistrito() const;
};

class Utilizador {
	string email, nome;
	int telemovel;
	Localizacao localizacao;
	vector<Anuncio *> anuncios;
public:
	Utilizador(string email, string nome, int telemovel,Localizacao localizacao);
	virtual ~Utilizador();
	string getEmail() const;
	string getNome() const;
	int getTelemovel() const;
	vector<Anuncio *> getAnuncios() const;

};


#endif /* UTILIZADOR_H_ */
