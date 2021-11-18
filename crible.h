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

#ifndef LABO6CRIBLE_CRIBLE_H
#define LABO6CRIBLE_CRIBLE_H

const char NBR_NON_PREMIER = 'O';
const char NBR_PREMIER = 'X';
const unsigned TAILLE_NBRS_PREMIERS = 4;
const unsigned NBRS_PREMIERS[TAILLE_NBRS_PREMIERS]= {2, 3, 5, 7};

void EliminerMultiples(char tab[], const unsigned taille, const unsigned multiple);
void EffectuerCribleSur(char tab[], const unsigned taille);
char* IninitialiserTableau(const unsigned taille);

#endif //LABO6CRIBLE_CRIBLE_H
