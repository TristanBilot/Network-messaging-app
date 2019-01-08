#ifndef _CONTENEUR_TDE_
#define _CONTENEUR_TDE_

/**
 * @file ConteneurTDE.h
 * Projet sem04-tp-Cpp1-3
 * @author l'équipe pédagogique 
 * @version 2 26/11/11
 * @brief Composant d'un conteneur d'items de capacité extensible
 * Structures de données et algorithmes - DUT1 Paris 5
 */

#include "Item.h"

/** @brief Conteneur d'items alloués en mémoire dynamique
 *  de capacité extensible suivant un pas d'extension
 */ 
struct ConteneurTDE {
	unsigned int capacite; 	   // capacité du conteneur (>0)
	unsigned int pasExtension; // pas d'extension du conteneur (>0)
	Item* tab;				   // conteneur alloué en mémoire dynamique
};

/**
 * @brief Initialise un conteneur d'items
 * Allocation en mémoire dynamique du conteneur d'items
 * de capacité (capa) extensible par pas d'extension (p)
 * @see detruire, pour sa désallocation en fin d'utilisation 
 * @param[out] c : le conteneur d'items
 * @param [in] capa : capacité du conteneur
 * @param [in] p : pas d'extension de capacité
 * @pre capa>0 et p>0
 */
void initialiser(ConteneurTDE& c, unsigned int capa, unsigned int p);

/**
 * @brief Désalloue un conteneur d'items en mémoire dynamique
 * @see initialiser, le conteneur d'items a déjà été alloué 
 * @param[in,out] c : le conteneur d'items
 */
void detruire(ConteneurTDE& c); 

/**
 * @brief Lecture d'un item d'un conteneur d'items
 * @param[in] c : le conteneur d'items
 * @param[in] i : la position de l'item dans le conteneur
 * @return l'item à la position i
 * @pre i < c.capacite   
 */
 Item lire(const ConteneurTDE& c, unsigned int i);

/**
 * @brief Ecrire un item dans un conteneur d'items
 * @param[in,out] c : le conteneur d'items
 * @param[in] i : la position où ajouter/modifier l'item
 * @param[in] it : l'item à écrire 
 */
void ecrire(ConteneurTDE& c, unsigned int i, const Item& it);

#endif /*_CONTENEUR_TDE_*/
