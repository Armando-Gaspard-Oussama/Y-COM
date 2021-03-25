#include <deplacement.h>
#include <niveaux.h>
#include <stdio.h>
#include <stdlib.h>

void test(int valeur, int attendu, int * reussit)
{
    if (valeur == attendu)
    {
        printf("OK\n");
    }
    else
    {
        printf("NOK\n");
        *reussit = 0;
    }
}

int main(int argc, char **argv)
{
    niveau_t niv;
    int res;
    int reussit = 1;

    printf("\n === Début du test des fonctions de déplacement ===\n");

    printf("Chargement du niveau...\n");
    chargement_contenu_niveau(niv, "06.niv");
    printf("Niveau chargé:\n");
    lecture_niveau(niv);

    printf(" == Test des disponibilités de cases:\n");
    printf("Test en x=3,y=3, doit être libre: ");
    res = disponible(niv, 3, 3);
    test(res, 1, &reussit);
    printf("Test en y=0,x=7, doit être libre: ");
    res = disponible(niv, 7, 0);
    test(res, 1, &reussit);
    printf("Test en x=11,y=7, doit être libre: ");
    res = disponible(niv, 11, 7);
    test(res, 1, &reussit);
    printf("Test en x=2,y=2, doit être occupé: ");
    res = disponible(niv, 2, 2);
    test(res, 0, &reussit);
    printf("Test en x=15,y=8, doit être occupé: ");
    res = disponible(niv, 15, 8);
    test(res, 0, &reussit);

    if (reussit)
        printf(" ++ Tous les tests on réussi ++\n");
    else
        printf(" !!! Des tests ont échoué !!!\n");

    printf(" === Fin du test des fonctions de déplacement ===\n");
    return reussit;
}
