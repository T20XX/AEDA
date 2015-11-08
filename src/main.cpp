#include <iostream>
#include <string>
#include "Utilizador.h"
#include "Olz.h"
#include<math.h>
using namespace std;

Olz olz;

void selecao1()
{
	string nome, email, freguesia, concelho, distrito;
	int telemovel;
	bool emailrepetido = true;

	cout << "Introduza os seguintes dados de Utilizador:" << endl;
	cout << "Email: ";
	getline(cin,email);
	while(emailrepetido){
		emailrepetido = false;
		for(int i=0; i < olz.getUtilizadores().size();i++){
			if(olz.getUtilizadores()[i].getEmail() == email){
				cout << "Email já se encontra em uso, introduza outro: ";
				getline(cin, email);
				emailrepetido = true;
				break;
			}
		}
	}
	cout << "Nome: ";
	getline(cin, nome);
	cout << "Telemóvel: ";
	cin >> telemovel;
	while(cin.fail()){
		cin.clear();
		cin.ignore();
		cout << "Número de telemóvel errado, introduza outro: ";
		cin >> telemovel;
	}
	if (!(telemovel> 99999999 && telemovel < 1000000000)){
		cout << "Número de telemóvel não tem nove digitos! Introduza outro: ";
		cin >> telemovel;
	}
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

	olz.escreverUtilizadores();
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
	cout << "Introduza os seguintes dados do Anúncio: " << endl;
	cout << "Utilizador(email): ";

	while(index == -1){										//email do Utilizador a fazer Anuncio
		getline(cin,email);
		for(int i = 0; i < olz.getUtilizadores().size(); i++)
		{
			if(olz.getUtilizadores()[i].getEmail() == email)
			{
				index = i;
				break;
			}
		}
		if(index == -1)
			cout << "Email não existe, introduza outro: ";
	}

	cout << "Introduza C para criar um Anúnio de Compra ou V um de Venda: ";
	cin >> tipo;
	while(tipo != 'C' && tipo != 'c' && tipo != 'V'&& tipo != 'v'){
		cout << "Por favor, escreva C (de Compra) ou V (de Venda): ";
		cin >> tipo;
	}

	cout << "Data(dd/mm/aaaa): ";
	bool dataerrada=true;
	while(dataerrada){
		dataerrada = false;
		cin >> data;
		stringstream s1;
		char tempchar, tempchar1;
		int dia, mes, ano;
		s1 << data;
		s1 >> dia >> tempchar >> mes >> tempchar1 >> ano;
		if(tempchar != '/' || tempchar1 != '/')
			dataerrada = true;
		else if(mes >= 1 && mes<=12){
			if(mes==1 || mes == 3|| mes ==5|| mes == 7|| mes ==9 || mes == 11){
				if(dia <=1 || dia >=30)
					dataerrada = true;
			}
			else if(mes == 4 || mes == 6 || mes == 8 || mes == 10 || mes == 12){
				if(dia <= 1 || dia >=31)
					dataerrada = true;
			}
			else if(mes == 2){
				if(dia <= 1 || dia >= 28)
					dataerrada=true;
			}
		}
		else dataerrada = true;
		if(dataerrada)
			cout << "Data Errada, introduza outra: ";
	}
	cin.ignore();
	cout << "Título: ";
	getline(cin, titulo);
	cout << "Categoria: ";
	getline(cin, categoria);

	cout << "Introduza S para mostrar o seu Nome ou N para não mostrar o seu Nome: "; //mostrarNome
	cin >> mostrar;
	while(mostrar != 'S' && mostrar != 'N' && mostrar != 's' && mostrar !='n'){
		cout << "Por favor, escreva S (de Sim) ou N (de Não): ";
		cin >> mostrar;
	}
	if(mostrar == 'S' || mostrar == 's')
		mostraNome = true;
	else
		mostraNome = false;

	(mostrar == 'A' || mostrar == 'a');

	cout << "Introduza S para mostrar o seu Email ou N para não mostrar o seu Email: ";
	cin >> mostrar;

	while(mostrar != 'S' && mostrar != 'N' && mostrar != 's' && mostrar != 'n'){
		cout << "Por favor, escreva S (de Sim) ou N (de Não: " << endl; //mostrarEmail
		cin >> mostrar;
	}
	if(mostrar == 'S' || mostrar == 's')
		mostraEmail = true;
	else
		mostraEmail = false;

	(mostrar == 'A' || mostrar == 'a');

	cout << "Introduza S para mostrar o seu Telemovel ou N para não mostrar o seu Telemovel: ";
	cin >> mostrar;

	while(mostrar != 'S' && mostrar != 'N' && mostrar != 's' && mostrar != 'n'){
		cout << "Por favor, escreva S (de Sim) ou N (de Não): "; //mostrarTelemovel
		cin >> mostrar;
	}
	if(mostrar == 'S' || mostrar == 's')
		mostraTelemovel = true;
	else
		mostraTelemovel = false;

	cout << "Descrição: ";
	cin.ignore();
	getline(cin, descricao);												//descrição

	if(mostrar == 'V' || mostrar == 'v')
	{
		cout << "Estado(Novo,Usando como novo, Funcional ou Para Peças): " ;
		estado = "Partido";

		getline(cin, estado);
		while(estado != "Novo" && estado != "Usando como novo" && estado != "Funcional" && estado != "Para Peças"){
			cout << "Estado inválido: ";
					getline(cin, estado);
		}

		cout << "Preço: ";
		cin >> preco;
		while(cin.fail()){
			cout << "Introduza um preço valido: ";
			cin >> preco;
		}

		cout << "Negociavel(S/N)? ";
		cin >> nego;
		while(nego != 'S' && nego != 'N' && nego != 's'&& nego != 'n'){
			cout << "Por favor, escreva S (de Sim) ou N (de Não): ";
			cin >> nego;
		}
		if(nego == 'S' || nego == 's')
			negociavel = true;
		else
			negociavel = false;

		olz.addAnuncio(index, new AnuncioVenda(NULL, Data(data), titulo, categoria, descricao, mostraEmail, mostraNome, mostraTelemovel, estado, preco, negociavel));
	}
	else {
		cout << "Proposta de troca?(S/N) ";
		while(troca != 'S' && troca !='N' && troca != 's' && troca != 'n'){
			cin >> troca;
		}
		if(troca == 'S' || troca == 's')
		{
			cout << "Introduza o ID: " << endl;
			cin >> vendaID;
			while(cin.fail()){
				cin.clear();
				cin.ignore();
				cin >> vendaID;
			}
		}
		else
			vendaID = -1;
		olz.addAnuncio(index, new AnuncioCompra(NULL, Data(data), titulo, categoria,  descricao, mostraEmail, mostraNome, mostraTelemovel, vendaID));
	}
	olz.carregaAnuncios();
	olz.escreverAnuncios();
}

void selecao3()
{
	int ID, index=-1;
	string email, mensagem;
	string data;
	cout << "Indique o ID do anúncio para o qual pretende realizar contacto: ";
	while(index == -1){										//email do Utilizador a fazer Anuncio
		cin >> ID;
		for(int i = 0; i < olz.getAnuncios().size(); i++)
		{
			if(olz.getAnuncios()[i]->getID() == ID)
			{
				index = i;
				break;
			}
		}
		if(index == -1)
			cout << "ID Indisponível, tente outra vez: ";
	}
	cout << "Data(dd/mm/aaaa): ";
	bool dataerrada=true;
	while(dataerrada){
		dataerrada = false;
		cin >> data;
		stringstream s1;
		char tempchar, tempchar1;
		int dia, mes, ano;
		s1 << data;
		s1 >> dia >> tempchar >> mes >> tempchar1 >> ano;
		if(tempchar != '/' || tempchar1 != '/')
			dataerrada = true;
		else if(mes >= 1 && mes<=12){
			if(mes==1 || mes == 3|| mes ==5|| mes == 7|| mes ==9 || mes == 11){
				if(dia <=1 || dia >=30)
					dataerrada = true;
			}
			else if(mes == 4 || mes == 6 || mes == 8 || mes == 10 || mes == 12){
				if(dia <= 1 || dia >=31)
					dataerrada = true;
			}
			else if(mes == 2){
				if(dia <= 1 || dia >= 28)
					dataerrada=true;
			}
		}
		else dataerrada = true;
		if(dataerrada)
			cout << "Data Errada, introduza outra: ";
	}
	cin.ignore();
	cout << "Indique o seu email: ";
	getline(cin,email);
	cout << "Indique a mensagem que quer enviar: ";
	getline(cin, mensagem);

	olz.addContacto(olz.getAnuncios()[index]->getID(), new Contacto(olz.getAnuncios()[index], data, email, mensagem));
	olz.carregaContactos();
	olz.escreverContactos();
}
void selecao4()
{
	int pag = 0, porpag= 50;
	string tipoOrd = "EA";
	string selecao = "X";
	string tipoPes, tipoAlt;
	while (selecao != "S")
	{
		olz.tabelaUtilizadores(pag,porpag,tipoOrd);
		cout << "Pag." << (pag + 1) << ", Utilizadores por Página: " << porpag << endl;
		cout << "Introduza V(er), A(lterar), E(liminar), O(rdenar), P(esquisa), PP(or Página), PS(Pag. Seguinte), PA(Pag. Anterior) ou S(air)";
		cin >> selecao;
		if (selecao == "S" || selecao == "s")
			break;
		else if (selecao == "V" || selecao == "v")
		{
			cout << "Indique o número do utilizador que deseja visualizar: ";
			int index = -1;
			cin >> index;
			while(cin.fail()){
				cout << "Indique um número: ";
				cin.clear();
				cin.ignore();
				cin >> index;
			while (index < 1 || index > olz.getUtilizadores().size())
			{
				cout << "Número inválido, indique outro: ";
				cin >> index;

				}
			}
			olz.getUtilizadores()[index-1].verUtilizador();
		}
		else if (selecao == "A" || selecao == "a")
		{
			cout << "Indique o número do utilizador que deseja alterar: ";
			int index = -1;
			cin >> index;
			while(cin.fail()){
				cout << "Indique um número :";
				cin >> index;
			while (index < 1 || index > olz.getUtilizadores().size())
			{
				cout << "Número inválido, indique outro: ";
				cin >> index;
				}
			}

			cout <<"Indique o que deseja alterar do Utilizador: ";
			string tempinfo = "erro";
			cin >> tempinfo;

			while(tempinfo != "N" && tempinfo!= "T" && tempinfo!= "L" && tempinfo != "n" && tempinfo!= "t" && tempinfo!= "l")
			{
				cout << "Informação Invalida, tente outra vez: ";
				cin >> tempinfo;
			}
			cin.ignore();


			if(tempinfo == "N" || tempinfo == "n"){
				cout << "Insira novo nome desejado: ";
				getline(cin, tempinfo);
				olz.setUtiNome(index-1,tempinfo);
			}
			else if(tempinfo == "T" || tempinfo == "t"){
				cout << "Insira telemovel novo";
				int temptele;
				cin >> temptele;
				cin.ignore();
				olz.setUtiTelemovel(index-1,temptele);
			}
			else if(tempinfo == "L" || tempinfo == "l"){
				string tempd, tempf, tempc;
				cout << "Freguesia nova: ";
				getline(cin, tempf);
				cout << "Concelho novo: ";
				getline(cin, tempc);
				cout << "Distrito: ";
				getline(cin, tempd);
				olz.setUtiLocalizacao(index-1,Localizacao(tempf,tempc,tempd));
			}
		}
		else if (selecao == "E" || selecao == "e")
		{
			cout << "Indique o número do utilizador que deseja eliminar: ";
			int index = -1;
			cin >> index;
			while(cin.fail()){
				cout << "Indique um número:	";
				cin.clear();
				cin.ignore();
				cin >> index;
			while (index < 1 || index > olz.getUtilizadores().size())
			{
				cout << "Número inválido, indique outro: ";
				cin >> index;
			}
		}
			olz.eliminaUtilizador(olz.getUtilizadores()[index-1].getEmail());
		}
		else if (selecao == "O" || selecao == "o")
		{	cout << "Tipo ordenação: " << endl;
		cout << "E(mail), N(ome), A(nuncios), D(istrito) + A(scendente), D(escendente)";
		cin >> tipoOrd;
		}
		else if (selecao == "P" || selecao == "p")
		{
			cout << "Em que atributo deseja procurar:: E(mail), N(ome), A(nuncios), D(istrito), F(reguesia), C(oncelho)";
			cin >> tipoPes;
			cout << "O que deseja procurar: ";
			cin >> tipoAlt;
			olz.pesquisarUtilizador(tipoPes,tipoAlt);
			tipoOrd= "nulo";
		}
		else if (selecao == "PP" || selecao == "pp")
		{
			cin >> porpag;
			while(cin.fail()){
				cout<< "Indique um número: ";
				cin.clear();
				cin.ignore();
				cin >> porpag;

			while (porpag < 0)
			{
				cout << "Número inválido, indique outro: ";
				cin >> porpag;
				}
		}
			if (porpag == 0)
				porpag = olz.getUtilizadores().size();
			pag=0;
		}
		else if (selecao == "PS" || selecao == "ps")
		{
			if(porpag*(pag+1) < olz.getUtilizadores().size())
				pag++;
		}
		else if (selecao == "PA"|| selecao == "pa")
		{
			if (pag > 0)
				pag--;
		}
	}
	olz.escreverUtilizadores();

}

void selecao5()
{
	olz.carregaAnuncios();
	int pag = 0, porpag= 50;
	string selecao = "X";
	string tipoOrd = "IA";
	string tipoPes = "I";
	string tipoAlt;
	while (selecao != "S" || selecao != "s")
	{
		olz.tabelaAnuncios(pag,porpag,tipoOrd);

		cout << "Pag." << (pag + 1) << ", Anuncios por Página: " << porpag << endl;
		cout << "Introduza V(er), A(lterar), E(liminar), O(rdenar), P(esquisa), PP(or Página), PS(Pag. Seguinte), PA(Pag. Anterior) ou S(air)";
		cin >> selecao;
		if (selecao == "S" || selecao == "s")
			break;
		else if (selecao == "V" || selecao == "v")
		{
			cout << "Indique o número do anuncio que deseja visualizar: ";
			int index = -1;
			cin >> index;
			while(cin.fail()){
				cout << "Indique um número: ";
				cin.clear();
				cin.ignore();
				cin >> index;
			while (index < 1 || index > olz.getAnuncios().size())
			{
				cout << "Número inválido, indique outro: ";
				cin >> index;
				}
			}
			olz.getAnuncios()[index-1]->verAnuncio();
		}
		else if (selecao == "A" || selecao == "a")
		{
			cout << "Indique o número do anuncio que deseja alterar: ";
			int index = -1;
			cin >> index;
			while(cin.fail()){
				cout << "Indique um número: ";
				cin.clear();
				cin.ignore();
				cin >> index;
			while (index < 1 || index > olz.getAnuncios().size())
			{
				cout << "Número inválido, indique outro: ";
				cin >> index;
				}
			}

			cout <<"Indique o que deseja alterar do Anúncio: ";
			string tempinfo = "erro";
			cin >> tempinfo;

			while(tempinfo != "Titulo" && tempinfo!= "Categoria" && tempinfo!= "Descrição" && tempinfo != "Mostra Email" && tempinfo != "Mostra Nome" && tempinfo != "Mostra Telemovel")
			{

				cout << "Informação Invalida, tente outra vez: ";
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
						else if(tempinfo == "Descrição"){
							cout << "Nova descrição: ";
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

		else if (selecao == "E" || selecao == "e")
		{
			cout << "Indique o número do anuncio que deseja eliminar: ";
			int index = -1;
			cin >> index;
			while(cin.fail()){
				cout << "Indique um número: ";
				cin.clear();
				cin.ignore();
				cin >> index;
			while (index < 1 || index > olz.getAnuncios().size())
			{
				cout << "Número inválido, indique outro: ";
				cin >> index;
				}
			}
			olz.eliminaAnuncio(olz.getAnuncios()[index-1]->getID());
		}
		else if (selecao == "O"|| selecao == "o")
		{
			cout << "I(D), D(ata), T(ítulo), C(ategoria), N(úmero de Cliques)  + A(scendente), D(escendente)";
			cin >> tipoOrd;
		}
		else if(selecao == "P" || selecao == "p")
		{
			cout << "Em que atributo deseja procurar: I(D), D(escrição), T(ítulo), C(ategoria), N(úmero de Cliques). E(mail); ";
			cin >> tipoPes;
			cout << "O que deseja alterar??";
			cin >> tipoAlt;
			olz.pesquisarAnuncio(tipoPes,tipoAlt);
			tipoOrd= "nulo";
		}
		else if (selecao == "PP" || selecao == "pp")
		{
			cin >> porpag;
			while(cin.fail()){
				cout<< "Indique um número: ";
				cin.clear();
				cin.ignore();
				cin >> porpag;

			while (porpag < 0)
			{
				cout << "Número inválido, indique outro: ";
				cin >> porpag;

				}
			}
			if (porpag == 0)
				porpag = olz.getAnuncios().size();
			pag = 0;
		}
		else if (selecao == "PS" || selecao == "ps")
		{
			if(porpag*(pag+1) < olz.getAnuncios().size())
				pag++;
		}
		else if (selecao == "PA" || selecao == "pa")
		{
			if (pag > 0)
				pag--;
		}
	}
	olz.escreverAnuncios();

}

void selecao6()
{
	int pag = 0, porpag= 50;
	string selecao = "X";
	string tipoOrd = "IA";
	string tipoPes = "I";
	string tipoAlt;
	while (selecao != "S")
	{
		olz.tabelaAnunciosFinalizados(pag,porpag,tipoOrd);
		cout << "Pag." << (pag + 1) << ", Anuncios por Página: " << porpag << endl;
		cout << "Introduza V(er), O(rdenar), P(esquisa), PP(or Página), PS(Pag. Seguinte), PA(Pag. Anterior) ou S(air)";
		cin >> selecao;
		if (selecao == "S" || selecao == "s")
			break;
		else if (selecao == "V" || selecao == "v")
		{
			cout << "Indique o número do anuncio que deseja visualizar: ";
			int index = -1;
			cin >> index;
			while(cin.fail()){
				cout<< "Indique um número: ";
				cin.clear();
				cin.ignore();
				cin >> index;

			while (index < 1 || index > olz.getAnunciosFinalizados().size())
			{
				cout << "Número inválido, indique outro: ";
				cin >> index;

				}
			}
			olz.getAnunciosFinalizados()[index-1]->verAnuncio();
		}
		else if (selecao == "O" || selecao == "o")
		{
			cout << "I(D), D(ata), T(ítulo), C(ategoria), N(úmero de Cliques)  + A(scendente), D(escendente)";
			cin >> tipoOrd;
		}
		else if(selecao == "P"|| selecao == "p")
		{
			cout << "Em que atributo deseja procurar: I(D), D(escrição), T(ítulo), C(ategoria), N(úmero de Cliques). E(mail); ";
			cin >> tipoPes;
			cout << "O que deseja alterar??";
			cin >> tipoAlt;
			olz.pesquisarAnuncioFinalizado(tipoPes,tipoAlt);
			tipoOrd= "nulo";
		}
		else if (selecao == "PP" || selecao == "pp")
		{
			cin >> porpag;
			while(cin.fail()){
				cout<< "Indique um número: ";
				cin.clear();
				cin.ignore();
				cin >> porpag;

			while (porpag < 0)
			{
				cout << "Número inválido, indique outro: ";
				cin >> porpag;

				}
			}
			if (porpag == 0)
				porpag = olz.getAnunciosFinalizados().size();
			pag = 0;
		}
		else if (selecao == "PS" || selecao == "ps")
		{
			if(porpag*(pag+1) < olz.getAnunciosFinalizados().size())
				pag++;
		}
		else if (selecao == "PA" || selecao == "pa")
		{
			if (pag > 0)
				pag--;
		}
	}
	olz.escreverAnunciosFinalizados();

}

void selecao7()
{
	olz.carregaContactos();
	int pag = 0, porpag= 50;
	string selecao = "X";
	string tipoOrd = "DA";
	string tipoPes, tipoAlt;
	while (selecao != "S")
	{
		olz.tabelaContactos(pag,porpag,tipoOrd);
		cout << "Pag." << (pag + 1) << ", Contactos por Página: " << porpag << endl;
		cout << "Introduza V(er), A(lterar), E(liminar), O(rdenar), P(esquisa), PP(or Página), PS(Pag. Seguinte), PA(Pag. Anterior) ou S(air)";
		cin >> selecao;
		if (selecao == "S" || selecao == "s")
			break;
		else if (selecao == "V" || selecao == "v")
		{
			cout << "Indique o número do contacto que deseja visualizar: ";
			int index = -1;
			cin >> index;
			while(cin.fail()){
				cout<< "Indique um número: ";
				cin.clear();
				cin.ignore();
				cin >> index;

			while (index < 1 || index > olz.getContactos().size())
			{
				cout << "Número inválido, indique outro: ";
				cin >> index;

				}
			}
			olz.getContactos()[index-1]->verContacto();
		}
		else if (selecao == "A" || selecao == "a")
		{
			cout << "Indique o número do contacto que deseja alterar: ";
			int index = -1;
			cin >> index;
			while(cin.fail()){
				cout<< "Indique um número: ";
				cin.clear();
				cin.ignore();
				cin >> index;

			while (index < 1 || index > olz.getContactos().size())
			{
				cout << "Número inválido, indique outro: ";
				cin >> index;

				}
			}

			cout <<"Indique o que deseja alterar do Contacto: ";
			string tempinfo = "erro";
			cin >> tempinfo;

			while(tempinfo != "Email" && tempinfo!= "Contacto")
			{

				cout << "Informação Invalida, tente outra vez: ";
				cin >> tempinfo;
			}

			cin.ignore();
			for (int i=0; i< olz.getContactos().size(); i++){
				if (olz.getContactos()[i]->getEmail() == olz.getContactos()[index-1]->getEmail())
				{
					if(tempinfo == "Email"){
						cout << "Email novo: ";
						getline(cin, tempinfo);
						olz.getContactos()[i]->setEmail(tempinfo);
					}
					else if(tempinfo == "Contacto"){
						cout << "Contacto novo: ";
						getline(cin, tempinfo);
						olz.getContactos()[i]->setContacto(tempinfo);
					}

					break;
				}
			}
			olz.carregaContactos();
		}
		else if (selecao == "O" || selecao == "o")
		{
			cout << "D(ata), A(núncio), E(mail) + A(scendente), D(escendente)";
			cin >> tipoOrd;
		}
		else if(selecao == "P" || selecao == "p")
		{
			cout << "Em que atributo deseja procurar: I(D), E(mail), C(ontacto)";
			cin >> tipoPes;
			cout << "O que deseja alterar??";
			cin >> tipoAlt;
			olz.pesquisarContacto(tipoPes,tipoAlt);
			tipoOrd= "nulo";
		}
		else if (selecao == "PP" || selecao == "pp")
		{
			cin >> porpag;
			while (porpag < 0)
			{
				cout << "Número inválido, indique outro: ";
				cin >> porpag;
				while(cin.fail()){
					cout<< "Indique um número: ";
					cin.clear();
					cin.ignore();
					cin >> porpag;
				}
			}
			if (porpag == 0)
				porpag = olz.getContactos().size();
			pag = 0;
		}
		else if (selecao == "PS" || selecao == "ps")
		{
			if(porpag*(pag+1) < olz.getContactos().size())
				pag++;
		}
		else if (selecao == "PA" || selecao == "pa")
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
	olz.lerAnunciosFinalizados();
	olz.lerContactos();
	olz.carregaAnuncios();
	olz.carregaContactos();
	int selecao=-1;
	while (selecao !=0)
	{
		cout << "Menu" << endl;
		cout << "1. Registar Utilizador" << endl;
		cout << "2. Criar Anuncio" << endl;
		cout << "3. Criar Contacto" << endl;
		cout << "4. Gerir Utilizadores" << endl;
		cout << "5. Gerir Anúncios" << endl;
		cout << "6. Gerir Anúncios Finalizados" << endl;
		cout << "7. Gerir Contactos" << endl;
		cout << "0. Sair" << endl;

		cin >> selecao;
		while(cin.fail()){
			cout << "Indique 1,2,3,4,5,6,7 ou 0: ";
			cin.clear();
			cin.ignore();
			cin >> selecao;
		}
		while (selecao < 0 || selecao > 7){
			cout << "Número de seleção invalido, tente outro: ";
			cin.clear();
			cin.ignore();
			cin >> selecao;
		}
		cin.ignore();
		if (selecao == 0)
			break;
		else if (selecao == 1)
			selecao1();
		else if (selecao == 2 && olz.getUtilizadores().size() > 0)
			selecao2();
		else if(selecao == 3 && olz.getAnuncios().size() > 0)
			selecao3();
		else if (selecao == 4 && olz.getUtilizadores().size() > 0)
			selecao4();
		else if (selecao == 5 && olz.getAnuncios().size() > 0)
			selecao5();
		else if (selecao == 6 && olz.getAnunciosFinalizados().size() > 0)
			selecao6();
		else if (selecao == 7 && olz.getContactos().size() > 0)
			selecao7();
		else if ((selecao == 2 || selecao == 4)&& olz.getUtilizadores().size() == 0)
			cout << "Não existem utilizadores." << endl;

		else if ((selecao == 3 || selecao == 5) && olz.getAnuncios().size() == 0)
			cout << "Não existem anúncios." << endl;

		else if (selecao == 6 && olz.getAnunciosFinalizados().size() == 0)
			cout << "Não existem anúncios finalizados." << endl;
		else if (selecao == 7 && olz.getContactos().size() == 0)
			cout << "Não existem contactos." << endl;
		selecao = -1;
	}
	cout << "Obrigado por utilizar o OLZ." << endl;
	return 0;
}
