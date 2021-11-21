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

const char NBR_PREMIER = 'O';
const char NBR_NON_PREMIER = 'X';

// TODO: pas besoin de déclarer ça en hardcodé. On peut parcourir les indices de 1 à 7, en vérifiant si l'indice i a déjà été coché
const unsigned NBR_INDICE_ERATOSTHENE_MAX = 6;

void EliminerMultiples(char tableau[],
                       unsigned taille,
                       unsigned indiceNbrPremier);

void EffectuerCribleSur(char tableau[],
                        unsigned taille);

void InitialiserTableau(char tableau[],
                        unsigned taille);

#endif //LABO6CRIBLE_CRIBLE_H
