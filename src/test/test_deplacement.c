#include <deplacement.h>
#include <niveaux.h>
#include <stdio.h>
#include <stdlib.h>

void test(int valeur, int attendu, int * reussi)
{
    if (valeur == attendu)
    {
        printf("OK\n");
    }
    else
    {
        printf("NOK\n");
        *reussi = 0;
    }
}

int main(int argc, char **argv)
{
    niveau_t niv;
    int res;
    int reussi = 1;
    int mat[9][16];
    int mat_att[9][16] = {
        {-1,-1,-1,-1,-1,-1,-1, 0, 0,-1,-1,-1,-1,-1,-1,-1},
        {-1, 0, 0, 0, 0,-1, 0, 0, 0, 0, 0, 0, 0, 0, 0,-1},
        {-1, 0,-1, 0, 0, 0, 0, 0, 0,-1, 0, 0,-1, 0, 0,-1},
        {-1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,-1},
        { 0, 0, 0, 0, 0,-1, 0,-1, 0, 0, 0, 0, 0, 0, 0, 0},
        {-1, 0, 0, 0,-1, 0, 0, 0, 0, 0, 0, 0, 0,-1, 0,-1},
        {-1, 0, 0, 0, 0, 0, 0, 0, 0,-1, 0,-1, 0, 0, 0,-1},
        {-1, 0,-1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,-1},
        {-1,-1,-1,-1,-1,-1,-1, 0, 0,-1,-1,-1,-1,-1,-1,-1}
    }; 
    int i, j;

    printf("\n === Début du test des fonctions de déplacement ===\n");

    printf("Chargement du niveau...\n");
    chargement_contenu_niveau(niv, "06.niv");
    printf("Niveau chargé:\n");
    lecture_niveau(niv);

    printf("\n == Test des disponibilités de cases:\n");
    printf("Test en x=3,y=3, doit être libre: ");
    res = disponible(niv, 3, 3);
    test(res, 1, &reussi);
    printf("Test en y=0,x=7, doit être libre: ");
    res = disponible(niv, 0, 7);
    test(res, 1, &reussi);
    printf("Test en x=11,y=7, doit être libre: ");
    res = disponible(niv, 7, 11);
    test(res, 1, &reussi);
    printf("Test en x=2,y=2, doit être occupé: ");
    res = disponible(niv, 2, 2);
    test(res, 0, &reussi);
    printf("Test en x=15,y=8, doit être occupé: ");
    res = disponible(niv, 8, 15);
    test(res, 0, &reussi);

    printf("\n == Test de la simplification de matrice:\n");
    printf("Matrice simplifiée:\n");
    simplication_mat(niv, mat);
    afficherMat(mat);
    printf("Matrice attendue:\n");
    afficherMat(mat_att);
    res = 1;

    for (i = 0; i < 9; i++)
    {
        for (j = 0; j < 16; j++)
        {
            res = res && (mat[i][j] == mat_att[i][j]);
        }
    }

    test(res, 1, &reussi);

    if (reussi)
        printf(" ++ Tous les tests on réussi ++\n");
    else
        printf(" !!! Des tests ont échoué !!!\n");

    printf(" === Fin du test des fonctions de déplacement ===\n");
    return reussi;
}
