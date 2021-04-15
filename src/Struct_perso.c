/**
 * \file Struct_perso.c
 * \brief Fonctions pour la gestion d'affichage et de changements de statistiques des personnages
 * 
 * Les informations sur les persnnages et les armes sont dans des fichiers séparés
 * Affichage des informations sur les personnages et les armes et changement de statistiques sur les personnages en fonction de l'arme
 * Structure dans le fichier struct.h
 * \sa struct.h
 */

#include "../lib/commun.h"
#include "../lib/struct.h"
#include "../lib/affichage.h"

/**
 * \fn void afficher_perso_jouant(t_pers* pers, int num)
 * \brief Affiche la base des personnages
 * \param pers pointeur sur la structure pers contenant les informations des différents personnages
 * \param num numéro du personnage
 */
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

    printf ("Poids max de l'inventaire : %i\n",pers[num].poids_inv_max);

    printf ("Point de vie : %i\n",pers[num].HP);
    printf ("Attaque : %i\n",pers[num].attaque);
    printf ("Défense : %i\n",pers[num].defense);
    printf ("Point d'action : %i\n",pers[num].PA);
    printf ("Point de mouvement : %i\n",pers[num].PM);
    printf ("\n");
    printf ("\n");
    printf ("\n");
}


/**
 * \fn stock_obj_stat(char * fichier, int nb_obj, t_objet * tab)
 * \brief stock les informations sur les armes dans un tableau d'objet
 * \param fichier nom du fichier contenant les armes
 * \param nb_obj nombre d'objet dans le fichier
 * \param tab tableau sur a structure objet pour stocker toutes les valeurs
 */
void stock_obj_stat(char * fichier, int nb_obj, t_objet * tab){

    FILE* fic;
    fic = fopen(fichier, "r");

    char * nom_arme;

    int att,def,hp,pa,pm,poids;

    for (int i=0 ; i<nb_obj ; i++){

        fscanf(fic,"Nom : %s", nom_arme);
        fscanf(fic,"Poids : %s", taille);
        fscanf(fic,"ATT : %i", &att);
        fscanf(fic,"DEF : %i", &def);
        fscanf(fic,"HP_obj : %i", &hp);
        fscanf(fic,"PA_obj : %i", &pa);
        fscanf(fic,"PM_obj : %i", &pm);
        
        strcpy(nom_arme,tab[i].nom);
        tab[i].Poids = poids;
        tab[i].ATT = att;
        tab[i].DEF = def;
        tab[i].HP_obj = hp;
        tab[i].PA_obj = pa;
        tab[i].PM_obj = pm;
        
    }
    
    fclose(fic);
}

/**
 * \fn charger_stat_perso(t_texperso tabPerso[], int numPerso, char * nomFPerso)
 * \brief stock les informations sur les personnages dans un tableau de personnages
 * \param nomFPerso nom du fichier contenant les objets
 * \param numpPerso nombre de personnages dans le fichier
 * \param tabPerso tableau sur la structure pers pour stocker toutes les valeurs
 */
void charger_stat_perso(t_texperso tabPerso[], int numPerso, char * nomFPerso){

    FILE* fic;
    fic = fopen(nomFPerso, "r");

    char * nom_pers;

    int att,def,hp,pa,pm,poids;

    for (int i=0 ; i<numPerso ; i++){

        fscanf(fic,"nom : %s", nom_pers);
        fscanf(fic,"poids : %s", &poids_inv_max);
        fscanf(fic,"ATT : %i", &attaque);
        fscanf(fic,"DEF : %i", &defense);
        fscanf(fic,"HP_obj : %i", &HP);
        fscanf(fic,"PA_obj : %i", &PA);
        fscanf(fic,"PM_obj : %i", &PM);
        fscanf(fic,"categ : %i", &categ);

        
        strcpy(nom_pers,tab[i].nom);
        tabPerso[i].poids = poids;
        tabPerso[i].attaque = att;
        tabPerso[i].defense = def;
        tabPerso[i].HP = hp;
        tabPerso[i].PA = pa;
        tabPerso[i].PM = pm;
        tabPerso[i].ceteg = categ;
        
    }
    
    fclose(fic);
}

/**
 * \fn void afficher_arme(t_objet* obj, int num)
 * \brief affiche les informations sur les armes
 * \param obj pointeur sur la structure objet contenant les informations sur les différentes armes
 * \param num numéro dde la l'arme
 */

void afficher_arme(t_objet* obj, int num){
    printf ("Nom : %s\n",obj[num].nom);

    printf ("Poids de l'objet : %s\n",obj[num].poids);

    printf ("Point de vie : %i\n",obj[num].HP_obj);
    printf ("taille de l'objet : %i\n",obj[num].taille);
    printf ("Attaque : %i\n",obj[num].ATT);
    printf ("Défense : %i\n",obj[num].DER);
    printf ("Point d'action : %i\n",obj[num].PA_obj);
    printf ("Point de mouvement : %i\n",obj[num].PM_obj);
    printf ("\n");
    printf ("\n");
    printf ("\n");
}

/**
 * \fn perso_stat(t_pers* pers, t_objet * objet)
 * \brief change les statistiques des personnages en fonction de celle de l'arme qu'il possède
 * \param pers pointeur sur la structure personnage t_pers
 * \param objet pointeur sur la structure objet t_objet
 */
void perso_stat(t_pers* pers, t_objet * objet){

    if (pers->poids_inv_max > 0 ){
           if(pers->poids_inv_max - objet->poids < 0){
               printf("l'objet depage le poids maximul autorisé par l'inventaire");
           }
           else pers->poids_inv_max -= objet->poids;
    }
    else printf("l'inventaire est déjà plein");

    pers->attaque += objet->ATT;
    pers->defense += objet->DEF;
    pers->HP += objet->HP_obj;
    pers->PA += objet->PA_obj;
    pers->PM += objet->PM_obj;

} 
