/* 
 ----------------------------------------------------------------------------------- 
 Nom du fichier  : main.cpp
 Auteur(s)       : Pedro Alves da Silva, Jeremiah Steiner
 Date creation   : 18 novembre 2021
 Nom laboratoire : Labo 6-D - Crible
 Description     : Programme qui utilise le crible d'Eratosthène pour identifier tous
                   tous les nombres premiers dans un tableau C, avec une taille
                   maximale de 100 nombres
 Remarque(s)     : -
 Compilateur     : gcc 9.3.0 on Ubuntu 20.04, Mingw-w64 g++ 8.1.0 on Windows, Cmake
 ----------------------------------------------------------------------------------- 
*/

#include <iostream>
#include <string>
#include "io.h"
#include "crible.h"

using namespace std;

/// Fonction principale
/// \return Status de l'exécution du programme
int main()
{
    /*
     * Déclaration des constantes locales
     */
    const unsigned TABLEAU_TAILLE_MIN           = 2;
    const unsigned TABLEAU_TAILLE_MAX           = 100;

    // Déclarer le tableau
    bool tableau[TABLEAU_TAILLE_MAX];

    /*
     * Démarrage du programme
     */
    Afficher(MESSAGE_DEMARRAGE);

    /*
     * Entrée et affichage du tableau initialisé
     */

    // Demander taille de tableau
	const size_t tailleTableau = LireUnNombre(TABLEAU_TAILLE_MIN,
                                                TABLEAU_TAILLE_MAX,
                                                MESSAGE_DEMANDER_NOMBRE);

	// Initialiser tableau (mettre toutes les valeurs entre index 0 et tailleTableau à leur valeur initiale)
    InitialiserTableau(tableau, tailleTableau);

    // Affichage du tableau initialisé
    Afficher(MESSAGE_INITIALISATION_TABLEAU);
    AfficherTableau(tableau, tailleTableau);
    NouvelleLigne();

    /*
     * Identification des nombres premiers, et affichage du criblage et des nombres premiers trouvés
     */

    // Toutefois, le premier indice (index 0) sera toujours non-premier, car il réprésente 1,
    // qui est un multiple de tous les nombres
    tableau[0] = false;

	// Démarrer l'algorithme de crible avec le tableau
	EffectuerCribleSur(tableau, tailleTableau);

    // Afficher le tableau après application du crible
    Afficher(MESSAGE_CRIBLAGE_TABLEAU);
    AfficherTableau(tableau, tailleTableau);
    NouvelleLigne();

	// Afficher les nombres premiers identifiés dans le tableau
	AfficherNombresPremiers(tableau, tailleTableau);

    /*
     * Fin du programme
     */
    Afficher(MESSAGE_FIN, false);
	VIDER_BUFFER();
	return EXIT_SUCCESS;
}