/**
 * @file ConteneurTD.cpp
 * Projet sem04-tp-Cpp3
 * @author l'�quipe p�dagogique 
 * @version 1 19/12/05
 * @brief Composant de conteneur d'items en m�moire dynamique � capacit� fixe
 * Structures de donn�es et algorithmes - DUT1 Paris 5
 */

#include <iostream>
#include <cassert>

#include "ConteneurTD.h"
using namespace std;

/**
 * @brief Initialise un conteneur d'items vide
 * Allocation en m�moire dynamique du conteneur d'items de capacit� capa
 * @see detruire pour sa d�sallocation en fin d'utilisation 
 * @param[out] c : le conteneur d'items
 * @param [in] capa : capacit� du tableau
 * @pre capa>0
 */
void initialiser(ConteneurTD& c, unsigned int capa) {
	assert(capa>0);
	c.capacite = capa;
	// arr�t du programme en cas d'erreur d'allocation
	c.tab = new ItemF[capa];	
	/* Affichage pour une trace de l'allocation
	 * Ne jamais faire d'affichage dans une fonction 
	 * dont ce n'est pas le r�le explicite */	
	//cout << "Allocation de " << t.capacite*sizeof(Item)<< " octets"<< endl;
}

/**
 * @brief D�salloue un conteneur d'items en m�moire dynamique
 * @see initialiser le conteneur d'items a d�j� �t� allou� 
 * @param[out] c : le conteneur d'items
 */
void detruire(ConteneurTD& c) {
	delete [] c.tab;
	c.tab = NULL;
}

/**
 * @brief Lecture d'un item dans un conteneur
 * @param[in] c : le conteneur d'items
 * @param[in] i : l'indice de l'item dans le conteneur
 * @return l'item � la position i
 * @pre i < c.capacite   
 */
 ItemF lire(const ConteneurTD& c, unsigned int i) {
	assert(i < c.capacite);
	return c.tab[i];
}

/**
 * @brief Ecrire un item dans un conteneur d'items
 * @param[out] c : le conteneur d'items
 * @param[in] i : la position o� ajouter/modifier l'item
 * @param[in] item : l'item � �crire
 * @pre i < c.capacite
 */
void ecrire(ConteneurTD& c, unsigned int i, const ItemF& it) {
	assert(i < c.capacite);
	c.tab[i] = it;
}