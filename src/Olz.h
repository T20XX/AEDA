/**
* Olz.h
 */

#include <vector>
#include <iostream>
#include "Anuncio.h"
#include "Utilizador.h"
#include "BST.h"
#include <sstream>

using namespace std;

#ifndef OLZ_H_
#define OLZ_H_

class Olz {
	vector<Utilizador> utilizadores;
	vector<Anuncio *> anuncios;
	vector<Contacto *> contactos;
	vector<Anuncio *> anunciosfinalizados;
	BST<Utilizador> util_por_finalizados;
	priority_queue<Anuncio *> anuncios_pago;
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
	 * Comeca por ordenar o vetor dos anuncios e depois mostra num formato de "tabela"
	 * @param num_pagina Numero da pagina em que se encontra a listagem
	 * @param num_anuncios_pagina Numero de anuncios por pagina
	 * @param tipoOrd String com o tipo de ordenacao pretendida dos anuncios
	 */
	void tabelaAnuncios(int num_pagina, int num_anuncios_pagina, string tipoOrd);

	/**
	 * Comeca por ordenar o vetor dos utilizadores e depois mostra num formato de "tabela"
	 * @param num_pagina Numero da pagina em que se encontra a listagem
	 * @param num_anuncios_pagina Numero de utilizadores por pagina
	 * @param tipoOrd String com o tipo de ordenacao pretendida dos utilizadores
	 */
	void tabelaUtilizadores(int num_pagina, int num_utilizadores_pagina, string tipoOrd);


	void tabelaUtilizadores_p_finalizados(string tipoOrd);

	/**
	 * Adiciona o Utilizador u ao vetor de utilizadores
	 * @param u Utilizador para ser adicionado ao vetor utilizadores
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
	 * Adiciona um anuncio ao utilizador no vetor de utilizadores na posicao index
	 * @param index Index do utilizador para adicionar o anuncio ao vetor de anuncios
	 * @param a Anuncio para adicionar ao vetor de anuncios do utilizador
	 */
	void addAnuncio(int index,Anuncio * a);
	/**
	 * @return Vetor de anuncios
	 */
	vector<Anuncio *> getAnuncios() const;
	/**
	 * @return Vetor de anuncios finalizados
	 */
	vector<Anuncio *> getAnunciosFinalizados() const;
	/**
	 * @return Vetor de utilizadores
	 */
	vector<Utilizador> getUtilizadores();
	/**
	 * @return Vetor de contactos
	 */
	vector<Contacto *> getContactos() const;
	/**
	 * Elimina o anuncio com o ID passado por argumento(elimina do vetor anuncios do Olz e do Utilizador)
	 * @param ID ID do anuncio que se pretende eliminar
	 */
	void eliminaAnuncio(int ID);
	/**
	 * Elimina o utilizador com o email passado por argumento
	 * @param email Email do utilizador que se pretende eliminar
	 */
	void eliminaUtilizador(string email);
	/**
	 * Altera o nome do utilizador na posicao index para o argumento nome
	 * @param index Posicao do utilizador para alterar o nome
	 * @param nome Novo nome para alterar
	 */
	void setUtiNome(int index, string nome);
	/**
	 * Altera o telemovel do utilizador na posicao index para o argumento telemovel
	 * @param index Posicao do utilizador para alterar o telemovel
	 * @param telemovel Novo telemovel para alterar
	 */
	void setUtiTelemovel(int index, int telemovel);
	/**
	 * Altera a localizacao do utilizador na posicao index para o argumento localizacao
	 * @param index Posicao do utilizador para alterar a localizacao
	 * @param localizacao Nova localizacao para alterar
	 */
	void setUtiLocalizacao(int index, Localizacao localizacao);
	/**
	 * Pesquisa no vetor dos utilizadores os utilizadores que correspondem à pesquisa pretendida
	 * @param atributo Atributo do utilizador no qual pretende pesquisar
	 * @param pesquisa Valor que pretende pesquisar no vetor dos utilizadores
	 */
	void pesquisarUtilizador(string atributo, string pesquisa);
	/**
	 * Comeca por ordenar o vetor dos contactos e depois mostra num formato de "tabela"
	 * @param num_pagina Numero da pagina em que se encontra a listagem
	 * @param num_anuncios_pagina Numero de contactos por pagina
	 * @param tipoOrd String com o tipo de ordenacao pretendida dos contactos
	 */
	void tabelaContactos(int num_pagina, int num_contactos_pagina, string tipoOrd);
	/**
	 * Pesquisa no vetor dos anuncios os anuncios que correspondem à pesquisa pretendida
	 * @param atributo Atributo do anuncio no qual pretende pesquisar
	 * @param pesquisa Valor que pretende pesquisar no vetor dos anuncios
	 */
	void pesquisarAnuncio(string atributo, string pesquisa);
	/**
	 * Pesquisa no vetor dos contactos os contactos que correspondem à pesquisa pretendida
	 * @param atributo Atributo do contacto no qual pretende pesquisar
	 * @param pesquisa Valor que pretende pesquisar no vetor dos contactos
	 */
	void pesquisarContacto(string atributo, string pesquisa);
	/**
	 * Adiciona um anuncio ao utilizador no vetor de utilizadores na posicao index
	 * @param ID ID do anuncio para adicionar o contacto ao vetor de contactos
	 * @param c Contacto para adicionar ao vetor de contactos do anuncio
	 */
	void addContacto(int ID, Contacto * c);
	/**
	 * Le do ficheiro AnunciosFinalizados.txt e carrega o vetor de utilizadores
	 * Apenas usada no inicio do correr do programa
	 */
	void lerAnunciosFinalizados();
	/**
	 * Escreve no ficheiro AnunciosFinalizados.txt  o vetor de contactos
	 * A funcao e chamada apos alguma alteracao
	 */
	void escreverAnunciosFinalizados();
	/**
	 * Comeca por ordenar o vetor dos anuncios finalizados e depois mostra num formato de "tabela"
	 * @param num_pagina Numero da pagina em que se encontra a listagem
	 * @param num_anuncios_pagina Numero de anuncios finalizados por pagina
	 * @param tipoOrd String com o tipo de ordenacao pretendida dos anuncios finalizados
	 */
	void tabelaAnunciosFinalizados(int num_pagina, int num_anuncios_pagina, string tipoOrd);
	/**
	 * Pesquisa no vetor dos anuncios finalizados os contactos que correspondem à pesquisa pretendida
	 * @param atributo Atributo do anuncio finalizado no qual pretende pesquisar
	 * @param pesquisa Valor que pretende pesquisar no vetor dos anuncios finalizados
	 */
	void pesquisarAnuncioFinalizado(string atributo, string pesquisa);
	/**
	 * Classe excecao para quando o anuncio com o ID ID nao e encontrado no vetor dos anuncios
	 */
	void Olz::anuncios_pago_ordena();

	class AnuncioNaoEncontrado{
		int ID;
	public:
		AnuncioNaoEncontrado(int ID) {this->ID=ID;}
		int getID() {return ID;}
	};
	/**
	 * Classe excecao para quando o utilizador com o email email nao e encontrado no vetor dos utilizadores
	 */
	class UtilizadorNaoEncontrado{
		string email;
	public:
		UtilizadorNaoEncontrado(string email) {this->email=email;}
		string getEmail() {return email;}
	};
	/**
	 * Classe excecao para quando o index nao esta inserido nos limites do vetor
	 */
	class PosicaoForadoVetor{
		int index, size;
	public:
		PosicaoForadoVetor(int index, int size) {
			this->index=index;
			this->size=size;}
		int getIndex() {return index;}
		int getSize() {return size;}
	};
};

#endif /* OLZ_H_ */
