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
    Mosin-Nagant,
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
    t_categ categ;
    t_type type;
}t_pers;

typedef struct{
    int ATT;
    int DEF;
    int HP_obj;
    int PA_obj;
    int PM obj;
    t_sniper snip;
    t_assaut ass;
    t_cac cac;
}t_objet;
