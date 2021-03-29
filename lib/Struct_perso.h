#ifndef zxc


#define zxc

#include "./commun.h"


 typedef enum{
    sniper,
    assaut,
    corps,
    vilain
}t_categ;


typedef struct{
    char nom[20];
    int attaque;
    int defense;
    int HP;
    int PA;
    int PM;
    t_categ categ;
}t_pers;

typedef struct{
    char nom[20];
    int ATT;
    int DEF;
    int HP_obj;
    int PA_obj;
    int PM_obj;
}t_objet;

void afficher_perso_jouant(t_pers* pers, int num);

void afficher_arme(t_objet* obj, int num);

void stock_obj_stat(char * fichier, int nb_obj, t_objet * tab);

void perso_stat(t_pers* pers, t_objet * objet);
#endif
