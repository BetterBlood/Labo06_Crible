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
 *      - char*
 */

/// IninitialiserTableau
/// \param taille
/// \return
void InitialiserTableau(char tableau[],
                        unsigned taille)
{
    // Initialiser tous les indices
	for (int i = 0; i < taille; ++i)
	{
        // Lors de l'initialisation, on part du principe que tous les indices réprésentent un nombre premier
		tableau[i] = NBR_PREMIER;
	}
}


/*
 * Fonction EliminerMultiples
 *  params:
 *      - tableau
 *      - taille
 *      - multiple
 */
/// EliminerMultiples
/// \param tableau
/// \param taille
/// \param multiple
void EliminerMultiples(char tableau[],
                       unsigned taille,
                       unsigned indiceNbrPremier)
{
    // Les indices commencent à 0; ajouter 1 pour obtenir le nombre premier
    unsigned nombrePremier = indiceNbrPremier + 1;

    // Parcourir tous les nombres composés
    // Nous avons essayé de rendre la clause plus lisible à cause du nom des variables
	for (unsigned indiceNbrCompose = indiceNbrPremier + nombrePremier ;
         indiceNbrCompose < taille ;
         indiceNbrCompose += nombrePremier)
	{
        tableau[indiceNbrCompose] = NBR_NON_PREMIER;
	}
}

/*
 * Fonction EffectuerCribleSur
 *  params:
 *      - tableau
 *      - taille
 */

/// EffectuerCribleSur (Crible Eratosthène)
/// \param tableau
/// \param taille
void EffectuerCribleSur(char tableau[],
                        unsigned taille)
{
    // Vérifier les indices de 0 à 6 (valeurs 1 à 7), et éliminer leurs multiples
	for (int indice = 0; indice <= NBR_INDICE_ERATOSTHENE_MAX; ++indice)
	{
        // Vérifier si la valeur dans l'indice n'a pas encore été éliminée
        if(tableau[indice] != NBR_NON_PREMIER)
        {
            EliminerMultiples(tableau,
                              taille,
                              indice);
        }
	}
}