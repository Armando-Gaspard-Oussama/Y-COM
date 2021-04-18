#include "../../lib/affichage.h"
#include "../../lib/commun.h"
#include "../../lib/Struct_perso.h"
#include "../../lib/niveaux.h"
#include "../../lib/deplacement.h"
#include "../../lib/combat.h"
#include "../../lib/IA.h"

int main(int argc, char **argv){

    t_texperso tabPerso[20];
    SDL_Renderer * rend;
    TTF_Init();
    TTF_Font * font = TTF_OpenFont("../../media/font/ethno.ttf",200);
    int nbPerso=0;
    SDL_Window * window;
    SDL_Texture * niveau;
    charger_stat_perso(tabPerso,2,0,3,2);
    charger_stat_perso(tabPerso,3,1,9,5);
    charger_stat_perso(tabPerso,0,2,1,3);
    niveau_t niv;
    int mat[9][16]={0};
    SDL_Init(SDL_INIT_VIDEO);

    window=creation_fenetre_renderer("Y-COM",&rend);

    niveau=charger_niveau(window,"../../media/sprites/niv_06.png",rend);
    chargement_contenu_niveau(niv,"../../media/niveaux/06.niv");
    
    charger_personnage(window,"../../media/sprites/perso2.png",rend,tabPerso,&nbPerso,niv,font);
    charger_personnage(window,"../../media/sprites/ennemy.png",rend,tabPerso,&nbPerso,niv,font);
    charger_personnage(window,"../../media/sprites/perso.png",rend,tabPerso,&nbPerso,niv,font);

    printf("%d",nbPerso);


    phase_deplacement(tabPerso,0,window,rend,niv,niveau,nbPerso,font);
    phase_deplacement(tabPerso,2,window,rend,niv,niveau,nbPerso,font);
    phase_deplacement(tabPerso,2,window,rend,niv,niveau,nbPerso,font);
    
    phaseAttaque(tabPerso,0,niv,nbPerso);

    Update(tabPerso,window,rend,niveau,nbPerso,font);
    printf("IA : \n\n\n");

    IA(tabPerso,1,niv,window,rend,font,nbPerso,niveau);

    SDL_Delay(1000);
    toutSupprimer(tabPerso,&nbPerso,window,rend,niveau);

    printf("Tout se passe bien !");
    
    TTF_Init();
    SDL_Quit();
    return 0;
}