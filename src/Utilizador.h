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
	void setLocalizacao(Localizacao l);
	vector<Anuncio *> getAnuncios() const;
	void addAnuncio(Anuncio * a);
};


#endif /* UTILIZADOR_H_ */
