#ifndef _FILE_
#define _FILE_

/**
 * @file FileAPriorite.h
 * Projet sem06-cours-Cpp1
 * @author l'équipe pédagogique 
 * @version 2 - 13/01/10
 * @brief Composant de file dont le conteneur est
 * un tableau circulaire en mémoire dynamique avec capacité paramétrée
 * Structures de données et algorithmes - DUT1 Paris 5
 */

#include "ConteneurTD.h"

struct FileAPriorite {
 ConteneurTD c;	 // conteneur des éléments de file
 unsigned int indPremier; // index de la tête de file dans tab
 unsigned int indProchain;// index du prochain élément entré en file
 unsigned int nb;		 // nombre d'éléments dans la file
};

/**
 * @brief initialiser une file vide
 * la file est allouée en mémoire dynamique
 * @see detruire, elle est à désallouer en fin d’utilisation
 * @param[out] f : la file à initialiser
 * @param[in] capa : capacité de la file (nb maximum d‘items stockés)
 * @pre capa>0
 */
void initialiser(FileAPriorite& f, unsigned int capa);

	/**
	 * @brief Désallouer une file
	 * @see initialiser, la file a déjà été allouée en mémoire dynamique
	 * @param[out] f : la file 
	 */
void detruire(FileAPriorite& f);

/**
 * @brief Test de file pleine
 * @param[in] f : la file testée
 * @return true si f est pleine, false sinon
 */
bool estPleine(const FileAPriorite& f);

/**
 * @brief Test de file vide 
 * @param[in] f : la file testée
 * @return true si f est vide, false sinon
 */
bool estVide(const FileAPriorite& f);

/**
 * @brief Lire l'item en tête de file 
 * @param[in] f : la file
 * @return la valeur de l'item en tête de file
 * @pre la file n’est pas vide
 */
ItemF tete(const FileAPriorite& f);

/**
 * @brief Entrer un item dans la file
 * @param[in,out] f : la file
 * @param[in] it : l'item à entrer
 * @pre f n’est pas pleine
 */
void entrer(FileAPriorite& f, const ItemF& it);

/**
 * @brief Sortir l’item tête de file
 * @param[in,out] f : la file
 * @pre f n’est pas vide
 */
void sortir(FileAPriorite& f);

#endif
