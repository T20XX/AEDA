/*
 * colz.h
 *
 *  Created on: 02/11/2015
 *      Author: Jorge
 */

#include <vector>
#include <iostream>
#include "Anuncio.h"

using namespace std;

#ifndef COLZ_H_
#define COLZ_H_

class colz {
	vector<Utilizador *> utilizadores;
	vector<Anuncio *> anuncios;
public:
	colz();
	virtual ~colz();
};

#endif /* COLZ_H_ */
