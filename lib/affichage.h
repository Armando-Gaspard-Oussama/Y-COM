#ifndef asd


#define asd
    #include "./commun.h"
    #include "./Struct_perso.h"
    #include "./niveaux.h"

    /**
     * \file affichage.h
     * \brief Définitions des types et des fonction relatifs à l'affichage
     * 
     */

    /**
     * \brief Structure qui contient les Texture relatives à un personnage, permet un affichage plus simple à mettre en œuvre
     */
    typedef struct s_texperso
    {
        t_pers stPerso;
        SDL_Texture * Tex;
        SDL_Texture * HP;
        SDL_Texture * Nom;
    }t_texperso;
    

    SDL_Window * creation_fenetre_renderer(char * nom, SDL_Renderer ** rend);

    SDL_Texture * charger_niveau(SDL_Window * pWindow, char * nomFNiveau, SDL_Renderer * renderer);

    void charger_personnage(SDL_Window * pWindow, char * nomFPersonnage, SDL_Renderer * renderer, t_texperso tabPerso[], int * numeroPerso,niveau_t niv, TTF_Font * font);

    void Update(t_texperso tabPerso[], SDL_Window * pWindow, SDL_Renderer * rend, SDL_Texture * Texniv,int nbPerso, TTF_Font * font);

    void charger_stat_perso(t_texperso tabPerso[], int catego, int numPerso,int posX, int posY);

    void supprimerTexturePersonnage(t_texperso tabPerso[], int * nbPerso, int numeroPerso);

    void supprimerToutPersonnage(t_texperso tabperso[], int * nbPerso);

    void toutSupprimer(t_texperso tabperso[], int * nbPerso, SDL_Window * pWindow, SDL_Renderer * rend, SDL_Texture * niv);
#endif
