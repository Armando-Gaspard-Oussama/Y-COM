#include "./commun.h"
#include "./Struct_perso.h"

SDL_Window * creation_fenetre_renderer(char * nom, SDL_Renderer ** rend);

SDL_Texture * charger_niveau(SDL_Window * pWindow, char * nomFNiveau, SDL_Renderer * renderer);

SDL_Texture * charger_personnage(SDL_Window * pWindow, char * nomFNiveau, SDL_Renderer * renderer, int x, int y);

void PositionUpdate(t_pers * perso, SDL_Window * pWindow, SDL_Renderer * rend, SDL_Texture * Texperso, int x, int y);