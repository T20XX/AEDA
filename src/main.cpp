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
	cout << "Telem�vel: ";
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

	int preco, vendaID, index = -1;
	bool mostraEmail, mostraNome, mostraTelemovel, negociavel;
	string email, titulo, categoria, descricao, estado, data;
	char tipo = 'J';
	char troca = 'J';
	char mostrar;
	char nego;
	cout << "Utilizador(email): ";

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
			cout << "Email Indispon�vel, tente outra vez!" << endl;
	}
	cout << "Introduza C para realizar uma Compra ou V para realizar uma Venda." << endl;
	cin >> tipo;
	while(tipo != 'C' && tipo != 'V'){
		cout << "Por favor, escreva C (de Compra) ou V (de Venda)." << endl; //tipo (venda ou compra)
		cin >> tipo;
	}
	cout << "Data(dd/mm/aaaa): ";
	cin >>data;
	cin.ignore();
	cout << "T�tulo: ";
	getline(cin, titulo);
	cout << "Categoria: ";
	getline(cin, categoria);

	cout << "Introduza S para mostrar o seu Nome ou N para n�o mostrar o seu Nome." << endl;
	cin >> mostrar;

	while(mostrar != 'S' && mostrar != 'N'){
		cout << "Por favor, escreva S (de Sim) ou N (de N�o)." << endl; //mostrarNome
		cin >> mostrar;
	}
	if(mostrar == 'S')
		mostraNome = true;
	else
		mostraNome = false;

	mostrar = 'A';

	cout << "Introduza S para mostrar o seu Email ou N para n�o mostrar o seu Email." << endl;
	cin >> mostrar;

	while(mostrar != 'S' && mostrar != 'N'){
		cout << "Por favor, escreva S (de Sim) ou N (de N�o)." << endl; //mostrarNome
		cin >> mostrar;
	}
	if(mostrar == 'S')
		mostraEmail = true;
	else
		mostraEmail = false;

	mostrar = 'A';

	cout << "Introduza S para mostrar o seu Email ou N para n�o mostrar o seu Email." << endl;
	cin >> mostrar;

	while(mostrar != 'S' && mostrar != 'N'){
		cout << "Por favor, escreva S (de Sim) ou N (de N�o)." << endl; //mostrarNome
		cin >> mostrar;
	}
	if(mostrar == 'S')
		mostraTelemovel = true;
	else
		mostraTelemovel = false;

	cout << "Descri��o: ";
	cin.ignore();
	getline(cin, descricao);												//descri��o

	if(tipo == 'V')
	{
		cout << "Estado: " << endl << "Pre�o: " << endl << "Negociavel?" << endl;

		estado = "Partido";

		while(estado != "Novo" && estado != "Usando como novo" && estado != "Funcional" && estado != "Para Pe�as"){
			getline(cin, estado);
		}

		cin >> preco;

		cin >> nego;

		while(nego != 'S' && nego != 'N'){
			cout << "Por favor, escreva S (de Sim) ou N (de N�o)." << endl; //mostrarNome
			cin >> nego;
		}
		if(nego == 'S')
			negociavel = true;
		else
			negociavel = false;

		olz.addAnuncio(index, new AnuncioVenda(NULL, Data(data), titulo, categoria, descricao, mostraEmail, mostraNome, mostraTelemovel, estado, preco, negociavel));
	}
	else {
		cout << "Proposta de troca? ( S / N ) " << endl;
		while(troca != 'S' && troca !='N'){
			cin >> troca;
		}
		if(troca == 'S')
		{
			cout << "Introduza o ID: " << endl;
			cin >> vendaID;
		}
		else
			vendaID = -1;
		olz.addAnuncio(index, new AnuncioCompra(NULL, Data(data), titulo, categoria,  descricao, mostraEmail, mostraNome, mostraTelemovel, vendaID));
	}
}

void selecao3()
{
	int pag = 0, porpag= 50;
	string tipoOrd = "EA";
	string selecao = "X";
	while (selecao != "S")
	{
		olz.tabelaUtilizadores(pag,porpag,tipoOrd);
		cout << "Pag." << (pag + 1) << ", Utilizadores por P�gina: " << porpag << endl;
		cout << "Introduza V(er), A(lterar), E(liminar), O(rdenar), P(or P�gina), PS(Pag. Seguinte), PA(Pag. Anterior) ou S(air)";
		cin >> selecao;
		if (selecao == "S")
			break;
		else if (selecao == "V")
		{
			cout << "Indique o n�mero do utilizador que deseja visualizar: ";
			int index = -1;
			cin >> index;
			while (index < 1 || index > olz.getUtilizadores().size())
			{
				cout << "N�mero inv�lido, indique outro: ";
				cin >> index;
			}
			olz.getUtilizadores()[index-1].verUtilizador();
		}
		else if (selecao == "A")
		{
			cout << "Indique o n�mero do anuncio que deseja alterar: ";
			int index = -1;
			cin >> index;
			while (index < 1 || index > olz.getAnuncios().size())
			{
				cout << "N�mero inv�lido, indique outro: ";
				cin >> index;
			}

			cout <<"Indique o que deseja alterar do An�ncio: ";
			string tempinfo = "erro";
			cin >> tempinfo;

			while(tempinfo != "N" && tempinfo!= "T" && tempinfo!= "L")
			{
				cout << "Informa��o Invalida, tente outra vez: ";
				cin >> tempinfo;
			}
			cin.ignore();


			if(tempinfo == "N"){
				cout << "Insira novo nome desejado: ";
				getline(cin, tempinfo);
				olz.setUtiNome(index-1,tempinfo);
			}
			else if(tempinfo == "T"){
				cout << "Insira telemovel novo";
				int temptele;
				cin >> temptele;
				cin.ignore();
				olz.setUtiTelemovel(index-1,temptele);
			}
			else if(tempinfo == "L"){
				string tempd, tempf, tempc;
				cout << "Freguesia nova: " << endl << "Concelho novo: " << endl << "Distrito: ";
				getline(cin, tempf);
				getline(cin, tempc);
				getline(cin, tempd);
				olz.setUtiLocalizacao(index-1,Localizacao(tempf,tempc,tempd));
			}
		}
		else if (selecao == "E")
		{
			cout << "Indique o n�mero do utilizador que deseja eliminar: ";
			int index = -1;
			cin >> index;
			while (index < 1 || index > olz.getUtilizadores().size())
			{
				cout << "N�mero inv�lido, indique outro: ";
				cin >> index;
			}
			olz.eliminaUtilizador(olz.getUtilizadores()[index-1].getEmail());
		}
		else if (selecao == "O")
		{
			cout << "E(mail), N(ome), A(nuncios), D(istrito) + A(scendente), D(escendente)";
			cin >> tipoOrd;
		}
		else if (selecao == "P")
		{
olz.pesquisarUtilizador("N","elmo");
tipoOrd= "nulo";
		}
		else if (selecao == "PP")
		{
			cin >> porpag;
			while (porpag < 0)
			{
				cout << "N�mero inv�lido, indique outro: ";
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
	olz.escreverUtilizadores();
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
			cout << "Indique o n�mero do anuncio que deseja visualizar: ";
			int index = -1;
			cin >> index;
			while (index < 1 || index > olz.getAnuncios().size())
			{
				cout << "N�mero inv�lido, indique outro: ";
				cin >> index;
			}
			olz.getAnuncios()[index-1]->verAnuncio();
		}
		else if (selecao == "A")
		{
			cout << "Indique o n�mero do anuncio que deseja alterar: ";
			int index = -1;
			cin >> index;
			while (index < 1 || index > olz.getAnuncios().size())
			{
				cout << "N�mero inv�lido, indique outro: ";
				cin >> index;
			}

			cout <<"Indique o que deseja alterar do An�ncio: ";
			string tempinfo = "erro";
			cin >> tempinfo;

			while(tempinfo != "Titulo" && tempinfo!= "Categoria" && tempinfo!= "Descri��o" && tempinfo != "Mostra Email" && tempinfo != "Mostra Nome" && tempinfo != "Mostra Telemovel")
			{

				cout << "Informa��o Invalida, tente outra vez: ";
				cin >> tempinfo;
			}

			cin.ignore();
			for (int i=0; i < olz.getUtilizadores().size(); i++)
			{
				for (int j=0; j< olz.getUtilizadores()[i].getAnuncios().size(); j++)
					if (olz.getUtilizadores()[i].getAnuncios()[j]->getID() == olz.getAnuncios()[index-1]->getID())
					{
						if(tempinfo == "Titulo"){
							cout << "Titulo novo: ";
							getline(cin, tempinfo);
							olz.getUtilizadores()[i].getAnuncios()[j]->setTitulo(tempinfo);
						}
						else if(tempinfo == "Categoria"){
							cout << "Categoria nova: ";
							getline(cin, tempinfo);
							olz.getUtilizadores()[i].getAnuncios()[j]->setCategoria(tempinfo);
						}
						else if(tempinfo == "Descri��o"){
							cout << "Nova descri��o: ";
							getline(cin, tempinfo);
							olz.getUtilizadores()[i].getAnuncios()[j]->setDescricao(tempinfo);
						}
						else if(tempinfo == "Mostra Email")
							olz.getUtilizadores()[i].getAnuncios()[j]->setmostraEmail();
						else if(tempinfo == "Mostra Nome")
							olz.getUtilizadores()[i].getAnuncios()[j]->setmostraNome();
						else if(tempinfo == "Mostra Telemovel")
							olz.getUtilizadores()[i].getAnuncios()[j]->setmostraTelemovel();
						break;
					}
			}
			olz.carregaAnuncios();
		}

		else if (selecao == "E")
		{
			cout << "Indique o n�mero do anuncio que deseja eliminar: ";
			int index = -1;
			cin >> index;
			while (index < 1 || index > olz.getAnuncios().size())
			{
				cout << "N�mero inv�lido, indique outro: ";
				cin >> index;
			}
			olz.eliminaAnuncio(olz.getAnuncios()[index-1]->getID());
		}
		else if (selecao == "O")
		{

		}
		else if (selecao == "PP")
		{
			cin >> porpag;
			while (porpag < 0)
			{
				cout << "N�mero inv�lido, indique outro: ";
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
	olz.escreverAnuncios();
}

void selecao5()
{
	//olz.carregaContactos();
	int pag = 0, porpag= 50;
	string selecao = "X";
	while (selecao != "S")
	{
		//olz.tabelaContactos(pag,porpag,"default");
		cin >> selecao;
		if (selecao == "S")
			break;
		else if (selecao == "V")
		{

		}
		else if (selecao == "A")
		{

		}
		else if (selecao == "E")
		{

		}
		else if (selecao == "O")
		{

		}
		else if (selecao == "P")
		{

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
	olz.escreverContactos();
}



int main() {
	olz.lerUtilizadores();
	olz.lerAnuncios();
	olz.lerContactos();
	//olz.addAnuncio(0, new AnuncioCompra(NULL,22,"Oculos","sabesbem","sabes",0,0,0,2));
	olz.carregaAnuncios();
	olz.carregaContactos();
	int selecao=-1;
	while (selecao !=0)
	{
		cout << "Menu" << endl;
		cout << "1. Registar Utilizador" << endl;
		cout << "2. Criar Anuncio" << endl;
		cout << "3. Gerir Utilizadores" << endl;
		cout << "4. Gerir An�ncios" << endl;
		cout << "5. Gerir Contactos" << endl;
		cout << "0. Sair" << endl;
		while (selecao < 0 || selecao > 5)
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
		else if (selecao == 5)
			selecao5();
		selecao = -1;
	}
	cout << "Obrigado por utilizar o OLZ." << endl;
	return 0;
}
