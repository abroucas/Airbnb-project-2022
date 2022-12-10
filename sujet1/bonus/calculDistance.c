/**
 * @file calculDistance.c
 * @author Jade Cado (canojade2@gmail.com) et Astrid Broucas (astrid.broucas@icloud.com)
 * @brief calcul distance univariée et calcul distance multivariée
 * @version 0.1
 * @date 2022-12-09
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
