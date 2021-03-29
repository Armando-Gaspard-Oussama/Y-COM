#ifndef qwe


#define qwe

    #include "commun.h"
    #include "niveaux.h"
    #include "Struct_perso.h"

    int disponible(niveau_t mat, int posX, int posY);

    int valides(int coord_x,int coord_y);

    int est_vide(int coord_x, int coord_y, int mat[9][16]);

    void simplication_mat(niveau_t mat, int simp[9][16]);

    void afficherMat(int mat[9][16]);

    int chercher_chemin_rec(int simp[9][16],int chemin[9][16],int x,int y, int x_fin,int y_fin, int reccu, int reccu_max);

    void copie_chemin(int simp[9][16],int chemin[9][16]);

    int chercher_chemin(int simp[9][16],int x_debut, int y_debut, int x_fin, int y_fin);

    void phase_deplacement(t_pers * perso, SDL_Window * pWindow, SDL_Renderer * renderer, niveau_t mat,SDL_Texture * Texperso, SDL_Texture * Texniv);
#endif