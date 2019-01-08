#ifndef _LISTE_
#define _LISTE_

/**
* @file Liste.h
* Projet sem06-cours-Cpp2
* @author l'équipe pédagogique
* @version 2 - 13/01/10
* @brief Composant de liste en mémoire dynamique et extensible
* Structures de données et algorithmes - DUT1 Paris 5
*/

#include "ConteneurTDE.h"

struct Liste {
	ConteneurTDE c;		// tableau mémorisant les éléments de la liste
	unsigned int nb;	// nombre d'éléments stockés dans la liste
};

/**
* @brief Initialiser une liste vide
* la liste est allouée en mémoire dynamique
* @see detruire, la liste est à désallouer en fin d’utilisation
* @param[out] l : la liste à initialiser
* @param[in] capa : capacité de la liste
* @param[in] pas : pas d’extension de la liste
* @pre capa>0 et pas>0
*/
void initialiser(Liste& l, unsigned int capa, unsigned int pas);

/**
* @brief Désallouer une liste
* @see initialiser, la liste a déjà été allouée en mémoire dynamique
* @param[out] l : la liste
*/
void detruire(Liste& l);

/**
* @brief Longueur de liste
* @param[in] l : la liste
* @return la longueur de la liste
*/
unsigned int longueur(const Liste& l);

/**
* @brief Lire un élément de liste
* @param[in] l : la liste
* @param[in] pos : position de l'élément à lire
* @return l'item lu en position pos
* @pre 0<=pos<longueur(l)
*/
Item lire(const Liste& l, unsigned int pos);

/**
* @brief Ecrire un item dans la liste
* @param[in,out] l : la liste
* @param[in] pos : position de l'élément à écrire
* @param[in] it : l'item
* @pre 0<=pos<longueur(l)
*/
void ecrire(Liste& l, unsigned int pos, const Item& it);

/**
* @brief Insérer un élément dans une liste
* @param[in,out] l : la liste
* @param[in] pos : la position à laquelle l'élément est inséré
* @param[in] it : l'élément inséré
* @pre 0<=pos<=longueur(l)
* l’insertion est faite avant la position pos
*/
void inserer(Liste& l, unsigned int pos, const Item& it);

/**
* @brief Supprimer un élément dans une liste
* @param[in,out] l : la liste
* @param[in] pos : la position de l'élément à supprimer
* @pre longueur(l)>0 et 0<=pos<longueur(l)
*/
void supprimer(Liste& l, unsigned int pos);

#endif
