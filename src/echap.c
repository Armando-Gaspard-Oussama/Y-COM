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
 * \fn SDL_Texture * menu_quitter(t_texperso tabPerso[], SDL_Window * pWindow, SDL_Renderer * rend, SDL_Texture * TexMenu,int nbPerso)
 * \brief Ouvre une fenêtre à l'aide de la SDL2 et affecte un renderer à cette fenêtre.
 * \param pWindow Pointeur sur la fenêtre déjà ouverte
 * \param rend Pointeur sur le renderer qui sera affecté à la fenêtre genérée
 * \param tabPerso tableau contenant tout les personnage ainsi que leur texture
 * \param nbPerso Le nombre de personnage dans le tableau
 * \param Texniv Texture du menu
 */

void menu_quitter(t_texperso tabPerso[], SDL_Window * pWindow, SDL_Renderer * rend, SDL_Texture * TexMenu,int nbPerso){

    int continuer = 3;
    SDL_Event event;

    SDL_Surface *menu = NULL;

    SDL_Rect positionMenu;
    positionMenu.x=LARGEUR/2;
    positionMenu.y=HAUTEUR/2;

    menu = SDL_RWops *rwop=SDL_RWFromFile("menu.png","rb");

    menu = IMG_LoadPNG_RW(rwop);
    SDL_Texture * menu_tex = SDL_CreateTextureFromSurface(rend, menu);


    if (event.key.keysym.sym == SDLK_ESCAPE){
        while (continuer){
            SDL_WaitEvent(&event);

            switch(event.type){ 
                case SDL_QUIT:
                continuer=0;
                break;

                case SDL_KEYDOWN:
                switch(event.key.keysym.sym){
                    case SDLK_ESCAPE:
                    exit(1);
                    break;

                    case SDLK_ENTER:
                    continuer =2;
                    break;
                }
                break;
            }
            SDL_QueryTexture(menu_tex, NULL, NULL, &(positionMenu.w), &(positionMenu.h));
            SDL_RenderCopy(rend, menu_tex, NULL, &positionMenu);

            SDL_RenderPresent(rend);
            SDL_RWclose(rwop);

            Update(tabPerso, pWindow, rend, TexMenu, nbPerso);
        }

        SDL_FreeSurface(menu);
    }
}
