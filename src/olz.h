/*
 * olz.h
 *
 *  Created on: 02/11/2015
 *      Author: Jorge
 */

#include <vector>
#include <iostream>
#include "Anuncio.h"
#include "Utilizador.h"

using namespace std;

#ifndef OLZ_H_
#define OLZ_H_

class olz {
	vector<Utilizador *> utilizadores;
	vector<Anuncio *> anuncios;
public:
	olz();
	virtual ~olz();
};

#endif /* OLZ_H_ */
