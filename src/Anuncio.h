/**
 * Anuncio.h
 */


#ifndef ANUNCIO_H_
#define ANUNCIO_H_


#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Anuncio;

class Utilizador;

class Data{
	int ano, mes, dia;
public:
	Data(string data);
	Data(int dia, int mes, int ano);
	friend ostream& operator<<(std::ostream& os, const Data d1);
	/**
	 * @returns Ano
	 */
	int getAno() const;
	/**
	 * @returns Mes
	 */
	int getMes() const;
	/**
	 * @returns Dia
	 */
	int getDia() const;
	bool operator <(const Data d1);
	bool operator >(const Data d1);
	bool operator ==(const Data d1);
};

class Contacto {
	Anuncio * anuncio;
	string email, contacto;
	Data data;
public:
	/**
	 * Construtor da classe
	 */
	Contacto(Anuncio * anuncio, Data data, string email,string contacto);
	/**
	 * Destrutor da classe
	 */
	virtual ~Contacto();
	/**
	 * Altera o membro-dado Anuncio para o argumento a
	 * @param a Novo Anuncio
	 */
	void setAnuncio(Anuncio * a);
	/**
	 * @return Anuncio
	 */
	Anuncio * getAnuncio();
	/**
	 * @return Email
	 */
	string getEmail();
	/**
	 * @return Contacto
	 */
	string getContacto();
	/**
	 * @return Data
	 */
	Data getData();
	/**
	 * Permite ao utilizador visualizar o contacto
	 */
	void verContacto() const;
	/**
	 * Altera o membro-dado Email para o argumento em
	 * @param em Novo Email
	 */
	void setEmail(string em);
	/**
	 * Altera o membro-dado Contacto para o argumento c
	 * @param c Novo Contacto
	 */
	void setContacto(string c);
};

class Anuncio {
	static int nextID;
	string titulo, categoria, descricao; //imagens?
	int ID, numCliques;
	Data data;
	Utilizador * utilizador;
	bool mostraNome, mostraTelemovel, mostraEmail, pago;
	vector<Contacto *> contactos;
public:
	/**
	 * Construtor da classe
	 */
	Anuncio(Utilizador * utilizador, Data data, string titulo, string categoria, string descricao, bool mostraEmail, bool mostraNome, bool mostraTelemovel);
	/**
	 * Destrutor da classe
	 */
	virtual ~Anuncio();
	/**
	 * Mostra ao utilizador as informações do
	 * anuncio
	 */
	virtual void verAnuncio() const = 0;
	/**
	 * Altera o membro-dado NextID para o argumento ID
	 * @param ID Novo NextID
	 */
	static void setNextID(int ID);
	/**
	 * @return NextID
	 */
	static int getNextID();
	/**
	 * Altera o membro-dado ID para o argumento I
	 * @param I Novo ID
	 */
	void setID(int I);
	/**
	 * Adiciona contacto
	 * @param I Novo ID
	 */
	void addContacto(Contacto * c);
	/**
	 * Altera o membro-dado Utilizador para o argumento Utilizador * u
	 */
	void setUtilizador(Utilizador * u);
	/**
	 * Altera o membro-dado numCliques para o argumento NumCliques
	 * @param numCliques Novo numCliques
	 */
	void setNumCliques(int numCliques);
	/**
	 * @returns ID
	 */
	int getID() const;
	/**
	 * @returns Data
	 */
	Data getData() const;
	/**
	 * Altera o membro-dado Data para o argumento d
	 * @param d Novo Data
	 */
	void setData(Data d);
	/**
	 * @returns numCliques
	 */
	int getnumCliques() const;
	/**
	 * @returns Titulo
	 */
	string getTitulo() const;
	/**
	 * @returns Categoria
	 */
	string getCategoria() const;
	/**
	 * @returns Descricao
	 */
	string getDescricao() const;
	/**
	 * Altera o membro-dado Titulo para o argumento t
	 * @param t Novo Titulo
	 */
	void setTitulo(string t);
	/**
	 * Altera o membro-dado Categoria para o argumento c
	 * @param c Novo Categoria
	 */
	void setCategoria(string c);
	/**
	 * Altera o membro-dado Descricao para o argumento des
	 * @param des Novo Descricao
	 */
	void setDescricao(string des);
	/**
	 * @returns mostraNome
	 */
	bool getmostraNome() const;
	/**
	 * Altera o membro-dado mostraNome para o argumento mostraNome
	 * @param mostraNome Novo mostraNome
	 */
	void setmostraNome();
	/**
	 * Altera o membro-dado mostraEmail para o argumento mostraEmail
	 * @param mostraEmail Novo mostraEmail
	 */
	void setmostraEmail();
	/**
	 * @returns mostraTelemovel
	 */
	bool getmostraTelemovel() const;

	/**
	 * Altera o membro-dado mostraTelemovel para o argumento mostraTelemovel
	 * @param mostraTelemovel Novo mostraTelemovel
	 */
	void setmostraTelemovel();
	/**
	 * @returns mostraEmail
	 */
	bool getmostraEmail() const;
	/**
	 * @returns Utilizador
	 */
	Utilizador* getUtilizador() const;
	/**
	 * @returns pago
	 */
	bool getPago() const;
	/**
	 * Altera o membro-dado pago para o argumento isPago
	 * @param isPago valor a alterar
	 */
	void setPago(bool isPago);
	/**
	 * @returns Contactos
	 */
	vector<Contacto *> getContactos() const;
	/**
	 * @returns Estado
	 */
	virtual string getEstado() const = 0;
	/**
	 * @returns Preco
	 */
	virtual int getPreco() const = 0;
	/**
	 * @returns Tipo
	 */
	virtual bool getTipo() const = 0;
	/**
	 * @returns Negociavel
	 */
	virtual bool getNegociavel() const = 0;
	/**
	 * @returns VendaID
	 */
	virtual int getVendaID() const = 0;
};

class AnuncioVenda: public Anuncio {
	string estado;
	int preco;
	bool negociavel;
public:
	/**
	 * Construtor da classe
	 */
	AnuncioVenda(Utilizador * utilizador, Data data, string titulo, string categoria, string descricao, bool mostraEmail,bool mostraNome, bool mostraTelemovel, string estado, int preco, bool negociavel);
	/**
	 * Permite ao utilizador visualizar Anuncio
	 */
	void verAnuncio() const;
	/**
	 * @returns Estado
	 */
	string getEstado() const;
	/**
	 * @returns Preco
	 */
	int getPreco() const;
	/**
	 * @returns Tipo
	 */
	bool getTipo() const;
	/**
	 * @returns Negociavel
	 */
	bool getNegociavel() const;
	/**
	 * @returns VendaID
	 */
	int getVendaID() const;
};

class AnuncioCompra: public Anuncio {
	int vendaID;
public:
	/**
	 * Construtor da classe
	 */
	AnuncioCompra(Utilizador * utilizador, Data data, string titulo, string categoria, string descricao,  bool mostraEmail, bool mostraNome, bool mostraTelemovel, int vendaID);
	/**
	 * Permite ao utilizador visualizar Anuncio
	 */
	void verAnuncio() const;
	/**
	 * @returns Tipo
	 */
	bool getTipo() const;
	/**
	 * @returns Estado
	 */
	string getEstado() const;
	/**
	 * @returns Preco
	 */
	int getPreco() const;
	/**
	 * @returns Negociavel
	 */
	bool getNegociavel() const;
	/**
	 * @returns VendaID
	 */
	int getVendaID() const;
};

class AnuncioFinalizado: public Anuncio {
	int preco;
public:
	/**
	 * Construtor da classe
	 */
	AnuncioFinalizado(Utilizador * utilizador, Data data, string titulo, string categoria, string descricao,  bool mostraEmail, bool mostraNome, bool mostraTelemovel,int IDantigo, int preco);
	/**
	 * Permite ao utilizador visualizar Anuncio
	 */
	void verAnuncio() const;
	/**
	 * @returns Tipo
	 */
	bool getTipo() const;
	/**
	 * @returns Estado
	 */
	string getEstado() const;
	/**
	 * @returns Preco
	 */
	int getPreco() const;
	/**
	 * @returns Negociavel
	 */
	bool getNegociavel() const;
	/**
	 * @returns VendaID
	 */
	int getVendaID() const;
};
class AnuncioPtr{
public:
	Anuncio * anuncio;
	AnuncioPtr(Anuncio * a1): anuncio(a1){};

	/**
	 * Overload do operador de igualdade
	 */
	bool operator == (const  AnuncioPtr &a) const;
	/**
	 * Overload do operador de menor para permitir a fila de prioridade ordenar os anúncios
	 */
	bool operator < (const  AnuncioPtr &a1) const;
};
#endif /* ANUNCIO_H_ */
