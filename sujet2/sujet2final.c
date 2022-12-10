/**
 * @file sujet2final.c
 * @author Astrid Broucas (astrid.broucas@icloud.com) et Jade Cano (canojade2@gmail.com)
 * @version 0.1
 * @date 2022-12-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "fonctions.h"


int main(int argc, char const *argv[])
{   /*initialisation de l'ordonnanceur */
    Ordonnanceur *ordonnanceur;
    ordonnanceur->premier = NULL;

    /* rajouter des processus à l'ordonnanceur */
    char ajoutMaillon[20];
    printf("Voulez-vous ajouter un processus à la file de l'ordonnanceur? (yes or no) \n");
    scanf("%s", ajoutMaillon);
    if (*ajoutMaillon == 'y')
    {
        ajout_activite(ordonnanceur);
    }

    /* exécuter l'ordonnanceur */
    char execOrdonnanceur[20];
    printf("Voulez-vous exécuter l'ensemble des processus de l'ordonnanceur? (yes or no )\n");
    scanf("%s", execOrdonnanceur);
    if (*execOrdonnanceur == 'y')
    {
        run(ordonnanceur);
    }
    
    return(0);
} 