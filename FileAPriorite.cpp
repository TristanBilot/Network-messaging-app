/**
 * @file FileAPriorite.cpp
 * Projet sem06-cours-Cpp1
 * @author l'�quipe p�dagogique 
 * @version 2 - 13/01/10
 * @brief Composant de file avec capacit� param�tr�e
 * Structures de donn�es et algorithmes - DUT1 Paris 5
 */
 
#include <cassert>

#include "FileAPriorite.h"

/**
 * @brief initialiser une file vide
 * la file est allou�e en m�moire dynamique
 * @see detruire, elle est � d�sallouer en fin d�utilisation
 * @param[out] f : la file � initialiser
 * @param[in] capa : capacit� de la file (nb maximum d�items stock�s)
 * @pre capa>0
 */
void initialiser(FileAPriorite& f, unsigned int capa) {
	assert(capa>0);
	initialiser(f.c, capa); // @see initialiser de ConteneurTD
	f.indPremier = 0;
	f.indProchain = 0;
	f.nb = 0;
}

/**
 * @brief D�sallouer une file
 * @see initialiser, la file a d�j� �t� allou�e en m�moire dynamique
 * @param[out] f : la file 
 */
void detruire(FileAPriorite& f) {
	 detruire(f.c); // @see detruire de ConteneurTD
}

/**
 * @brief Test de file pleine
 * @param[in] f : la file test�e
 * @return true si f est pleine, false sinon
 */
bool estPleine(const FileAPriorite& f) {
	return (f.nb == f.c.capacite); // @see type ConteneurTD 
}

/**
 * @brief Test de file vide 
 * @param[in] f : la file test�e
 * @return true si f est vide, false sinon
 */
bool estVide(const FileAPriorite& f) {
	return (f.nb == 0);
}

/**
 * @brief Lire l'item en t�te de file 
 * @param[in] f : la file
 * @return la valeur de l'item en t�te de file
 * @pre la file n�est pas vide
 */
ItemF tete(const FileAPriorite& f) {
	assert(!estVide(f));
	return lire(f.c, f.indPremier); // @see lire, dans ConteneurTD 
}

/**
 * @brief Entrer un item dans la file
 * @param[in,out] f : la file
 * @param[in] it : l'item � entrer
 * @pre f n�est pas pleine
 */
void entrer(FileAPriorite& f, const ItemF& it) {
	assert(!estPleine(f));
	BlocData b1;
	bool ordre = false;
	for (unsigned int i = 0; i < f.nb; i++) {
		b1 = lire(f.c, i);
		if (enOrdre(it, b1)) {
			ordre = true;
			for (unsigned int j = f.nb; j > i; j--) {
				ecrire(f.c, j, lire(f.c, j - 1));
			}
			ecrire(f.c, i, it);
			break;
		}
	}
	if (!ordre)
		ecrire(f.c, f.indProchain, it);
	f.indProchain = (f.indProchain + 1) % f.c.capacite;
	f.nb++;
}

/**
 * @brief Sortir l�item t�te de file
 * @param[in,out] f : la file
 * @pre f n�est pas vide
 */
void sortir(FileAPriorite& f) {
	assert(!estVide(f));
	f.indPremier = (f.indPremier+1)%f.c.capacite;;
	f.nb--;
}