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
using namespace std;

#include "MessageEnCours.h"

#define TAILLEFILE 50

void initialiser(MessageEnCours& m, const PaquetReseau& p) {
	m.idMes = p.IdMes;
	m.nbPRecus = 1;
	m.LgMes = 0;
	m.LastPRecu = p.noPr;
	initialiser(m.fileB, TAILLEFILE);
	entrer(m.fileB, p.blocD);
}

void detruire(MessageEnCours& m) {
	detruire(m.fileB);
}

void ecrireMEC(ostream& os, MessageEnCours& m) {
	BlocData BDtmp;
	ecrireID(os, m.idMes);
	os << endl;
	while (!estVide(m.fileB)) {
		BDtmp = tete(m.fileB);
		ecrireBD(os, BDtmp);
		sortir(m.fileB);
		// on affiche la tête et on la sort à chaque itération
	}
}
