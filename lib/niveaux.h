#ifndef __NIVEAUX_H__
#define __NIVEAUX_H__

/**
 * \file niveaux.h
 * \brief Définitions des types et fonctions relatifs aux niveaux
 */

/**
 * \brief Constantes qui indiquent de quel type sont une case dans une matrice de niveau.
 */
typedef enum carreau_e {
    VIDE, /**< 0: vide (espace où les personnages peuvent aller)*/
    PORTE, /**< 1: porte (changement de niveau)*/
    COUV, /**< 2: couverture (pour se protéger de tirs ennemis)*/
    MUR = 4  /**< 4: mur*/
} carreau_t;

typedef carreau_t niveau_t[9][16];

void chargement_contenu_niveau(niveau_t mat,char * nom_fichier);

void lecture_niveau(niveau_t mat);

#endif
