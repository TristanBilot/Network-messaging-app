#ifndef _MESSAGE_
#define _MESSAGE_

/**
* @file IdMessage.h
* Projet SDA
* @author Tristan Bilot
* @version 1 - 14/12/2017
* @brief Structure pour stocker les informations d'un message
*/

#include <iostream>
#include <cassert>
using namespace std;

/**
* @brief Structure de données de type IdMessage
*/
struct IdMessage {
	enum { MAX = 50, LGFORMAT = 9 };
	char exp[MAX];
	char dest[MAX];
	char date[LGFORMAT];
	char heure[LGFORMAT];
};

IdMessage lireID(istream& is);

void ecrireID(ostream& os, const IdMessage& i);

/**
* @brief Retourne true si 2 IdMessage sont égaux sinon false
* @param[in] id1 : IdMessage 1
* @param[in] id2 : IdMessage 2
*/
bool estEgal(const IdMessage &id1, const IdMessage &id2);

#endif