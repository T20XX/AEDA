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
	 * Construtor da classe
	 */
	Localizacao(string freguesia, string concelho, string distrito);
	/**
	 * Destrutor da classe
	 */
	virtual ~Localizacao();
	/**
	 * Altera o membro-dado freguesia para o argumento f
	 * @param f Nova freguesia
	 */
	void setFreguesia(string f);
	/**
	 * Altera o membro-dado concelho para o argumento c
	 * @param c Novo concelho
	 */
	void setConcelho(string c);
	/**
	 * Altera o membro-dado distrito para o argumento d
	 * @param d Nova distrito
	 */
	void setDistrito(string d);
	/**
	 * @return Freguesia
	 */
	string getFreguesia() const;
	/**
	 * @return Concelho
	 */
	string getConcelho() const;
	/**
	 * @return Distrito
	 */
	string getDistrito() const;
	/**
	 * Overload do operator do operator<< que imprime a localização no formato freguesia, concelho, distrito
	 */
	friend ostream& operator<<(std::ostream& os, const Localizacao l);

};

class Utilizador {
	string email, nome;
	int telemovel;
	Localizacao localizacao;
	vector<Anuncio *> anuncios;
public:
	/**
	 * Construtor da classe
	 */
	Utilizador(string email, string nome, int telemovel,Localizacao localizacao);
	/**
	 * Destrutor da classe
	 */
	virtual ~Utilizador();
	/**
	 * Imprime as informacoes do utilizador
	 */
	void verUtilizador();
	void setEmail(string e);
	void setNome(string n);
	void setTelemovel(int t);
	void setLocalizacao(Localizacao l);
	void addAnuncio(Anuncio * a);
	/**
	 * @returns Email
	 */
	string getEmail() const;
	/**
	 * @returns Nome
	 */
	string getNome() const;
	/**
	 * @returns Telemovel
	 */
	int getTelemovel() const;
	/**
	 * @returns Localizacao
	 */
	Localizacao getLocalizacao() const;
	/**
	 * @returns Vetor dos anuncios
	 */
	vector<Anuncio *> getAnuncios() const;
};


#endif /* UTILIZADOR_H_ */
