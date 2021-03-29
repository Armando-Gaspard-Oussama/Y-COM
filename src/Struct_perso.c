#include <stdio.h>
#include <stdlib.h>
#include "../lib/commun.h"
#include "../lib/struct.h"


void afficher_perso_jouant(t_pers* pers, int num){
    printf ("Nom : %s\n",pers[num].nom);

    switch(pers[num].categ){
      case sniper : printf("Catégorie : sniper\n");
      break;
      case assaut : printf("Catégorie : assaut\n");
      break;
      case corps : printf("Catégorie : corps a corps\n");
      break;
      case vilain : printf("Catégorie : ennemie\n");
      break;
    }

    printf ("Point de vie : %i\n",pers[num].HP);
    printf ("Attaque : %i\n",pers[num].attaque);
    printf ("Défense : %i\n",pers[num].defense);
    printf ("Point d'action : %i\n",pers[num].PA);
    printf ("Point de mouvement : %i\n",pers[num].PM);
    printf ("\n");
    printf ("\n");
    printf ("\n");
}

void afficher_arme(t_objet* obj, int num){
    printf ("Nom : %s\n",obj[num].nom);

    printf ("Point de vie : %i\n",obj[num].HP_obj);
    printf ("Attaque : %i\n",obj[num].ATT);
    printf ("Défense : %i\n",obj[num].DER);
    printf ("Point d'action : %i\n",obj[num].PA_obj);
    printf ("Point de mouvement : %i\n",obj[num].PM_obj);
    printf ("\n");
    printf ("\n");
    printf ("\n");
}

void stock_obj_stat(char * fichier, int nb_obj, t_objet * tab){

    FILE* fic;
    fic = fopen(fichier, "r");

    char * nom_arme;

    int att,def,hp,pa,pm;

    for (int i=0 ; i<nb_obj ; i++){

        fscanf(fic,"Nom : %s", nom_arme);
        fscanf(fic,"ATT : %i", &att);
        fscanf(fic,"DEF : %i", &def);
        fscanf(fic,"HP_obj : %i", &hp);
        fscanf(fic,"PA_obj : %i", &pa);
        fscanf(fic,"PM_obj : %i", &pm);
        
        strcpy(nom_arme,tab[i].nom);
        tab[i].ATT = att;
        tab[i].DEF = def;
        tab[i].HP_obj = hp;
        tab[i].PA_obj = pa;
        tab[i].PM_obj = pm;
        
    }
    
    fclose(fic);
}

void perso_stat(t_pers* pers, t_objet * objet){

    pers->attaque += objet->ATT;
    pers->defense += objet->DEF;
    pers->HP += objet->HP_obj;
    pers->PA += objet->PA_obj;
    pers->PM += objet->PM_obj;

}    
