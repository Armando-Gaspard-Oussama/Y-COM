#include <stdio.h>
#include <stdlib.h>

typedef enum{
    Bill,
    Jane,
    Pau,
    Ennemie
}t_categ;

typedef enum{
    sniper,
    assaut,
    corps,
    vilain
}t_type;

typedef struct{
    int pos_X;
    int pos_Y;
    int attaque;
    int defense;
    int HP;
    int PA;
    int PM;
    t_categ categ;
    t_type type;
}t_pers;

typedef struct{
    int ATT;
    int DEF;
    int HP_obj;
    int PA_obj;
    int PM_obj;
}t_objet;



void afficher_perso_jouant(t_pers * pers, int num){
    printf ("Nom : %s\n",pers[num].categ);
    printf ("Type du personnage : %s\n",pers[num].type);
    printf ("Position : %i %i\n",pers[num].pos_X , pers[num].pos_Y);
    printf ("Point de vie : %i\n",pers[num].HP);
    printf ("Attaque : %i\n",pers[num].attaque);
    printf ("Défense : %i\n",pers[num].defense);
    printf ("Point d'action : %i\n",pers[num].PA);
    printf ("Point de mouvement : %i\n",pers[num].PM);
    printf ("\n");
    printf ("\n");
    printf ("\n");
}


void objet_stat(t_pers* pers, t_objet* obj, char* objet, int num){
    if (objet == 'sniper'){
        if (pers[num].type == 'sniper'){
            pers[num].attaque += obj[/*objet*/].ATT;
            pers[num].PA += obj[/*objet*/].PA_obj;
            pers[num].PM += obj[/*objet*/].PM_obj;
        }
        if (pers[num].type /= 'sniper'){
            printf("La classe du personnage n'est pas compatible avec l'arme\n");
        }
    }

    if (objet == 'assaut'){
        if (pers[num].type == 'assaut'){
            pers[num].attaque += obj[/*objet*/].ATT;
            pers[num].PA += obj[/*objet*/].PA_obj;
            pers[num].PM += obj[/*objet*/].PM_obj;
        }
        if (pers[num].type /= 'assaut'){
            printf("La classe du personnage n'est pas compatible avec l'arme\n");
        }
    }

    if (objet == 'corps'){
        if (pers[num].type == 'corps'){
            pers[num].attaque += obj[/*objet*/].ATT;
            pers[num].PA += obj[/*objet*/].PA_obj;
            pers[num].PM += obj[/*objet*/].PM_obj;
        }
        if (pers[num].type /= 'corps'){
            printf("La classe du personnage n'est pas compatible avec l'arme\n");
        }
    }
}


