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
#include <algorithm>
#include <string>

using namespace std;

//bool para ordenar utilizadores
bool EA(const Utilizador &u1,const Utilizador &u2){return (u1.getEmail() < u2.getEmail());}
bool ED(const Utilizador &u1,const Utilizador &u2){return (u1.getEmail() > u2.getEmail());}
bool NA(const Utilizador &u1,const Utilizador &u2){
	if(u1.getNome() == u2.getNome())
		return EA(u1,u2);
	else return (u1.getNome() < u2.getNome());
}
bool ND(const Utilizador &u1,const Utilizador &u2){
	if(u1.getNome() == u2.getNome())
		return ED(u1,u2);
	return (u1.getNome() > u2.getNome());
}
bool AA(const Utilizador &u1,const Utilizador &u2){
	if(u1.getAnuncios().size() == u2.getAnuncios().size())
		return NA(u1,u2);
	else
		return (u1.getAnuncios().size() < u2.getAnuncios().size());
}
bool AD(const Utilizador &u1,const Utilizador &u2){
	if(u1.getAnuncios().size() == u2.getAnuncios().size())
		return ND(u1,u2);
	else
		return (u1.getAnuncios().size() > u2.getAnuncios().size());
}
bool DA(const Utilizador &u1,const Utilizador &u2){
	if(u1.getLocalizacao().getDistrito() == u2.getLocalizacao().getDistrito())
		return AA(u1,u2);
	else return (u1.getLocalizacao().getDistrito() < u2.getLocalizacao().getDistrito());
}
bool DD(const Utilizador &u1,const Utilizador &u2){
	if(u1.getLocalizacao().getDistrito() == u2.getLocalizacao().getDistrito())
		return AD(u1,u2);
	else return (u1.getLocalizacao().getDistrito() > u2.getLocalizacao().getDistrito());
}

//bool para ordenar anuncios
bool IA(const Anuncio &a1,const Anuncio &a2){return (a1.getID() < a2.getID());}
bool ID(const Anuncio &a1,const Anuncio &a2){return (a1.getID() > a2.getID());}
bool DaA(const Anuncio &a1,const Anuncio &a2){
	if(a1.getData() == a2.getData())
		return IA(a1,a2);
	else return (a1.getData() < a2.getData());
}
bool DaD(const Anuncio &a1,const Anuncio &a2){
	if(a1.getData() == a2.getData())
		return ID(a1,a2);
	return (a1.getData() > a2.getData());
}
bool TA(const Anuncio &a1,const Anuncio &a2){
	if(a1.getTitulo() == a1.getTitulo())
		return IA(a1,a2);
	else
		return (a1.getTitulo() < a2.getTitulo());
}
bool TD(const Anuncio &a1,const Anuncio &a2){
	if(a1.getTitulo() == a1.getTitulo())
		return ID(a1,a2);
	else
		return (a1.getTitulo() > a2.getTitulo());
}
bool CA(const Anuncio &a1,const Anuncio &a2){
	if(a1.getCategoria() == a2.getCategoria())
		return IA(a1,a2);
	else return (a1.getCategoria() < a2.getCategoria());
}
bool CD(const Anuncio &a1,const Anuncio &a2){
	if(a1.getCategoria() == a2.getCategoria())
		return ID(a1,a2);
	else return (a1.getCategoria() > a2.getCategoria());
}
bool NCA(const Anuncio &a1,const Anuncio &a2){
	if(a1.getnumCliques() == a2.getnumCliques())
		return IA(a1,a2);
	else return (a1.getnumCliques() < a2.getnumCliques());
}
bool NCD(const Anuncio &a1,const Anuncio &a2){
	if(a1.getnumCliques() == a2.getnumCliques())
		return ID(a1,a2);
	else return (a1.getnumCliques() > a2.getnumCliques());
}

//bool ordenar contactos

bool CDA(Contacto &c1, Contacto &c2){return (c1.getData() < c2.getData());}
bool CDD(Contacto &c1, Contacto &c2){return (c1.getData() > c2.getData());}
bool CAA(Contacto &c1,Contacto &c2){
	if(c1.getAnuncio()->getID() == c2.getAnuncio()->getID())
		return CDA(c1, c2);
	return (c1.getAnuncio()->getID() < c2.getAnuncio()->getID());
}
bool CAD(Contacto &c1, Contacto &c2){
	if(c1.getAnuncio()->getID() == c2.getAnuncio()->getID())
		return CDD(c1, c2);
	return (c1.getAnuncio()->getID() > c2.getAnuncio()->getID());
}
bool CEA(Contacto &c1, Contacto &c2){
	if(c1.getEmail() == c2.getEmail())
		return CAA(c1,c2);
	return (c1.getEmail() < c2.getEmail());
}
bool CED(Contacto &c1, Contacto &c2){
	if(c1.getEmail() == c2.getEmail())
		return CAD(c1,c2);
	return (c1.getEmail() > c2.getEmail());
}


Olz::Olz() {}

Olz::~Olz() {
	// TODO Auto-generated destructor stub
}

void Olz::carregaAnuncios(){
	anuncios.clear();
	for (int i = 0; i < utilizadores.size(); i++)
	{
		for (int j = 0; j < utilizadores[i].getAnuncios().size(); j++)
		{
			anuncios.push_back(utilizadores[i].getAnuncios()[j]);
		}
	}
}


void Olz::carregaContactos(){
	contactos.clear();
	for (int i = 0; i < utilizadores.size(); i++)
	{
		for (int j = 0; j < utilizadores[i].getAnuncios().size(); j++)
		{
			for (int k = 0; k < utilizadores[i].getAnuncios()[j]->getContactos().size(); k++)
			{
				contactos.push_back(utilizadores[i].getAnuncios()[j]->getContactos()[k]);
			}
		}
	}
}

void Olz::tabelaAnuncios(int num_pagina, int num_anuncios_pagina, string tipoOrd) // Função que imprimi uma tabela com o ID do Utilizador, a Data, o Título e a Categoria
{
	/*if(tipoOrd == "IA")
		sort(anuncios.begin(), anuncios.end(), IA);
	else if(tipoOrd == "ID")
		sort(anuncios.begin(), anuncios.end(), ID);
	else if(tipoOrd == "DA")
		sort(anuncios.begin(), anuncios.end(), DaA);
	else if(tipoOrd == "DD")
		sort(anuncios.begin(), anuncios.end(), DaD);
	else if(tipoOrd == "TA")
		sort(anuncios.begin(), anuncios.end(), TA);
	else if(tipoOrd == "TD")
		sort(anuncios.begin(), anuncios.end(), TD);
	else if(tipoOrd == "CA")
		sort(anuncios.begin(), anuncios.end(), CA);
	else if(tipoOrd == "CD")
		sort(anuncios.begin(), anuncios.end(), CD);
	else if(tipoOrd == "NA")
		sort(anuncios.begin(), anuncios.end(), NCA);
	else if(tipoOrd == "ND")
		sort(anuncios.begin(), anuncios.end(), NCD);*/

	cout << setw(3) << "#" << " " << setw(4) << "ID" << " " << setw(7) << "Data" << " " << setw(7) << "Título" << " " << setw(9) << "Categoria" << endl;
	for (int i=num_pagina*num_anuncios_pagina; i < num_pagina*num_anuncios_pagina + num_anuncios_pagina;i++)
	{
		if (i < anuncios.size())
		{
			cout << setw(3) << (i+1)<< " " << setw(4) << anuncios[i]->getID() << " " << setw(7) << anuncios[i]->getData() << " "<< setw(7) << anuncios[i]->getTitulo() << " " << setw(9) << anuncios[i]->getCategoria() << endl;
		}
		else
			break;
	}
}

void Olz::tabelaUtilizadores(int num_pagina, int num_utilizadores_pagina, string tipoOrd) // Função que imprimi uma tabela com o Email, Nome do Utilizador, Telemóvel e Número do Anúncio
{
	if (tipoOrd == "EA")
		sort(utilizadores.begin(),utilizadores.end(),EA);
	else if (tipoOrd == "ED")
		sort(utilizadores.begin(),utilizadores.end(),ED);
	else if (tipoOrd == "NA")
		sort(utilizadores.begin(),utilizadores.end(), NA);
	else if(tipoOrd == "ND")
		sort(utilizadores.begin(),utilizadores.end(),ND);
	else if (tipoOrd == "AA")
		sort(utilizadores.begin(),utilizadores.end(),AA);
	else if (tipoOrd == "AD")
		sort(utilizadores.begin(),utilizadores.end(),AD);
	if(tipoOrd == "DA")
		sort(utilizadores.begin(),utilizadores.end(),DA);
	if(tipoOrd == "DD")
		sort(utilizadores.begin(),utilizadores.end(),DD);
	cout << setw(3) << "#" << setw(15) << "Email" << setw(15) << "Nome" << " " << setw(9) << "Telemóvel" << " " << setw(9) << "Nº Anúncio" << endl;
	for (int i=num_pagina*num_utilizadores_pagina; i < num_pagina*num_utilizadores_pagina + num_utilizadores_pagina;i++)
	{
		if (i < utilizadores.size())
		{
			cout << setw(3) << (i+1) << setw(25) << utilizadores[i].getEmail().substr(0,24);
			cout << setw(15) << utilizadores[i].getNome().substr(0,14) << " " << setw(9) << utilizadores[i].getTelemovel() << setw(9) << utilizadores[i].getAnuncios().size() << endl;
		}
		else
			break;
	}
}


void Olz::tabelaContactos(int num_pagina, int num_utilizadores_pagina, string tipoOrd){
	/*if (tipoOrd == "DA")
		sort(contactos.begin(),contactos.end(),CDA);
	else if(tipoOrd == "DD")
		sort(contactos.begin(),contactos.end(),CDD);
	else if(tipoOrd == "AA")
		sort(contactos.begin(),contactos.end(),CAA);
	else if(tipoOrd == "AD")
		sort(contactos.begin(),contactos.end(),CAD);
	else if(tipoOrd == "EA")
		sort(contactos.begin(),contactos.end(),CEA);
	else if(tipoOrd == "ED")
		sort(contactos.begin(),contactos.end(),CED);*/

	cout << setw(3) << "#" << " " << setw(3) << "ID" << " " << setw(20) << "Email" << " " << setw(8) << "Contacto" << " " << setw(8) << "Data"<< endl;
		for (int i=num_pagina*num_utilizadores_pagina; i < num_pagina*num_utilizadores_pagina + num_utilizadores_pagina;i++)
		{
			if (i < contactos.size())
			{
				cout << setw(3) << (i+1) << " " << setw(3) << contactos[i]->getAnuncio()->getID() << " " << setw(20) << contactos[i]->getEmail().substr(0,20) << " "  << setw(20) << contactos[i]->getContacto().substr(0,20) << " " << setw(10) << contactos[i]->getData()  << endl;
			}
			else
				break;

		}
}

void Olz::addUtilizador(Utilizador u) {
	utilizadores.push_back(u);
}

void Olz::lerUtilizadores() {
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


void Olz::escreverUtilizadores() {
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

void Olz::lerAnuncios() {
	string titulo, categoria, descricao, email, tipo, estado;
	int ID, numCliques, preco, vendaID, nextID;
	string data;
	bool mostraNome, mostraTelemovel, mostraEmail, negociavel;

	ifstream Anun;

	Anun.open("Anuncios.txt");

	Anun >> nextID;
	Anun.ignore();
	while(!Anun.eof()) {
		getline(Anun, tipo);
		if (tipo != "")
		{
			getline(Anun,email);
			getline(Anun, titulo);
			getline(Anun, categoria);
			Anun >> ID;
			Anun >> data;
			Anun >> numCliques;
			Anun >> mostraNome;
			Anun >> mostraTelemovel;
			Anun >> mostraEmail;
			Anun.ignore();
			getline(Anun, descricao);
			if(tipo == "AnuncioVenda"){
				getline(Anun, estado);
				Anun >> preco;
				Anun >> negociavel;
			}
			else if(tipo == "AnuncioCompra"){
				Anun >> vendaID;
			}
			for(int i = 0 ; i < utilizadores.size();i++)
			{
				if(utilizadores[i].getEmail() == email)
				{
					Anuncio * tempanun;
					Anuncio::setNextID(ID);
					if(tipo == "AnuncioVenda")
					{

						tempanun = new AnuncioVenda(&utilizadores[i],Data(data),titulo,categoria,descricao,mostraEmail,mostraNome,mostraTelemovel,estado,preco,negociavel);
					}
					else if(tipo == "AnuncioCompra")
					{
						tempanun = new AnuncioCompra(&utilizadores[i],Data(data),titulo,categoria,descricao,mostraEmail,mostraNome,mostraTelemovel,vendaID);
					}
					tempanun->setNumCliques(numCliques);
					utilizadores[i].addAnuncio(tempanun);
				}
			}
			Anun.ignore();
			getline(Anun,tipo);
		}
	}
	Anuncio::setNextID(nextID);
	Anun.close();
}

void Olz::escreverAnuncios() {
	ofstream Anun;

	Anun.open("Anuncios.txt", ofstream::out | ofstream::trunc);

	Anun << Anuncio::getNextID() <<endl;
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
				<< anuncios[i]->getmostraEmail()<<endl
				<< anuncios[i]->getDescricao()<<endl;
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

void Olz::lerContactos(){
	string data,email, contacto;
	int ID;

	ifstream Cont;

	Cont.open("Contactos.txt");


	while(!Cont.eof()) {
		Cont >> data;
		if (data != "")
		{
			Cont >> ID;
			Cont >> email;
			Cont.ignore();
			getline(Cont, contacto);

			for (int i = 0 ; i < utilizadores.size();i++)
			{
				for (int j= 0 ; j < utilizadores[i].getAnuncios().size(); j++)
				{
					if (utilizadores[i].getAnuncios()[j]->getID() == ID)
					{
						utilizadores[i].getAnuncios()[j]->addContacto(new Contacto(utilizadores[i].getAnuncios()[j],Data(data),email,contacto));
						break;
					}
				}
			}
			getline(Cont,data);
		}
	}
	Cont.close();
}

void Olz::escreverContactos(){
	ofstream Cont;

	Cont.open("Contactos.txt", ofstream::out | ofstream::trunc);

	for(int i=0; i < contactos.size();i++) {
		Cont << contactos[i]->getData() << endl
				<< contactos[i]->getAnuncio()->getID() <<endl
				<<  contactos[i]->getEmail() <<endl
				<< contactos[i]->getContacto()<<endl
				<< endl;
	}
	Cont.close();
}

void Olz::addAnuncio(int index,Anuncio * a) {
	a->setUtilizador(&utilizadores[index]);
	utilizadores[index].addAnuncio(a);
}


vector<Anuncio *> Olz::getAnuncios() const {return anuncios;}

vector<Utilizador> Olz::getUtilizadores() {return utilizadores;}

vector<Contacto *> Olz::getContactos() const {return contactos;}

void Olz::eliminaAnuncio(int ID){
	for(int i = 0; i < anuncios.size(); i++){
		if(anuncios[i]->getID() == ID){
			anuncios.erase(anuncios.begin() + i);
		}
	}
	for(int i = 0; i< utilizadores.size(); i++){
		for (int j=0; j<utilizadores[i].getAnuncios().size();j++){
			if(utilizadores[i].getAnuncios()[j]->getID() == ID)
				utilizadores[i].getAnuncios().erase(utilizadores[i].getAnuncios().begin() + j);
		}
	}
}

void Olz::eliminaUtilizador(string email){
	for(int i = 0; i< utilizadores.size(); i++)
	{
		if(utilizadores[i].getEmail() == email)
		{
			for(int j=0; j< anuncios.size(); j++)
			{
				if(anuncios[j]->getUtilizador()->getEmail() == email)
				{
					anuncios.erase(anuncios.begin()+j);
				}
			}
			utilizadores.erase(utilizadores.begin()+i);
		}
	}
}

void Olz::setUtiNome(int index, string nome){
	utilizadores[index].setNome(nome);
}

void Olz::setUtiTelemovel(int index, int telemovel){
	utilizadores[index].setTelemovel(telemovel);
}

void Olz::setUtiLocalizacao(int index, Localizacao localizacao){

	utilizadores[index].setLocalizacao(localizacao);
}


int Olz::pesquisarUtilizador(string atributo, string pesquisa){
	vector<string> temp;
	int counter = 0;
	for (int i=0; i < utilizadores.size();i++){
		if(atributo == "E")
			temp.push_back(utilizadores[i].getEmail());
		else if(atributo == "N")
			temp.push_back(utilizadores[i].getNome());
		else if(atributo == "F")
			temp.push_back(utilizadores[i].getLocalizacao().getFreguesia());
		else if(atributo == "C")
			temp.push_back(utilizadores[i].getLocalizacao().getConcelho());
		else if(atributo == "D")
			temp.push_back(utilizadores[i].getLocalizacao().getDistrito());

		if (temp[i].find(pesquisa) != string::npos)
		{
			if (counter != i){

				swap(utilizadores[counter],utilizadores[i]);
			}


			cout<< "ENCONTROU!!" << i;
			counter++;
		}
	}
}

int Olz::pesquisarAnuncio(string atributo, string pesquisa){

	vector<string> temps;
	vector<int> tempi;
	int counter = 0;
	for(int i = 0; i < anuncios.size(); i++){
		if(atributo == "E")
			temps.push_back(anuncios[i]->getUtilizador()->getEmail());
		else if(atributo == "T")
			temps.push_back(anuncios[i]->getTitulo());
		else if(atributo == "C")
			temps.push_back(anuncios[i]->getCategoria());
		else if(atributo == "D")
			temps.push_back(anuncios[i]->getDescricao());
		else if(atributo == "N")
			tempi.push_back(anuncios[i]->getnumCliques());
		else if(atributo == "I")
			tempi.push_back(anuncios[i]->getID());


		if(atributo == "E" || atributo == "T" || atributo == "C" || atributo == "D"){
			if(temps[i].find(pesquisa) != string::npos){
				if(counter != i){
					swap(anuncios[counter], anuncios[i]);
				}
				cout << "ENCONTROU" << i;
				counter++;
			}
		}
		else{
			stringstream ss;
			int pesquisai;
			ss << pesquisa;
			ss >>pesquisai;

			if(find(tempi.begin(), tempi.end(), pesquisai) != tempi.end()){
				if(counter != i){
					swap(anuncios[counter], anuncios[i]);
				}
				cout << "ENCONTROU" << i;
				counter++;
			}
		}
	}
}

int Olz::pesquisarContacto(string atributo, string pesquisa){
	vector<string> temps;
	vector<int> tempi;
	int counter = 0;
	for(int i = 0; i < contactos.size(); i++){
		if(atributo == "E")
			temps.push_back(contactos[i]->getEmail());
		else if(atributo == "C")
			temps.push_back(contactos[i]->getContacto());
		else if(atributo == "I")
			tempi.push_back(contactos[i]->getAnuncio()->getID());


		if(atributo == "E" || atributo == "C"){
			if(temps[i].find(pesquisa) != string::npos){
				if(counter != i){
					swap(contactos[counter], contactos[i]);
				}
				cout << "ENCONTROU" << i;
				counter++;
			}
		}
		else{
			stringstream ss;
			int pesquisai;
			ss << pesquisa;
			ss >>pesquisai;

			if(find(tempi.begin(), tempi.end(), pesquisai) != tempi.end()){
				if(counter != i){
					swap(contactos[counter], contactos[i]);
				}
				cout << "ENCONTROU" << i;
				counter++;
			}
		}
	}
}

void Olz::addContacto(int ID, Contacto * c){
	for(int i = 0; i < anuncios.size(); i++){
		if(anuncios[i]->getID() == ID)
			anuncios[i]->addContacto(c);
	}
}

