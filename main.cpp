/**
* @file main.cpp
* Projet SDA
* @author Morgane Laurent, Aroun Radjavelou, Tristan Bilot
* @version 1 - 14/12/2017
* @brief Test Sprint6
*/
#include <iostream>
#include <fstream>

#include "paquetReseau.h"
#include "Messagerie.h"
using namespace std;
#define TAILLE_FICHIER 80


int main() {
	ifstream pqtReseau;
	pqtReseau.open("ligne.txt");
	Messagerie messagerie;
	initialiser(messagerie);
	PaquetReseau paquetReseau;
	if (pqtReseau.fail()) {
		cerr << "Impossible de lire le fichier" << endl;
		system("pause");
	}
	else {
		while (!pqtReseau.eof()) {
			recevoirPaquetReseau(pqtReseau, paquetReseau);
			traiterPaquetReseau(messagerie, paquetReseau);
		}
		messagerie.os << "Fin de transmission, supression de message ";
		for (unsigned int i = 0; i < longueur(messagerie.listeS); i++) {
			ecrireID(messagerie.os, lire(messagerie.listeS, i));
			messagerie.os << endl;
		}
		creerMailbox(messagerie);
	}
	system("pause");
	return 0;
}