/**
 * @file fonctions.h
 * @author Astrid Broucas (astrid.broucas@icloud.com) et Jade Cano (canojade2@gmail.com)
 * @version 0.1
 * @date 2022-12-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef HEADER_VAR
#define HEADER_VAR

// librairies
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

/**
 * @brief définition d'une nouvelle structure Processus
 * 
 */
typedef struct Processus Processus;
struct Processus{
    char nom[256]; // nom du processus
    float duree_execution; // durée d'exécution du processus en secondes
    int priorite; // priorité du processus (entier compris entre 0 et 5)
};

/**
 * @brief définition d'une nouvelle structure maillon, qui correspond à un maillon de la file de l'ordonnanceur, ie un processus 
 * 
 */
typedef struct Maillon Maillon;
struct Maillon
{
    Processus p;
    Maillon *suivant;

};

/**
 * @brief définition d'une nouvelle structure ordonnanceur, modélisé par une file
 * 
 */
typedef struct Ordonnanceur Ordonnanceur;
struct Ordonnanceur
{
    Maillon *premier;

};

/**
 * @brief ajoute un nouveau processus à la file de l'ordonnanceur. On rajoutera notre nouvel élément après le dernier.
 * 
 * @param ordonnanceur file à laquelle on ajoute un nouveau processus
 * @param nvProcessus nouvel élément de la file
 */
void enfiler(Ordonnanceur *ordonnanceur, Processus nvProcessus);

/**
 * @brief enlève le premier élément de la file de l'ordonnanceur et renvoie sa valeur
 * 
 * @param ordonnanceur ordonnanceur à qui l'on va enlever son premier élément
 * @return Processus premier élément de l'ordonnanceur, qui a été éliminé
 */
Processus defiler(Ordonnanceur *ordonnanceur);

/**
 * @brief parcourt la file de l'ordonnanceur et renvoie chacune des valeurs de ses maillons
 * 
 * @param ordonnanceur file dont on va afficher la valeur des maillons
 */
void afficherFile(Ordonnanceur *ordonnanceur);

/**
 * @brief interroge l'utilisateur pour savoir quel processus il veut ajouter à la file de l'ordonnanceur
 * 
 * @param ordonnanceur file à laquelle on va ajouter un élément
 */
void ajout_activite(Ordonnanceur *ordonnanceur);

/**
 * @brief effectue un “tour” d’ordonnancement 
 * 
 * @param ordonnanceur file sur laquelle on travaille
 * @return char* renvoie le nom et la durée du processus exécuté ou un message d'indication si la pile est vide
 */
char* step(Ordonnanceur *ordonnanceur);

/**
 * @brief itère step jusqu’à obtenir une file de processus vide
 * 
 * @param ordonnanceur file sur laquelle on travaille
 */
void run(Ordonnanceur *ordonnanceur);



#endif