#ifndef _CONTENEUR_TD_
#define _CONTENEUR_TD_

/**
 * @file ConteneurTD.h
 * Projet sem04-tp-Cpp3
 * @author l'équipe pédagogique 
 * @version 1 19/12/05
 * @brief Composant de conteneur d'items en mémoire dynamique à capacité fixe
 * Structures de données et algorithmes - DUT1 Paris 5
 */

#include "ItemF.h"

/** @brief Type des conteneurs d'itemes alloués en mémoire dynamique
 *  et de capacité fixe */ 
struct ConteneurTD {
	unsigned int capacite; 	// capacité du conteneur (>0)
	ItemF* tab;				// tableau d'items alloué en mémoire dynamique
};

/**
 * @brief Initialise un conteneur d'items vide
 * Allocation en mémoire dynamique du conteneur d'items de capacité capa
 * @see detruire pour sa désallocation en fin d'utilisation 
 * @param[out] c : le conteneur d'items
 * @param [in] capa : capacité du tableau
 * @pre capa>0
 */
void initialiser(ConteneurTD& c, unsigned int capa);

/**
 * @brief Désalloue un conteneur d'items en mémoire dynamique
 * @see initialiser le conteneur d'items a déjà été alloué 
 * @param[out] c : le conteneur d'items
 */
void detruire(ConteneurTD& c);

/**
 * @brief Lecture d'un item dans un conteneur
 * @param[in] c : le conteneur d'items
 * @param[in] i : l'indice de l'item dans le conteneur
 * @return l'item à la position i
 * @pre i < c.capacite   
 */
 ItemF lire(const ConteneurTD& c, unsigned int i); 

/**
 * @brief Ecrire un item dans un conteneur d'items
 * @param[out] c : le conteneur d'items
 * @param[in] i : la position où ajouter/modifier l'item
 * @param[in] item : l'item à écrire
 * @pre i < c.capacite
 */
void ecrire(ConteneurTD& t, unsigned int i, const ItemF& it);

#endif /*_CONTENEUR_TD_*/



