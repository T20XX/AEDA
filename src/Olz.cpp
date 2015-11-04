/*
 * Olz.cpp
 *
 *  Created on: 02/11/2015
 *      Author: Jorge
 */

#include "Olz.h"

#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>

using namespace std;

Olz::Olz() {
	// TODO Auto-generated constructor stub

}

Olz::~Olz() {
	// TODO Auto-generated destructor stub
}

void Olz::tabelaAnuncios(int num_pagina, int num_anuncios_pagina, string tipoOrganizacao) // Função que imprimi uma tabela com o ID do Utilizador, a Data, o Título e a Categoria
{
	cout << setw(4) << "ID" << setw(7) << "Data" << setw(7) << "Título" << setw(9) << "Categoria" << endl;
	for (int i=num_pagina*num_anuncios_pagina; i < num_pagina*num_anuncios_pagina + num_anuncios_pagina;i++)
	{
		if (i < anuncios.size())
		{
			cout << setw(4) << anuncios[i]->getID() << setw(7) << anuncios[i]->getData() << setw(7) << anuncios[i]->getTitulo() << setw(9) << anuncios[i]->getCategoria() << endl;
		}
		else
			break;
	}
}

void Olz::tabelaUtilizadores(int num_pagina, int num_anuncios_pagina, string tipoOrganizacao) // Função que imprimi uma tabela com o Email, Nome do Utilizador, Telemóvel e Número do Anúncio
{
	cout << setw(7) << "Email" << setw(7) << "Nome" << setw(9) << "Telemóvel" << setw(7) << "Nº Anúncio" << endl;
	for (int i=num_pagina*num_anuncios_pagina; i < num_pagina*num_anuncios_pagina + num_anuncios_pagina;i++)
	{
		if (i < utilizadores.size())
		{
			cout << setw(7) << utilizadores[i].getEmail() << setw(7) << utilizadores[i].getNome() << setw(9) << utilizadores[i].getTelemovel() << setw(7) << utilizadores[i].getAnuncios().size() << endl;
		}
		else
			break;
	}
}


void Olz::addUtilizador(Utilizador u) {
	utilizadores.push_back(u);
}

void Olz::lerUtilizador() {
	string nome, freguesia, email, concelho, distrito;
	int telemovel;

	ifstream Uti;

	Uti.open("Utilizadores.txt");


	while(!Uti.eof()) {
		getline(Uti,email);
		getline(Uti, nome);
		Uti >> telemovel;
		getline(Uti, freguesia);
		getline(Uti, concelho);
		getline(Uti, distrito);
		utilizadores.push_back(Utilizador(email, nome, telemovel, Localizacao(freguesia, concelho, distrito)));
		getline(Uti, nome);
	}

	Uti.close();
}


void Olz::escreverUtilizador() {
	string nome, freguesia, email, concelho, distrito;
	int telemovel;

	ofstream Uti;

	Uti.open("Utilizadores.txt", ofstream::out | ofstream::trunc);

	while(!Uti.eof()) {
		Uti << email << nome << telemovel << freguesia << concelho << distrito;
	}

	Uti.close();
}

