#include "../../lib/affichage.h"
#include "../../lib/commun.h"
#include "../../lib/niveaux.h"
#include "../../lib/deplacement.h"

int main(){
    SDL_Renderer * rend;
    SDL_Window * window;
    SDL_Texture * niveau;
    niveau_t niv;
    int mat[9][16]={0};
    int soluc[9][16]={0};
    window=creation_fenetre_renderer("test",&rend);
    niveau=charger_niveau(window,"../../media/sprites/niv_01.png",rend);
    chargement_contenu_niveau(niv,"../../media/niveaux/01.niv");

    simplication_mat(niv,mat);
    solvemaze(4,4,5,1,mat,soluc);
    afficherMat(soluc);
    
    SDL_Delay(10000);
    SDL_DestroyWindow(window);
    return 0;
}