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
	} while(erreur && cout << msgErreur);

	return nombreLu;
}


/// Affiche toutes les valeurs dans le tableau fourni en paramètres
/// \param tableau Tableau à lire
/// \param taille Taille du tableau
void AfficherTableau(char tableau[],
                     int taille)
{
	// Parcourir toutes les cases du tableau
	for(int i = 0; i < taille; ++i)
	{
		// Afficher la valeur à l'index i
		Afficher(tableau[i], false);

		// Déterminer s'il nous faudra faire un saut de ligne. Sinon, rajouter un espace
		if (i % NOMBRES_PAR_LIGNE == 0)
		{
			NouvelleLigne();
		}
		else
		{
			Afficher(CARACTERE_ESPACE, false);
		}
	}
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
void Afficher(const char caractere,
              bool retourLigne)
{
	Afficher(string(1, caractere), retourLigne);
}