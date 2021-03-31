#include "../lib/combat.h"
#include "../lib/niveaux.h"
#include <time.h>

int est_perso(niveau_t mat, int x, int y){
    return(mat[y][x]==PERSO);
}

int getNumEnnemie(t_texperso tabPerso[],int x, int y, int nbPerso){
    int i;
    for(i=0;i<nbPerso;i++){
        if(tabPerso[i].stPerso.pos_X==x && tabPerso[i].stPerso.pos_Y==y){
            return i;
        }
    }
    return -1;
}

int traverseBarriere(niveau_t mat, int x_debut, int y_debut, int x_fin, int y_fin){
    int signeX;
    int signeY;
    
    signeX=(x_fin-x_debut)/abs(x_fin-x_debut);
    signeY=(y_fin-y_debut)/abs(y_fin-y_debut);


    return -1; //Si l attaque n est pas bloquer par une barriere
}

void phaseAttaque(t_texperso tabPerso[], int numeroPerso, niveau_t mat, int nbPerso){
    srand(time(NULL));
    int flag =1;
    int x_point,y_point;
    int numEnnemie;
    int degats;

    SDL_Event event;
    printf("Au personnage %d d'attaquer\n",numeroPerso);
    while(flag==1){
        
        while(SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT){
                return ;

            }
            if(event.type == SDL_MOUSEBUTTONDOWN){
                x_point = event.button.x/64;
                y_point = event.button.y/64;

                if(est_perso(mat,x_point,y_point)){
                    flag =-1;
                }

            }
        }
        SDL_Delay(10);
    }
    numEnnemie=getNumEnnemie(tabPerso,x_point,y_point,nbPerso);
    if(rand()%5==0){ //Correspond a un coup critique
        degats = (int)(tabPerso[numeroPerso].stPerso.attaque*1.20);
        printf("Coup Critique !\n");
    }else{
        degats = rand()%(int)(tabPerso[numeroPerso].stPerso.attaque -(tabPerso[numeroPerso].stPerso.attaque*0.7)) + (int)(tabPerso[numeroPerso].stPerso.attaque*0.7); //Degats peuvent etre fait entre [70%;100%] de l'attaque initial du personnage
    }

    traverseBarriere(mat,tabPerso[numeroPerso].stPerso.pos_X,tabPerso[numeroPerso].stPerso.pos_Y,x_point,y_point);

    tabPerso[numEnnemie].stPerso.HP-=degats;

    printf("%d degats infliger\n",degats);

    printf("Le personnage %d inflige %d degats a l'ennemie %d\n",numeroPerso,degats,numEnnemie);

}
