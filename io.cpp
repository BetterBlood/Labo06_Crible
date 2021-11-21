/* 
 ----------------------------------------------------------------------------------- 
 Nom du fichier :  $fileRelativePath()$ $end$
 Auteur(s)      : Pedro Alves da Silva
 Date creation  : $date("dd-MM-YYYY")$
 
 Description    : <à compléter> 
 
 Remarque(s)    : TODO: à ne pas effacer!
                  la méthode LireUnNombre prend en compte un paramètre "afficherBornes"
                  Pour ce laboratoire, elles seront toujours affichées, mais nous
                  l'avons ajouté pour des soucis de réutilisation
 
 Compilateur    : Mingw-w64 g++ 11.1.0  
 ----------------------------------------------------------------------------------- 
*/
#include "io.h"
#include <cmath>

using namespace std;


/// Lis un nombre entré par l'utilisateur, et retourne ledit nombre
/// \param msgPrompt Message de demande
/// \param msgErreur Message à Afficher en cas d'erreur
/// \param borneMin Valeur minimale acceptable (inclue)
/// \param borneMax Valeur maximale acceptable (inclue)
/// \remark Vérification des bornes: [borneMin; borneMax]
/// \return Le nombe récupéré du flux
int LireUnNombre(int borneMin,
				 int borneMax,
				 const std::string &msgPrompt,
                 const std::string &msgErreur,
                 bool afficherBornes)
{
	bool erreur = false;
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
void AfficherTableau(char tableau[],
                     unsigned int taille)
{
    bool retourLigne = false;

	// Parcourir toutes les cases du tableau
	for(int i = 0; i < taille; ++i)
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
        Afficher(tableau[i], false);

        // Afficher l'espace après la valeur que si on n'a pas besoin de faire un retour de ligne
        //if(!retourLigne) {
            Afficher(CARACTERE_ESPACE, false);
        //}
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


/// AfficherNombresPremiers affiche l'indice + 1de chaque caractère passé en param
/// \param tab
/// \param taille
/// \param caractereAComparer
void AfficherNombresPremiers(const char tab[], unsigned taille, char caractereAComparer)
{
    string listeDesNombresPremier = "";
    unsigned nbrDeNombresPremier = 0;
    int dernierI = 2; // car le premier nombre premier est 2 (donc première fois que dernierI est initialiser)

    for (unsigned i = 0; i < taille; ++i)
    {
        if (tab[i] == caractereAComparer)
        {
            listeDesNombresPremier.append(EspaceNecessairePourAffichage(i + 1));
            listeDesNombresPremier.append(to_string(i + 1));

            ++nbrDeNombresPremier;
            dernierI = i;
        }

        if (nbrDeNombresPremier % NOMBRES_PAR_LIGNE == 0 && dernierI == i)
        {
            listeDesNombresPremier.append("\n");
        }
    }

    // TODO: afficher "nbres premiers" au singulier si nbrDeNombresPremier == 1
    Afficher(MESSAGE_NOMBRES_PREMIER_1 + to_string(nbrDeNombresPremier) + MESSAGE_NOMBRES_PREMIER_2, true);
    Afficher(listeDesNombresPremier, true);
}


/// EspaceNecessairePourAffichage permet d'obtenir le nombre d'espace nécessaire pour l'affichage de chiffre
/// \param chiffreAffiche
/// \param maxDigit
/// \return
// TODO: rennomer fonction
string EspaceNecessairePourAffichage(int chiffreAffiche, int maxDigit)
{
    if (chiffreAffiche <= 0)
    {
        return " ";
    }

    string nbrEspace = "";

    for (int i = maxDigit - log10(chiffreAffiche); i > 0; --i)
    {
        nbrEspace += " ";
    }

    return nbrEspace;
}