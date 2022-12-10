/**
 * @file partie1.c
 * @author Astrid Broucas (astrid.broucas@icloud.com) et Jade Cano (canojade2@gmail.com)
 * @brief contient les fonctions pour charger entièrement un fichier dans un tableau et pour déterminer le prix du logement étudié en utilisant l'alogorithme des KNN
 * @version 0.1
 * @date 2022-12-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "fonction.h"


Logement* chargementFichierEntier (int* ligne) 
{

    FILE* fichier = ouvertureFichier("airbnb_donnees_propres.csv");

    
    *ligne = 0;
    char chaine[MAX_BUFFER_SIZE];

   
    while (fgets(chaine, MAX_BUFFER_SIZE, fichier) != NULL)  
    {
        (*ligne)++;
    }
    
    /* ATTENTION : à la fin de la boucle while le curseur se trouve à la fin du fichier 
    donc il faudra penser à le remettre au début*/


    printf("%d\n", *ligne); 

    Logement *tab=malloc((*ligne-1)*sizeof(Logement));


    if (tab==NULL)
    {
        fprintf(stderr, "Création de tableau impossible !");
        exit(EXIT_FAILURE);
    }


    lectureFichier(fichier, tab, ligne);

    fclose(fichier);


    return (tab);
}

float trouverPrixLogement(int *ligne, Logement *tab, Logement *x)
{
    
    for (size_t i = 0; i < ((*ligne)-1); i++) 
    
    {
        /* calcul de la distance univariée entre le logement étudié et un autre logement selon le critère accomodates */
        tab[i].distance[0]=getdistanceunivar(x->accomodates, tab[i].accomodates);
        
        /* calcul de la distance univariée entre le logement étudié et un autre logement selon le critère bedrooms */
        tab[i].distance[1]=getdistanceunivar(x->bedrooms, tab[i].bedrooms);

        /* calcul de la distance univariée entre le logement étudié et un autre logement selon le critère beds */
        tab[i].distance[2]=getdistanceunivar(x->beds, tab[i].beds);

        /* calcul de la distance multivariée entre le logement étudié et un autre logement selon les 3 critères précédents */
        tab[i].distance[3]=getdistancemulti(tab[i].distance);
    }
    
    

    randomiserTableau(tab, ligne); 

    triTableau(tab, ligne);
    
    float prix;
    prix = prixLogement(tab, x); 

    return(prix); 
}
