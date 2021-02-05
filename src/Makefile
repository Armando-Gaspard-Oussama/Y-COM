ERRLEVEL="-Wall -Werror -Wextra"
OPTI="-g"
LIBS="-lSDL2"
INCLUDE="-I../lib/" #peut-être mieux de mettre le -I à l'extérieur de la variable et plutôt dans l'appel de GCC
LIBDIR="-L../lib/" # pareil
COMPIL="gcc"
# probablement ajouter dossiers de sources et chercher d'autres options pour gcc

all: #dépendances
	$(COMPIL) $(ERRLEVEL) $(OPTI) $(INCLUDE) $(LIBDIR) $(LIBS) #output et #sources
