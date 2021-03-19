#include "../lib/deplacement.h"
#include "../lib/niveaux.h"
#include <stdio.h>
#include <stdlib.h>

int disponible(niveau_t mat, int posX, int posY){
    return ((posX>0 && posX<9) && (posY>0 && posY<16) && (mat[posX][posY]==PORTE || mat[posX][posY]==VIDE));
}

int valides(int coord_x,int coord_y){
    return ( (coord_x>=0 && coord_x<9) && (coord_y>=0 && coord_y<16) );
}

int est_vide(int coord_x, int coord_y, int mat[9][16]){
    return ((mat[coord_x][coord_y]==0) && valides(coord_x,coord_y));
}

void afficherMat(int mat[9][16]){
    int i,j;
    for (i=0;i<9;i++){
        for(j=0;j<16;j++){
            printf(" %i ",mat[i][j]);
        }
        printf("\n");
    }
}

void simplication_mat(niveau_t mat, int simp[9][16]){
    int i,j;
    for(i=0;i<9;i++){

        for(j=0;j<16;j++){

            if(disponible(mat,i,j)){
                simp[i][j]=0;
            }else{
                simp[i][j]=-1;
            }
        }

    }
}

int chercher_chemin_rec(int simp[9][16],int chemin[9][16],int x,int y, int x_fin,int y_fin, int reccu,int reccu_max){
    reccu +=1;
    if(x==x_fin && y==y_fin){
        chemin[x][y]==1;
        return 1;
    }
    if(reccu > reccu_max){
        return -1;
    }

    if(est_vide(x,y,simp)==1){

        if(chemin[x][y]==1){
            return -1;
        }

        chemin[x][y]=1;

        if(chercher_chemin_rec(simp,chemin,x+1,y,x_fin,y_fin,reccu,reccu_max) == 1){
            return 1;
        }

        if(chercher_chemin_rec(simp,chemin,x,y+1,x_fin,y_fin,reccu,reccu_max) == 1){
            return 1;
        }

        if(chercher_chemin_rec(simp,chemin,x-1,y,x_fin,y_fin,reccu,reccu_max) == 1){
            return 1;
        }

        if(chercher_chemin_rec(simp,chemin,x,y-1,x_fin,y_fin,reccu,reccu_max) == 1){
            return 1;
        }

        chemin[x][y] = 0;
        return -1;
    }

    return -1;
}

void copie_chemin(int simp[9][16],int chemin[9][16]){
    int i,y;
    for(i=0;i<9;i++){
        for(y=0;y<16;y++){
            if(chemin[i][y]==1){
                simp[i][y]=1;
            }
        }
    }
}

int chercher_chemin(int simp[9][16],int x_debut, int y_debut, int x_fin, int y_fin){
    int chemin[9][16]={0};
    if(chercher_chemin_rec(simp,chemin,x_debut,y_debut,x_fin,y_fin,0,(abs(x_fin-x_debut)+abs(y_fin-y_debut)))==-1){
        printf("Pas de solution");
    }
    copie_chemin(simp,chemin);
    return 1;
}

void phase_deplacement(t_pers * perso, SDL_Window * pWindow, SDL_Renderer * renderer, niveau_t mat,SDL_Texture * Texperso){
    int simpli[9][16]={0};
    int x_point,y_point;

    simplication_mat(mat,simpli);

    //Recuperer la case ou la personne clique pour deplacer (Gestion d evenement)

    chercher_chemin(simpli,perso->pos_X,perso->pos_Y,x_point,y_point);

    while(perso->pos_X!=x_point && perso->pos_Y!=y_point){

        if(simpli[(perso->pos_X)+1][perso->pos_Y]==1){
            simpli[(perso->pos_X)+1][perso->pos_Y]==0;
            PositionUpdate(perso, pWindow, renderer,Texperso,(perso->pos_X)+1,perso->pos_Y);
        } 
        if(simpli[(perso->pos_X)][(perso->pos_Y)+1]==1){
            simpli[perso->pos_X][(perso->pos_Y)+1]==0;
            PositionUpdate(perso, pWindow, renderer,Texperso,(perso->pos_X)+1,perso->pos_Y);
        } 
        if(simpli[(perso->pos_X)-1][perso->pos_Y]==1){
            simpli[(perso->pos_X)-1][perso->pos_Y]==0;
            PositionUpdate(perso, pWindow, renderer,Texperso,(perso->pos_X)+1,perso->pos_Y);
        } 
        if(simpli[perso->pos_X][(perso->pos_Y)-1]==1){
            simpli[perso->pos_X][(perso->pos_Y)-1]==0;
            PositionUpdate(perso, pWindow, renderer,Texperso,(perso->pos_X)+1,perso->pos_Y);
        } 

    }
}