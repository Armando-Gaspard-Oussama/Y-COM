#ifndef fff


#define fff
    #include "./commun.h"
    #include "./affichage.h"
    #include "./niveaux.h"

    int est_perso(niveau_t mat, int x, int y);

    int getNumEnnemie(t_texperso tabPerso[],int x, int y, int nbPerso);

    int traverseBarriere(niveau_t mat, int x_debut, int y_debut, int x_fin, int y_fin);

    int est_mort(t_texperso tabPerso[], int numeroPerso);

    int finCombat(t_texperso tabPerso[], int nbPerso);

    void phaseAttaque(t_texperso tabPerso[], int numeroPerso, niveau_t mat, int nbPerso);

#endif