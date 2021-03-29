#include "../lib/deplacement.h"
#include "../lib/niveaux.h"
#include "../lib/Struct_perso.h"
#include "../lib/affichage.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * \fn int disponible(niveau_t mat, int posX, int posY)
 * \brief Verifie si la case selectionner dans la matrice du niveau n'est pas hors limite et si cela est une porte ou si c est vide
 * \param mat Matrice decrivant le niveau
 * \param posX Coordonnees X dont on veut verifier l'etat
 * \param posY Coordonnees Y dont on veut verifier l'etat
 * \return un booleen sous forme d un int
 */
int disponible(niveau_t mat, int posX, int posY){
    return ((posX>=0 && posX<9) && (posY>=0 && posY<16) && (mat[posX][posY]==PORTE || mat[posX][posY]==VIDE));
}

/**
 * \fn int est_vide(int coord_x, int coord_y, int mat[9][16])
 * \brief Verifie si la case selectionner ce est libre
 * \param coord_x Coordonnees X dont on veut verifier l'etat
 * \param coord_y Coordonnees Y dont on veut verifier l'etat
 * \param mat Matrice comportant la simplification du niveau
 * \return un booleen sous forme d un int
 */

int est_vide(int coord_x, int coord_y, int mat[9][16]){
    return (coord_x>=0 && coord_x<9) && (coord_y>=0 && coord_y<16) && (mat[coord_x][coord_y]==0);
}

/**
 * \fn void afficherMat(int mat[9][16])
 * \brief Affiche sur la sortie standart la matrice (le terminal)
 * \param mat Matrice comportant la simplification du niveau
 */
void afficherMat(int mat[9][16]){
    int i,j;
    for (i=0;i<9;i++){
        for(j=0;j<16;j++){
            printf(" % i ",mat[i][j]);
        }
        printf("\n");
    }
}

/**
 * \fn void simplication_mat(niveau_t mat, int simp[9][16])
 * \brief Transforme la matrice de niveau (detailler), en une matrice simple ayant des 0 pour les cases libre et -1 pour les cases non libre
 * \param mat Matrice decrivant le niveau de facon detailler
 * \param simp Matrice comportant la simplification du niveau 
 */

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

/**
 * \fn int chercher_chemin_rec(int simp[9][16],int chemin[9][16],int x,int y, int x_fin,int y_fin, int reccu,int reccu_max)
 * \brief Fonction de backtracking servant a faire du pathfinding
 * \param simp Matrice comportant la simplification du niveau
 * \param chemin Matrice comportant le chemin final
 * \param x Coordonnes x ou se trouve le personnage
 * \param y Coordonnes y ou se trouve le personnage
 * \param x_fin Coordonnes x ou on veut aller
 * \param y_fin Coordonnes y ou on veut aller
 * \param reccu Nombre d'appel de la fonction
 * \param reccu_max Nombre d'appel max de la fonction
 * \return un booleen sous forme d un int
 */

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
/**
 * \fn void copie_chemin(int simp[9][16],int chemin[9][16])
 * \brief Transpose le chemin de la matrice chemin jusqu a la matrice simpliee
 * \param simp Matrice comportant la simplification du niveau
 * \param chemin Matrice comportant le chemin final
 */

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

/**
 * \fn int chercher_chemin(int simp[9][16],int x_debut, int y_debut, int x_fin, int y_fin)
 * \brief Fonction d encapsulation de checher_chemin_rec
 * \param simp Matrice comportant la simplification du niveau
 * \param x_debut Coordonnes x ou se trouve le personnage
 * \param y_debut Coordonnes y ou se trouve le personnage
 * \param x_fin Coordonnes x ou on veut aller
 * \param y_fin Coordonnes y ou on veut aller
 */
int chercher_chemin(int simp[9][16],int x_debut, int y_debut, int x_fin, int y_fin){
    int chemin[9][16]={0};
    if(chercher_chemin_rec(simp,chemin,x_debut,y_debut,x_fin,y_fin,0,5)==-1){
        return -1;
    }
    copie_chemin(simp,chemin);
    return 1;
}

/**
 * \fn void phase_deplacement(t_pers * perso, SDL_Window * pWindow, SDL_Renderer * renderer, niveau_t mat,SDL_Texture * Texperso)
 * \brief Fonction permettant de gerer la partie deplacement d'un personnage lors d'un tour
 * \param tabPerso tableau contenant tout les personnage ainsi que leur texture
 * \param numPerso indice dans le tableau tabPerso du personnage que l on veut bouger
 * \param pWindow pointeur sur la fenetre
 * \param renderer pointeur sur le renderer liee la fenetre
 * \param mat Matrice devriant le niveau
 * \param Texniv Texture du niveau
 * \param nbPerso Nombre total de personnage inscrit dans le tableau tabPerso
 */



void phase_deplacement(t_texperso tabPerso[],int numPerso, SDL_Window * pWindow, SDL_Renderer * renderer, niveau_t mat, SDL_Texture * Texniv, int nbPerso){
    int simpli[9][16]={0};
    int x_point=-1,y_point=-1;
    int flag =1;

    SDL_Event event;

    simplication_mat(mat,simpli);
    simpli[tabPerso[numPerso].stPerso.pos_X][tabPerso[numPerso].stPerso.pos_Y]=0;

    while(flag==1){

        while(SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT){
                return ;   
            }
            if( event.type == SDL_MOUSEBUTTONDOWN ){
                x_point = event.button.x/64;
                y_point = event.button.y/64;
                if(est_vide(y_point,x_point,simpli)){
                    if (chercher_chemin(simpli, tabPerso[numPerso].stPerso.pos_X, tabPerso[numPerso].stPerso.pos_Y, x_point, y_point)==1 ){
                        flag=-1;
                    }
                }   
            }
        } 
        SDL_Delay(10);
    }
    tabPerso[numPerso].stPerso.pos_X=x_point;
    tabPerso[numPerso].stPerso.pos_Y=y_point;
    Update(tabPerso,pWindow,renderer,Texniv,nbPerso);
}
