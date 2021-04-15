#ifndef asd


#define asd
    #include "./commun.h"
    #include "./Struct_perso.h"
    #include "./niveaux.h"

    /**
     * \file affichage.h
     * \brief Definitions des types et des fonction relatifs a l'affichage
     * 
     */

    /**
     * \brief Structure qui contient les Texture relatif a un personnage, permet un affichage plus simple a mettre en oeuvre
     */
    typedef struct s_texperso
    {
        t_pers stPerso;
        SDL_Texture * Tex;
    }t_texperso;
    

    SDL_Window * creation_fenetre_renderer(char * nom, SDL_Renderer ** rend);

    SDL_Texture * charger_niveau(SDL_Window * pWindow, char * nomFNiveau, SDL_Renderer * renderer);

    void charger_personnage(SDL_Window * pWindow, char * nomFPersonnage, SDL_Renderer * renderer, t_texperso tabPerso[], int * numeroPerso,niveau_t niv);

    void Update(t_texperso tabPerso[], SDL_Window * pWindow, SDL_Renderer * rend, SDL_Texture * Texniv,int nbPerso);

    void charger_stat_perso(t_texperso tabPerso[], int catego, int numPerso);
#endif