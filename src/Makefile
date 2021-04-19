IDIR =../lib
CC=gcc
CFLAGS= -I$(IDIR)


ODIR=obj
LDIR =../lib

LIBS=  -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lm

_DEPS = affichage.h combat.h commun.h deplacement.h IA.h niveaux.h Struct_perso.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = affichage.o combat.o deplacement.o IA.o niveaux.o Struct_perso.o main.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.c $(DEPS)
		$(CC) -c -o $@ $< $(CFLAGS)

prog: $(OBJ)
		$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
		rm -f $(ODIR)/*.o *~ core $(IDIR)/*~