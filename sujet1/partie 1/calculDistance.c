/**
 * @file calculDistance.c
 * @author Astrid Broucas (astrid.broucas@icloud.com) et Jade Cano (canojade2@gmail.com)
 * @brief contient les fonctions pour calculer la distance univariée et multivariée entre 2 logements
 * @version 0.1
 * @date 2022-12-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "fonction.h"

float getdistanceunivar(float a,float b){

    return (sqrt(pow((a - b),2)));
}

float getdistancemulti(float *distance){

    float sum = 0;
   
    for (size_t i = 0; i < (TAILLE_TABLEAU-1); i++)
    {
       sum = sum + pow(distance[i],2); 
    }

    return(sqrt(sum));

}
