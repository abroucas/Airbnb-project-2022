/**
 * @file main2.c
 * @author Jade Cado (canojade2@gmail.com) et Astrid Broucas (astrid.broucas@icloud.com)
 * @brief contient la fonction main pour le bonus du sujet 1
 * @version 0.1
 * @date 2022-12-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "fonction.h"


int main(int argc, char const *argv[])
{
    Logement *tabEntrainement = NULL;
    Logement *tabTest = NULL;
    
    int lignebis;

    chargementFichierDeuxParties(&lignebis, &tabEntrainement,&tabTest);

    int tailleTabEntrainement;
    int tailleTabTest;

    /* tabEntrainement correspond à 80% des données du fichier "airbnb_donnees_propres.csv" */
    tailleTabEntrainement = (unsigned int)(0.8*((lignebis)-1));

    /* tabTest correspond à 20% des données du fichier "airbnb_donnees_propres.csv" */
    tailleTabTest = (lignebis)-tailleTabEntrainement;

    float *tabPrixPredit = malloc(tailleTabTest*sizeof(float));

    if (tabPrixPredit==NULL)
    {
        fprintf(stderr, "Création de tableau impossible !");
        exit(EXIT_FAILURE);
    }

    /* on initialise un entier k afin de sélectionner les k premiers logements les plus proches du logement étudié*/
    int k;

    do
    {
        printf("Rentrez un entier k compris entre 1 et %u: \n", tailleTabEntrainement);
        scanf("%d", &k);
    } while (k<1 || k > tailleTabEntrainement);


    for (size_t i = 0; i < tailleTabTest; i++)
    {
        for (size_t j = 0; j < tailleTabEntrainement; j++)
        {
        /* calcul distance univariée par rapport au critère accomodates */
        tabEntrainement[j].distance[0]=getdistanceunivar((tabTest[i]).accomodates, tabEntrainement[j].accomodates);

        /* calcul distance univariée par rapport au critère bedrooms */
        tabEntrainement[j].distance[1]=getdistanceunivar((tabTest[i]).bedrooms, tabEntrainement[j].bedrooms);

        /* calcul distance univariée par rapport au critère beds */
        tabEntrainement[j].distance[2]=getdistanceunivar((tabTest[i]).beds, tabEntrainement[j].beds);

       /* calcul distance multivariée par rapport aux trois précédentes distances univariées */
        tabEntrainement[j].distance[3]=getdistancemulti(tabEntrainement[j].distance);
        }

        randomiserTableau(tabEntrainement, &tailleTabEntrainement);
        triTableau(tabEntrainement,&tailleTabEntrainement);
        tabPrixPredit[i]=prixLogement(tabEntrainement, &(tabTest[i]), k);
    
    }

    
    /* calcul MAE */

    double sum = 0; 
    float MAE; 

    for (size_t i = 0; i < tailleTabTest; i++)
    {
        sum= sum+ fabs(tabPrixPredit[i]-(tabTest[i]).price);
    }
    
    MAE = sum/tailleTabTest;

    printf("MAE : %f\n", MAE );


    free(tabPrixPredit);
    free(tabEntrainement);
    free(tabTest);

    return(0);
}