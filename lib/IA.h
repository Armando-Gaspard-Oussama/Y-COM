#ifndef ia

#define ia
    #include "./commun.h"
    #include "./deplacement.h"
    #include "./combat.h"

    void indiceMaxMatrice(int mat[5][5],int * x, int * y);

    int evaluationDeplacement(niveau_t mat, int x,int y);

    int plusBasVie(t_texperso tabperso[],int nbPerso);

    void IA(t_texperso tabPerso[], int numeroPerso, niveau_t mat,SDL_Window * pWindow, SDL_Renderer * rend, TTF_Font * font,int nbperso, SDL_Texture * textNiv);
#endif