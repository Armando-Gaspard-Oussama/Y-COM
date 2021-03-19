#include "../lib/deplacement.h"
#include "../lib/niveaux.h"
#include <stdio.h>

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

int chercher_chemin(int xDebut, int yDebut, int xFin, int yFin, int mat[9][16],int soluc[9][16])
{
    

}

void marquer_chemin(int xa, int ya,int mat[9][16]){
    int capt = mat[xa][ya];
    int i,j;
    while(capt!=0){
        capt--;
        mat[xa][ya]=-2;
        for(i = xa-1 ; i <xa+1; i++){
            for(j = ya-1;j<ya+1;j++){
                if(mat[i][j]==capt && valides(i,j)){
                    xa=i;
                    ya=j;
                }
            }
        }
    }
}

void nettoyer(int mat[9][16]){
    int i,j;
    for(i=0;i<9;i++){
        for(j=0;j<16;j++){
            if(mat[i][j]>0){
                mat[i][j]=0;
            }
        }
    }
}

void afficherChemin(int mat[9][16]){
    int i,j;
    
    for (i=0;i<9;i++){
        printf("|");
        for (j=0;j<16;j++){
            switch (mat[i][j]){

            case -2:    printf(" . ");
                        break;
            case -1:    printf(" * ");
                        break;
            case 0:     printf("   ");
                        break;
            }
        }
        printf("|\n");
    }
}
