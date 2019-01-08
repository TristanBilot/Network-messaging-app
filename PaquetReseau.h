#ifndef _PAQUET_
#define _PAQUET_

/**
* @file PaquetReaseau.h
* Projet SDA
* @author Tristan Bilot
* @version 1 - 14/12/2017
* @brief Structure pour stocker les informations d'un paquet réseau
*/


#include "IdMessage.h"
#include "BlocData.h"
using namespace std;

/**
* @brief Structure de données de type PaquetReseau
*/
struct PaquetReseau {
	int noPr;
	IdMessage IdMes;
	BlocData blocD;
	unsigned short finMsg;
};

/**
* @brief Lis un à un les champs du fichier et les introduit dans les structures adaptées
* @param[in] lecture : flux d'entrée
* @param[in] paquet :  paquet en pointeur pour manipuler un tableau
*/
PaquetReseau lirePR(istream &lecture);	

void ecrirePR(ostream& os, const PaquetReseau& p);

#endif