#include "../lib/IA.h"

void affichermat(int mat[5][5]){
    int i,j;
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            printf("% d",mat[i][j]);
        }
        printf("\n");
    }
}

/**
 * \fn void indiceMaxMatrice(int mat[5][5],int * x, int * y)
 * \brief Trouve les indice de la valeur la plus grande de la matrice
 * \param x Pointeur sur la variable ou sera stocké l indice
 * \param y Pointeur sur la variable ou sera stocké l indice
 */

void indiceMaxMatrice(int mat[5][5],int * x, int * y){
    int i,j;
    int max = -1;
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            if(max<mat[i][j]){
                *(x) = i;
                *(y) = j;
                max=mat[i][j];
            }
        }
    }
}

/**
 * \fn int evaluationDeplacement(niveau_t mat, int x,int y)
 * \brief Retourne une valeur arbritraire définissant si cela vaut le coup de se deplace a la case passer en paramatre
 * \param mat Matrice decrivant le niveau
 * \param x Position x de la case ou l evaluation va etre faite
 * \param y Position y de la case ou l evaluation va etre faite
 * \return valeur arbitraire en fonction de barriere se situant sur la vertical et l horizontal de la case
 */

int evaluationDeplacement(niveau_t mat, int x,int y){
    int nbBarriere=0;
    int i;
    for(i=1;i<(LARGEUR/64)-x;i++){
        if(mat[y][x+i]==3){
            nbBarriere++;
            break;
        }
    }
    for(i=1;i<x;i++){
        if(mat[y][x-i]==3){
            nbBarriere++;
            break;
        }
    }
    for(i=1;i<(HAUTEUR)/64-y;i++){
        if(mat[y+i][x]==2){
            nbBarriere++;
            break;
        }
    }
    for(i=1;i<y;i++){
        if(mat[y-i][x]==2){
            nbBarriere++;
            break;
        }
    }

    return nbBarriere;
}

/**
 * \fn int plusBasVie(t_texperso tabperso[],int nbPerso)
 * \brief Trouve le personnage joueur qui a le moins de vie
 * \param tabPerso Tableau contenant les informations de toute les personnages
 * \param nbPerso Nombre total de personnage
 * \return L'indice dans le tableau tabPerso du personnage ayant le moins de vie
 */
int plusBasVie(t_texperso tabperso[],int nbPerso){
    int i;
    int min = 10000;
    int iMin=0;
    for(i=0;i<nbPerso;i++){
        if(min>tabperso[i].stPerso.HP && tabperso[i].stPerso.categ!=3){
            iMin=i;
            min=tabperso[i].stPerso.HP;
            printf("Min : %d index : %d\n",min,iMin);
        }
    }
    return iMin;
}

/**
 * \fn void IA(t_texperso tabPerso[], int numeroPerso, niveau_t mat,SDL_Window * pWindow, SDL_Renderer * rend, TTF_Font * font,int nbperso, SDL_Texture * textNiv)
 * \brief Tout le deroulement d une partie de jeu d'une IA
 * \param tabPerso Tableau contenant les informations de toute les personnages
 * \param numeroPerso Personnage IA
 * \param mat Matrice decrivant le niveau
 * \param pWindow Pointeur sur la fenêtre déjà ouverte
 * \param rend Pointeur sur le renderer ratacher a la fenetre
 * \param font Pointeur sur la police d'ecriture utilisé
 * \param nbPerso Nombre total de personnage
 * \param textNiv Pointeur sur la texture du niveau
 */

void IA(t_texperso tabPerso[], int numeroPerso, niveau_t mat,SDL_Window * pWindow, SDL_Renderer * rend, TTF_Font * font,int nbperso, SDL_Texture * textNiv){
    if(tabPerso[numeroPerso].stPerso.categ==3){

        int possibilites[5][5]={0};
        int attaque[4] = {0};
        int i,j;
        int degats;
        int victime =0;

        for(i=0;i<=5;i++){

            for(j=0;j<=5;j++){
                if(disponible(mat,tabPerso[numeroPerso].stPerso.pos_Y+(i-2),tabPerso[numeroPerso].stPerso.pos_X+(j-2))){

                    possibilites[i][j]=evaluationDeplacement(mat,tabPerso[numeroPerso].stPerso.pos_X+(j-2),tabPerso[numeroPerso].stPerso.pos_Y+(i-2));
                }
            }
        }
        indiceMaxMatrice(possibilites,&i,&j);

        mat[tabPerso[numeroPerso].stPerso.pos_Y][tabPerso[numeroPerso].stPerso.pos_X]=0;
        tabPerso[numeroPerso].stPerso.pos_Y=tabPerso[numeroPerso].stPerso.pos_Y+(i-2);
        tabPerso[numeroPerso].stPerso.pos_X=tabPerso[numeroPerso].stPerso.pos_X+(j-2);
        mat[tabPerso[numeroPerso].stPerso.pos_Y][tabPerso[numeroPerso].stPerso.pos_X]=-1;

        Update(tabPerso,pWindow,rend,textNiv,nbperso,font);

        victime=plusBasVie(tabPerso,nbperso);
        printf("%d\n",victime);

        if(rand()%5==0){ //Correspond a un coup critique
            degats = (int)(tabPerso[numeroPerso].stPerso.attaque*1.20);
            printf("Coup Critique !\n");
        }else{
            degats = rand()%(int)(tabPerso[numeroPerso].stPerso.attaque -(tabPerso[numeroPerso].stPerso.attaque*0.7)) + (int)(tabPerso[numeroPerso].stPerso.attaque*0.7); //Degats peuvent etre fait entre [70%;100%] de l'attaque initial du personnage
        }

        if(traverseBarriere(mat,tabPerso[numeroPerso].stPerso.pos_X,tabPerso[numeroPerso].stPerso.pos_Y,tabPerso[victime].stPerso.pos_X,tabPerso[victime].stPerso.pos_Y)==1){
            degats -= (degats*0.5);
            printf("Le coup traverse une barriere\n");
        }

        tabPerso[victime].stPerso.HP-=degats;

        Update(tabPerso,pWindow,rend,textNiv,nbperso,font);

    }
}