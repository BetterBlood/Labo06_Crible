/* 
 ----------------------------------------------------------------------------------- 
 Nom du fichier  : main.cpp
 Auteur(s)       : Pedro Alves da Silva, Jeremiah Steiner
 Date creation   : 18 novembre 2021
 Nom laboratoire : Labo 6-D - Crible
 Description     : Fichier source permettant la gestion de l'affichage des données,
                   qu'elles soient messages ou tableau
 Remarque(s)     : -
 Compilateur     : gcc 9.3.0 on Ubuntu 20.04, Mingw-w64 g++ 8.1.0 on Windows, Cmake
 ----------------------------------------------------------------------------------- 
*/

#include "io.h"
#include <cmath>

using namespace std;

/*
 * Constantes utilisées au sein du fichier source
 */
const int NOMBRES_PAR_LIGNE               = 10;
const char CARACTERE_ESPACE               = ' ';
const char CARACTERE_FIN_PROMPT           = ':';
const char NBR_PREMIER                    = 'O';
const char NBR_NON_PREMIER                = 'X';

/// Lis un nombre entré par l'utilisateur, et retourne ledit nombre
/// \param borneMin Valeur minimale acceptable (inclue)
/// \param borneMax Valeur maximale acceptable (inclue)
/// \param msgPrompt Message de demande
/// \param msgErreur Message à Afficher en cas d'erreur
/// \param afficherBornes Est-ce que les bornes sont affichées?
/// \remark Vérification des bornes: [borneMin; borneMax]
/// \return Le nombe récupéré du flux
int LireUnNombre(int borneMin,
				 int borneMax,
				 const std::string &msgPrompt,
                 const std::string &msgErreur,
                 bool afficherBornes)
{
	bool erreur;
	int nombreLu;

	do {
		Afficher(MESSAGE_PROMPT_NOMBRE, false);

		// Afficher les bornes seulement si on a besoin
		if(afficherBornes)
		{
			Afficher(CARACTERE_ESPACE, false);
			Afficher("["s + to_string(borneMin) + " - " + to_string(borneMax) + "]", false);
		}

		// Afficher fin de prompt et lire nombre
		Afficher(CARACTERE_FIN_PROMPT, false);
		Afficher(CARACTERE_ESPACE, false);
		cin >> nombreLu;

		// Vérification d'erreurs
		erreur = cin.fail() || nombreLu < borneMin || nombreLu > borneMax;
		cin.clear();
		VIDER_BUFFER();

        // La méthode Afficher retourne void, donc on ne peut pas l'utiliser dans la clause
        // du while pour afficher un message en cas d'erreur
        if(erreur)
        {
            Afficher(msgErreur);
        }

	} while(erreur);

	return nombreLu;
}


/// Affiche toutes les valeurs dans le tableau fourni en paramètres
/// \param tableau Tableau à lire
/// \param taille Taille du tableau
void AfficherTableau(const bool tableau[],
                     size_t taille)
{
    bool retourLigne = false;

	// Parcourir toutes les cases du tableau
	for(size_t i = 0; i < taille; ++i)
	{
		// Déterminer s'il nous faudra faire un saut de ligne
        // Si on en a besoin, alors on affecte la variable booléenne pour vérifier plus tard si on a besoin d'un espace
        // 0 est multiple de n'importe quel nombre, donc on vérifie que i > 0
		if (i > 0 && i % NOMBRES_PAR_LIGNE == 0)
		{
            retourLigne = true;
			NouvelleLigne();
		}
		else
		{
            retourLigne = false;
		}

        // Afficher la valeur à l'index i
        Afficher(tableau[i] ? NBR_PREMIER : NBR_NON_PREMIER, false);

        // Afficher l'espace après la valeur que si on n'a pas besoin de faire un retour de ligne
        Afficher(CARACTERE_ESPACE, false);
	}

    // Ajouter une nouvelle ligne pour terminer l'affichage du tableau
    NouvelleLigne();
}


/// Fait un retour de ligne dans la console
void NouvelleLigne()
{
	cout << endl;
}


/// Affiche un message dans la console. Fonction surchargée
/// \param message Message à Afficher
/// \param retourLigne Est-ce qu'il faut faire un retour de ligne?
void Afficher(const string &message,
              bool retourLigne)
{
	cout << message;

	if (retourLigne)
	{
		NouvelleLigne();
	}
}


/// Affiche un caractère dans la console. Fonction surchargée
/// \param caractere Caractère à Afficher
/// \param retourLigne Est-ce qu'il faut faire un retour de ligne?
void Afficher(char caractere,
              bool retourLigne)
{
	Afficher(string(1, caractere), retourLigne);
}


/// Affiche l'indice + 1de chaque caractère passé en param
/// \param tab Tableau
/// \param taille Taille du tableau
void AfficherNombresPremiers(const bool tab[],
							 size_t taille)
{
    string msgListeNbrPrem;
    unsigned nbrNbrPrem = 0; // Nombre de nombres premiers contenus dans le tableau
    int dernierI = 2; // car le premier nombre premier est 2 (donc première fois que dernierI est initialiser)

    for (size_t i = 0; i < taille; ++i)
    {
		// Si tab[i] est un nombre premier
        if (tab[i])
        {
			// Récupérer le nombre d'espaces à afficher pour l'espacement, et ajouter au string du message à afficher
            msgListeNbrPrem.append(string(EspacementAvantNombre(i + 1), CARACTERE_ESPACE));
            msgListeNbrPrem.append(to_string(i + 1));

            ++nbrNbrPrem;
            dernierI = i;
        }

		// Ajouter une nouvelle ligne chaque 10 nombres premiers
        if (nbrNbrPrem % NOMBRES_PAR_LIGNE == 0 && dernierI == i)
        {
            msgListeNbrPrem.append("\n");
        }
    }

    Afficher(MESSAGE_NOMBRES_PREMIER_1 + to_string(nbrNbrPrem), false);

	// Afficher le message au singulier ou au pluriel selon le nombre de nombres premiers
	if(nbrNbrPrem == 1)
	{
		Afficher(MESSAGE_NOMBRES_PREMIER_2_SING);
	}
	else
	{
		Afficher(MESSAGE_NOMBRES_PREMIER_2_PLUR);
	}

	// Afficher la liste de nombres premiers identifiés
    Afficher(msgListeNbrPrem, true);
}


/// Permet d'obtenir le nombre d'espace nécessaire pour l'affichage de chiffre
/// \param chiffreAffiche
/// \param espacementMax
/// \return
size_t EspacementAvantNombre(int chiffreAffiche,
							 int espacementMax)
{
    if (chiffreAffiche <= 0)
    {
        return 1;
    }
    return espacementMax - (int)log10(chiffreAffiche);
}