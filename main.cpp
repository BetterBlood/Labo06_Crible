/* 
 ----------------------------------------------------------------------------------- 
 Nom du fichier  : main.cpp
 Auteur(s)       : Pedro Alves da Silva, Jeremiah Steiner
 Date creation   : 18 novembre 2021
 Nom laboratoire : Labo 6-D - Crible
 Description     :
 Remarque(s)     : <à compléter>
 Compilateur     : gcc 9.3.0 on Ubuntu 20.04, Mingw-w64 g++ 8.1.0 on Windows, Cmake
 ----------------------------------------------------------------------------------- 
*/

#include <iostream>
#include <string>
#include "io.h"
#include "crible.h"

using namespace std;

int main()
{
    /*
     * Déclaration des constantes locales
     */
    const unsigned TABLEAU_TAILLE_MIN           = 2;
    const unsigned TABLEAU_TAILLE_MAX           = 300;
    const string MESSAGE_DEMANDER_NOMBRE        = "Entrez le nombre de valeurs";
    const string MESSAGE_INITIALISATION_TABLEAU = "initialisation du tableau";
    const string MESSAGE_CRIBLAGE_TABLEAU       = "Criblage du tableau";
    const string MESSAGE_FIN                    = "Veuillez appuyer sur enter pour quitter le programme";
    const string MESSAGE_DEMARRAGE              = "Labo 6D - Identification de tous les nombres premiers dans "
                                                  "l'intervalle 2 à n en utilisant la méthode du crible Eratosthène";

    // Déclarer le tableau
    static char tableau[TABLEAU_TAILLE_MAX];

    /*
     * Démarrage du programme
     */
    Afficher(MESSAGE_DEMARRAGE);

    /*
     * Entrée et affichage du tableau initialisé
     */

    // Demander taille de tableau
	const unsigned tailleTableau = LireUnNombre(TABLEAU_TAILLE_MIN,
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
    tableau[0] = NBR_NON_PREMIER;

	// Démarrer l'algorithme de crible avec le tableau
	EffectuerCribleSur(tableau, tailleTableau);

    // Afficher le tableau après application du crible
    Afficher(MESSAGE_CRIBLAGE_TABLEAU);
    AfficherTableau(tableau, tailleTableau);
    NouvelleLigne();

	// TODO : Afficher les nombres premiers + message descriptif
    AfficherNombresPremiers(tableau, tailleTableau, NBR_PREMIER);

    /*
     * Fin du programme
     */
    Afficher(MESSAGE_FIN, false);
	VIDER_BUFFER();
	return EXIT_SUCCESS;
}