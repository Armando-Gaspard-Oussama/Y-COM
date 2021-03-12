#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

SDL_Window * creation_fenetre_renderer(char * nom, SDL_Renderer ** rend);

SDL_Texture * charger_niveau(SDL_Window * pWindow, char * nomFNiveau, SDL_Renderer * renderer);

SDL_Texture * charger_personnage(SDL_Window * pWindow, char * nomFNiveau, SDL_Renderer * renderer, int x, int y);
