/*
 -----------------------------------------------------------------------------------
 Nom du fichier  : io.h
 Auteur(s)       : Pedro Alves da Silva, Jeremiah Steiner
 Date creation   : 18 novembre 2021
 Nom laboratoire : Labo 6-D - Crible
 Description     : Header pour io.cpp
 Remarque(s)     : -
 Compilateur     : gcc 9.3.0 on Ubuntu 20.04, Mingw-w64 g++ 8.1.0 on Windows, Cmake
 -----------------------------------------------------------------------------------
*/

#ifndef LABO6CRIBLE_IO_H
#define LABO6CRIBLE_IO_H

#include <iostream>
#include <limits>
#include <string>
#include "dictionnaire.h"

#define VIDER_BUFFER() std::cin.ignore(std::numeric_limits<streamsize>::max(), '\n')

int LireUnNombre(int borneMin,
				 int borneMax,
				 const std::string &msgPrompt = MESSAGE_PROMPT_NOMBRE,
                 const std::string &msgErreur = MESSAGE_ERREUR_NOMBRE,
				 bool afficherBornes = true);

void Afficher(const std::string& message,
			  bool retourLigne = true);

void Afficher(char caractere,
              bool retourLigne = true);

void AfficherTableau(const bool tableau[],
                     size_t taille);

void AfficherNombresPremiers(const bool tab[],
							 size_t taille);

size_t EspacementAvantNombre(int chiffreAffiche,
							 int espacementMax = 4);

void NouvelleLigne();

#endif //LABO6CRIBLE_IO_H
