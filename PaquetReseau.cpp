/**
* @file PaquetReseau.cpp
* Projet SDA
* @author Morgane Laurent, Aroun Radjavelou, Tristan Bilot
* @version 1 - 14/12/2017
* @brief Composant Paquet Réseau
*/

#include <iostream>
#include <fstream>
#include "paquetReseau.h"

#define buffer 200

/**
* @brief Lis un à un les champs du fichier et les introduit dans les structures adaptées
* @param[in] lecture : flux d'entrée
* @param[in] paquet :  paquet en pointeur pour manipuler un tableau
*/
PaquetReseau lirePR(istream& is) {
	char *container = new char[255];  // variable temporaire en allocation dynamique
	PaquetReseau p;
	is >> container;
	p.noPr = atoi(container);
	p.IdMes = lireID(is);
	is >> container;
	p.finMsg = atoi(container);
	p.blocD = lireBD(is);
	delete[] container;  // libération du stockage dynamique
	container = NULL;  // initialisation
	return p;
}

void ecrirePR(ostream& os, const PaquetReseau& p) {
	static unsigned int i = 0;
	os << "m.idMes[" << i << "]=|";
	ecrireID(os, p.IdMes);
	os << "|" << endl;
	i++;
}