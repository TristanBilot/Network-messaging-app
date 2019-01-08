#ifndef _CONTENEUR_TD_
#define _CONTENEUR_TD_

/**
 * @file ConteneurTD.h
 * Projet sem04-tp-Cpp3
 * @author l'�quipe p�dagogique 
 * @version 1 19/12/05
 * @brief Composant de conteneur d'items en m�moire dynamique � capacit� fixe
 * Structures de donn�es et algorithmes - DUT1 Paris 5
 */

#include "ItemF.h"

/** @brief Type des conteneurs d'itemes allou�s en m�moire dynamique
 *  et de capacit� fixe */ 
struct ConteneurTD {
	unsigned int capacite; 	// capacit� du conteneur (>0)
	ItemF* tab;				// tableau d'items allou� en m�moire dynamique
};

/**
 * @brief Initialise un conteneur d'items vide
 * Allocation en m�moire dynamique du conteneur d'items de capacit� capa
 * @see detruire pour sa d�sallocation en fin d'utilisation 
 * @param[out] c : le conteneur d'items
 * @param [in] capa : capacit� du tableau
 * @pre capa>0
 */
void initialiser(ConteneurTD& c, unsigned int capa);

/**
 * @brief D�salloue un conteneur d'items en m�moire dynamique
 * @see initialiser le conteneur d'items a d�j� �t� allou� 
 * @param[out] c : le conteneur d'items
 */
void detruire(ConteneurTD& c);

/**
 * @brief Lecture d'un item dans un conteneur
 * @param[in] c : le conteneur d'items
 * @param[in] i : l'indice de l'item dans le conteneur
 * @return l'item � la position i
 * @pre i < c.capacite   
 */
 ItemF lire(const ConteneurTD& c, unsigned int i); 

/**
 * @brief Ecrire un item dans un conteneur d'items
 * @param[out] c : le conteneur d'items
 * @param[in] i : la position o� ajouter/modifier l'item
 * @param[in] item : l'item � �crire
 * @pre i < c.capacite
 */
void ecrire(ConteneurTD& t, unsigned int i, const ItemF& it);

#endif /*_CONTENEUR_TD_*/



