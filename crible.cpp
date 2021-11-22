/* 
 ----------------------------------------------------------------------------------- 
 Nom du fichier  : main.cpp
 Auteur(s)       : Pedro Alves da Silva, Jeremiah Steiner
 Date creation   : 18 novembre 2021
 Nom laboratoire : Labo 6-D - Crible
 Description     : Fichier source avec toutes les fonctions de gestion du tableau
				   et propres au labo
 Remarque(s)     : -
 Compilateur     : gcc 9.3.0 on Ubuntu 20.04, Mingw-w64 g++ 8.1.0 on Windows, Cmake
 ----------------------------------------------------------------------------------- 
*/

#include <iostream>
#include "crible.h"

using namespace std;

/*
 * Déclaration des constantes propes au fichier source
 */
const unsigned NBR_INDICE_ERATOSTHENE_MAX = 6;

/// Initialise toutes les cellules du tableau avec leur valeur par défaut
/// \param taille Taille du tableau
void InitialiserTableau(bool tableau[],
                        size_t taille)
{
    // Initialiser tous les indices
	for (size_t i = 0; i < taille; ++i)
	{
        // Lors de l'initialisation, on part du principe que tous les indices réprésentent un nombre premier
		tableau[i] = true;
	}
}


/// Élimine tous les multiples du nombre fourni en paramètre dans le tableau
/// \param tableau Tableau
/// \param taille Taille du tableau
/// \param indiceNbrPremier Indice du nombre premier, avec lequel trouver les multiples
void EliminerMultiples(bool tableau[],
                       size_t taille,
                       unsigned indiceNbrPremier)
{
    // Les indices commencent à 0; ajouter 1 pour obtenir le nombre premier
    unsigned nombrePremier = indiceNbrPremier + 1;

    // Parcourir tous les nombres composés
    // Nous avons essayé de rendre la clause plus lisible à cause du nom des variables
	for (unsigned indiceNbrCompose = indiceNbrPremier + nombrePremier ;
         indiceNbrCompose < taille ;
         indiceNbrCompose += nombrePremier)
	{
        tableau[indiceNbrCompose] = false;
	}
}


/// Utilise la procédure du crible d'Eratosthène pour identifier les nombres premiers dans un tableau fourni
/// \param tableau Tableau
/// \param taille Taille du tableau
void EffectuerCribleSur(bool tableau[],
                        size_t taille)
{
    // Vérifier les indices de 0 à 6 (valeurs 1 à 7), et éliminer leurs multiples
	for (size_t indice = 0; indice <= NBR_INDICE_ERATOSTHENE_MAX; ++indice)
	{
        // Vérifier si la valeur dans l'indice n'a pas encore été éliminée
        if(tableau[indice])
        {
            EliminerMultiples(tableau,
                              taille,
                              indice);
        }
	}
}