/**
 * Utilizador.h
 */


#ifndef UTILIZADOR_H_
#define UTILIZADOR_H_

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Anuncio;

class Localizacao {
	string freguesia, concelho, distrito;
public:
	/**
	 * Construtor da classe
	 */
	Localizacao(string freguesia, string concelho, string distrito);
	/**
	 * Destrutor da classe
	 */
	virtual ~Localizacao();
	/**
	 * Altera o membro-dado freguesia para o argumento f
	 * @param f Nova freguesia
	 */
	void setFreguesia(string f);
	/**
	 * Altera o membro-dado concelho para o argumento c
	 * @param c Novo concelho
	 */
	void setConcelho(string c);
	/**
	 * Altera o membro-dado distrito para o argumento d
	 * @param d Nova distrito
	 */
	void setDistrito(string d);
	/**
	 * @return Freguesia
	 */
	string getFreguesia() const;
	/**
	 * @return Concelho
	 */
	string getConcelho() const;
	/**
	 * @return Distrito
	 */
	string getDistrito() const;
	/**
	 * Overload do operator do operator<< que imprime a localização no formato freguesia, concelho, distrito
	 */
	friend ostream& operator<<(std::ostream& os, const Localizacao l);

};

class Utilizador {
	string email, nome;
	int telemovel, num_finalizados;
	Localizacao localizacao;
	vector<Anuncio *> anuncios;
	bool pago;
public:
	/**
	 * Construtor da classe
	 */
	Utilizador(string email, string nome, int telemovel,Localizacao localizacao);
	/**
	 * Destrutor da classe
	 */
	virtual ~Utilizador();
	/**
	 * Imprime as informacoes do utilizador
	 */
	void verUtilizador();
	/**
	 * Altera o membro-dado email para o argumento e
	 * @param e Novo email
	 */
	void setEmail(string e);
	/**
	 * Altera o membro-dado nome para o argumento n
	 * @param n Novo nome
	 */
	void setNome(string n);
	/**
	 * Altera o membro-dado telemovel para o argumento t
	 * @param t Novo telemovel
	 */
	void setTelemovel(int t);
	/**
	 * Altera o membro-dado localizacao para o argumento l
	 * @param l Nova localizacao
	 */
	void setLocalizacao(Localizacao l);
	/**
	 * Adiciona o anuncio a ao vetor de anuncios do utilizador
	 * @param a Anuncio a ser adicionado
	 */
	void addAnuncio(Anuncio * a);
	/**
	 * @returns Email
	 */
	string getEmail() const;
	/**
	 * @returns Nome
	 */
	string getNome() const;
	/**
	 * @returns Telemovel
	 */
	int getTelemovel() const;
	/**
	 * @returns Localizacao
	 */
	Localizacao getLocalizacao() const;
	/**
	 * @returns Vetor dos anuncios
	 */
	vector<Anuncio *> getAnuncios() const;
	/**
	 * @returns Numero de anúncios finalizados por um utilizador
	 */
	int getNum_Finalizados() const;
	/**
	 * Altera o membro-dado num_finalizados para o argumento recebido
	 * @param num_finalizados Novo numero de anuncios finalizados
	 */
	void setNum_Finalizados(int num_finalizados);
	/**
	 * Elimina o anncio na posicao index do vetor anuncios do utilizador
	 * @param index posicao do vetor a eliminar
	 */
	void eliminaAnuncio(int index);
	/**
	 * Overload do operador de menor para usar na BST
	 */
	bool operator < (const  Utilizador &u) const;
	/**
	 * Overload do operador de igualdade
	 */
	bool operator == (const  Utilizador &u) const;
};


#endif /* UTILIZADOR_H_ */
