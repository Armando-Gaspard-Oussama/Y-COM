#include "../../lib/affichage.h"
#include "../../lib/commun.h"
#include "../../lib/niveaux.h"
#include "../../lib/deplacement.h"
#include "../../lib/combat.h"

int main(){

    t_texperso tabPerso[20];
    SDL_Renderer * rend;
    int nbPerso=0;
    SDL_Window * window;
    SDL_Texture * niveau;
    t_pers pers ={"Test",5,9,0,100,0,0,3,2,0};
    t_pers pers1={"Test",6,4,0,100,0,0,6,5,0};
    tabPerso[0].stPerso = pers;
    tabPerso[1].stPerso = pers1;
    niveau_t niv;
    SDL_Init(SDL_INIT_VIDEO);

    int mat[9][16]={0};
    window=creation_fenetre_renderer("test",&rend);
    niveau=charger_niveau(window,"../../media/sprites/niv_06.png",rend);
    chargement_contenu_niveau(niv,"../../media/niveaux/06.niv");
    charger_personnage(window,"./perso.png",rend,tabPerso,&nbPerso,niv);
    charger_personnage(window,"./perso.png",rend,tabPerso,&nbPerso,niv);

    phase_deplacement(tabPerso,0,window,rend,niv,niveau,nbPerso);
    phase_deplacement(tabPerso,1,window,rend,niv,niveau,nbPerso);

    printf("Vie perso1: %d\n",tabPerso[1].stPerso.HP);
    SDL_Delay(10);
    phaseAttaque(tabPerso,0,niv,nbPerso);
    printf("Vie perso1: %d \n",tabPerso[1].stPerso.HP);


    SDL_Delay(1000);
    SDL_DestroyTexture(niveau);
    SDL_DestroyTexture(tabPerso[0].Tex);
    SDL_DestroyRenderer(rend);
    SDL_DestroyWindow(window);
  
    SDL_Quit();
    return 0;
}