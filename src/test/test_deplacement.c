#include <deplacement.h>
#include <niveaux.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    niveau_t niv;

    chargement_contenu_niveau(niv, "06.niv");
    lecture_niveau(niv);

    return 0;
}
