/**
 * @file partie2.c
 * @author Jade Cado (canojade2@gmail.com) et Astrid Broucas (astrid.broucas@icloud.com)
 * @brief charge le fichier dans 2 tableaux distincts
 * @version 0.1
 * @date 2022-12-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "fonction.h"


void chargementFichierDeuxParties (int* lignebis, Logement **tabEntrainement, Logement **tabTest) 
{
    /*ouverture du fichier de données airbnb_donnees_propres.csv*/
    FILE* fichier = ouvertureFichier("airbnb_donnees_propres.csv");
    int tailleTabEntrainement;
    int tailleTabTest;

    /*lecture de ce fichier pour déterminer le nombre de lignes*/
    *lignebis = 0;
    char chaine[MAX_BUFFER_SIZE];

    while (fgets(chaine, MAX_BUFFER_SIZE, fichier) != NULL)  
    {
        (*lignebis)++;
    }
    
    /* ATTENTION : à la fin de la boucle while le curseur se trouve à la fin du fichier 
    donc il faudra penser à le remettre au début*/

    printf("Nombre de lignes: %d\n", *lignebis); 

    tailleTabEntrainement = (unsigned int)(0.8*((*lignebis)-1));
    tailleTabTest = (*lignebis)-tailleTabEntrainement;

    *tabEntrainement=malloc((tailleTabEntrainement*sizeof(Logement)));


    if (tabEntrainement==NULL)
    {
        fprintf(stderr, "Création de tableau impossible !");
        exit(EXIT_FAILURE);
    }

    /* re-déplacer le curseur en début de fichier */
    rewind(fichier); 
    fgets(chaine, MAX_BUFFER_SIZE, fichier);
    lectureFichier(fichier, *tabEntrainement, &tailleTabEntrainement);

    *tabTest=malloc((tailleTabTest*sizeof(Logement)));


    if (tabTest==NULL)
    {
        fprintf(stderr, "Création de tableau impossible !");
        exit(EXIT_FAILURE);
    }

    lectureFichier(fichier, *tabTest, &tailleTabTest);


    fclose(fichier);


}


