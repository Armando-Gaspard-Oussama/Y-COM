#include "affichage.h"
#include "commun.h"
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

SDL_Window * creation_fenetre_renderer(char * nom, SDL_Renderer * rend){
    SDL_Window * pWindow = NULL;

    pWindow = SDL_CreateWindow(nom,
    SDL_WINDOWPOS_CENTERED,
    SDL_WINDOWPOS_CENTERED,
    largeur,
    hauteur,
    SDL_WINDOW_SHOWN);
    
    if(!pWindow){
        fprintf(stderr,"Erreur a la creation de la fenetre : %s \n",SDL_GetError());
        exit(EXIT_FAILURE);
    }

    rend = SDL_CreateRenderer(pWindow, -1, SDL_RENDERER_ACCELERATED);
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
 */


void charger_niveau(SDL_Window * pWindow, char * nomFNiveau){
    SDL_Surface * image = IMG_Load(nomFNiveau);
    SDL_Rect Place = {0,0,1024,576};
    SDL_BlitSurface(image,NULL,SDL_GetWindowSurface(pWindow),&image);
    SDL_UpdateWindowSurface(pWindow);
    SDL_FreeSurface(image);
}