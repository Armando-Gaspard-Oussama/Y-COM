GIT_ROOT = ../../
INC_DIR = $(GIT_ROOT)/lib/

all: affichage.o niveaux.o test_niveau.o deplacement.o test_niveau

test_niveau: test_niveau.o affichage.o niveaux.o deplacement.o
	gcc test_niveau.o affichage.o niveaux.o deplacement.o -o test_niveau -lSDL2 -lSDL2_ttf -lSDL2_image -g

test_niveau.o: test_niveau.c
	gcc test_niveau.c -c -lSDL2 -lSDL2_ttf -lSDL2_image -g
affichage.o : ../affichage.c ../../lib/affichage.h
	gcc ../affichage.c -c -lSDL2 -lSDL2_ttf -lSDL2_image -g

niveaux.o : ../niveaux.c ../../lib/niveaux.h
	gcc ../niveaux.c -c -lSDL2 -lSDL2_ttf -lSDL2_image -g
deplacement.o : ../deplacement.c ../../lib/deplacement.h
	gcc ../deplacement.c -c -lSDL2 -lSDL2_ttf -lSDL2_image -g

test_deplacement: deplacement.o niveaux.o test_deplacement.o
	gcc -o $@ $^

test_deplacement.o: test_deplacement.c ../../lib/deplacement.h ../../lib/niveaux.h
	gcc -g -c $< -I $(INC_DIR)
