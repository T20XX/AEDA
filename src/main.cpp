#include <iostream>
#include <string>
#include "Utilizador.h"
#include "Olz.h"
using namespace std;

Olz olz;

void selecao1()
{
	std::string nome, email, freguesia, concelho, distrito;
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

		}
		else if (selecao == "PS")
		{

		}
		else if (selecao == "PA")
		{

		}
	}
	olz.escreverUtilizador();
}

void selecao3()
{
	olz.tabelaAnuncios(0,50,"default");
	olz.escreverAnuncio();
}



int main() {
	olz.lerUtilizador();
	olz.addAnuncio(0, new AnuncioVenda(22,"Oculos","sabesbem","sabes",0,0,0,"novo",20,0));
	int selecao=-1;
	while (selecao !=0)
	{
		cout << "Menu" << endl;
		cout << "1. Registar Utilizador" << endl;
		cout << "2. Gerir Utilizadores" << endl;
		cout << "3. Gerir Anúncios" << endl;
		cout << "0. Sair" << endl;
		while (selecao < 0 || selecao > 3)
			cin >> selecao;
		if (selecao == 0)
			break;
		else if (selecao == 1)
			selecao1();
		else if (selecao == 2)
			selecao2();
		else if (selecao == 3)
			selecao3();
		selecao = -1;
	}
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}
