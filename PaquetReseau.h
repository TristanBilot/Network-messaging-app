#ifndef _PAQUET_
#define _PAQUET_

/**
* @file PaquetReaseau.h
* Projet SDA
* @author Tristan Bilot
* @version 1 - 14/12/2017
* @brief Structure pour stocker les informations d'un paquet r�seau
*/


#include "IdMessage.h"
#include "BlocData.h"
using namespace std;

/**
* @brief Structure de donn�es de type PaquetReseau
*/
struct PaquetReseau {
	int noPr;
	IdMessage IdMes;
	BlocData blocD;
	unsigned short finMsg;
};

/**
* @brief Lis un � un les champs du fichier et les introduit dans les structures adapt�es
* @param[in] lecture : flux d'entr�e
* @param[in] paquet :  paquet en pointeur pour manipuler un tableau
*/
PaquetReseau lirePR(istream &lecture);	

void ecrirePR(ostream& os, const PaquetReseau& p);

#endif