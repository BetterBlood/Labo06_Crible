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

const string MESSAGE_DEMANDER_NOMBRE = "Entrez le nombre de valeurs";

int main()
{
	const unsigned tailleTableau = LireUnNombre(0, 100, MESSAGE_DEMANDER_NOMBRE);
	// Demander taille de tableau
	// Initialiser tableau
	char* tab = IninitialiserTableau(tailleTableau);
	// Démarrer algorithme de crible avec le tableau
	EffectuerCribleSur(tab, tailleTableau);
	// Afficher les nombres premiers

	// TODO: à appeller afficher, et à mettre le message "Veuillez appuyer pour quitter le programme" en constant
	VIDER_BUFFER();
	return EXIT_SUCCESS;
}