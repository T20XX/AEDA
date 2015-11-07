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
	/**
	 * Construtor da classe
	 */
	Olz();
	/**
	 * Destrutor da classe
	 */
	virtual ~Olz();
	/**
	 * Carrega o vetor @see anuncios com referências aos anúncios de todos os utilizadores
	 */
	void carregaAnuncios();
	void carregaContactos();
	void tabelaAnuncios(int num_pagina, int num_anuncios_pagina, string tipoOrd);
	void tabelaUtilizadores(int num_pagina, int num_utilizadores_pagina, string tipoOrd);
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
	vector<Contacto *> getContactos() const;
	void eliminaAnuncio(int ID);
	void eliminaUtilizador(string email);
	void setUtiNome(int index, string nome);
	void setUtiTelemovel(int index, int telemovel);
	void setUtiLocalizacao(int index, Localizacao localizacao);
	int pesquisarUtilizador(string atributo, string pesquisa);
	void tabelaContactos(int num_pagina, int num_contactos_pagina, string tipoOrd);
	int pesquisarAnuncio(string atributo, string pesquisa);
	int pesquisarContacto(string atributo, string pesquisa);
	void addContacto(int ID, Contacto * c);
};

#endif /* OLZ_H_ */
