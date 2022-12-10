/**
 * @file manipulationDeFichier.c
 * @author Jade Cado (canojade2@gmail.com) et Astrid Broucas (astrid.broucas@icloud.com)
 * @brief contient les fonctions pour ouvrir et pour lire un fichier
 * @version 0.1
 * @date 2022-12-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "fonction.h"


FILE* ouvertureFichier (char* nomFichier){
    FILE* fichier = fopen(nomFichier,"r");

    /* définition d'une chaine de taille MAX_BUFFER_SIZE vide */
    char chaine[MAX_BUFFER_SIZE] = ""; 

    if (fichier==NULL)
    {
        fprintf(stderr, "Ouverture du fichier impossible !");
        exit(EXIT_FAILURE);
    }
    return (fichier);
}

void lectureFichier(FILE* fichier, Logement *tab, int* ligne){


    for (size_t i = 0; i < (*ligne)-1; i++)
    {
        fscanf(fichier, "%f,%f,%f,%f,%f,%f,%f,%f,%f", 
        &(tab[i].num_logement), 
        &(tab[i].accomodates), 
        &(tab[i].bedrooms), 
        &(tab[i].bathrooms), 
        &(tab[i].beds), 
        &(tab[i].price), 
        &(tab[i].minimum_nights), 
        &(tab[i].maximum_nights), 
        &(tab[i].number_of_reviews));
    }

}


