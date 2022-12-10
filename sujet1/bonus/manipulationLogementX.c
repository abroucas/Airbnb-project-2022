/**
 * @file manipulationLogementX.c
 * @author Jade Cado (canojade2@gmail.com) et Astrid Broucas (astrid.broucas@icloud.com)
 * @brief calcul du prix d'un logement
 * @version 0.1
 * @date 2022-12-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "fonction.h"


float prixLogement(Logement *tab, Logement *x,int k){

    float sum = 0;

    for (size_t i = 0; i < k; i++)
    {
       sum = sum + tab[i].price;
    }

    return(sum/k);
}

