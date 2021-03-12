/**
 * \file niveaux.c
 * \brief Fonctions pour la gestion de niveaux à partir de leurs fichiers
 *
 * Les niveaux sont représentés dans leurs fichiers media/niveaux/XX.niv où XX est le numéro du niveau.
 * Chaque fichier est une suite de caractères de chiffres sans espaces, représentant la matrice de gauche à droite et de haut en bas.
 * Chaque caractère représente un bloc spécifique
 * \sa niveaux.h
 */

#include "../lib/niveaux.h"
#include "../lib/commun.h"
#include <stdio.h>

/**
 * \fn void chargement_contenu_niveau(carreau_t mat[9][16],char * nom_fichier)
 * \brief Charge la matrice representant les elements du niveau a l aide d un Fichier
 * \author Armando Costa
 * \param mat Matrice dans laquel sera charger les elements
 * \param nom_fichier string contenant le nom du fichiers dans lequel sont sauvegarder les elements du niveau
 */
void chargement_contenu_niveau(carreau_t mat[9][16],char * nom_fichier){

    FILE * niveau = fopen(nom_fichier,"r");
    int i,j;
    int k;

    for(i=0;i<9;i++){

        for(j=0;j<16;j++){

            fscanf(niveau,"%d",&k);
            mat[i][j]=k;

        }

    }

    fclose(niveau);

}
