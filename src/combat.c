#include "../lib/combat.h"

/**
 * \file combat.c
 * \brief Toutes les fonctions nécessaires au combat.
 * \author Armando Costa
 * \version 1.0
 * \date 19/02/2021
 */

/**
 * \fn int est_perso(niveau_t mat, int x, int y)
 * \brief Vérifie si la case indiquée comporte un personnage
 * \param mat Matrice décrivant le niveau
 * \param x Position x où on regarde
 * \param y Position y où on regarde
 * \return un booléen
 */
int est_perso(niveau_t mat, int x, int y){
    return(mat[y][x]==PERSO);
}


/**
 * \fn int getNumEnnemie(t_texperso tabPerso[],int x, int y, int nbPerso)
 * \brief Trouve le numéro dans le tableau du personnage à la position donnée en paramètres
 * \param tabPerso Tableau contenant les informations de toute les personnages
 * \param x Position x du personnage dont on veut le numéro
 * \param y Position y du personnage dont on veut le numéro
 * \param nbPerso Nombre total de personnage dans le tableau
 * \return L'indice du personnage dans le tableau positioné aux coordonnées (x;y)
 */
int getNumEnnemie(t_texperso tabPerso[],int x, int y, int nbPerso){
    int i;
    for(i=0;i<nbPerso;i++){
        if(tabPerso[i].stPerso.pos_X==x && tabPerso[i].stPerso.pos_Y==y){
            return i;
        }
    }
    return -1;
}

/**
 * \fn int traverseBarriere(niveau_t mat, int x_debut, int y_debut, int x_fin, int y_fin)
 * \brief Vérifie si l'attaque traverse une barrière sur l'horizontale ou la verticale
 * \param mat Matrice décrivant le niveau
 * \param x_debut Position x de l'origine de l'attaque
 * \param y_debut Position y de l'origine de l'attaque
 * \param x_fin Position x de la destination de l'attaque
 * \param y_fin Position y de la destination de l'attaque
 * \return Un booléen
 */
int traverseBarriere(niveau_t mat, int x_debut, int y_debut, int x_fin, int y_fin){
    int signeX=1;
    int signeY=1;
    int i;   

    
    if(x_fin-x_debut <= 0){
        signeX= -1;
    }
    if(y_fin-y_debut <= 0){
        signeY= -1;
    }

    if(x_debut == x_fin){
        for(i=0;i<abs(y_fin-y_debut);i++){
            i*=signeY;
            if(mat[y_debut+i][x_debut]==BARR_H){
                return 1;
            }
        }
    }
    if(y_debut == y_fin){
        for(i=0;i<abs(x_fin-x_debut);i++){
            i*=signeX;
            if(mat[y_debut][x_debut+i]==BARR_V){
                return 1;
            }
        }
    }
    return -1; //Si l attaque n est pas bloquer par une barriere
}
/**
 * \fn int est_mort(t_texperso tabPerso[], int numeroPerso)
 * \brief Vérifie si un personnage est mort
 * \param tabPerso  Tableau contenant toutes les information des personnages
 * \param numeroPerso personnage dont on souhaite connaître l'état
 */

int est_mort(t_texperso tabPerso[], int numeroPerso){
    return tabPerso[numeroPerso].stPerso.HP<=0;
}


/**
 * \fn int finCombat(t_texperso tabPerso[], int nbPerso)
 * \brief Verifie si tous les personnages d'un camp sont morts
 * \param tabPerso Tableau contenant toutes les information des personnages
 * \param nbPerso nombre total de personnages
 */
int finCombat(t_texperso tabPerso[], int nbPerso){
    int ennemie=0,allie=0;
    int i;
    for (i=0;i<nbPerso;i++){
        if(!est_mort(tabPerso,i)){
            if(tabPerso[i].stPerso.categ==3){
                ennemie++;

            }else{
                allie++;

            }

        }

    }
    return ennemie==0 || allie==0;
}

/**
 * \fn void phaseAttaque(t_texperso tabPerso[], int numeroPerso, niveau_t mat, int nbPerso)
 * \brief Déroulement de toute une partie attaque d'un personnage contrôlé par le joueur
 * \param tabPerso Tableau contenant toutes les informations des personnages
 * \param numeroPerso Indice dans le tableau du personnage qui va faire l'attaque
 * \param mat Matrice décrivant le niveau
 * \param nbPerso Nombre total de personnages sur le niveau
 */
void phaseAttaque(t_texperso tabPerso[], int numeroPerso, niveau_t mat, int nbPerso){
    int flag =1;
    int x_point,y_point;
    int numEnnemie;
    int degats;

    SDL_Event event;
    printf("Au personnage %d d'attaquer\n",numeroPerso);
    while(flag==1){
        
        while(SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT){
                return;

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

    if(traverseBarriere(mat,tabPerso[numeroPerso].stPerso.pos_X,tabPerso[numeroPerso].stPerso.pos_Y,x_point,y_point)==1){
        degats -= (degats*0.5);
        printf("Le coup traverse une barriere\n");
    }

    tabPerso[numEnnemie].stPerso.HP-=degats;

    printf("%d degats infligé \n",degats);

    printf("Le personnage %d inflige %d degats a l'ennemie %d\n Il lui reste %d HP \n",numeroPerso,degats,numEnnemie,tabPerso[numEnnemie].stPerso.HP);

    if(finCombat(tabPerso,nbPerso)){
        printf("C'est la fin du combat");
    }
    flag=0;
}
