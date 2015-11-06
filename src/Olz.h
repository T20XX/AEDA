/*
 * Olz.h
 *
 *  Created on: 02/11/2015
 *      Author: Jorge
 */

#include <vector>
#include <iostream>
#include "Anuncio.h"
#include "Utilizador.h"
#include <sstream>

using namespace std;

#ifndef OLZ_H_
#define OLZ_H_

class Olz {
	vector<Utilizador> utilizadores;
	vector<Anuncio *> anuncios;
	vector<Contacto *> contactos;
public:
	Olz();
	virtual ~Olz();
	void carregaAnuncios();
	void carregaContactos();
	void tabelaAnuncios(int num_pagina, int num_anuncios_pagina, string tipoOrd);
	void tabelaUtilizadores(int num_pagina, int num_anuncios_pagina, string tipoOrd);
	void addUtilizador(Utilizador u);
	void lerUtilizadores();
	void escreverUtilizadores();
	void lerAnuncios();
	void escreverAnuncios();
	void lerContactos();
	void escreverContactos();
	void addAnuncio(int index,Anuncio * a);
	vector<Anuncio *> getAnuncios() const;
	vector<Utilizador> getUtilizadores();
	void eliminaAnuncio(int ID);
	void eliminaUtilizador(string email);
	void setUtiNome(int index, string nome);
	void setUtiTelemovel(int index, int telemovel);
	void setUtiLocalizacao(int index, Localizacao localizacao);
};

#endif /* OLZ_H_ */
