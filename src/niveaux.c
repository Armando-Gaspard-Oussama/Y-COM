/**
 * \file niveaux.c
 * \brief Fonctions pour la gestion de niveaux à partir de leurs fichiers
 *
 * Les niveaux sont représentés dans leurs fichiers media/niveaux/XX.niv où XX est le numéro du niveau.
 * Chaque fichier est une suite de caractères de chiffres sans espaces, représentant la matrice de gauche à droite et de haut en bas.
 * Chaque caractère représente un bloc spécifique.
 * \sa niveaux.h
 */

#include "../lib/niveaux.h"
#include "../lib/commun.h"
#include <stdio.h>

/**
 * \fn void chargement_contenu_niveau(carreau_t mat[9][16],char * nom_fichier)
 * \brief Charge la matrice représentant les éléments du niveau à l'aide d un Fichier.
 * \author Armando Costa
 * \param mat Matrice dans laquelle seront chargés les éléments
 * \param nom_fichier string contenant le nom du fichier dans lequel sont sauvegardés les éléments du niveau
 */
void chargement_contenu_niveau(niveau_t mat,char * nom_fichier){

    FILE * niveau = fopen(nom_fichier,"r");
    int i,j;
    char k;

    for(i=0;i<9;i++){

        for(j=0;j<16;j++){

            fscanf(niveau,"%c",&k);
            mat[i][j]=k-'0';

        }

    }

    fclose(niveau);

}

void lecture_niveau(niveau_t mat){
    int i,j;

    for(i=0;i<9;i++){

        for(j=0;j<16;j++){

            printf(" %d ",mat[i][j]);

        }

        printf("\n");
    }
}
