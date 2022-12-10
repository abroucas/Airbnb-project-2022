/**
 * @file manipulationDeTableau.c
 * @author Astrid Broucas (astrid.broucas@icloud.com) et Jade Cano (canojade2@gmail.com)
 * @brief contient les fonctions pour randomiser et trier un tableau de logements
 * @version 0.1
 * @date 2022-12-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "fonction.h"

void randomiserTableau(Logement *tab, int *ligne){

    /* choix de 2 indices au hasard */

    int indice_1;
    int indice_2;
    Logement tmp; 

    /* initialisation nécessaire pour le bon fonctionnement de rand */
    srand(time(NULL)); 

   for (size_t i = 0; i < (*ligne)-1; i++)
    { 
        indice_1=(rand() % ((*ligne)-1));
        indice_2=(rand() % ((*ligne)-1));
        
        
        tmp = tab[indice_1];
        tab[indice_1] = tab[indice_2];
        tab[indice_2] = tmp;
    
    }

}


void triTableau(Logement *tab, int *ligne){


    int j;
    Logement vartmp;

    for (size_t i = 1; i < ((*ligne) -1); i++)
    {
        j=i;

        while (j>0 && tab[j-1].distance[3] > tab[j].distance[3])
        {
          vartmp = tab[j];
          tab[j] = tab[j-1];
          tab[j-1] = vartmp;

          j--;
        }
        
    }

}


