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
	 * Carrega o vetor dos anuncios com referencias aos anuncios de todos os utilizadores
	 */
	void carregaAnuncios();
	/**
	 * Carrega o vetor dos contactos com referencias aos contactos de todos os anuncios de todos os utilizadores
	 */
	void carregaContactos();
	/**
	 * @param num_pagina Numero da pagina em que se encontra a listagem
	 * @param num_anuncios_pagina Numero de anuncios por pagina
	 * @param tipoOrd String com o tipo de ordenacao pretendida dos anuncios
	 * Comeca por ordenar o vetor dos anuncios e depois mostra num formato de "tabela"
	 */
	void tabelaAnuncios(int num_pagina, int num_anuncios_pagina, string tipoOrd);
	/**
	 * @param num_pagina Numero da pagina em que se encontra a listagem
	 * @param num_anuncios_pagina Numero de utilizadores por pagina
	 * @param tipoOrd String com o tipo de ordenacao pretendida dos utilizadores
	 * Comeca por ordenar o vetor dos utilizadores e depois mostra num formato de "tabela"
	 */
	void tabelaUtilizadores(int num_pagina, int num_utilizadores_pagina, string tipoOrd);
	/**
	 * @param u Utilizador para ser adicionado ao vetor utilizadores
	 * Adiciona o Utilizador u ao vetor de utilizadores
	 */
	void addUtilizador(Utilizador u);
	/**
	 * Le do ficheiro Utilizadores.txt e carrega o vetor de utilizadores
	 * Apenas usada no inicio do correr do programa
	 */
	void lerUtilizadores();
	/**
	 * Escreve no ficheiro Utilizadores.txt o vetor de utilizadores
	 * A funcao e chamada apos alguma alteracao
	 */
	void escreverUtilizadores();
	/**
	 * Le do ficheiro Anuncios.txt e carrega o vetor de anuncios
	 * Apenas usada no inicio do correr do programa
	 */
	void lerAnuncios();
	/**
	 * Escreve no ficheiro Anuncios.txt o vetor de anuncios
	 * A funcao e chamada apos alguma alteracao
	 */
	void escreverAnuncios();
	/**
	 * Le do ficheiro Contactos.txt e carrega o vetor de contactos
	 * Apenas usada no inicio do correr do programa
	 */
	void lerContactos();
	/**
	 * Escreve no ficheiro Contactos.txt o vetor de contactos
	 * A funcao e chamada apos alguma alteracao
	 */
	void escreverContactos();
	/**
	 * @param index Index do utilizador para adicionar o anuncio ao vetor de anuncios
	 * @param a Anuncio para adicionar ao vetor de anuncios do utilizador
	 * Adiciona um anuncio ao utilizador no vetor de utilizadores na posicao index
	 */
	void addAnuncio(int index,Anuncio * a);
	/**
	 * @return Vetor de anuncios
	 */
	vector<Anuncio *> getAnuncios() const;
	/**
	 * @return Vetor de utilizadores
	 */
	vector<Utilizador> getUtilizadores();
	/**
	 * @return Vetor de contactos
	 */
	vector<Contacto *> getContactos() const;
	/**
	 * @param ID ID do anuncio que se pretende eliminar
	 * Elimina o anuncio com o ID passado por argumento(elimina do vetor anuncios do Olz e do Utilizador)
	 */
	void eliminaAnuncio(int ID);
	/**
	 * @param email Email do utilizador que se pretende eliminar
	 * Elimina o utilizador com o email passado por argumento
	 */
	void eliminaUtilizador(string email);
	/**
	 * @param index Posicao do utilizador para alterar o nome
	 * @param nome Novo nome para alterar
	 * Altera o nome do utilizador na posicao index para o argumento nome
	 */
	void setUtiNome(int index, string nome);
	/**
	 * @param index Posicao do utilizador para alterar o telemovel
	 * @param telemovel Novo telemovel para alterar
	 * Altera o telemovel do utilizador na posicao index para o argumento telemovel
	 */
	void setUtiTelemovel(int index, int telemovel);
	/**
	 * @param index Posicao do utilizador para alterar a localizacao
	 * @param localizacao Nova localizacao para alterar
	 * Altera a localizacao do utilizador na posicao index para o argumento localizacao
	 */
	void setUtiLocalizacao(int index, Localizacao localizacao);
	/**
	 * @param atributo Atributo do utilizador no qual pretende pesquisar
	 * @param pesquisa Valor que pretende pesquisar no vetor dos utilizadores
	 * Pesquisa no vetor dos utilizadores os utilizadores que correspondem à pesquisa pretendida
	 */
	int pesquisarUtilizador(string atributo, string pesquisa);
	/**
	 * @param num_pagina Numero da pagina em que se encontra a listagem
	 * @param num_anuncios_pagina Numero de contactos por pagina
	 * @param tipoOrd String com o tipo de ordenacao pretendida dos contactos
	 * Comeca por ordenar o vetor dos contactos e depois mostra num formato de "tabela"
	 */
	void tabelaContactos(int num_pagina, int num_contactos_pagina, string tipoOrd);
	/**
	 * @param atributo Atributo do anuncio no qual pretende pesquisar
	 * @param pesquisa Valor que pretende pesquisar no vetor dos anuncios
	 * Pesquisa no vetor dos anuncios os anuncios que correspondem à pesquisa pretendida
	 */
	int pesquisarAnuncio(string atributo, string pesquisa);
	/**
	 * @param atributo Atributo do contacto no qual pretende pesquisar
	 * @param pesquisa Valor que pretende pesquisar no vetor dos contactos
	 * Pesquisa no vetor dos contactos os contactos que correspondem à pesquisa pretendida
	 */
	int pesquisarContacto(string atributo, string pesquisa);
	/**
	 * @param ID ID do anuncio para adicionar o contacto ao vetor de contactos
	 * @param c Contacto para adicionar ao vetor de contactos do anuncio
	 * Adiciona um anuncio ao utilizador no vetor de utilizadores na posicao index
	 */
	void addContacto(int ID, Contacto * c);
};

#endif /* OLZ_H_ */
