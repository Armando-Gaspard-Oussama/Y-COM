#include "../../lib/affichage.h"
#include "../../lib/commun.h"
#include "../../lib/niveaux.h"
#include "../../lib/deplacement.h"

int main(){


    SDL_Renderer * rend;

    SDL_Window * window;
    SDL_Texture * niveau;
    SDL_Texture * perso;
    niveau_t niv;
    SDL_Init(SDL_INIT_VIDEO);

    int mat[9][16]={0};
    window=creation_fenetre_renderer("test",&rend);
    niveau=charger_niveau(window,"../../media/sprites/niv_01.png",rend);
    perso = charger_personnage(window,"./perso.png",rend,3,4);
    chargement_contenu_niveau(niv,"../../media/niveaux/01.niv");

    simplication_mat(niv,mat);
    chercher_chemin(mat,4,4,3,4);
    mat[3][4]=3;
    afficherMat(mat);
    
    SDL_Delay(10000);
    SDL_DestroyTexture(niveau);
    SDL_DestroyTexture(perso);
    SDL_DestroyRenderer(rend);
    SDL_DestroyWindow(window);
  
    SDL_Quit();
    return 0;
}