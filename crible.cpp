/* 
 ----------------------------------------------------------------------------------- 
 Nom du fichier :  $fileRelativePath()$ $end$
 Auteur(s)      : Pedro Alves da Silva
 Date creation  : $date("dd-MM-YYYY")$
 
 Description    : <à compléter> 
 
 Remarque(s)    : <à compléter> 
 
 Compilateur    : Mingw-w64 g++ 11.1.0  
 ----------------------------------------------------------------------------------- 
*/
#include "crible.h"

/*
 * initialiserTableau
 *  params:
 *      - taille
 *  retourne:
 *      - int[]
 */

/// IninitialiserTableau
/// \param taille
/// \return
char* IninitialiserTableau(const unsigned taille)
{
	char tab[taille];

	for (int i = 0; i < taille; ++i)
	{
		tab[i] = NBR_NON_PREMIER;
	}

	return (char*)tab;
}


/*
 * Fonction EliminerMultiples
 *  params:
 *      - tableau
 *      - taille
 *      - multiple
 */
/// EliminerMultiples
/// \param tab
/// \param taille
/// \param multiple
void EliminerMultiples(char tab[], const unsigned taille, const unsigned multiple)
{
	for (int i = multiple*multiple; i < taille; i += multiple)
	{
		tab[i] = NBR_PREMIER;
	}
}

/*
 * Fonction EffectuerCribleSur
 *  params:
 *      - tableau
 *      - taille
 */

/// EffectuerCribleSur
/// \param tab
/// \param taille
void EffectuerCribleSur(char tab[], const unsigned taille)
{
	for (int iterateur = 0; iterateur < TAILLE_NBRS_PREMIERS; ++iterateur)
	{
		EliminerMultiples(tab, taille, NBRS_PREMIERS[iterateur++]);
	}
}