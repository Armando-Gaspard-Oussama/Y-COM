#include "../lib/deplacement.h"
#include "../lib/perso.h"
#include "../lib/niveaux.h"

int disponible(carreau_t mat[9][16], int posX, int posY){
    return ((posX>0 && posX<9) && (posY>0 && posY<16) && mat[9][16]!=MUR);
}


noeuds_t * creation_noeuds(int posX,int posY,noeuds_t * pere, int posXRecherche, int posYRecherche,carreau_t mat[9][16]){

    noeuds_t * noeuds = malloc(sizeof(noeuds_t));

    noeuds->pos_X=posX;
    noeuds->pos_Y=posY;
    noeuds->pere=pere;

    if(posX==posXRecherche && posY==posYRecherche){
        return noeuds;
    }else{

        if(disponible(mat,posX,posY+1)){
            noeuds->F1=creation_noeuds(posX,posY+1,noeuds,posXRecherche,posYRecherche);
        }else{
            noeuds->F1=NULL;
        }

        if(disponible(mat,posX+1,posY))
            noeuds->F2=creation_noeuds(posX+1,posY,noeuds,posXRecherche,posYRecherche);
        }else{
            noeuds->F2=NULL;
        }

        if(disponible(mat,posX,posY-1)){
            noeuds->F3=creation_noeuds(posX,posY-1,noeuds,posXRecherche,posYRecherche);
        }else{
            noeuds->F3=NULL;
        }

        if(disponible(mat,posX-1,posY)){
            noeuds->F4=creation_noeuds(posX-1,posY,noeuds,posXRecherche,posYRecherche);
        }else{
            noeuds->F4=NULL;
        }

    }

    return noeuds;
}

void deplacement(t_pers personnage, int posXFin, int posYFin){

}