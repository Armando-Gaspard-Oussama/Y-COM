GIT_ROOT = ../../
INC_DIR = $(GIT_ROOT)/lib/
CC=gcc
LIBS = -lmingw32  -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf 

all: affichage.o niveaux.o test_niveau.o deplacement.o combat.o Struct_perso.o IA.o test_niveau

test_niveau: test_niveau.o affichage.o niveaux.o deplacement.o combat.o IA.o
	$(CC) test_niveau.o affichage.o niveaux.o deplacement.o combat.o Struct_perso.o IA.o -o test_niveau $(LIBS)

test_niveau.o: test_niveau.c
	$(CC) test_niveau.c -c $(LIBS) 
IA.o: ../IA.c ../../lib/IA.h
	$(CC) ../IA.c -c $(LIBS)
combat.o: ../combat.c ../../lib/combat.h
	$(CC) ../combat.c -c $(LIBS)
affichage.o : ../affichage.c ../../lib/affichage.h
	$(CC) ../affichage.c -c $(LIBS)
niveaux.o : ../niveaux.c ../../lib/niveaux.h
	$(CC) ../niveaux.c -c $(LIBS)
deplacement.o : ../deplacement.c ../../lib/deplacement.h
	$(CC) ../deplacement.c -c $(LIBS)
Struct_perso.o: ../Struct_perso.c ../../lib/Struct_perso.h
	$(CC) ../Struct_perso.c -c $(LIBS)
