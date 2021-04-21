#include "../lib/deplacement.h"

/**
 * \file deplacement.c
 * \brief Toutes les fonctions nécessaires au deplacement.
 * \author Armando Costa
 * \version 1.0
 * \date 19/02/2021
 */

/**
 * \fn int disponible(niveau_t mat, int posX, int posY)
 * \brief Vérifie si la case selectionnée dans la matrice du niveau n'est pas hors-limites et si cela est une porte ou si c'est vide
 * \param mat Matrice décrivant le niveau
 * \param posX Coordonnées X dont on veut vérifier l'état
 * \param posY Coordonnées Y dont on veut vérifier l'état
 * \return un booléen sous forme d'un int
 */
int disponible(niveau_t mat, int posX, int posY){
    return ((posX>=0 && posX<9) && (posY>=0 && posY<16) && (mat[posX][posY]==PORTE || mat[posX][posY]==VIDE));
}

/**
 * \fn int est_vide(int coord_x, int coord_y, int mat[9][16])
 * \brief Vérifie si la case selectionnée est libre
 * \param coord_x Coordonnees X dont on veut vérifier l'état
 * \param coord_y Coordonnees Y dont on veut vérifier l'état
 * \param mat Matrice comportant la simplification du niveau
 * \return un booléen sous forme d'un int
 */

int est_vide(int coord_x, int coord_y, int mat[9][16]){
    return (coord_x>=0 && coord_x<9) && (coord_y>=0 && coord_y<16) && (mat[coord_x][coord_y]==0);
}

/**
 * \fn void afficherMat(int mat[9][16])
 * \brief Affiche sur la sortie standard la matrice (le terminal)
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
 * \brief Transforme la matrice de niveau (detaillé), en une matrice simple ayant des 0 pour les cases libres et -1 pour les cases non-libres
 * \param mat Matrice décrivant le niveau de facon détaillée
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
 * \brief Fonction de backtracking servant à faire du pathfinding
 * \param simp Matrice comportant la simplification du niveau
 * \param chemin Matrice comportant le chemin final
 * \param x Coordonnes x où se trouve le personnage
 * \param y Coordonnes y où se trouve le personnage
 * \param x_fin Coordonnes x où on veut aller
 * \param y_fin Coordonnes y où on veut aller
 * \param reccu Nombre d'appels de la fonction
 * \param reccu_max Nombre d'appels max de la fonction
 * \return un booléen sous forme d'un int
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

    if(chemin[x][y]==1 || chemin[x][y]==-1){
        return -1;
    }
    chemin[x][y]=1;


    if(chercher_chemin_rec(simp,chemin,x+1,y,x_fin,y_fin,reccu,reccu_max) == 1){
        return 1;
    }

    if(chercher_chemin_rec(simp,chemin,x-1,y,x_fin,y_fin,reccu,reccu_max) == 1){
        return 1;
    }

    
    if(chercher_chemin_rec(simp,chemin,x,y+1,x_fin,y_fin,reccu,reccu_max) == 1){
        return 1;
    }

    if(chercher_chemin_rec(simp,chemin,x,y-1,x_fin,y_fin,reccu,reccu_max) == 1){
        return 1;
    }
    chemin[x][y]=0;

    return -1;
}

/**
 * \fn int chercher_chemin(int simp[9][16],int x_debut, int y_debut, int x_fin, int y_fin)
 * \brief Fonction d'encapsulation de checher_chemin_rec
 * \param simp Matrice comportant la simplification du niveau
 * \param x_debut Coordonnée x où se trouve le personnage
 * \param y_debut Coordonnée y où se trouve le personnage
 * \param x_fin Coordonnée x où on veut aller
 * \param y_fin Coordonnée y où on veut aller
 * \return Un booléen en fonction de si un chemin a été trouvé ou non
 */
int chercher_chemin(int simp[9][16],int x_debut, int y_debut, int x_fin, int y_fin,niveau_t niv){
    int chemin[9][16]={0};
    simplication_mat(niv,chemin);
    if(disponible(niv,x_debut+1,y_debut)==1){
        if(chercher_chemin_rec(simp,chemin,x_debut+1,y_debut,x_fin,y_fin,0,3)==1){
            copie_chemin(simp,chemin);
            return 1;
        }
    }
    if(disponible(niv,x_debut-1,y_debut)==1){
        if(chercher_chemin_rec(simp,chemin,x_debut-1,y_debut,x_fin,y_fin,0,3)==1){
            copie_chemin(simp,chemin);
            return 1;
        }
    }
    if(disponible(niv,x_debut,y_debut-1)==1){
        if(chercher_chemin_rec(simp,chemin,x_debut,y_debut-1,x_fin,y_fin,0,3)==1){
            copie_chemin(simp,chemin);
            return 1;
        }
    }
    if(disponible(niv,x_debut,y_debut+1)==1){
        if(chercher_chemin_rec(simp,chemin,x_debut,y_debut+1,x_fin,y_fin,0,3)==1){
            copie_chemin(simp,chemin);
            return 1;
        }
    }
    return -1;
}


/**
 * \fn void copie_chemin(int simp[9][16],int chemin[9][16])
 * \brief Transpose le chemin de la matrice chemin jusqu'à la matrice simplifiée
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
 * \fn void phase_deplacement(t_pers * perso, SDL_Window * pWindow, SDL_Renderer * renderer, niveau_t mat,SDL_Texture * Texperso)
 * \brief Fonction permettant de gérer la partie déplacement d'un personnage lors d'un tour
 * \param tabPerso tableau contenant tous les personnages ainsi que leurs textures
 * \param numPerso indice dans le tableau tabPerso du personnage que l'on veut bouger
 * \param pWindow pointeur sur la fenêtre
 * \param renderer pointeur sur le renderer lié la fenêtre
 * \param mat Matrice décrivant le niveau
 * \param Texniv Texture du niveau
 * \param nbPerso Nombre total de personnages inscrits dans le tableau tabPerso
 * \param font Police d'écriture du nom et des HP affichés
 */

void phase_deplacement(t_texperso tabPerso[],int numPerso, SDL_Window * pWindow, SDL_Renderer * renderer, niveau_t mat, SDL_Texture * Texniv, int nbPerso, TTF_Font * font){
    int simpli[9][16]={0};
    int x_point=-1,y_point=-1;
    int flag =1;

    SDL_Event event;

    simplication_mat(mat,simpli);
    

    while(flag==1){

        while(SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT){
                return ;   
            }
            if( event.type == SDL_MOUSEBUTTONDOWN ){
                x_point = event.button.x/64;
                y_point = event.button.y/64;
                if(est_vide(y_point,x_point,simpli)){
                    if (chercher_chemin(simpli, tabPerso[numPerso].stPerso.pos_Y, tabPerso[numPerso].stPerso.pos_X, y_point, x_point,mat)==1 ){
                        flag=-1;
                    }
                }   
            }
        } 
        SDL_Delay(10);
    }
    mat[tabPerso[numPerso].stPerso.pos_Y][tabPerso[numPerso].stPerso.pos_X]=0;

    tabPerso[numPerso].stPerso.pos_X=x_point;
    tabPerso[numPerso].stPerso.pos_Y=y_point;

    mat[tabPerso[numPerso].stPerso.pos_Y][tabPerso[numPerso].stPerso.pos_X]=-1;

    Update(tabPerso,pWindow,renderer,Texniv,nbPerso,font);
}
