#include "../lib/combat.h"
#include "../lib/niveaux.h"
#include <time.h>

void phaseAttaque(t_texperso tabPerso[], int numeroPerso, niveau_t mat, int nbPerso){
    srand(time(NULL));
    int flag =1;
    int x_point,y_point;
    int numEnnemie;
    int degats;

    SDL_Event event;

    while(flag==1){
        
        while(SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT){
                return ;

            }
            if(event.type == SDL_MOUSEBUTTONDOWN){
                x_point = event.button.x/64;
                y_point = event.button.y/64;

                if(est_ennemie(mat,x_point,y_point)){
                    flag =-1;

                }

            }
        }
        SDL_Delay(10);
    }
    numEnnemie=getNumEnnemie(tabPerso,x_point,y_point,nbPerso);
    if(rand()%5==0){ //Correspond a un coup critique
        degats = (int)(tabPerso[numeroPerso].stPerso.attaque*1.20);
    }else{
        degats = rand()%(int)(tabPerso[numeroPerso].stPerso.attaque -(tabPerso[numeroPerso].stPerso.attaque*0.7)) + (int)(tabPerso[numeroPerso].stPerso.attaque*0.7); //Degats peuvent etre fait entre [70%;100%] de l'attaque initial du personnage
    }
    
    if(traverseBarriere(mat,tabPerso[numeroPerso].stPerso.pos_X,tabPerso[numeroPerso].stPerso.pos_X,x_point,y_point)){
        degats = (int)(degats*0.4);
    }

    tabPerso[numEnnemie].stPerso.HP-=degats;

    printf("L ennemie %d prend %d degats",numEnnemie,degats);

}
