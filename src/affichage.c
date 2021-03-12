#include "../lib/affichage.h"
#include "../lib/commun.h"
#include <stdio.h>

/**
 * \file affichage.c
 * \brief Toutes les fonctions d affichage necessaire au projet
 * \author Armando Costa
 * \version 1.0
 * \date 09/02/2021
 */



/**
 * \fn SDL_Window * creation_fenetre_renderer(char * nom, SDL_Renderer * rend)
 * \brief Ouvre une fenetre a l aide de la SDL2 et affecte un renderer a cette fenetre
 * \author Armando Costa
 * \param nom Nom de la fenetre ouverte
 * \param rend Pointeur sur le renderer qui sera affecter a la fenetre generee
 * \return Un pointeur sur la fenetre ouverte par la fonction
 */

SDL_Window * creation_fenetre_renderer(char * nom, SDL_Renderer ** rend){
    SDL_Window * pWindow = NULL;

    pWindow = SDL_CreateWindow(nom,
    SDL_WINDOWPOS_CENTERED,
    SDL_WINDOWPOS_CENTERED,
    LARGEUR,
    HAUTEUR,
    SDL_WINDOW_SHOWN);

    if(!pWindow){
        fprintf(stderr,"Erreur a la creation de la fenetre : %s \n",SDL_GetError());
        exit(EXIT_FAILURE);
    }

    *(rend) = SDL_CreateRenderer(pWindow, -1, SDL_RENDERER_ACCELERATED);
    if(rend == NULL){
        fprintf(stderr, "Erreur a la creation de renderer \n");
        exit(EXIT_FAILURE);
    }

    return pWindow;
}

/**
 * \fn void charger_niveau(SDL_Window * pWindow, char * nomFNiveau)
 * \brief Charge un niveau
 * \author Armando Costa
 * \param pWindow Pointeur sur la fenetre deja ouverte
 * \param nomFNiveau Nom de l image du niveau
 * \return Retourne un pointeur sur la Texture
 */


SDL_Texture * charger_niveau(SDL_Window * pWindow, char * nomFNiveau, SDL_Renderer * renderer){
    SDL_Rect imgDestRect;
    SDL_RWops *rwop=SDL_RWFromFile(nomFNiveau,"rb");
    SDL_Surface *image;

    image = IMG_LoadPNG_RW(rwop);
    SDL_Texture * image_tex = SDL_CreateTextureFromSurface(renderer, image);

    if(!image) {
	     printf("IMG_LoadPNG_RW: %s\n", IMG_GetError());
    }
    SDL_FreeSurface(image);

    imgDestRect.x = 0;
    imgDestRect.y = 0;


    SDL_QueryTexture(image_tex, NULL, NULL, &(imgDestRect.w), &(imgDestRect.h));
    SDL_RenderCopy(renderer, image_tex, NULL, &imgDestRect);

    SDL_RenderPresent(renderer);

    return image_tex;
  }


SDL_Texture * charger_personnage(SDL_Window * pWindow, char * nomFNiveau, SDL_Renderer * renderer, int x, int y){
  SDL_Rect imgDestRect;
  SDL_RWops *rwop=SDL_RWFromFile(nomFNiveau,"rb");
  SDL_Surface *image;

  image = IMG_LoadPNG_RW(rwop);
  SDL_Texture * image_tex = SDL_CreateTextureFromSurface(renderer, image);

  if(!image) {
     printf("IMG_LoadPNG_RW: %s\n", IMG_GetError());
  }
  SDL_FreeSurface(image);

  imgDestRect.x = (LARGEUR/16)*x;
  imgDestRect.y = (HAUTEUR/9)*y;

  SDL_QueryTexture(image_tex, NULL, NULL, &(imgDestRect.w), &(imgDestRect.h));
  SDL_RenderCopy(renderer, image_tex, NULL, &imgDestRect);

  SDL_RenderPresent(renderer);

  return image_tex;
}
