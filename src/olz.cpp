/*
 * olz.cpp
 *
 *  Created on: 02/11/2015
 *      Author: Jorge
 */

#include "olz.h"
#include <iomanip>

olz::olz() {
	// TODO Auto-generated constructor stub

}

void olz::tabelaAnuncios(int num_pagina, int num_anuncios_pagina, string tipoOrganizacao) // Função que imprimi uma tabela com o ID do Utilizador, a Data, o Título e a Categoria
{
	cout << setw(4) << "ID" << setw(7) << "Data" << setw(7) << "Título" << setw(9) << "Categoria" << endl;
	for (int i=num_pagina*num_anuncios_pagina; i < num_pagina*num_anuncios_pagina + num_anuncios_pagina;i++)
	{
		cout << "merdas alalalallaa" << endl;
	}
}

void olz::tabelaUtilizador(int num_pagina, int num_anuncios_pagina, string tipoOrganizacao) // Função que imprimi uma tabela com o Email, Nome do Utilizador, Telemóvel e Número do Anúncio
{
	cout << setw(7) << "Email" << setw(7) << "Nome" << setw(9) << "Telemóvel" << setw(7) << "Nº Anúncio" << endl;
	for (int i=num_pagina*num_anuncios_pagina; i < num_pagina*num_anuncios_pagina + num_anuncios_pagina;i++)
	{
		cout << setw(7) << Utilizadores[i].getEmail() << setw(7) << Utilizadores[i].getNome() << setw(9) << Utilizadores[i].getTelemovel() << setw(7) << " "  << endl;
	}
}

olz::~olz() {
	// TODO Auto-generated destructor stub
}

