#ifndef _DATA_
#define _DATA_

/**
* @file BlocData.h
* Projet SDA
* @author Tristan Bilot
* @version 1 - 14/12/2017
* @brief Structure pour stocker les informations d'un bloc de données
*/

#include <iostream>
#include <cassert>
using namespace std;

/**
* @brief Structure de données de type BlocData
*/
struct BlocData {
	enum {MAX = 21};
	unsigned short noBloc;
	char data[MAX];
};

BlocData lireBD(istream& is);

void ecrireBD(ostream& os, const BlocData b);


bool enOrdre(const BlocData& b1, const BlocData& b2);

#endif