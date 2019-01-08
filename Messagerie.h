#ifndef _MESSAGERIE_
#define _MESSAGERIE_

/**
* @file Messagerie.h
* Projet SDA
* @author Morgane Laurent, Aroun, Tristan Bilot
* @version 1 - 17/12/2017
* @brief Fonctions liées à la messagerie
*/

#include "Liste.h"
#include "Liste2.h"
#include "PaquetReseau.h"
using namespace std;

/**
* @brief Structure de données de type Messagerie
*/
struct Messagerie {
	Liste listeM; // liste de message en cours
	Liste2 listeS; // liste des MEC à supprimer
	ofstream os;
};

void initialiser(Messagerie& m);

void detruire(Messagerie& m);

void recevoirPaquetReseau(istream& is, PaquetReseau& paquet);

/**
* @brief Affiche les BlocData associés à chaque IdMessage
* @version 2.0 : 24/12/2017
* @param[out] ListeMsgEnCours : liste contenant les BlocData de chaque message
* @param[in] is : flux d'entrée istream sur un fichier txt
* @param[in] paquet : PaquetReseau en pointeur pour manipuler un tableau de paquets
*/
void traiterPaquetReseau(Messagerie& is, PaquetReseau& paquet);

/**
* @brief Retourne true si l'IdMessage est dans la liste sinon false
* @param[in] liste : la liste d'IdMessage
* @param[in] id : l'IdMessage a comparé
* @return true ou false (booléen)
*/
bool existList(const Liste &liste, const IdMessage &id);

/**
* @brief : Retourne la position du message
en cours où l'IdMessage coïncide
* @param[in] liste : la liste d'IdMessage
* @param[in] id : l'IdMessage a comparé
*/
int poslist(const Liste &liste, const PaquetReseau& paquet);

int pertePaquet(const Liste &liste, PaquetReseau& pR);

void ecrireM(ostream& os, const Messagerie& m);

void supprMes(Messagerie& m);

void creerMailbox(Messagerie& m);

#endif