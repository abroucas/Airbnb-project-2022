/**
 * @file fonctionsOrdonnanceur.c
 * @author Astrid Broucas (astrid.broucas@icloud.com) et Jade Cano (canojade2@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-12-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include"fonctions.h"

void ajout_activite(Ordonnanceur *ordonnanceur)
{

    char reponse[20] ;    
    do
    {
        Processus nvProcessus;
        printf("Quel est le nom du processus ? \n");
        scanf("%s", nvProcessus.nom);
        printf("Quelle est la durée d'exécution du processus (en secondes)? \n");
        scanf("%f", &nvProcessus.duree_execution);
        printf("Quelle est la priorité du processus? (entier entre 0 et 5) \n");
        scanf("%d", &nvProcessus.priorite);
        enfiler(ordonnanceur, nvProcessus);
        printf("Voulez-vous rentrer un nouveau processus? (yes or no) \n");
        scanf("%s", reponse);

    } while (*reponse == 'y');

}

 char* step(Ordonnanceur *ordonnanceur)
{
    /* cas où la file n'est pas vide */
    if (ordonnanceur->premier != NULL)
    {
        Processus processusexec;
        processusexec = defiler(ordonnanceur);

        int min = processusexec.priorite;
   
        Maillon *actuel = ordonnanceur->premier;
        while (actuel != NULL)
        {
            if (min > actuel->p.priorite )
            {
                min = actuel->p.priorite;
                break;
            }
    
        }

        if (min == processusexec.priorite)
        {
            printf("Nom du processus exécuté : %s \nDurée d'éxécution : %f \n", processusexec.nom, processusexec.duree_execution);
            sleep(processusexec.duree_execution);
        }
        
        else
        {
            enfiler(ordonnanceur, processusexec);
        }
        
    }
    /* cas où la file est vide */
    else 
    {
        return("La file est vide. \n");
    }
    
}


void run(Ordonnanceur *ordonnanceur)
{
   
        while (ordonnanceur->premier != NULL)
        {
            step(ordonnanceur);
        }   
        printf("Fait !\n");
        
    
}
