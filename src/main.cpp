#include <iostream>
#include <string>
#include "Utilizador.h"
#include "Olz.h"
using namespace std;

Olz olz;

void selecao1()
{
	string nome, email, freguesia, concelho, distrito;
	int telemovel;

	cout << "Nome: " << endl << "Email: " << endl << "Telemovel: " << endl << "Freguesia: " << endl << "Concelho: " << endl << "Distrito: " << endl;

	cin >> nome >> email >> telemovel >> freguesia >> concelho >> distrito;

	Localizacao tempLocal(freguesia, concelho, distrito);
	Utilizador tempUti(email, nome, telemovel, tempLocal);
	olz.addUtilizador(tempUti);

	cout << "Utilizador criado com sucesso" << endl;
}

void selecao2()
{

	int data, preco, vendaID, index = -1;
	bool mostraEmail, mostraNome, mostraTelemovel, negociavel;
	string email, titulo, categoria, descricao, estado;
	char tipo = 'J';
	char troca = 'J';
	char mostrar;
	char nego;
	cout << "Utilizador(email): " << endl << "Anuncio Venda ou Compra(C / V): " << endl << "Titulo: " << endl << "Categoria: " << endl << "Mostrar Email? " << endl
			<< "Mostrar Nome?" << endl << "Mostrar Telemovel?" << endl << "Descrição: " << endl << "Data: " << endl;

	while(index == -1){										//email do Utilizador a fazer Anuncio
		cin >> email;
		for(int i = 0; i < olz.getUtilizadores().size(); i++)  // VE LA ISTO SFF
		{
			if(olz.getUtilizadores()[i].getEmail() == email)
			{
				index = i;
				break;
			}
		}
		if(index == -1)
			cout << "Email Indisponivel, tente outra vez!" << endl;
	}
	cin >> tipo;
	while(tipo != 'S' && tipo != 'V'){
		cout << "Tipo indisponivel, tente outra vez!" << endl;//tipo (venda ou compra)
		cin >> tipo;
	}
	cin >> titulo >> categoria;

	cin >> mostrar;

	while(mostrar != 'S' && mostrar != 'N'){
		cout << "Escreva S ou N se faz o favor!" << endl;//mostrarNome
		cin >> mostrar;
	}
	if(mostrar == 'S')
		mostraNome = true;
	else
		mostraNome = false;

	mostrar = 'A';

	cin >> mostrar;

	while(mostrar != 'S' && mostrar != 'N'){
		cout << "Escreva S ou N se faz o favor!" << endl;//mostrarNome
		cin >> mostrar;
	}
	if(mostrar == 'S')
		mostraEmail = true;
	else
		mostraEmail = false;

	mostrar = 'A';

	cin >> mostrar;

	while(mostrar != 'S' && mostrar != 'N'){
		cout << "Escreva S ou N se faz o favor!" << endl;//mostrarNome
		cin >> mostrar;
	}
	if(mostrar == 'S')
		mostraTelemovel = true;
	else
		mostraTelemovel = false;


	cin >> descricao;													//descrição

	if(tipo == 'V')
	{
		cout << "Estado: " << endl << "Preço: " << endl << "Negociavel?" << endl;

		estado = "partido";

		while(estado != "novo" && estado != "usando como novo" && estado != "funcional" && estado != "para peças"){
			cin >> estado;
		}
		cin >> preco;

		cin >> nego;

		while(nego != 'S' && nego != 'N'){
				cout << "Escreva S ou N se faz o favor!" << endl;//mostrarNome
				cin >> nego;
			}
			if(nego == 'S')
				negociavel = true;
			else
				negociavel = false;

		olz.addAnuncio(index, new AnuncioVenda(NULL, data, titulo, categoria, descricao, mostraEmail, mostraNome, mostraTelemovel, estado, preco, negociavel));
	}
	else {
		cout << "Proposta de troca? (S /N) " << endl;
		while(troca != 'S' || troca !='N'){
			cin >> troca;
		}
		if(troca == 'S')
		{
			cout << "Qual o ID?: " << endl;
			cin >> vendaID;
		}
		else
			vendaID = -1;
		olz.addAnuncio(index, new AnuncioCompra(NULL, data, titulo, categoria,  descricao, mostraEmail, mostraNome, mostraTelemovel, vendaID));
	}
}

void selecao3()
{
	int pag = 0, porpag= 50;
	string selecao = "X";
	while (selecao != "S")
	{
		olz.tabelaUtilizadores(pag,porpag,"default");
		cin >> selecao;
		if (selecao == "S")
			break;
		else if (selecao == "V")
		{
			cout << "Indique o número do utilizador que deseja visualizar: ";
			int index = -1;
			cin >> index;
			while (index < 1 || index > olz.getUtilizadores().size())
			{
				cout << "Número inválido, indique outro: ";
				cin >> index;
			}
			olz.getUtilizadores()[index-1].verUtilizador();
		}
		else if (selecao == "A")
		{

		}
		else if (selecao == "E")
		{
			cout << "Indique o número do utilizador que deseja eliminar: ";
			int index = -1;
			cin >> index;
			while (index < 1 || index > olz.getUtilizadores().size())
			{
				cout << "Número inválido, indique outro: ";
				cin >> index;
			}
			olz.getUtilizadores()[index-1].verUtilizador();
		}
		else if (selecao == "O")
		{

		}
		else if (selecao == "P")
		{
			cin >> porpag;
			while (porpag < 0)
			{
				cout << "Número inválido, indique outro: ";
				cin >> porpag;
			}
			if (porpag == 0)
				porpag = olz.getUtilizadores().size();
		}
		else if (selecao == "PS")
		{
			pag++;
		}
		else if (selecao == "PA")
		{
			if (pag > 0)
				pag--;
		}
	}
	olz.escreverUtilizador();
}

void selecao4()
{
	olz.carregaAnuncios();
	olz.tabelaAnuncios(0,50,"default");
	olz.escreverAnuncio();
}



int main() {
	olz.lerUtilizador();
	olz.lerAnuncio();
	olz.addAnuncio(0, new AnuncioVenda(NULL,22,"Oculos","sabesbem","sabes",0,0,0,"novo",20,0));
	olz.addAnuncio(0, new AnuncioVenda(NULL,22,"Oculos","sabesbem","sabes",0,0,0,"novo",20,0));
	olz.addAnuncio(0, new AnuncioVenda(NULL,22,"Oculos","sabesbem","sabes",0,0,0,"novo",20,0));
	olz.carregaAnuncios();
	int selecao=-1;
	while (selecao !=0)
	{
		cout << "Menu" << endl;
		cout << "1. Registar Utilizador" << endl;
		cout << "2. Criar Anuncio" << endl;
		cout << "3. Gerir Utilizadores" << endl;
		cout << "4. Gerir Anúncios" << endl;
		cout << "0. Sair" << endl;
		while (selecao < 0 || selecao > 4)
			cin >> selecao;
		if (selecao == 0)
			break;
		else if (selecao == 1)
			selecao1();
		else if (selecao == 2)
			selecao2();
		else if (selecao == 3)
			selecao3();
		else if (selecao == 4)
			selecao4();
		selecao = -1;
	}
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}
