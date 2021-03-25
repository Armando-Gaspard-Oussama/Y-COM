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
        PERSO = -1, /**< case occupée par un personnage (joueur ou adversaire)**/
        VIDE, /**< 0: vide (espace où les personnages peuvent aller)**/
        PORTE, /**< 1: porte (changement de niveau)**/
        BARR_H, /**< 2: couverture (pour se protéger de tirs ennemis) horizontale**/
        BARR_V, /**< 3: couverture verticale **/
        MUR /**< 4: mur, limite du niveau**/
    } carreau_t;

    typedef carreau_t niveau_t[9][16];

    void chargement_contenu_niveau(niveau_t mat,char * nom_fichier);

    void lecture_niveau(niveau_t mat);

#endif
