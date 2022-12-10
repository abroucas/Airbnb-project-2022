/**
 * @file manipulationDeFichier.c
 * @author Astrid Broucas (astrid.broucas@icloud.com) et Jade Cano (canojade2@gmail.com)
 * @brief contient les fonctions pourouvrir un fichier et le charger dans un tableau
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
    char chaine[MAX_BUFFER_SIZE];

    /* re-déplacer le curseur en début de fichier */
    rewind(fichier); 


    fgets(chaine, MAX_BUFFER_SIZE, fichier);


    for (size_t i = 0; i < (*ligne-1); i++)
    {
        fscanf(fichier, "%f,%f,%f,%f,%f,%f,%f,%f,%f", 
        &tab[i].num_logement, 
        &tab[i].accomodates, 
        &tab[i].bedrooms, 
        &tab[i].bathrooms, 
        &tab[i].beds, 
        &tab[i].price, 
        &tab[i].minimum_nights, 
        &tab[i].maximum_nights, 
        &tab[i].number_of_reviews);
    }

}


