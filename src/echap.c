/**
 * \file echap.c
 * \brief Fonctions pour la création d'un menu quitter/continuer pendant une partie
 * Affcihage d'un menu permettant de metre en pause ou quitter le jeu a l'aide des touches du clavier
 * Structure dans le fichier affichage.h
 * \sa affichage.h
 */

#include "../lib/affichage.h"
#include "../lib/commun.h"

/**
 * \fn SDL_Texture * menu_quitter(SDL_Window * pWindow)
 * \brief Génère un menu pour quitter
 * \author Belkadi Oussama
 * \param pWindow Pointeur sur la fenêtre déjà ouverte
 */

SDL_Texture * menu_quitter(SDL_Window * pWindow){

    int continuer = 3;
    SDL_Event evenement;


    pWindow = SDL_CreateWindow(nom,
    SDL_WINDOWPOS_CENTERED,
    SDL_WINDOWPOS_CENTERED,
    640,
    480,
    SDL_WINDOW_SHOWN);

    SDL_Surface *ecran = NULL;
    SDL_Surface *menu = NULL;

    SDL_rect positionMenu;
    
    menu = IMG_Load("menu.png");


    if (event.key.keysym.sym == SDLK_ESCAPE){
        whle (continuer){
            SDL_WaitEvent(&evenement);

            switch(evenement.type){ // si continuer =0 on quitte la sdl
                case SDL_QUIT:
                continuer=0;
                break;

                case SDL_KEYDOWN:
                switch(event.key.keysym.sym){
                    case SDLK_ESCAPE:
                    continuer =0;
                    break;

                    case SDLK_ENTER:
                    continuer =2;
                    break;
                }
                break;
            }
            SDL_BlitSurface(menu,NULL,ecran,&positionMenu);
            SDL_flip(ecran);
        }

        SDL_FreeSurface(menu);
        SDL_Quit();
        return EXIT_success;
    }
}
