all: affichage.o niveaux.o test_niveau.o deplacement.o test_niveau

test_niveau: test_niveau.o affichage.o niveaux.o deplacement.o
	gcc test_niveau.o affichage.o niveaux.o deplacement.o -o test_niveau -lSDL2 -lSDL2_ttf -lSDL2_image

test_niveau.o: test_niveau.c
	gcc test_niveau.c -c -lSDL2 -lSDL2_ttf -lSDL2_image
affichage.o : ../affichage.c ../../lib/affichage.h
	gcc ../affichage.c -c -lSDL2 -lSDL2_ttf -lSDL2_image

niveaux.o : ../niveaux.c ../../lib/niveaux.h
	gcc ../niveaux.c -c -lSDL2 -lSDL2_ttf -lSDL2_image
deplacement.o : ../deplacement.c ../../lib/deplacement.h
	gcc ../deplacement.c -c -lSDL2 -lSDL2_ttf -lSDL2_image