#ifndef zxc


#define zxc

#include "./commun.h"
    
    /**
     * \file struct.h
     * \brief Définitions des types et fonctions relatifs aux objets et personnages
     */

typedef enum{
    sniper,
    assaut,
    corps,
    vilain
}t_categ;


typedef struct{
    char nom[20];
    int poids_inv_max;
    int attaque;
    int defense;
    int pos_X;
    int pos_Y;
    int HP;
    int PA;
    int PM;
    t_categ categ;
}t_pers;

typedef struct{
    char nom[20];
    int Poids;
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
