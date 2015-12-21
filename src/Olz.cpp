/**
 * Olz.cpp
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
bool IA(const Anuncio *a1,const Anuncio *a2){return (a1->getID() < a2->getID());}
bool ID(const Anuncio *a1,const Anuncio *a2){return (a1->getID() > a2->getID());}
bool DaA(const Anuncio *a1,const Anuncio *a2){
	if(a1->getData() == a2->getData())
		return IA(a1,a2);
	else return (a1->getData() < a2->getData());
}
bool DaD(const Anuncio *a1,const Anuncio *a2){
	if(a1->getData() == a2->getData())
		return ID(a1,a2);
	return (a1->getData() > a2->getData());
}
bool TA(const Anuncio *a1,const Anuncio *a2){
	if(a1->getTitulo() == a1->getTitulo())
		return IA(a1,a2);
	else
		return (a1->getTitulo() < a2->getTitulo());
}
bool TD(const Anuncio *a1,const Anuncio *a2){
	if(a1->getTitulo() == a1->getTitulo())
		return ID(a1,a2);
	else
		return (a1->getTitulo() > a2->getTitulo());
}
bool CA(const Anuncio *a1,const Anuncio *a2){
	if(a1->getCategoria() == a2->getCategoria())
		return IA(a1,a2);
	else return (a1->getCategoria() < a2->getCategoria());
}
bool CD(const Anuncio *a1,const Anuncio *a2){
	if(a1->getCategoria() == a2->getCategoria())
		return ID(a1,a2);
	else return (a1->getCategoria() > a2->getCategoria());
}
bool NCA(const Anuncio *a1,const Anuncio *a2){
	if(a1->getnumCliques() == a2->getnumCliques())
		return IA(a1,a2);
	else return (a1->getnumCliques() < a2->getnumCliques());
}
bool NCD(const Anuncio *a1,const Anuncio *a2){
	if(a1->getnumCliques() == a2->getnumCliques())
		return ID(a1,a2);
	else return (a1->getnumCliques() > a2->getnumCliques());
}

//bool ordenar contactos

bool CDA(Contacto *c1,  Contacto *c2){return (c1->getData() < c2->getData());}
bool CDD( Contacto *c1,  Contacto *c2){return (c1->getData() > c2->getData());}
bool CAA(Contacto *c1,Contacto *c2){
	if(c1->getAnuncio()->getID() == c2->getAnuncio()->getID())
		return CDA(c1, c2);
	return (c1->getAnuncio()->getID() < c2->getAnuncio()->getID());
}
bool CAD(Contacto *c1, Contacto *c2){
	if(c1->getAnuncio()->getID() == c2->getAnuncio()->getID())
		return CDD(c1, c2);
	return (c1->getAnuncio()->getID() > c2->getAnuncio()->getID());
}
bool CEA( Contacto *c1, Contacto *c2){
	if(c1->getEmail() == c2->getEmail())
		return CAA(c1,c2);
	return (c1->getEmail() < c2->getEmail());
}
bool CED(Contacto *c1, Contacto *c2){
	if(c1->getEmail() == c2->getEmail())
		return CAD(c1,c2);
	return (c1->getEmail() > c2->getEmail());
}


Olz::Olz()
:util_por_finalizados(Utilizador("","",0,Localizacao("","",""))){
}

Olz::~Olz() {
	// TODO Auto-generated destructor stub
}

void Olz::carregaAnuncios(){
	anuncios.clear();
	while(!anuncios_pago.empty())
		anuncios_pago.pop();
	for (int i = 0; i < utilizadores.size(); i++)
	{
		for (int j = 0; j < utilizadores[i].getAnuncios().size(); j++)
		{
			anuncios.push_back(utilizadores[i].getAnuncios()[j]);
			anuncios_pago.push((utilizadores[i].getAnuncios()[j]));
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
	if(tipoOrd == "IA")
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
		sort(anuncios.begin(), anuncios.end(), NCD);


	for (int i=num_pagina*num_anuncios_pagina; i < num_pagina*num_anuncios_pagina + num_anuncios_pagina;i++)
	{
		if (i < (anuncios.size()))
		{
			cout << setw(3) << (i+1) << setw(4) << anuncios[i]->getID() << " " << anuncios[i]->getData();
			if (anuncios[i]->getTipo())
				cout << setw(7)  << "Venda" ;
			else
				cout << setw(7)  << "Compra";
			cout << setw(10)  << anuncios[i]->getTitulo().substr(0,9)<<setw(10)  << anuncios[i]->getCategoria().substr(0,9) << setw(15)  << anuncios[i]->getUtilizador()->getEmail().substr(0,14) << setw(5)  << anuncios[i]->getnumCliques() << setw(6)  << anuncios[i]->getContactos().size() << endl;
		}
		else
			break;
	}
}

void Olz::tabelaAnunciosFinalizados(int num_pagina, int num_anuncios_pagina, string tipoOrd) // Função que imprimi uma tabela com o ID do Utilizador, a Data, o Título, a Categoria e o preço finalizado
{
	if(tipoOrd == "IA")
		sort(anunciosfinalizados.begin(), anunciosfinalizados.end(), IA);
	else if(tipoOrd == "ID")
		sort(anunciosfinalizados.begin(), anunciosfinalizados.end(), ID);
	else if(tipoOrd == "DA")
		sort(anunciosfinalizados.begin(), anunciosfinalizados.end(), DaA);
	else if(tipoOrd == "DD")
		sort(anunciosfinalizados.begin(), anunciosfinalizados.end(), DaD);
	else if(tipoOrd == "TA")
		sort(anunciosfinalizados.begin(), anunciosfinalizados.end(), TA);
	else if(tipoOrd == "TD")
		sort(anunciosfinalizados.begin(), anunciosfinalizados.end(), TD);
	else if(tipoOrd == "CA")
		sort(anunciosfinalizados.begin(), anunciosfinalizados.end(), CA);
	else if(tipoOrd == "CD")
		sort(anunciosfinalizados.begin(), anunciosfinalizados.end(), CD);
	else if(tipoOrd == "NA")
		sort(anunciosfinalizados.begin(), anunciosfinalizados.end(), NCA);
	else if(tipoOrd == "ND")
		sort(anunciosfinalizados.begin(), anunciosfinalizados.end(), NCD);

	cout << setw(3) << "#" << setw(4) << "ID"  <<setw(11)<< "Data" << setw(10) << "Titulo" << setw(10) << "Categoria" << setw(15) << "Utilizador" << setw(5) << "Vis." << endl;
	for (int i=num_pagina*num_anuncios_pagina; i < num_pagina*num_anuncios_pagina + num_anuncios_pagina;i++)
	{
		if (i < anunciosfinalizados.size())
		{
			cout << setw(3) << (i+1) << setw(4) << anunciosfinalizados[i]->getID() <<  " " << anunciosfinalizados[i]->getData()<< anunciosfinalizados[i]->getTitulo().substr(0,9) << setw(10)  << anunciosfinalizados[i]->getCategoria().substr(0,9) << setw(15)  << anunciosfinalizados[i]->getUtilizador()->getEmail().substr(0,14) << setw(5)  << anunciosfinalizados[i]->getnumCliques() << endl;
		}
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
	cout << setw(3) << "#" << setw(25) << "Email" <<setw(15) << "Nome" << setw(10) << "Nº Tel." << setw(6) << "Anun." << endl;
	for (int i=num_pagina*num_utilizadores_pagina; i < num_pagina*num_utilizadores_pagina + num_utilizadores_pagina;i++)
	{
		if (i < utilizadores.size())
		{
			cout << setw(3) << (i+1) << setw(25) << utilizadores[i].getEmail().substr(0,24) << setw(15) << utilizadores[i].getNome().substr(0,14) << setw(10) << utilizadores[i].getTelemovel() << setw(6) << utilizadores[i].getAnuncios().size() << endl;
		}
		else
			break;
	}
}

void Olz::tabelaUtilizadores_p_finalizados(string tipoOrd) // Função que imprimi uma tabela com o Email, Nome do Utilizador, Telemóvel e Número do Anúncio
{
	cout << setw(3) << "#" << setw(25) << "Email" <<setw(15) << "Nome" << setw(10) << "Nº Tel." << setw(6) << "Finalizados" << endl;
	BSTItrIn<Utilizador> it(util_por_finalizados);
	int index = 0;
	while (!it.isAtEnd())
	{
		index++;
		cout << setw(3) << index << setw(25) << it.retrieve().getEmail().substr(0,24) << setw(15) << it.retrieve().getNome().substr(0,14) << setw(10) << it.retrieve().getTelemovel() << setw(6) << it.retrieve().getNum_Finalizados() << endl;
		it.advance();
	}

	/*for (int i=num_pagina*num_utilizadores_pagina; i < num_pagina*num_utilizadores_pagina + num_utilizadores_pagina;i++)
	{
		if (i < utilizadores.size())
		{
			cout << setw(3) << (i+1) << setw(25) << utilizadores[i].getEmail().substr(0,24) << setw(15) << utilizadores[i].getNome().substr(0,14) << setw(10) << utilizadores[i].getTelemovel() << setw(6) << utilizadores[i].getNum_Finalizados() << endl;
		}
		else
			break;
	}*/
}

void Olz::tabelaContactos(int num_pagina, int num_utilizadores_pagina, string tipoOrd){
	if (tipoOrd == "DA")
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
		sort(contactos.begin(),contactos.end(),CED);

	cout << setw(3) << "#" << setw(4) << "ID" << setw(11) << "Data"<< setw(25) << "Email" << setw(50) << "Mensagem"<< endl;
	for (int i=num_pagina*num_utilizadores_pagina; i < num_pagina*num_utilizadores_pagina + num_utilizadores_pagina;i++)
	{
		if (i < contactos.size())
		{
			cout << setw(3) << (i+1) << setw(4) << contactos[i]->getAnuncio()->getID() << " " << contactos[i]->getData()<< setw(25) << contactos[i]->getEmail().substr(0,24) << setw(50) << contactos[i]->getContacto().substr(0,49)  << endl;
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
	int telemovel,num_finalizados;

	ifstream Uti;

	Uti.open("Utilizadores.txt");
	if (!Uti.good()){
		Uti.close();
		ofstream temp("Utilizadores.txt");
		temp.close();
		Uti.open("Utilizadores.txt");
	}


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
			Uti >> num_finalizados;
			Uti.ignore();
			Localizacao templocal(freguesia,concelho,distrito);
			Utilizador temputi(email, nome, telemovel, templocal);
			temputi.setNum_Finalizados(num_finalizados);
			addUtilizador(temputi);
			util_por_finalizados.insert(temputi);
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
				<< utilizadores[i].getNum_Finalizados()<< endl
				<< endl ;
	}

	Uti.close();
}

void Olz::lerAnuncios() {
	string titulo, categoria, descricao, email, tipo, estado;
	int ID, numCliques, preco, vendaID, nextID;
	string data;
	bool mostraNome, mostraTelemovel, mostraEmail, negociavel, isPago;

	ifstream Anun;

	Anun.open("Anuncios.txt");
	if (!Anun.good()){
		Anun.close();
		ofstream temp("Anuncios.txt");
		temp << "0" << endl;
		temp.close();
		Anun.open("Anuncios.txt");
	}

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
			Anun >> isPago;
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
					tempanun->setPago(isPago);
					tempanun->setNumCliques(numCliques);
					utilizadores[i].addAnuncio(tempanun);
					anuncios_pago.push(tempanun);
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
		Anun << anuncios[i]->getPago()<< endl;
		Anun << endl;
	}
	Anun.close();
}

void Olz::lerContactos(){
	string data,email, contacto;
	int ID;

	ifstream Cont;

	Cont.open("Contactos.txt");
	if (!Cont.good()){
		Cont.close();
		ofstream temp("Contactos.txt");
		temp.close();
		Cont.open("Contactos.txt");
	}


	while(!Cont.eof()) {
		Cont >> data;
		if (data != "")
		{
			Cont >> ID;
			Cont >> email;
			Cont.ignore();
			getline(Cont, contacto);

			for (int i = 0 ; i < utilizadores.size(); i++)
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
	if (index >=0 && index < utilizadores.size()) {
		a->setUtilizador(&utilizadores[index]);
		utilizadores[index].addAnuncio(a);
	}
	else
		throw PosicaoForadoVetor(index, utilizadores.size());
}


vector<Anuncio *> Olz::getAnuncios() const {return anuncios;}

vector<Anuncio *> Olz::getAnunciosFinalizados() const {return anunciosfinalizados;}

vector<Utilizador> Olz::getUtilizadores() {return utilizadores;}

vector<Contacto *> Olz::getContactos() const {return contactos;}

void Olz::eliminaAnuncio(int ID){
	bool encontrou = false;
	for(int i = 0; i< utilizadores.size(); i++){
		for (int j=0; j<utilizadores[i].getAnuncios().size();j++){
			if(utilizadores[i].getAnuncios()[j]->getID() == ID)
			{
				utilizadores[i].eliminaAnuncio(j);
				encontrou = true;
				break;
			}
		}
	}
	if (!encontrou)
		throw AnuncioNaoEncontrado(ID);
	priority_queue<Anuncio *> tempQ;
	while(!anuncios_pago.empty()){
		if(anuncios_pago.top()->getID() != ID)
			tempQ.push(anuncios_pago.top());
			anuncios_pago.pop();
	}
	while(!tempQ.empty()){
		anuncios_pago.push(tempQ.top());
		tempQ.pop();
	}
	carregaAnuncios();
}

void Olz::eliminaUtilizador(string email){
	bool encontrou =false;
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
			encontrou =true;
		}
	}
	if (!encontrou)
		throw UtilizadorNaoEncontrado(email);
}

void Olz::setUtiNome(int index, string nome){
	if (index >=0 && index < utilizadores.size())
		utilizadores[index].setNome(nome);
	else
		throw PosicaoForadoVetor(index, utilizadores.size());
}

void Olz::setUtiTelemovel(int index, int telemovel){
	if (index >=0 && index < utilizadores.size())
		utilizadores[index].setTelemovel(telemovel);
	else
		throw PosicaoForadoVetor(index, utilizadores.size());
}

void Olz::setUtiLocalizacao(int index, Localizacao localizacao){
	if (index >=0 && index < utilizadores.size())
		utilizadores[index].setLocalizacao(localizacao);
	else
		throw PosicaoForadoVetor(index, utilizadores.size());
}


void Olz::pesquisarUtilizador(string atributo, string pesquisa){
	vector<string> temp;
	int counter = 0;
	for (int i=0; i < utilizadores.size();i++){
		if(atributo == "E" || atributo == "e")
			temp.push_back(utilizadores[i].getEmail());
		else if(atributo == "N" || atributo == "n")
			temp.push_back(utilizadores[i].getNome());
		else if(atributo == "F" || atributo == "f")
			temp.push_back(utilizadores[i].getLocalizacao().getFreguesia());
		else if(atributo == "C" || atributo == "c")
			temp.push_back(utilizadores[i].getLocalizacao().getConcelho());
		else if(atributo == "D" || atributo == "d")
			temp.push_back(utilizadores[i].getLocalizacao().getDistrito());

		if (temp[i].find(pesquisa) != string::npos)
		{
			if (counter != i){

				swap(utilizadores[counter],utilizadores[i]);
			}
			counter++;
		}
	}

	if (counter !=0)
		cout << "Utilizadores até à posição " << counter << " foram detetados na pesquisa." << endl;
	else
		cout << "Não foi encontrado nenhum utilizador relevante. Tente usar outra palavras." << endl;
}

void Olz::pesquisarAnuncio(string atributo, string pesquisa){

	vector<string> temps;
	vector<int> tempi;
	int counter = 0;
	for(int i = 0; i < anuncios.size(); i++){
		if(atributo == "E" || atributo == "e")
			temps.push_back(anuncios[i]->getUtilizador()->getEmail());
		else if(atributo == "T" || atributo == "t")
			temps.push_back(anuncios[i]->getTitulo());
		else if(atributo == "C" || atributo == "c")
			temps.push_back(anuncios[i]->getCategoria());
		else if(atributo == "D" || atributo == "d")
			temps.push_back(anuncios[i]->getDescricao());
		else if(atributo == "N" || atributo == "n")
			tempi.push_back(anuncios[i]->getnumCliques());
		else if(atributo == "I" || atributo == "i")
			tempi.push_back(anuncios[i]->getID());


		if(atributo == "E" || atributo == "T" || atributo == "C" || atributo == "D"|| atributo == "e"|| atributo == "t"|| atributo == "c"|| atributo == "d"){
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

	if (counter !=0)
		cout << "Anúncios até à posição " << counter << " foram detetados na pesquisa." << endl;
	else
		cout << "Não foi encontrado nenhum anúncio relevante. Tente usar outra palavras." << endl;
}

void Olz::pesquisarContacto(string atributo, string pesquisa){
	vector<string> temps;
	vector<int> tempi;
	int counter = 0;
	for(int i = 0; i < contactos.size(); i++){
		if(atributo == "E" || atributo == "e")
			temps.push_back(contactos[i]->getEmail());
		else if(atributo == "C" || atributo == "c")
			temps.push_back(contactos[i]->getContacto());
		else if(atributo == "I" || atributo == "i")
			tempi.push_back(contactos[i]->getAnuncio()->getID());


		if(atributo == "E" || atributo == "C"|| atributo == "e"|| atributo == "c"){
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

		if (counter !=0)
			cout << "Contactos até à posição " << counter << " foram detetados na pesquisa." << endl;
		else
			cout << "Não foi encontrado nenhum contacto relevante. Tente usar outra palavras." << endl;
	}
}

void Olz::addContacto(int ID, Contacto * c){
	bool encontrou = false;
	for(int i = 0; i < anuncios.size(); i++){
		if(anuncios[i]->getID() == ID){
			anuncios[i]->addContacto(c);
			encontrou =true;
			break;
		}
	}
	if (!encontrou)
		throw AnuncioNaoEncontrado(ID);

}

void Olz::lerAnunciosFinalizados() {
	string titulo, categoria, descricao, email, estado;
	int ID, numCliques, preco,nextID;
	string data;
	bool mostraNome, mostraTelemovel, mostraEmail, negociavel;

	ifstream Anun;

	Anun.open("AnunciosFinalizados.txt");
	if (!Anun.good()){
		Anun.close();
		ofstream temp("AnunciosFinalizados.txt");
		temp.close();
		Anun.open("AnunciosFinalizados.txt");
	}


	while(!Anun.eof()) {
		getline(Anun,email);
		if(email!= ""){
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
			Anun >> preco;
			for(int i = 0 ; i < utilizadores.size();i++)
			{
				if(utilizadores[i].getEmail() == email)
				{
					anunciosfinalizados.push_back(new AnuncioFinalizado(&utilizadores[i],Data(data),titulo,categoria,descricao,mostraEmail,mostraNome,mostraTelemovel,ID,preco));
				}
			}
			Anun.ignore();
			getline(Anun,email);
		}
	}
	Anun.close();
}

void Olz::escreverAnunciosFinalizados(){
	ofstream Anun;

	Anun.open("AnunciosFinalizados.txt", ofstream::out | ofstream::trunc);

	for(int i=0; i < anunciosfinalizados.size();i++) {
		Anun << anunciosfinalizados[i]->getUtilizador()->getEmail() << endl
				<< anunciosfinalizados[i]->getTitulo()<<endl
				<< anunciosfinalizados[i]->getCategoria() <<endl
				<< anunciosfinalizados[i]->getID()<<endl
				<< anunciosfinalizados[i]->getData()<<endl
				<< anunciosfinalizados[i]->getnumCliques()<<endl
				<< anunciosfinalizados[i]->getmostraNome()<<endl
				<< anunciosfinalizados[i]->getmostraTelemovel()<<endl
				<< anunciosfinalizados[i]->getmostraEmail()<<endl
				<< anunciosfinalizados[i]->getDescricao()<<endl
				<< anunciosfinalizados[i]->getPreco()<<endl;
		Anun << endl;
	}
	Anun.close();
}

void Olz::pesquisarAnuncioFinalizado(string atributo, string pesquisa){

	vector<string> temps;
	vector<int> tempi;
	int counter = 0;
	for(int i = 0; i < anunciosfinalizados.size(); i++){
		if(atributo == "E" || atributo == "e")
			temps.push_back(anunciosfinalizados[i]->getUtilizador()->getEmail());
		else if(atributo == "T" || atributo == "t")
			temps.push_back(anunciosfinalizados[i]->getTitulo());
		else if(atributo == "C" || atributo == "c")
			temps.push_back(anunciosfinalizados[i]->getCategoria());
		else if(atributo == "D" || atributo == "d")
			temps.push_back(anunciosfinalizados[i]->getDescricao());
		else if(atributo == "N" || atributo == "n")
			tempi.push_back(anunciosfinalizados[i]->getnumCliques());
		else if(atributo == "I" || atributo == "i")
			tempi.push_back(anunciosfinalizados[i]->getID());


		if(atributo == "E" || atributo == "T" || atributo == "C" || atributo == "D"|| atributo == "e"|| atributo == "t"|| atributo == "c"|| atributo == "d"){
			if(temps[i].find(pesquisa) != string::npos){
				if(counter != i){
					swap(anunciosfinalizados[counter], anunciosfinalizados[i]);
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
					swap(anunciosfinalizados[counter], anunciosfinalizados[i]);
				}
				cout << "ENCONTROU" << i;
				counter++;
			}
		}
	}

	if (counter !=0)
		cout << "Anúncios finalizados até à posição " << counter << " foram detetados na pesquisa." << endl;
	else
		cout << "Não foi encontrado nenhum anúncio finalizado relevante. Tente usar outra palavras." << endl;
}

bool Olz::pagaAnuncio(int ID){
	for(unsigned int i = 0; i < utilizadores.size(); i++)
	{
		for(unsigned int j = 0; j < utilizadores[i].getAnuncios().size(); j++)
		{
			if(utilizadores[i].getAnuncios()[j]->getID() == ID)
			{
				utilizadores[i].getAnuncios()[j]->setPago(true);
				return true;
			}
		}
	}
	return false;
}

void Olz::tabelaAnunciosPago(int num_pagina, int num_anuncios_pagina) // Função que imprimi uma tabela com o ID do Utilizador, a Data, o Título e a Categoria
{
	priority_queue<Anuncio *> tempQ;
	cout << endl;
	cout << setw(3) << "#" << setw(4) << "ID" <<setw(11)<< "Data" << setw(7) << "Tipo" << setw(10) << "Titulo" << setw(10) << "Categoria" << setw(15) << "Utilizador" << setw(5) << "Vis." << setw(6) << "Cont." << endl;
	unsigned int j=num_pagina*num_anuncios_pagina;
	while(!(anuncios_pago.empty()) && j < num_pagina*num_anuncios_pagina + num_anuncios_pagina){
		cout << setw(3) << (j+1) << setw(4) << anuncios_pago.top()->getID() << " " << anuncios_pago.top()->getData();
		if (anuncios_pago.top()->getTipo())
			cout << setw(7)  << "Venda" ;
		else
			cout << setw(7)  << "Compra";
		cout << setw(10)  << anuncios_pago.top()->getTitulo().substr(0,9)<<setw(10)  << anuncios_pago.top()->getCategoria().substr(0,9) << setw(15)  << anuncios_pago.top()->getUtilizador()->getEmail().substr(0,14) << setw(5)  << anuncios_pago.top()->getnumCliques() << setw(6)  << anuncios_pago.top()->getContactos().size() << endl;

		tempQ.push(anuncios_pago.top());
		anuncios_pago.pop();
		j++;
	}

	while(!tempQ.empty())
	{
		anuncios_pago.push(tempQ.top());
		tempQ.pop();
	}
}

void Olz::setTituloPago(int ID, string tit){
	priority_queue<Anuncio *> tempQ;
	while(!anuncios_pago.empty()){
		if(anuncios_pago.top()->getID() == ID){
			anuncios_pago.top()->setTitulo(tit);
		}
		tempQ.push(anuncios_pago.top());
		anuncios_pago.pop();
	}
	while(!tempQ.empty()){
		anuncios_pago.push(tempQ.top());
		tempQ.pop();
	}
}

void Olz::setCategoriaPago(int ID, string cat){
	priority_queue<Anuncio *> tempQ;
	while(!anuncios_pago.empty()){
		if(anuncios_pago.top()->getID() == ID){
			anuncios_pago.top()->setCategoria(cat);
		}
		tempQ.push(anuncios_pago.top());
		anuncios_pago.pop();
	}
	while(!tempQ.empty()){
		anuncios_pago.push(tempQ.top());
		tempQ.pop();
	}
}

void Olz::setDescricaoPago(int ID, string desc){
	priority_queue<Anuncio *> tempQ;
	while(!anuncios_pago.empty()){
		if(anuncios_pago.top()->getID() == ID){
			anuncios_pago.top()->setCategoria(desc);
		}
		tempQ.push(anuncios_pago.top());
		anuncios_pago.pop();
	}
	while(!tempQ.empty()){
		anuncios_pago.push(tempQ.top());
		tempQ.pop();
	}
}


void Olz::setMEmailPago(int ID){
	priority_queue<Anuncio *> tempQ;
	while(!anuncios_pago.empty()){
		if(anuncios_pago.top()->getID() == ID){
			anuncios_pago.top()->setmostraEmail();
		}
		tempQ.push(anuncios_pago.top());
		anuncios_pago.pop();
	}
	while(!tempQ.empty()){
		anuncios_pago.push(tempQ.top());
		tempQ.pop();
	}
}

void Olz::setMNomePago(int ID){
	priority_queue<Anuncio *> tempQ;
	while(!anuncios_pago.empty()){
		if(anuncios_pago.top()->getID() == ID){
			anuncios_pago.top()->setmostraNome();
		}
		tempQ.push(anuncios_pago.top());
		anuncios_pago.pop();
	}
	while(!tempQ.empty()){
		anuncios_pago.push(tempQ.top());
		tempQ.pop();
	}
}

void Olz::setMTelemovelPago(int ID){
	priority_queue<Anuncio *> tempQ;
	while(!anuncios_pago.empty()){
		if(anuncios_pago.top()->getID() == ID){
			anuncios_pago.top()->setmostraTelemovel();
		}
		tempQ.push(anuncios_pago.top());
		anuncios_pago.pop();
	}
	while(!tempQ.empty()){
		anuncios_pago.push(tempQ.top());
		tempQ.pop();
	}
}

void Olz::setBUtiNome(string email, string nome){
	BSTItrIn<Utilizador> it(util_por_finalizados);
	//bool res = false;
	while(!it.isAtEnd()){
		if(it.retrieve().getEmail() == email){
			Utilizador  u1 = it.retrieve();
			util_por_finalizados.remove(it.retrieve());
			u1.setNome(nome);
			util_por_finalizados.insert(u1);

		//	res = true;
		}
		it.advance();
	}
}

void Olz::setBUtiTele(string email, int tele){
	BSTItrIn<Utilizador> it(util_por_finalizados);
	//bool res = false;
	while(!it.isAtEnd()){
		if(it.retrieve().getEmail() == email){
			Utilizador  u1 = it.retrieve();
			util_por_finalizados.remove(it.retrieve());
			u1.setTelemovel(tele);
			util_por_finalizados.insert(u1);
		//	res = true;
			break;
		}
		it.advance();
	}
}
