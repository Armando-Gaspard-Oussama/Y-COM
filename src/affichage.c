#include "../lib/affichage.h"
#include "../lib/commun.h"
#include <stdio.h>

/**
 * \file affichage.c
 * \brief Toutes les fonctions d'affichage nécessaires au projet.
 * \author Armando Costa
 * \version 1.0
 * \date 09/02/2021
 */



/**
 * \fn SDL_Window * creation_fenetre_renderer(char * nom, SDL_Renderer * rend)
 * \brief Ouvre une fenêtre à l'aide de la SDL2 et affecte un renderer à cette fenêtre.
 * \author Armando Costa
 * \param nom Nom de la fenêtre ouverte
 * \param rend Pointeur sur le renderer qui sera affecté à la fenêtre genérée
 * \return Un pointeur sur la fenêtre ouverte par la fonction
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
 * \param pWindow Pointeur sur la fenêtre déjà ouverte
 * \param nomFNiveau Nom de l'image du niveau
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
    SDL_RWclose(rwop);

    return image_tex;
  }


/**
 * \fn void charger_personnage(SDL_Window * pWindow, char * nomFNiveau)
 * \brief Charge un personnage
 * \author Armando Costa
 * \param pWindow Pointeur sur la fenetre deja ouverte
 * \param nomFPersonnage Nom de l image du personnage
 * \param renderer Pointeur sur le renderer ratacher a la fenetre pWindow
 * \param x Coordonnees x ou va etre charge le personnage
 * \param y Coordonnees y ou va etre charge le personnage
 * \return Retourne un pointeur sur la Texture
 */

SDL_Texture * charger_personnage(SDL_Window * pWindow, char * nomFPersonnage, SDL_Renderer * renderer, int x, int y){
  SDL_Rect imgDestRect;
  SDL_RWops *rwop=SDL_RWFromFile(nomFPersonnage,"rb");
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
  SDL_RWclose(rwop);

  return image_tex;
}


void PositionUpdate(t_pers * perso, SDL_Window * pWindow, SDL_Renderer * rend, SDL_Texture * Texperso, int x, int y){
  SDL_Rect persoPos;

  SDL_RenderClear(rend);

  persoPos.x=(LARGEUR/16)*x;
  persoPos.y=(HAUTEUR/9)*y;

  perso->pos_X=x;
  perso->pos_Y=y;

  SDL_QueryTexture(Texperso,NULL,NULL,&(persoPos.w),&(persoPos.h));
  SDL_RenderCopy(rend,Texperso,NULL,&persoPos);

  SDL_RenderPresent(rend);
}