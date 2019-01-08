#ifndef _MSG_
#define _MSG_

/**
* @file MessageEnCours.h
* Projet SDA
* @author Morgane Laurent, Aroun Radjavelou, Tristan Bilot
* @version 2 - 17/12/2017
* @brief Fonctions liées à la messagerie
*/

#include "IdMessage.h"
#include "FileAPriorite.h"
#include "PaquetReseau.h"



/**
* @brief Structure de données de type MessageEnCours
*/
struct MessageEnCours {
	IdMessage idMes; // Structure de IdMessage
	FileAPriorite fileB; // File contenant des blocData
	unsigned short LgMes; // Longueur du message
	unsigned short nbPRecus; // nombre de paquet reçus
	unsigned short LastPRecu; // Dernier paquet reçu
};
void initialiser(MessageEnCours& m, const PaquetReseau& p);

void detruire(MessageEnCours& m);

void ecrireMEC(ostream& os, MessageEnCours& m);

#endif