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
public:
	Olz();
	virtual ~Olz();
	void tabelaAnuncios(int num_pagina, int num_anuncios_pagina, string tipoOrganizacao);
	void tabelaUtilizadores(int num_pagina, int num_anuncios_pagina, string tipoOrganizacao);
	void addUtilizador(Utilizador u);
	void lerUtilizador();
	void escreverUtilizador();
	void lerAnuncio();
	void escreverAnuncio();
};

#endif /* OLZ_H_ */
