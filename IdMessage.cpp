/**
* @file IdMessage.cpp
* Projet SDA
* @author Morgane Laurent, Aroun Radjavelou, Tristan Bilot
* @version 1 - 17/12/2017
* @brief Fonctions liées à l'IdMessage
*/
#include <iostream>
#include <fstream>

#include "IdMessage.h"
using namespace std;



IdMessage lireID(istream& is) {
	char *container = new char[255];  // variable temporaire en allocation dynamique
	IdMessage i;
	is >> container;
	strcpy_s(i.exp, container);
	is >> container;
	strcpy_s(i.dest, container);
	is >> container;
	strcpy_s(i.date, container);
	is >> container;
	strcpy_s(i.heure, container);
	delete[] container;  // libération du stockage dynamique
	container = NULL;  // + initialisation
	return i;
}


void ecrireID(ostream& os, const IdMessage& m) {
	os << m.exp << " ";
	os << m.dest << " ";
	os << m.date << " ";
	os << m.heure;
}

/**
* @brief Retourne true si 2 IdMessage sont égaux sinon false
* @param[in] id1 : IdMessage 1
* @param[in] id2 : IdMessage 2
*/
bool estEgal(const IdMessage &id1, const IdMessage &id2) {
	if (strcmp(id1.exp, id2.exp) == 0)
		if (strcmp(id1.dest, id2.dest) == 0)
			if (strcmp(id1.date, id2.date) == 0)
				if (strcmp(id1.heure, id2.heure) == 0)
					return true;
	return false;
}