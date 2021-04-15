GIT_ROOT = ../../
INC_DIR = $(GIT_ROOT)/lib/
LIBS = -lmingw32  -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf 

all: affichage.o niveaux.o test_niveau.o deplacement.o combat.o test_niveau

test_niveau: test_niveau.o affichage.o niveaux.o deplacement.o combat.o
	gcc test_niveau.o affichage.o niveaux.o deplacement.o combat.o -o test_niveau -lmingw32 -lSDL2main -lSDL2 -lSDL2_ttf -lSDL2_image -g

test_niveau.o: test_niveau.c
	gcc test_niveau.c -c -lmingw32 -lSDL2main -lSDL2 -lSDL2_ttf -lSDL2_image -g
combat.o: ../combat.c ../../lib/combat.h
	gcc ../combat.c ../../lib/combat.h -c -lmingw32 -lSDL2main -lSDL2 -lSDL2_ttf -lSDL2_image -g 
affichage.o : ../affichage.c ../../lib/affichage.h
	gcc ../affichage.c -c -lmingw32 -lSDL2main -lSDL2 -lSDL2_ttf -lSDL2_image -g
niveaux.o : ../niveaux.c ../../lib/niveaux.h
	gcc ../niveaux.c -c -lmingw32  -lSDL2main -lSDL2 -lSDL2_ttf -lSDL2_image -g 
deplacement.o : ../deplacement.c ../../lib/deplacement.h
	gcc ../deplacement.c -c -lmingw32 -lSDL2main -lSDL2 -lSDL2_ttf -lSDL2_image -g  

test_deplacement: deplacement.o niveaux.o test_deplacement.o affichage.o
	gcc $(LIBS) -o $@ $^ 

test_deplacement.o: test_deplacement.c ../../lib/deplacement.h ../../lib/niveaux.h
	gcc -g -c $< -I $(INC_DIR)
