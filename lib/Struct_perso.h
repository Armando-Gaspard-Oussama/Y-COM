#include "./commun.h"


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

typedef enum{
    M24,
    MosinNagant,
    M98b,
}t_sniper;

typedef enum{
    AK47,
    Famas,
    MP4,
}t_assaut;

typedef enum{
    Balisong,
    Balistique,
    Bowie,
}t_cac;


typedef struct{
    int attaque;
    int defense;
    int HP;
    int PA;
    int PM;
    int pos_X;
    int pos_Y;
    t_categ categ;
    t_type type;
}t_pers;

typedef struct{
    int ATT;
    int DEF;
    int HP_obj;
    int PA_obj;
    int PM_obj;
    t_sniper snip;
    t_assaut ass;
    t_cac cac;
}t_objet;
