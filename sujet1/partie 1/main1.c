/**
 * @file main1.c
 * @author Astrid Broucas (astrid.broucas@icloud.com) et Jade Cano (canojade2@gmail.com)
 * @version 0.1
 * @date 2022-12-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "fonction.h"


int main(int argc, char const *argv[])
{
    /* on crée notre logement x que l'on va étudié*/
    Logement x;
    definitionLogement(&x); 
    
    /* on crée un compteur de ligne qui va nous permettre de parcourir le fichier */
    int ligne;

    /* on crée un tableau qui va contenir les données du fichier*/

    Logement* tab= chargementFichierEntier(&ligne);

   /* détermination du prix du logement étudié */

    float prixLogement; 
    prixLogement = trouverPrixLogement(&ligne, tab, &x);
    printf ("Le prix du logement x est %f \n", prixLogement);

    free(tab);
    return(0);
}