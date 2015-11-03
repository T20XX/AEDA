#include <iostream>
#include "Olz.h"
using namespace std;

Olz olz;

void selecao1()
{

	string nome, email, freguesia, concelho, distrito;
	int telemovel;

	cout << "Nome: " << endl << "Email: " << endl << "Telemovel: " << endl << "Freguesia: " << endl << "Concelho: " << endl << "Distrito: " << endl;

	cin >> nome >> email >> telemovel >> freguesia >> concelho >> distrito;

	Localizacao tempLocal = Localizacao(freguesia, concelho, distrito);
	Utilizador tempUti = Utilizador(email, nome, telemovel, tempLocal);
	olz.addUtilizador(tempUti*);

	cout << "Utilizador criado com sucesso" << endl;
}

void selecao2()
{
olz.tabelaUtilizadores(0,50,"nulo");
}

void selecao3()
{
	olz.tabelaAnuncios(0,50,"nulo");
}



int main() {
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
