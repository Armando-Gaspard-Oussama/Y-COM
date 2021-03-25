
#include "../lib/commun.h"
#include "../lib/Struct_perso.h"



#include <stdio.h>
#include <stdlib.h>



void afficher_perso_jouant(t_pers* pers, int num){
    printf ("Nom : %s\n",pers[num].categ);
    printf ("Type du personnage : %s\n",pers[num].type)
    printf ("Point de vie : %i\n",pers[num].HP);
    printf ("Attaque : %i\n",pers[num].attaque);
    printf ("Défense : %i\n",pers[num].defense);
    printf ("Point d'action : %i\n",pers[num].PA);
    printf ("Point de mouvement : %i\n",pers[num].PM);
    printf ("\n");
    printf ("\n");
    printf ("\n");
}

void perso_stat(t_pers* pers, t_objet* obj, char objet){
     if (objet == 'sniper'){
        if (pers[num].type == 'sniper' && obj[objet].snip == 'M24'){
            pers[num].attaque += obj[objet].ATT;
            pers[num].PA += obj[objet].PA_obj;
            pers[num].PM += obj[objet].PM_obj;
        }
     
        if (pers[num].type == 'sniper' && obj[objet].snip == 'Mosin-Nagant'){
            pers[num].attaque += obj[objet].ATT;
            pers[num].PA += obj[objet].PA_obj;
            pers[num].PM += obj[objet].PM_obj;
        }

        if (pers[num].type == 'sniper' && obj[objet].snip == 'M98b'){
            pers[num].attaque += obj[objet].ATT;
            pers[num].PA += obj[objet].PA_obj;
            pers[num].PM += obj[objet].PM_obj;
        }

        if (pers[num].type /= 'sniper'){
            printf("La classe du personnage n'est pas compatible avec l'arme\n");
        }
    }



     if (objet == 'assaut'){
        if (pers[num].type == 'assaut' && obj[objet].snip == 'AK47'){
            pers[num].attaque += obj[objet].ATT;
            pers[num].PA += obj[objet].PA_obj;
            pers[num].PM += obj[objet].PM_obj;
        }
     
        if (pers[num].type == 'assaut' && obj[objet].snip == 'Famas'){
            pers[num].attaque += obj[objet].ATT;
            pers[num].PA += obj[objet].PA_obj;
            pers[num].PM += obj[objet].PM_obj;
        }

        if (pers[num].type == 'assaut' && obj[objet].snip == 'MP4'){
            pers[num].attaque += obj[objet].ATT;
            pers[num].PA += obj[objet].PA_obj;
            pers[num].PM += obj[objet].PM_obj;
        }

        if (pers[num].type /= 'assaut'){
            printf("La classe du personnage n'est pas compatible avec l'arme\n");
        }
    }


         if (objet == 'corps'){
        if (pers[num].type == 'corps' && obj[objet].snip == 'Balisong'){
            pers[num].attaque += obj[objet].ATT;
            pers[num].PA += obj[objet].PA_obj;
            pers[num].PM += obj[objet].PM_obj;
        }
     
        if (pers[num].type == 'corps' && obj[objet].snip == 'balistique'){
            pers[num].attaque += obj[objet].ATT;
            pers[num].PA += obj[objet].PA_obj;
            pers[num].PM += obj[objet].PM_obj;
        }

        if (pers[num].type == 'corps' && obj[objet].snip == 'Bowie'){
            pers[num].attaque += obj[objet].ATT;
            pers[num].PA += obj[objet].PA_obj;
            pers[num].PM += obj[objet].PM_obj;
        }

        if (pers[num].type /= 'corps'){
            printf("La classe du personnage n'est pas compatible avec l'arme\n");
        }
    }
}
