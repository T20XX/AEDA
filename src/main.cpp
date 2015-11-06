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

	cout << "Nome: ";
	cin.ignore();
	getline(cin, nome);
	cout << "Email: ";
	cin >> email;
	cout << "Telemóvel: ";
	cin >> telemovel;
	cin.ignore();
	cout << "Freguesia: ";
	getline(cin, freguesia);
	cout << "Concelho: ";
	getline(cin, concelho);
	cout << "Distrito: ";
	getline(cin, distrito);

	Localizacao tempLocal(freguesia, concelho, distrito);
	Utilizador tempUti(email, nome, telemovel, tempLocal);
	olz.addUtilizador(tempUti);

	cout << "Utilizador criado com sucesso." << endl;
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
	cout << "Utilizador(email): " << endl << "Anuncio Venda ou Compra( C / V ): " << endl << "Titulo: " << endl << "Categoria: " << endl << "Mostrar Email? " << endl
			<< "Mostrar Nome?" << endl << "Mostrar Telemovel?" << endl << "Descrição: " << endl << "Data: " << endl;

	while(index == -1){										//email do Utilizador a fazer Anuncio
		cin >> email;
		for(int i = 0; i < olz.getUtilizadores().size(); i++)
		{
			if(olz.getUtilizadores()[i].getEmail() == email)
			{
				index = i;
				break;
			}
		}
		if(index == -1)
			cout << "Email Indisponível, tente outra vez!" << endl;
	}
	cout << "Introduza C para realizar uma Compra ou V para realizar uma Venda." << endl;
	cin >> tipo;
	while(tipo != 'C' && tipo != 'V'){
		cout << "Por favor, escreva C (de Compra) ou V (de Venda)." << endl; //tipo (venda ou compra)
		cin >> tipo;
		cin.ignore();
	}
	getline(cin, titulo);
	getline(cin, categoria);

	cout << "Introduza S para mostrar o seu Nome ou N para não mostrar o seu Nome." << endl;
	cin >> mostrar;

	while(mostrar != 'S' && mostrar != 'N'){
		cout << "Por favor, escreva S (de Sim) ou N (de Não)." << endl; //mostrarNome
		cin >> mostrar;
	}
	if(mostrar == 'S')
		mostraNome = true;
	else
		mostraNome = false;

	mostrar = 'A';

	cout << "Introduza S para mostrar o seu Email ou N para não mostrar o seu Email." << endl;
	cin >> mostrar;

	while(mostrar != 'S' && mostrar != 'N'){
		cout << "Por favor, escreva S (de Sim) ou N (de Não)." << endl; //mostrarNome
		cin >> mostrar;
	}
	if(mostrar == 'S')
		mostraEmail = true;
	else
		mostraEmail = false;

	mostrar = 'A';

	cout << "Introduza S para mostrar o seu Email ou N para não mostrar o seu Email." << endl;
	cin >> mostrar;

	while(mostrar != 'S' && mostrar != 'N'){
		cout << "Por favor, escreva S (de Sim) ou N (de Não)." << endl; //mostrarNome
		cin >> mostrar;
		cin.ignore();
	}
	if(mostrar == 'S')
		mostraTelemovel = true;
	else
		mostraTelemovel = false;

	getline(cin, descricao);												//descrição

	if(tipo == 'V')
	{
		cout << "Estado: " << endl << "Preço: " << endl << "Negociavel?" << endl;

		estado = "Partido";

		while(estado != "Novo" && estado != "Usando como novo" && estado != "Funcional" && estado != "Para Peças"){
			getline(cin, estado);
		}
		cin >> preco;

		cin >> nego;

		while(nego != 'S' && nego != 'N'){
				cout << "Por favor, escreva S (de Sim) ou N (de Não)." << endl; //mostrarNome
				cin >> nego;
			}
			if(nego == 'S')
				negociavel = true;
			else
				negociavel = false;

		olz.addAnuncio(index, new AnuncioVenda(NULL, data, titulo, categoria, descricao, mostraEmail, mostraNome, mostraTelemovel, estado, preco, negociavel));
	}
	else {
		cout << "Proposta de troca? ( S / N ) " << endl;
		while(troca != 'S' || troca !='N'){
			cin >> troca;
		}
		if(troca == 'S')
		{
			cout << "Introduza o ID: " << endl;
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
		cout << "Pag." << (pag + 1) << ", Utilizadores por Página: " << porpag << endl;
		cout << "Introduza V(er), A(lterar), E(liminar), O(rdenar), P(or Página), PS(Pag. Seguinte), PA(Pag. Anterior) ou S(air)";
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
	int pag = 0, porpag= 50;
		string selecao = "X";
		while (selecao != "S")
		{
			olz.tabelaAnuncios(pag,porpag,"default");
			cin >> selecao;
			if (selecao == "S")
				break;
			else if (selecao == "V")
			{
				cout << "Indique o número do anuncio que deseja visualizar: ";
				int index = -1;
				cin >> index;
				while (index < 1 || index > olz.getAnuncios().size())
				{
					cout << "Número inválido, indique outro: ";
					cin >> index;
				}
				olz.getAnuncios()[index-1]->verAnuncio();
			}
			else if (selecao == "A")
			{

			}
			else if (selecao == "E")
			{
				cout << "Indique o número do anuncio que deseja eliminar: ";
				int index = -1;
				cin >> index;
				while (index < 1 || index > olz.getAnuncios().size())
				{
					cout << "Número inválido, indique outro: ";
					cin >> index;
				}
				olz.getAnuncios()[index-1]->verAnuncio();
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
					porpag = olz.getAnuncios().size();
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
	olz.escreverAnuncio();
}



int main() {
	olz.lerUtilizador();
	olz.lerAnuncio();
	//olz.addAnuncio(0, new AnuncioCompra(NULL,22,"Oculos","sabesbem","sabes",0,0,0,2));
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
	cout << "Obrigado por utilizar o OLZ." << endl;
	return 0;
}
