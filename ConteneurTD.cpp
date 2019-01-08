/**
 * @file ConteneurTD.cpp
 * Projet sem04-tp-Cpp3
 * @author l'équipe pédagogique 
 * @version 1 19/12/05
 * @brief Composant de conteneur d'items en mémoire dynamique à capacité fixe
 * Structures de données et algorithmes - DUT1 Paris 5
 */

#include <iostream>
#include <cassert>

#include "ConteneurTD.h"
using namespace std;

/**
 * @brief Initialise un conteneur d'items vide
 * Allocation en mémoire dynamique du conteneur d'items de capacité capa
 * @see detruire pour sa désallocation en fin d'utilisation 
 * @param[out] c : le conteneur d'items
 * @param [in] capa : capacité du tableau
 * @pre capa>0
 */
void initialiser(ConteneurTD& c, unsigned int capa) {
	assert(capa>0);
	c.capacite = capa;
	// arrêt du programme en cas d'erreur d'allocation
	c.tab = new ItemF[capa];	
	/* Affichage pour une trace de l'allocation
	 * Ne jamais faire d'affichage dans une fonction 
	 * dont ce n'est pas le rôle explicite */	
	//cout << "Allocation de " << t.capacite*sizeof(Item)<< " octets"<< endl;
}

/**
 * @brief Désalloue un conteneur d'items en mémoire dynamique
 * @see initialiser le conteneur d'items a déjà été alloué 
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
 * @return l'item à la position i
 * @pre i < c.capacite   
 */
 ItemF lire(const ConteneurTD& c, unsigned int i) {
	assert(i < c.capacite);
	return c.tab[i];
}

/**
 * @brief Ecrire un item dans un conteneur d'items
 * @param[out] c : le conteneur d'items
 * @param[in] i : la position où ajouter/modifier l'item
 * @param[in] item : l'item à écrire
 * @pre i < c.capacite
 */
void ecrire(ConteneurTD& c, unsigned int i, const ItemF& it) {
	assert(i < c.capacite);
	c.tab[i] = it;
}