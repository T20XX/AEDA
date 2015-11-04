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

Olz::Olz() {}

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
	cout << setw(3) << "#" << setw(25) << "Email" << setw(9) << "Nome" << setw(9) << "Telemóvel" << setw(9) << "Nº Anúncio" << endl;
	for (int i=num_pagina*num_anuncios_pagina; i < num_pagina*num_anuncios_pagina + num_anuncios_pagina;i++)
	{
		if (i < utilizadores.size())
		{
			cout << setw(3) << (i+1) << setw(25) << utilizadores[i].getEmail() << setw(9) << utilizadores[i].getNome() << setw(9) << utilizadores[i].getTelemovel() << setw(9) << utilizadores[i].getAnuncios().size() << endl;
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
		if (email != "")
		{
			getline(Uti, nome);
			Uti >> telemovel;
			Uti.ignore();
			getline(Uti, freguesia);
			getline(Uti, concelho);
			getline(Uti, distrito);
			Localizacao templocal(freguesia,concelho,distrito);
			Utilizador temputi(email, nome, telemovel, templocal);
			addUtilizador(temputi);
			getline(Uti, nome);
		}
	}

	Uti.close();
}


void Olz::escreverUtilizador() {
	ofstream Uti;

	Uti.open("Utilizadores.txt", ofstream::out | ofstream::trunc);

	for(int i=0; i < utilizadores.size();i++) {
		Uti << utilizadores[i].getEmail() << endl
				<< utilizadores[i].getNome()<< endl
				<< utilizadores[i].getTelemovel() << endl
				<< utilizadores[i].getLocalizacao().getFreguesia()<< endl
				<< utilizadores[i].getLocalizacao().getConcelho()<< endl
				<< utilizadores[i].getLocalizacao().getDistrito()<< endl
				<< endl ;
	}

	Uti.close();
}

void Olz::lerAnuncio() {
	string titulo, categoria, descricao, email, tipo, estado;
	int ID, numCliques, data, preco;
	bool mostraNome, mostraTelemovel, mostraEmail, negociavel;

	ifstream Anun;

	Anun.open("Anuncios.txt");


	while(!Anun.eof()) {
		getline(Anun, tipo);
		getline(Anun,email);
		getline(Anun, titulo);
		getline(Anun, categoria);
		Anun >> ID;
		Anun >> data;
		Anun >> numCliques;
		Anun >> mostraNome;
		Anun >> mostraTelemovel;
		Anun >> mostraEmail;
		getline(Anun, descricao);
		if(tipo == "AnuncioVenda"){
			getline(Anun, estado);
			Anun >> preco;
			Anun >> negociavel;
		}
		else if(tipo == "AnuncioCompra"){
			Anun >> ID;
		}
		Anuncio::setNextID();
		for(int i = 0 ; i < utilizadores.size();i++)
		{
			if(utilizadores[i].getEmail() == email)
			{
				Anuncio * tempanun;
				if(tipo == "AnuncioVenda")
				{

					tempanun = new AnuncioVenda(data,titulo,categoria,descricao,mostraEmail,mostraNome,mostraTelemovel,estado,preco,negociavel);
				}
				else if(tipo == "AnuncioCompra")
				{
					tempanun = new AnuncioCompra(data,titulo,categoria,descricao,mostraEmail,mostraNome,mostraTelemovel,ID);
				}
				tempanun->setNumCliques(numCliques);
				utilizadores[i].addAnuncio(tempanun);
			}
		}
	}
	Anun.close();
}

void Olz::escreverAnuncio() {
	ofstream Anun;

	Anun.open("Anuncios.txt", ofstream::out | ofstream::trunc);

	for(int i=0; i < anuncios.size();i++) {
		if(anuncios[i]->getTipo())
			Anun << "AnuncioVenda" << endl;
		else Anun << "AnuncioCompra" << endl;
		Anun << anuncios[i]->getUtilizador()->getEmail() << endl
				<< anuncios[i]->getTitulo()<<endl
				<< anuncios[i]->getCategoria() <<endl
				<< anuncios[i]->getID()<<endl
				<< anuncios[i]->getData()<<endl
				<< anuncios[i]->getnumCliques()<<endl
				<< anuncios[i]->getmostraNome()<<endl
				<< anuncios[i]->getmostraTelemovel()<<endl
				<< anuncios[i]->getmostraEmail()<<endl;
		if(anuncios[i]->getTipo())
		{
			Anun << anuncios[i]->getEstado()<<endl
					<< anuncios[i]->getPreco()<<endl
					<< anuncios[i]->getNegociavel()<<endl;
		}
		else {
			Anun <<anuncios[i]->getVendaID() << endl;
		}
		Anun << endl;
	}

	Anun.close();
}

void Olz::addAnuncio(int index,Anuncio * a) {
	utilizadores[index].addAnuncio(a);
}

vector<Utilizador> Olz::getUtilizadores() {return utilizadores;}
