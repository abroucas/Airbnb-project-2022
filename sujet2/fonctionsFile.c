/**
 * @file fonctionsFile.c
 * @author Astrid Broucas (astrid.broucas@icloud.com) et Jade Cano (canojade2@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-12-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include"fonctions.h"

void enfiler(Ordonnanceur *ordonnanceur, Processus nvProcessus)
{
    Maillon *nouveau = malloc(sizeof(*nouveau));

    if (ordonnanceur == NULL || nouveau == NULL) 
    {
        exit(EXIT_FAILURE);
    }


    nouveau->p = nvProcessus;
    nouveau->suivant = NULL;

    /* cas où la file n'est pas vide */
    if (ordonnanceur->premier != NULL)
    {
        /* on se positionne à la fin de la file */
        Maillon *maillonActuel = ordonnanceur->premier;
        while (maillonActuel->suivant != NULL)
        {
            maillonActuel = maillonActuel->suivant;
        }

        maillonActuel->suivant = nouveau;
        
    }
    
    /* cas où la file est vide */
    else  
    {
        ordonnanceur->premier = nouveau;
    }
    
}

/* FIRST IN FIRST OUT */

Processus defiler(Ordonnanceur *ordonnanceur)
{
    if (ordonnanceur == NULL)
    {
        exit(EXIT_FAILURE);
    }
    
    Processus processusDefile;

   
    if (ordonnanceur->premier != NULL)
    {
        
        Maillon *maillonDefile = ordonnanceur->premier;
        
        processusDefile = maillonDefile->p;
      
        ordonnanceur->premier = maillonDefile->suivant;
        free(maillonDefile);
    }
    
    return (processusDefile);

}

void afficherFile(Ordonnanceur *ordonnanceur)
{
    if (ordonnanceur == NULL)
    {
        exit(EXIT_FAILURE);
    }
    Maillon *actuel = ordonnanceur->premier;
    while (actuel != NULL)
    {
        printf("Nom processus : %s \n Durée d'exécution : %f \n Priorité : %d \n", actuel->p.nom, actuel->p.duree_execution, actuel->p.priorite);
        actuel = actuel->suivant;
    }
    
    printf("NULL \n");

}