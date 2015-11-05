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
	void carregaAnuncios();
	void tabelaAnuncios(int num_pagina, int num_anuncios_pagina, string tipoOrganizacao);
	void tabelaUtilizadores(int num_pagina, int num_anuncios_pagina, string tipoOrganizacao);
	void addUtilizador(Utilizador u);
	void lerUtilizador();
	void escreverUtilizador();
	void lerAnuncio();
	void escreverAnuncio();
	void addAnuncio(int index,Anuncio * a);
	vector<Anuncio *> getAnuncios() const;
	vector<Utilizador> getUtilizadores();
	void eliminaAnuncio(int ID);
};

#endif /* OLZ_H_ */
