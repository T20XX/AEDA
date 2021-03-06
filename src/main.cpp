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
				cout << "Email j� se encontra em uso, introduza outro: ";
				getline(cin, email);
				emailrepetido = true;
				break;
			}
		}
	}
	cout << "Nome: ";
	getline(cin, nome);
	cout << "Telemovel: ";
	int temptele;
	cin >> temptele;
	while(cin.fail()){
		cout << "N�mero de telem�vel inv�lido, introduza outro: ";
		cin.clear();
		cin.ignore();
		cin >> temptele;
	}
	while (!(temptele > 99999999 && temptele < 1000000000)){
		cout << "N�mero de telem�vel n�o tem nove digitos! Introduza outro: ";
		cin >> temptele;
		while(cin.fail()){
			cout << "N�mero de telem�vel inv�lido, introduza outro: ";
			cin.clear();
			cin.ignore();
			cin >> temptele;
		}
	}
	cin.ignore();
	cout << "Freguesia: ";
	getline(cin, freguesia);
	cout << "Concelho: ";
	getline(cin, concelho);
	cout << "Distrito: ";
	getline(cin, distrito);

	Localizacao tempLocal(freguesia, concelho, distrito);
	Utilizador tempUti(email, nome, temptele, tempLocal);
	olz.addUtilizador(tempUti);

	olz.escreverUtilizadores();
	cout << "Utilizador criado com sucesso." << endl;

}

void selecao2()
{
	int preco, vendaID, index = -1;
	bool mostraEmail, mostraNome, mostraTelemovel, negociavel, bpago;
	string email, titulo, categoria, descricao, estado, data;
	char tipo = 'J';
	char troca = 'J';
	char mostrar;
	char nego;
	char pago;
	cout << "Introduza os seguintes dados do An�ncio: " << endl;
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
			cout << "Email n�o existe, introduza outro: ";
	}

	cout << "Introduza C para criar um An�nio de Compra ou V um de Venda: ";
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
	cout << "T�tulo: ";
	getline(cin, titulo);
	cout << "Categoria: ";
	getline(cin, categoria);

	cout << "Introduza S para mostrar o seu Nome ou N para n�o mostrar o seu Nome: "; //mostrarNome
	cin >> mostrar;
	while(mostrar != 'S' && mostrar != 'N' && mostrar != 's' && mostrar !='n'){
		cout << "Por favor, escreva S (de Sim) ou N (de N�o): ";
		cin >> mostrar;
	}
	if(mostrar == 'S' || mostrar == 's')
		mostraNome = true;
	else
		mostraNome = false;

	(mostrar == 'A' || mostrar == 'a');

	cout << "Introduza S para mostrar o seu Email ou N para n�o mostrar o seu Email: ";
	cin >> mostrar;

	while(mostrar != 'S' && mostrar != 'N' && mostrar != 's' && mostrar != 'n'){
		cout << "Por favor, escreva S (de Sim) ou N (de N�o: " << endl; //mostrarEmail
		cin >> mostrar;
	}
	if(mostrar == 'S' || mostrar == 's')
		mostraEmail = true;
	else
		mostraEmail = false;

	(mostrar == 'A' || mostrar == 'a');

	cout << "Introduza S para mostrar o seu Telemovel ou N para n�o mostrar o seu Telemovel: ";
	cin >> mostrar;

	while(mostrar != 'S' && mostrar != 'N' && mostrar != 's' && mostrar != 'n'){
		cout << "Por favor, escreva S (de Sim) ou N (de N�o): "; //mostrarTelemovel
		cin >> mostrar;
	}
	if(mostrar == 'S' || mostrar == 's')
		mostraTelemovel = true;
	else
		mostraTelemovel = false;

	cout << "Deseja pagar para o seu an�ncio aparecer em primeiro(S/N)? ";
	cin >> pago;

	if(pago == 'S' || pago == 's')
		bpago = true;
	else bpago = false;

	cout << "Descri��o: ";
	cin.ignore();
	getline(cin, descricao);												//descri��o

	if(tipo == 'V' || tipo == 'v')
	{
		cout << "Estado(Novo,Usando como novo, Funcional ou Para Pe�as): " ;
		estado = "Partido";

		getline(cin, estado);
		while(estado != "Novo" && estado != "Usando como novo" && estado != "Funcional" && estado != "Para Pe�as"){
			cout << "Estado inv�lido: ";
			getline(cin, estado);
		}

		cout << "Pre�o: ";
		cin >> preco;
		while(cin.fail()){
			cout << "Introduza um pre�o valido: ";
			cin >> preco;
		}

		cout << "Negociavel(S/N)? ";
		cin >> nego;
		while(nego != 'S' && nego != 'N' && nego != 's'&& nego != 'n'){
			cout << "Por favor, escreva S (de Sim) ou N (de N�o): ";
			cin >> nego;
		}
		if(nego == 'S' || nego == 's')
			negociavel = true;
		else
			negociavel = false;
		AnuncioVenda * temp =new AnuncioVenda(NULL, Data(data), titulo, categoria, descricao, mostraEmail, mostraNome, mostraTelemovel, estado, preco, negociavel);
		temp->setPago(bpago);
		olz.addAnuncio(index, temp);
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
				cout << "Introduza um n�mero: ";
				cin.clear();
				cin.ignore();
				cin >> vendaID;
			}
			bool encontrouid = false;
			while(!encontrouid){
				for(int i = 0; i < olz.getUtilizadores()[index].getAnuncios().size(); i++){
					if(olz.getUtilizadores()[index].getAnuncios()[i]->getID() == vendaID){
						encontrouid = true;
						break;
					}
				}
				if(!encontrouid){
					cout << "Id invalido introduza outro: ";
					cin >> vendaID;
					while(cin.fail()){
						cout << "Introduza um n�mero: ";
						cin.clear();
						cin.ignore();
						cin >> vendaID;
					}
				}
			}
		}
		else
			vendaID = -1;
		AnuncioCompra * temp = new AnuncioCompra(NULL, Data(data), titulo, categoria,  descricao, mostraEmail, mostraNome, mostraTelemovel, vendaID);
		temp->setPago(bpago);
		olz.addAnuncio(index, temp);
	}
	olz.carregaAnuncios();
	olz.escreverAnuncios();
}

void selecao3()
{
	int ID, index=-1;
	string email, mensagem;
	string data;
	cout << "Indique o ID do an�ncio para o qual pretende realizar contacto: ";
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
			cout << "ID Indispon�vel, tente outra vez: ";
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
		cout << "Pag." << (pag + 1) << ", Utilizadores por P�gina: " << porpag << endl;
		cout << "Introduza V(er), A(lterar), E(liminar), O(rdenar), P(esquisar), PP(or P�gina), PS(Pag. Seguinte), PA(Pag. Anterior) ou S(air)";
		cin >> selecao;
		if (selecao == "S" || selecao == "s")
			break;
		else if (selecao == "V" || selecao == "v")
		{
			cout << "Indique o n�mero do utilizador que deseja visualizar: ";
			int index = -1;
			cin >> index;
			while(cin.fail()){
				cout << "Indique um n�mero: ";
				cin.clear();
				cin.ignore();
				cin >> index;
			}
			while (index < 1 || index > olz.getUtilizadores().size())
			{
				cout << "N�mero inv�lido, indique outro: ";
				cin >> index;
				while(cin.fail()){
					cout << "Indique um n�mero: ";
					cin.clear();
					cin.ignore();
					cin >> index;
				}
			}
			olz.getUtilizadores()[index-1].verUtilizador();
		}
		else if (selecao == "A" || selecao == "a")
		{
			cout << "Indique o n�mero do utilizador que deseja alterar: ";
			int index = -1;
			cin >> index;
			while(cin.fail()){
				cout << "Indique um n�mero: ";
				cin >> index;
			}
			while (index < 1 || index > olz.getUtilizadores().size())
			{
				cout << "N�mero inv�lido, indique outro: ";
				cin >> index;
				while(cin.fail()){
					cout << "Indique um n�mero: ";
					cin.clear();
					cin.ignore();
					cin >> index;
				}
			}

			cout <<"Indique o que deseja alterar do Utilizador: N(ome), T(elem�vel), L(ocaliza��o): ";
			string tempinfo = "erro";
			cin >> tempinfo;

			while(tempinfo != "N" && tempinfo!= "T" && tempinfo!= "L" && tempinfo != "n" && tempinfo!= "t" && tempinfo!= "l")
			{
				cout << "Informa��o Invalida, tente outra vez: ";
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
				while(cin.fail()){
					cout << "N�mero de telem�vel inv�lido, introduza outro: ";
					cin.clear();
					cin.ignore();
					cin >> temptele;
				}
				while (!(temptele > 99999999 && temptele < 1000000000)){
					cout << "N�mero de telem�vel n�o tem nove digitos! Introduza outro: ";
					cin >> temptele;
					while(cin.fail()){
						cout << "N�mero de telem�vel inv�lido, introduza outro: ";
						cin.clear();
						cin.ignore();
						cin >> temptele;
					}
				}
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
			olz.escreverUtilizadores();
		}
		else if (selecao == "E" || selecao == "e")
		{
			cout << "Indique o n�mero do utilizador que deseja eliminar: ";
			int index = -1;
			cin >> index;
			while(cin.fail()){
				cout << "Indique um n�mero: ";
				cin.clear();
				cin.ignore();
				cin >> index;
			}
			while (index < 1 || index > olz.getUtilizadores().size())
			{
				cout << "N�mero inv�lido, indique outro: ";
				cin >> index;
				while(cin.fail()){
					cout << "Indique um n�mero: ";
					cin.clear();
					cin.ignore();
					cin >> index;
				}
			}
			olz.eliminaUtilizador(olz.getUtilizadores()[index-1].getEmail());
			olz.escreverUtilizadores();
			olz.carregaAnuncios();
			olz.escreverAnuncios();
		}
		else if (selecao == "O" || selecao == "o")
		{	cout << "Tipo ordena��o: " << endl;
		cout << "E(mail), N(ome), A(nuncios), D(istrito) + A(scendente), D(escendente)";
		cin >> tipoOrd;
		}
		else if (selecao == "P" || selecao == "p")
		{
			cout << "Em que atributo deseja procurar:: E(mail), N(ome), A(nuncios), D(istrito), F(reguesia), C(oncelho)";
			cin.ignore();
			getline(cin, tipoPes);
			while(tipoPes != "E" && tipoPes != "e" && tipoPes != "N" && tipoPes != "n" && tipoPes != "A" && tipoPes != "a" && tipoPes != "D" && tipoPes != "d" && tipoPes != "F" && tipoPes != "f" && tipoPes != "C" && tipoPes !="c"){
				cout << "Escreva um atributo v�lido: ";
				cin >> tipoPes;
			}
			cout << "O que deseja procurar: ";
			cin.ignore();
			getline(cin, tipoAlt);
			olz.pesquisarUtilizador(tipoPes,tipoAlt);
			tipoOrd= "nulo";
		}
		else if (selecao == "PP" || selecao == "pp")
		{
			cin >> porpag;
			while(cin.fail()){
				cout << "Indique um n�mero: ";
				cin.clear();
				cin.ignore();
				cin >> porpag;
			}
			while (porpag < 0)
			{
				cout << "N�mero inv�lido, indique outro: ";
				cin >> porpag;
				while(cin.fail()){
					cout << "Indique um n�mero: ";
					cin.clear();
					cin.ignore();
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

		cout << "Pag." << (pag + 1) << ", Anuncios por P�gina: " << porpag << endl;
		cout << "Introduza V(er), A(lterar), E(liminar), O(rdenar), P(esquisar), PP(or P�gina), PS(Pag. Seguinte), PA(Pag. Anterior) ou S(air)";
		cin >> selecao;
		if (selecao == "S" || selecao == "s")
			break;
		else if (selecao == "V" || selecao == "v")
		{
			cout << "Indique o n�mero do anuncio que deseja visualizar: ";
			int index = -1;
			cin >> index;
			while(cin.fail()){
				cout << "Indique um n�mero: ";
				cin.clear();
				cin.ignore();
				cin >> index;
			}
			while (index < 1 || index > olz.getAnuncios().size())
			{
				cout << "N�mero inv�lido, indique outro: ";
				cin >> index;
				while(cin.fail()){
					cout << "Indique um n�mero: ";
					cin.clear();
					cin.ignore();
					cin >> index;
				}
			}
			olz.getAnuncios()[index-1]->verAnuncio();
		}
		else if (selecao == "A" || selecao == "a")
		{
			cout << "Indique o n�mero do anuncio que deseja alterar: ";
			int index = -1;
			cin >> index;
			while(cin.fail()){
				cout << "Indique um n�mero: ";
				cin.clear();
				cin.ignore();
				cin >> index;
			}
			while (index < 1 || index > olz.getAnuncios().size())
			{
				cout << "N�mero inv�lido, indique outro: ";
				cin >> index;
				while(cin.fail()){
					cout << "Indique um n�mero: ";
					cin.clear();
					cin.ignore();
					cin >> index;
				}
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
			olz.escreverAnuncios();
		}

		else if (selecao == "E" || selecao == "e")
		{
			cout << "Indique o n�mero do anuncio que deseja eliminar: ";
			int index = -1;
			cin >> index;
			while(cin.fail()){
				cout << "Indique um n�mero: ";
				cin.clear();
				cin.ignore();
				cin >> index;
			}
			while (index < 1 || index > olz.getAnuncios().size())
			{
				cout << "N�mero inv�lido, indique outro: ";
				cin >> index;
				while(cin.fail()){
					cout << "Indique um n�mero: ";
					cin.clear();
					cin.ignore();
					cin >> index;
				}
			}
			olz.eliminaAnuncio(olz.getAnuncios()[index-1]->getID());
			olz.escreverAnuncios();
		}
		else if (selecao == "O"|| selecao == "o")
		{
			cout << "I(D), D(ata), T(�tulo), C(ategoria), N(�mero de Cliques)  + A(scendente), D(escendente)";
			cin >> tipoOrd;
		}
		else if(selecao == "P" || selecao == "p")
		{
			cout << "Em que atributo deseja procurar: I(D), D(escri��o), T(�tulo), C(ategoria), N(�mero de Cliques). E(mail); ";
			cin.ignore();
			getline(cin, tipoPes);
			while(tipoPes != "I" && tipoPes != "i" && tipoPes != "D" && tipoPes != "d" && tipoPes != "T" && tipoPes != "t" && tipoPes != "C" && tipoPes != "c" && tipoPes != "N" && tipoPes != "n" && tipoPes != "E" && tipoPes !="e"){
				cout << "Escreva um atributo v�lido: ";
				cin >> tipoPes;
			}
			cout << "O que deseja procurar: ";
			cin.ignore();
			getline(cin, tipoAlt);
			olz.pesquisarAnuncio(tipoPes,tipoAlt);
			tipoOrd= "nulo";
		}
		else if (selecao == "PP" || selecao == "pp")
		{
			cin >> porpag;
			while(cin.fail()){
				cout << "Indique um n�mero: ";
				cin.clear();
				cin.ignore();
				cin >> porpag;
			}
			while (porpag < 0)
			{
				cout << "N�mero inv�lido, indique outro: ";
				cin >> porpag;
				while(cin.fail()){
					cout << "Indique um n�mero: ";
					cin.clear();
					cin.ignore();
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
		cout << "Pag." << (pag + 1) << ", Anuncios por P�gina: " << porpag << endl;
		cout << "Introduza V(er), O(rdenar), P(esquisar), PP(or P�gina), PS(Pag. Seguinte), PA(Pag. Anterior) ou S(air)";
		cin >> selecao;
		if (selecao == "S" || selecao == "s")
			break;
		else if (selecao == "V" || selecao == "v")
		{
			cout << "Indique o n�mero do anuncio que deseja visualizar: ";
			int index = -1;
			cin >> index;
			while(cin.fail()){
				cout << "Indique um n�mero: ";
				cin.clear();
				cin.ignore();
				cin >> index;
			}
			while (index < 1 || index > olz.getAnunciosFinalizados().size())
			{
				cout << "N�mero inv�lido, indique outro: ";
				cin >> index;
				while(cin.fail()){
					cout << "Indique um n�mero: ";
					cin.clear();
					cin.ignore();
					cin >> index;
				}
			}
			olz.getAnunciosFinalizados()[index-1]->verAnuncio();
		}
		else if (selecao == "O" || selecao == "o")
		{
			cout << "I(D), D(ata), T(�tulo), C(ategoria), N(�mero de Cliques)  + A(scendente), D(escendente)";
			cin >> tipoOrd;
		}
		else if(selecao == "P"|| selecao == "p")
		{
			cout << "Em que atributo deseja procurar: I(D), D(escri��o), T(�tulo), C(ategoria), N(�mero de Cliques). E(mail); ";
			cin.ignore();
			getline(cin, tipoPes);
			while(tipoPes != "I" && tipoPes != "i" && tipoPes != "D" && tipoPes != "d" && tipoPes != "T" && tipoPes != "t" && tipoPes != "C" && tipoPes != "c" && tipoPes != "N" && tipoPes != "n" && tipoPes != "E" && tipoPes !="e"){
				cout << "Escreva um atributo v�lido: ";
				cin >> tipoPes;
			}
			cout << "O que deseja procurar: ";
			cin.ignore();
			getline(cin, tipoAlt);
			olz.pesquisarAnuncioFinalizado(tipoPes,tipoAlt);
			tipoOrd= "nulo";
		}
		else if (selecao == "PP" || selecao == "pp")
		{
			cin >> porpag;
			while(cin.fail()){
				cout << "Indique um n�mero: ";
				cin.clear();
				cin.ignore();
				cin >> porpag;
			}
			while (porpag < 0)
			{
				cout << "N�mero inv�lido, indique outro: ";
				cin >> porpag;
				while(cin.fail()){
					cout << "Indique um n�mero: ";
					cin.clear();
					cin.ignore();
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
		cout << "Pag." << (pag + 1) << ", Contactos por P�gina: " << porpag << endl;
		cout << "Introduza V(er), O(rdenar), P(esquisar), PP(or P�gina), PS(Pag. Seguinte), PA(Pag. Anterior) ou S(air)";
		cin >> selecao;
		if (selecao == "S" || selecao == "s")
			break;
		else if (selecao == "V" || selecao == "v")
		{
			cout << "Indique o n�mero do contacto que deseja visualizar: ";
			int index = -1;
			cin >> index;
			while(cin.fail()){
				cout << "Indique um n�mero: ";
				cin.clear();
				cin.ignore();
				cin >> index;
			}
			while (index < 1 || index > olz.getContactos().size())
			{
				cout << "N�mero inv�lido, indique outro: ";
				cin >> index;
				while(cin.fail()){
					cout << "Indique um n�mero: ";
					cin.clear();
					cin.ignore();
					cin >> index;
				}
			}
			olz.getContactos()[index-1]->verContacto();
		}
		else if (selecao == "A" || selecao == "a")
		{
			cout << "Indique o n�mero do contacto que deseja alterar: ";
			int index = -1;
			cin >> index;
			while(cin.fail()){
				cout << "Indique um n�mero: ";
				cin.clear();
				cin.ignore();
				cin >> index;
			}
			while (index < 1 || index > olz.getContactos().size())
			{
				cout << "N�mero inv�lido, indique outro: ";
				cin >> index;
				while(cin.fail()){
					cout << "Indique um n�mero: ";
					cin.clear();
					cin.ignore();
					cin >> index;
				}
			}

			cout <<"Indique o que deseja alterar do Contacto: ";
			string tempinfo = "erro";
			cin >> tempinfo;

			while(tempinfo != "Email" && tempinfo!= "Contacto")
			{

				cout << "Informa��o Invalida, tente outra vez: ";
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
			cout << "D(ata), A(n�ncio), E(mail) + A(scendente), D(escendente)";
			cin >> tipoOrd;
		}
		else if(selecao == "P" || selecao == "p")
		{
			cout << "Em que atributo deseja procurar: I(D), E(mail), C(ontacto)";
			cin.ignore();
			getline(cin, tipoPes);
			while(tipoPes != "I" && tipoPes != "i" && tipoPes != "E" && tipoPes != "e" && tipoPes != "C" && tipoPes != "c" ){
				cout << "Escreva um atributo v�lido: ";
				cin >> tipoPes;
			}
			cout << "O que deseja procurar: ";
			cin.ignore();
			getline(cin, tipoAlt);
			olz.pesquisarContacto(tipoPes,tipoAlt);
			tipoOrd= "nulo";
		}
		else if (selecao == "PP" || selecao == "pp")
		{
			cin >> porpag;
			while(cin.fail()){
				cout << "Indique um n�mero: ";
				cin.clear();
				cin.ignore();
				cin >> porpag;
			}
			while (porpag < 0)
			{
				cout << "N�mero inv�lido, indique outro: ";
				cin >> porpag;
				while(cin.fail()){
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

void selecao8()
{
	string tipoOrd = "EA";
	string selecao = "X";
	string tipoPes, tipoAlt;
	while (selecao != "S")
	{
		olz.tabelaUtilizadores_p_finalizados(tipoOrd);
		cout << "Introduza A(lterar), E(liminar) ou S(air)";
		cin >> selecao;
		if (selecao == "S" || selecao == "s")
			break;
		else if (selecao == "A" || selecao == "a")
		{
			cin.ignore();
			cout << "Indique o email do utilizador que deseja alterar: ";
			string tempemail;
			getline(cin,tempemail);
			cout <<"Indique o que deseja alterar do Utilizador: N(ome), T(elem�vel): ";
			string tempinfo = "erro";
			cin >> tempinfo;

			while(tempinfo != "N" && tempinfo!= "T" && tempinfo != "n" && tempinfo!= "t" )
			{
				cout << "Informa��o Invalida, tente outra vez: ";
				cin >> tempinfo;
			}
			cin.ignore();
			if(tempinfo == "N" || tempinfo == "n"){
				cout << "Insira novo nome desejado: ";
				getline(cin, tempinfo);
				/*int counter = 1;
				BSTItrIn<Utilizador> it(olz.getBUti());

				while(counter != index){
					cout << it.retrieve().getEmail() << endl;
					it.advance();
					counter++;
				}*/
				olz.setBUtiNome(tempemail, tempinfo);
			}
			else if(tempinfo == "T" || tempinfo == "t"){
				cout << "Insira telemovel novo";
				int temptele;
				cin >> temptele;
				while(cin.fail()){
					cout << "N�mero de telem�vel inv�lido, introduza outro: ";
					cin.clear();
					cin.ignore();
					cin >> temptele;
				}
				while (!(temptele > 99999999 && temptele < 1000000000)){
					cout << "N�mero de telem�vel n�o tem nove digitos! Introduza outro: ";
					cin >> temptele;
					while(cin.fail()){
						cout << "N�mero de telem�vel inv�lido, introduza outro: ";
						cin.clear();
						cin.ignore();
						cin >> temptele;
					}
				}
				cin.ignore();
				olz.setBUtiTele(tempemail, temptele);
			}
			olz.escreverUtilizadores();
		}
		else if (selecao == "E" || selecao == "e"){
			cin.ignore();
			cout << "Indique o email do utilizador que deseja alterar: ";
			string tempemail;
			getline(cin,tempemail);

			olz.delBUti(tempemail);
			olz.eliminaUtilizador(tempemail);
			olz.escreverUtilizadores();
		}
	}
	olz.escreverUtilizadores();
}




void selecao9()
{
	olz.carregaAnuncios();
	int pag = 0, porpag= 50;
	string selecao = "X";
	string tipoOrd = "IA";
	string tipoPes = "I";
	string tipoAlt;
	while (selecao != "S" || selecao != "s")
	{
		olz.tabelaAnunciosPago(pag,porpag);

		cout << "Pag." << (pag + 1) << ", Anuncios por P�gina: " << porpag << endl;
		cout << "Introduza V(er), A(lterar), E(liminar), ou S(air)";
		cin >> selecao;
		if (selecao == "S" || selecao == "s")
			break;
		else if (selecao == "V" || selecao == "v")
		{
			cout << "Indique o ID do anuncio que deseja visualizar: ";
			int index = -1;
			cin >> index;
			while(cin.fail()){
				cout << "Indique um n�mero: ";
				cin.clear();
				cin.ignore();
				cin >> index;
			}
			while (index < 0 || index > olz.getAnuncios().size())
			{
				cout << "N�mero inv�lido, indique outro: ";
				cin >> index;
				while(cin.fail()){
					cout << "Indique um n�mero: ";
					cin.clear();
					cin.ignore();
					cin >> index;
				}
			}
			olz.verAnuncioPago(index);
		}
		else if (selecao == "A" || selecao == "a")
		{
			cout << "Indique o n�mero do anuncio que deseja alterar: ";
			int index = -1;
			cin >> index;
			while(cin.fail()){
				cout << "Indique um n�mero: ";
				cin.clear();
				cin.ignore();
				cin >> index;
			}
			while (index < 1 || index > olz.getAnuncios().size())
			{
				cout << "N�mero inv�lido, indique outro: ";
				cin >> index;
				while(cin.fail()){
					cout << "Indique um n�mero: ";
					cin.clear();
					cin.ignore();
					cin >> index;
				}
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
							olz.setTituloPago(olz.getUtilizadores()[i].getAnuncios()[j]->getID(), tempinfo);
						}
						else if(tempinfo == "Categoria"){
							cout << "Categoria nova: ";
							getline(cin, tempinfo);
							olz.getUtilizadores()[i].getAnuncios()[j]->setCategoria(tempinfo);
							olz.setCategoriaPago(olz.getUtilizadores()[i].getAnuncios()[j]->getID(), tempinfo);
						}
						else if(tempinfo == "Descri��o"){
							cout << "Nova descri��o: ";
							getline(cin, tempinfo);
							olz.getUtilizadores()[i].getAnuncios()[j]->setDescricao(tempinfo);
							olz.setDescricaoPago(olz.getUtilizadores()[i].getAnuncios()[j]->getID(), tempinfo);
						}
						else if(tempinfo == "Mostra Email"){
							olz.getUtilizadores()[i].getAnuncios()[j]->setmostraEmail();
							olz.setMEmailPago(olz.getUtilizadores()[i].getAnuncios()[j]->getID());
						}
						else if(tempinfo == "Mostra Nome"){
							olz.getUtilizadores()[i].getAnuncios()[j]->setmostraNome();
							olz.setMEmailPago(olz.getUtilizadores()[i].getAnuncios()[j]->getID());
						}
						else if(tempinfo == "Mostra Telemovel"){
							olz.getUtilizadores()[i].getAnuncios()[j]->setmostraTelemovel();
							olz.setMEmailPago(olz.getUtilizadores()[i].getAnuncios()[j]->getID());
						}
						break;
					}
			}
			olz.carregaAnuncios();
			olz.escreverAnuncios();
		}

		else if (selecao == "E" || selecao == "e")
		{int index = -1;
		cout << "Indique o n�mero do anuncio que deseja eliminar: ";

		cin >> index;
		while(cin.fail()){
			cout << "Indique um n�mero: ";
			cin.clear();
			cin.ignore();
			cin >> index;
		}
		while (index < 1 || index > olz.getAnuncios().size())
		{
			cout << "N�mero inv�lido, indique outro: ";
			cin >> index;
			if(cin.fail()){
				cout << "Indique um n�mero: ";
				cin.clear();
				cin.ignore();
				cin >> index;
			}
		}
		olz.eliminaAnuncio(olz.getAnuncios()[index-1]->getID());
		olz.escreverAnuncios();
		}
	}
	olz.escreverAnuncios();
}

void selecao10()
{
	string atributo, valor;
	cout << "Introduza 'U' ou 'C' para pesquisar os neg�cios de um utilizador ou de uma categoria:" << endl;
	getline(cin,atributo);
	while (atributo != "U" && atributo != "C"){
		cout << "Introduza 'U' ou 'C':" << endl;
		getline(cin,atributo);
	}
	if (atributo == "U"){
		cout << "Introduza o e-mail do utilizador:" << endl;
	} else if (atributo == "C"){
		cout << "Introduza a categoria pretendida:" << endl;
	}
	getline(cin,valor);

	string selecao = "X";
	while (selecao != "S")
	{
		int counter = 0;
		counter = olz.tabelaNegocios(atributo,valor);
		if(counter != 0){
		cout << "Introduza V(er) ou S(air)";
		cin >> selecao;
		if (selecao == "S" || selecao == "s")
			break;
		else if (selecao == "V" || selecao == "v")
		{
			cout << "Indique o ID do anuncio que deseja visualizar: ";
			int index = -1;
			cin >> index;
			while(cin.fail()){
				cout << "Indique um n�mero: ";
				cin.clear();
				cin.ignore();
				cin >> index;
			}
			cout << endl;
			olz.verNegocio(index);
			cout << endl;
		}
	}
		else{
			cout << "Nao foi encontrado anuncio finalizado para este utilizador ou categoria " << endl;
			break;
		}
	}
	olz.escreverAnunciosFinalizados();

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
		cout << "5. Gerir An�ncios" << endl;
		cout << "6. Gerir An�ncios Finalizados" << endl;
		cout << "7. Gerir Contactos" << endl;
		cout << "8. Gerir Utilizadores por an�ncio (BST)" << endl;
		cout << "9. Gerir An�ncios por Pago (Priority Queue)" << endl;
		cout << "10. Gerir An�ncios Finalizados (Hash Table)" << endl;
		cout << "0. Sair" << endl;

		cin >> selecao;
		while(cin.fail()){
			cout << "Indique 1,2,3,4,5,6,7,8,9,10 ou 0: ";
			cin.clear();
			cin.ignore();
			cin >> selecao;
		}
		while (selecao < 0 || selecao > 10){
			cout << "N�mero de sele��o invalido, tente outro: ";
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
		else if (selecao == 8 && olz.getUtilizadores().size() > 0)
			selecao8();
		else if (selecao == 9 && olz.getAnuncios().size() > 0)
			selecao9();
		else if (selecao == 10 && olz.getAnunciosFinalizados().size() > 0)
					selecao10();
		else if ((selecao == 2 || selecao == 4)&& olz.getUtilizadores().size() == 0)
			cout << "N�o existem utilizadores." << endl;

		else if ((selecao == 3 || selecao == 5) && olz.getAnuncios().size() == 0)
			cout << "N�o existem an�ncios." << endl;

		else if (selecao == 6 && olz.getAnunciosFinalizados().size() == 0)
			cout << "N�o existem an�ncios finalizados." << endl;
		else if (selecao == 7 && olz.getContactos().size() == 0)
			cout << "N�o existem contactos." << endl;
		selecao = -1;
	}
	cout << "Obrigado por utilizar o OLZ." << endl;
	return 0;
}
