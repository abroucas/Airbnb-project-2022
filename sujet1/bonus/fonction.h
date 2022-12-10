/**
 * @file fonction.h
 * @author Jade Cado (canojade2@gmail.com) et Astrid Broucas (astrid.broucas@icloud.com)
 * @version 0.1
 * @date 2022-12-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#ifndef HEADER_VAR
#define HEADER_VAR

//librairies 
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

#define MAX_BUFFER_SIZE 256 
#define TAILLE_TABLEAU 4 

typedef struct Logement Logement;
struct Logement
{  
    /* numéro du logement */
    float num_logement; 

    /* nombre de personnes pouvant être acceuillies */
    float accomodates; 

    /* nombre de chambres */
    float bedrooms; 

    /* nombre de salle de bains */
    float bathrooms;

    /* nombre de lits */
    float beds; 

    /* prix du logement */
    float price; 

    /* nombre minimum de nuit */
    float minimum_nights; 

    /* nombre maximum de nuit */
    float maximum_nights; 

    /* nombre de commentaires*/
    float number_of_reviews; 

    /* tableau de distance entre deux logements selon 3 critères : accomodates, bedrooms, beds; puis distance de similarité*/
    float distance[TAILLE_TABLEAU]; 
};


/**
 * @brief calcul de la distance multivariée à partir des distances univariées en fonction de 3 différents critères
 * 
 * @param distance tableau des distances associé au logement étudié
 * @return float distance multivariée associée au logement étudié
 */
float getdistancemulti(float *distance);

/**
 * @brief ouvre un fichier dont le nom est en paramètre
 * 
 * @param nomFichier nom du fichier à ouvrir
 * @return FILE* fichier
 */
FILE* ouvertureFichier (char* nomFichier);

/**
 * @brief charge l'intégralité du fichier dans un tableau
 * 
 * @param ligne nombre de lignes du fichier
 * @return Logement* tableau de Logements
 */
Logement* chargementFichierEntier(int* ligne);

/**
 * @brief lit un fichier et rentre ses données dans un tableau de logements
 * 
 * @param fichier fichier dont les données sont à extraire
 * @param tab tableau dans lequel on va charger les données du fichier
 * @param ligne nombre de lignes du fichier 
 */
void lectureFichier(FILE* fichier, Logement *tab, int* ligne);

/**
 * @brief calcul distance univariée par rapport à un critère
 * 
 * @param a valeur d'un critère pour le logement étudié
 * @param b valeur du même critère pour un autre logement
 * @return float distance univariée pour un critère 
 */
float getdistanceunivar(float a,float b);

/**
 * @brief mélange les lignes du tableau de manière aléatoire
 * 
 * @param tab tableau à randomiser
 * @param ligne nombre de lignes du tableau
 */
void randomiserTableau(Logement *tab, int* ligne); 

/**
 * @brief tri le tableau de logements selon l'algorithme de tri par insertion
 * 
 * @param tab tableau à trier
 * @param ligne nombre de lignes du tableau
 */
void triTableau(Logement *tab, int* ligne);

/**
 * @brief détermine le prix du logement en faisant la moyenne des k logements les plus proches du logement étudié
 * 
 * @param tab tableau de logements 
 * @param x logement dont on veut calculer le prix
 * @param k choix de l'entier k qui va permettre de sélectionner les k logements les plus proches du logement étudié
 * @return float prix du logement étudié
 */
float prixLogement(Logement *tab, Logement *x, int k);


/**
 * @brief charge le fichier dans 2 tableaux : tabEntrainement (80% du fichier) et tabTest (20% du fichier)
 * 
 * @param lignebis nombre de lignes du fichier entier
 * @param tabEntrainement tableau de logements avec 80% des logements du fichier étudié
 * @param tabTest tableau de logements avec 20% des logements du fichier étudié
 */
void chargementFichierDeuxParties (int* lignebis, Logement **tabEntrainement, Logement **tabTest);


#endif