/*
 -----------------------------------------------------------------------------------
 Nom du fichier  : crible.h
 Auteur(s)       : Pedro Alves da Silva, Jeremiah Steiner
 Date creation   : 18 novembre 2021
 Nom laboratoire : Labo 6-D - Crible
 Description     : Header pour crible.cpp
 Remarque(s)     : -
 Compilateur     : gcc 9.3.0 on Ubuntu 20.04, Mingw-w64 g++ 8.1.0 on Windows, Cmake
 -----------------------------------------------------------------------------------
*/

#ifndef LABO6CRIBLE_CRIBLE_H
#define LABO6CRIBLE_CRIBLE_H

void EliminerMultiples(bool tableau[],
                       size_t taille,
                       unsigned indiceNbrPremier);

void EffectuerCribleSur(bool tableau[],
                        size_t taille);

void InitialiserTableau(bool tableau[],
                        size_t taille);

#endif //LABO6CRIBLE_CRIBLE_H
