/**
* @file Messagerie.cpp
* Projet SDA
* @author Morgane Laurent, Aroun Radjavelou, Tristan Bilot
* @version 1 - 17/12/2017
* @brief Fonctions liées à la messagerie
*/
#include <iostream>
#include <fstream>
#include <string.h>

#include "Messagerie.h"
using namespace std;

#define NBMEC 10
#define TAILLEFILE 10
#define NOMFICHIER 20


void initialiser(Messagerie& m) {
	initialiser(m.listeM, NBMEC, NBMEC);
	initialiser(m.listeS, NBMEC, NBMEC);
	m.os.open("log.txt");
}

void detruire(Messagerie& m) {
	detruire(m.listeM);
	detruire(m.listeS);
}

/**
* @brief Retourne true si l'IdMessage est dans la liste sinon false
* @param[in] liste : la liste d'IdMessage
* @param[in] id : l'IdMessage a comparé
*/
bool existList(const Liste &liste, const IdMessage &id) {
	IdMessage id2;
	for (unsigned int i = 0; i < longueur(liste); i++) {
		id2 = lire(liste, i).idMes;
		if (estEgal(id, id2))
			return true;
	}
	return false;
}

/**
* @brief Retourne true si l'IdMessage est dans la liste sinon false
* @param[in] liste : la liste d'IdMessage
* @param[in] id : l'IdMessage a comparé
*/


/**
* @brief : Retourne la position du message 
			  en cours où l'IdMessage coïncide
* @param[in] liste : la liste d'IdMessage
* @param[in] id : l'IdMessage a comparé
*/
int poslist(const Liste& liste, const PaquetReseau& paquet) {
	IdMessage id2;
	unsigned int i;
	for (i = 0; i < longueur(liste); i++) {
		id2 = lire(liste, i).idMes;
		if (estEgal(paquet.IdMes, id2))
			return i;
	}
	i = -1;
	assert(i == 1);
	return i;
	//lors du balayage, si on cherche une position
	//déjà connue alors elle existe forcément dans la liste
	//si on arrive à cette assertion alors l'IdMessage était
	//formatées ou mal stocké
}

/**
* @brief Retourne true si l'IdMessage est dans la liste sinon false
* @param[in] liste : la liste d'IdMessage
* @param[in] id : l'IdMessage a comparé
*/
int pertePaquet(const Liste &liste, PaquetReseau& pR) {
	MessageEnCours tmp;
	for (unsigned int i = 0; i < longueur(liste); i++) {
		tmp = lire(liste, i);
		if (pR.noPr >= tmp.LastPRecu + 10)
			return i;
	}
	return -1;
}

void recevoirPaquetReseau(istream& is, PaquetReseau& paquet) {
	paquet = lirePR(is);
}

/**
* @brief Affiche les BlocData associés à chaque IdMessage
* @version 2.0 : 24/12/2017
* @param[out] ListeMsgEnCours : liste contenant les BlocData de chaque message
* @param[in] is : flux d'entrée istream sur un fichier txt
* @param[in] paquet : PaquetReseau en pointeur pour manipuler un tableau de paquets
*/
void traiterPaquetReseau(Messagerie& m, PaquetReseau& paquet) {
	MessageEnCours tmp;
	unsigned int pos = 0;
	// Analyse des IdMessage et remplissage de la liste de messages en cours

	/* si l'IdMessage n'est pas dans la liste*/
	if (existList(m.listeM, paquet.IdMes)) {
		/* récupération de la position du
		MessageEnCours existant pour
		rajouter le blocData à sa file */
		pos = poslist(m.listeM, paquet);
		/* récupération du MessageEnCours existant
		pour rajouter le blocData à sa file */
		tmp = lire(m.listeM, pos);
		entrer(tmp.fileB, paquet.blocD);
		/* remplacement du MessageEnCours existant
		par le nouv. MessageEnCours dont on a
		entrer un element supp dans la file
		*/
		tmp.LastPRecu = paquet.noPr;
		tmp.nbPRecus++;
		ecrire(m.listeM, pos, tmp);
	}
	else {
		initialiser(tmp, paquet);
		// insertion du nouv. MessageEnCours dans la liste
		inserer(m.listeM, 0, tmp);
		m.os << paquet.noPr << " Detection de nouveau message ";
		ecrireID(m.os, paquet.IdMes);
		m.os << endl;
	}
	if (paquet.finMsg == 1) {
		pos = poslist(m.listeM, paquet);
		tmp = lire(m.listeM, pos);
		tmp.LgMes = paquet.blocD.noBloc;
		ecrire(m.listeM, pos, tmp);
		m.os << paquet.noPr << " Detection de fin de message ";
		ecrireID(m.os, paquet.IdMes);
		m.os << endl;
	}
	tmp = lire(m.listeM, poslist(m.listeM, paquet));
	if (tmp.LgMes == tmp.nbPRecus) {
		ecrireMEC(cout, tmp);
		cout << endl << endl;
		m.os << paquet.noPr << " Archivage mailbox ";
		ecrireID(m.os, paquet.IdMes);
		m.os << endl;
	}
	if (pertePaquet(m.listeM, paquet) != -1) {
		pos = pertePaquet(m.listeM, paquet);
		tmp = lire(m.listeM, pos);
		supprimer(m.listeM, pos);
		inserer(m.listeS, 0, tmp.idMes);
		m.os << paquet.noPr << " Perte de paquet, suppression de message ";
		ecrireID(m.os, tmp.idMes);
		m.os << endl;
	}
	supprMes(m);
	
}

void supprMes(Messagerie& m) {
	IdMessage tmp1,tmp2;
	for (unsigned int i = 0; i < longueur(m.listeS); i++) {
		tmp1 = lire(m.listeS, i);
		for (unsigned int j = 0; j < longueur(m.listeM); j++) {
			tmp2 = lire(m.listeM, j).idMes;
			if (estEgal(tmp1, tmp2))
				supprimer(m.listeM, j);
		}
	}
}

void ecrireM(ostream& os, const Messagerie& m) {
	MessageEnCours tmp;
	// Pour chaque MessageEnCours dans la liste
	for (int i = longueur(m.listeM) - 1; i >= 0; i--) {
		tmp = lire(m.listeM, i);
		ecrireMEC(os, tmp);
		os << endl;
	}
}

void creerMailbox(Messagerie& m) {
	MessageEnCours tmpMEC, tmpMEC2;
	enum { MAX = 10 };
	char nomFichier[NOMFICHIER];
	for (unsigned int i = 0; i <longueur(m.listeM); i++) {
		unsigned int tab[MAX];
		unsigned int itab = 0;
		tmpMEC = lire(m.listeM, i);
		for (unsigned int j = 0; j < longueur(m.listeM); j++) {
			tmpMEC2 = lire(m.listeM, j);
			if (strcmp(tmpMEC.idMes.dest,tmpMEC2.idMes.dest)==0) {
				tab[itab++] = j;
			}
		}
		ofstream os;
		sprintf_s(nomFichier, "mailbox%s.txt", tmpMEC.idMes.dest);
		os.open(nomFichier);
		os << "Mailbox " << tmpMEC.idMes.dest << endl;
		for (unsigned int k = 0; k <= itab - 1; k++) {
			tmpMEC2 = lire(m.listeM, tab[k]);
			ecrireMEC(os, tmpMEC2);
			os << endl;
		}
		for (unsigned int k = itab-1; k > 0; k--) {
			detruire(tmpMEC2);
			supprimer(m.listeM, tab[k]);
		}
	}
	detruire(m);
}