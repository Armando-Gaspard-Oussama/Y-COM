#include "../lib/deplacement.h"
#include "../lib/niveaux.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    niveau_t niv;

    charger_contenu_niveau(niv, "06.niv");
    lecture_niveau(niv);

    return 0;
}
