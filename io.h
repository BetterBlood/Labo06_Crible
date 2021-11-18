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

#ifndef LABO6CRIBLE_IO_H
#define LABO6CRIBLE_IO_H

#include <iostream>
#include <limits>

#define VIDER_BUFFER() std::cin.ignore(std::numeric_limits<streamsize>::max(), '\n')

const int NOMBRES_PAR_LIGNE = 10;
const char CARACTERE_ESPACE = ' ';
const char CARACTERE_FIN_PROMPT = ':';
const std::string MESSAGE_PROMPT_NOMBRE = "Veuillez entrer un nombre";
const std::string MESSAGE_ERREUR_NOMBRE = "Ce nombre n'est pas valable!";

int LireUnNombre(int borneMin,
				 int borneMax,
				 const std::string &msgPrompt = MESSAGE_PROMPT_NOMBRE,
                 const std::string &msgErreur = MESSAGE_ERREUR_NOMBRE,
				 bool afficherBornes=true);

void Afficher(const std::string& message,
			  bool retourLigne=true);

void Afficher(const char caractere,
			  bool retourLigne=true);

void afficherTableau(int tableau[],
					 int taille);

void NouvelleLigne();

#endif //LABO6CRIBLE_IO_H
