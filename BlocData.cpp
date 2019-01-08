/**
* @file Position.cpp
* Projet sem04-tp-Cpp3
* @author l'équipe pédagogique
* @version 1 19/12/05
* @brief Composant de positions sur une grille
* Structures de données et algorithmes - DUT1 Paris 5
*/

#include <iostream>
#include <cassert>

#include "BlocData.h"
using namespace std;

BlocData lireBD(istream& is) {
	char *container = new char[255];  // variable temporaire en allocation dynamique
	BlocData b;
	is >> container;
	b.noBloc = atoi(container);
	is.ignore(10, '\n'); // récupère le retour à la ligne
	is.getline(b.data, BlocData::MAX + 1, '\n');
	delete[] container;  // libération du stockage dynamique
	container = NULL;  // + initialisation
	return b;
}

void ecrireBD(ostream& os, const BlocData b) {
	os << b.data;
}


bool enOrdre(const BlocData& b1, const BlocData& b2) {
	if (b1.noBloc < b2.noBloc) {
		return true;
	}
	return false;
}