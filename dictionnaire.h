/*
 -----------------------------------------------------------------------------------
 Nom du fichier  : dictionnaire.h
 Auteur(s)       : Pedro Alves da Silva, Jeremiah Steiner
 Date creation   : 18 novembre 2021
 Nom laboratoire : Labo 6-D - Crible
 Description     : Header contenant tous les messages affichés dans la console,
                   prêts à être utilisés par les autres fichiers
 Remarque(s)     : -
 Compilateur     : gcc 9.3.0 on Ubuntu 20.04, Mingw-w64 g++ 8.1.0 on Windows, Cmake
 -----------------------------------------------------------------------------------
*/

#ifndef LABO6CRIBLE_DICTIONNAIRE_H
#define LABO6CRIBLE_DICTIONNAIRE_H

#include <iostream>
#include <string>

const std::string MESSAGE_PROMPT_NOMBRE          = "Veuillez entrer un nombre";
const std::string MESSAGE_ERREUR_NOMBRE          = "Ce nombre n'est pas valable!";
const std::string MESSAGE_NOMBRES_PREMIER_1      = "Il y a ";
const std::string MESSAGE_NOMBRES_PREMIER_2_SING = " nombre premier";
const std::string MESSAGE_NOMBRES_PREMIER_2_PLUR = " nombres premiers";
const std::string MESSAGE_DEMANDER_NOMBRE        = "Entrez le nombre de valeurs";
const std::string MESSAGE_INITIALISATION_TABLEAU = "initialisation du tableau";
const std::string MESSAGE_CRIBLAGE_TABLEAU       = "Criblage du tableau";
const std::string MESSAGE_FIN                    = "Veuillez appuyer sur enter pour quitter le programme";
const std::string MESSAGE_DEMARRAGE              = "Labo 6D - Identification de tous les nombres premiers dans "
												   "l'intervalle 2 à n en utilisant la méthode du crible Eratosthène";

#endif //LABO6CRIBLE_DICTIONNAIRE_H
