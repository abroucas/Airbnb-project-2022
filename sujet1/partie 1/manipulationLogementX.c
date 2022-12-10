/**
 * @file manipulationLogementX.c
 * @author Astrid Broucas (astrid.broucas@icloud.com) et Jade Cano (canojade2@gmail.com)
 * @brief contient les fonctions pour définir le logement étudié et pour déterminer son prix
 * @version 0.1
 * @date 2022-12-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "fonction.h"

void definitionLogement(Logement *x){
    
    
    printf("Quel est le numéro du logement x ? \n");
    scanf("%f", &x->num_logement);
    printf("Combien de personnes peuvent être acceuillies dans le logement x ? \n");
    scanf("%f", &x->accomodates);
    printf("Combien y a-t'il de chambres dans le logement x ? \n");
    scanf("%f", &x->bedrooms);
    printf("Combien y a-t'il de salles de bains dans le logement x ? \n ");
    scanf("%f", &x->bathrooms);
    printf("Combien y a-t'il de lits dans le logement x ? \n");
    scanf("%f", &x->beds);
    printf("Quel est le nombre de nuits minimum que l'on peut passer dans le logement x ? \n");
    scanf("%f", &x->minimum_nights);
    printf("Quel est le nombre de nuits maximum que l'on peut passer dans le logement ? \n");
    scanf("%f", &x->maximum_nights);
    printf("Quel est le nombre de commentaires disponibles sur le logement x ? \n");
    scanf("%f", &x->number_of_reviews);

}

float prixLogement(Logement *tab, Logement *x){

    /* on définit un entier k qui va nous servir à sélectionner les k premiers logements les plus proches du logement étudié */
    float k;
    
    float sum = 0;

    printf("Rentrez un entier k: \n");
    scanf("%f", &k);

    for (size_t i = 0; i < k; i++)
    {
       sum = sum + tab[i].price;
    }

    x->price = sum / k;
    return(x->price);
    
}

