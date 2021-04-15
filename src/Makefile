ERRLEVEL="-Wall -Werror -Wextra"
OPTI="-g"
LIBS="-lmingw32  -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf"
INCLUDE="-I../lib/" #peut-être mieux de mettre le -I à l'extérieur de la variable et plutôt dans l'appel de GCC
LIBDIR="-L../lib/" # pareil
COMPIL="gcc"
# probablement ajouter dossiers de sources et chercher d'autres options pour gcc

all: #dépendances
	$(COMPIL) $(ERRLEVEL) $(OPTI) $(INCLUDE) $(LIBDIR) $(LIBS) #output et #sources
