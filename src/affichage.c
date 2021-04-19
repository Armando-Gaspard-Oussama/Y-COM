#include "../lib/affichage.h"
#include "../lib/niveaux.h"

/**
 * \file affichage.c
 * \brief Toutes les fonctions d'affichage nécessaires au projet.
 * \author Armando Costa
 * \version 1.0
 * \date 09/02/2021
 */



/**
 * \fn SDL_Window * creation_fenetre_renderer(char * nom, SDL_Renderer ** rend)
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
 * \fn void affichageHP(t_texperso tabperso[], SDL_Renderer * rend,int numPerso, TTF_Font * font)
 * \brief Affiche le nom et les HP d un personnage
 * \param tabperso tableau sur la structure pers pour stocker toutes les valeurs et les textures
 * \param render Pointeur sur le renderer ratacher a la fenetre de jeu
 * \param font Police d ecriture du nom et des HP affichées
 */

void affichageHP(t_texperso tabperso[], SDL_Renderer * rend,int numPerso, TTF_Font * font){
  SDL_Rect HPRect;
  SDL_Rect NomRect;
  SDL_Surface * textSurface;
  SDL_Surface * NomSurface;
  SDL_Color Couleur;
  
  char nombre[3]="";
  char texte[10]="HP :";
  sprintf(nombre,"%i",tabperso[numPerso].stPerso.HP);
  strcat(texte,nombre);
  
  HPRect.x = tabperso[numPerso].stPerso.pos_X*64;
  HPRect.y = tabperso[numPerso].stPerso.pos_Y*64;
  HPRect.w = 50;
  HPRect.h = 20;

  NomRect.x = (tabperso[numPerso].stPerso.pos_X*64);
  NomRect.y = (tabperso[numPerso].stPerso.pos_Y*64)+30;
  NomRect.w = 50;
  NomRect.h = 20;
 
  Couleur.r=0;
  Couleur.g=0;
  Couleur.b=0;

  textSurface = TTF_RenderText_Blended(font,texte,Couleur);
  NomSurface = TTF_RenderText_Blended(font,tabperso[numPerso].stPerso.nom,Couleur);

  tabperso[numPerso].HP= SDL_CreateTextureFromSurface(rend,textSurface);
  tabperso[numPerso].Nom = SDL_CreateTextureFromSurface(rend,NomSurface);

  SDL_FreeSurface(NomSurface);
  SDL_FreeSurface(textSurface);

  SDL_RenderCopy(rend,tabperso[numPerso].Nom,NULL,&NomRect);
  SDL_RenderCopy(rend,tabperso[numPerso].HP,NULL,&HPRect);
}

/**
 * \fn void charger_niveau(SDL_Window * pWindow, char * nomFNiveau, SDL_Renderer * renderer)
 * \brief Charge un niveau
 * \author Armando Costa
 * \param pWindow Pointeur sur la fenêtre déjà ouverte
 * \param nomFNiveau Nom de l'image du niveau
 * \param renderer Pointeur sur le renderer
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
 * \fn charger_stat_perso(t_texperso tabPerso[], int numPerso, char * nomFPerso)
 * \brief stock les informations sur les personnages dans un tableau de personnages
 * \param nomFPerso nom du fichier contenant les objets
 * \param numpPerso nombre de personnages dans le fichier
 * \param tabPerso tableau sur la structure pers pour stocker toutes les valeurs
 * \param posX Position X ou le personnage va être placé
 * \param posY Position Y ou le personnage va être placé
 */
void charger_stat_perso(t_texperso tabPerso[], int catego, int numPerso,int posX, int posY){

  FILE* fic;
  fic = fopen("../media/personnagesEtArmes/pers.txt", "r");

  t_pers pers;
  pers.pos_X=posX;
  pers.pos_Y=posY;

  int i;

  for (i=0 ; i<=catego ; i++){
    fscanf(fic,"nom : %s\npoids : %i\nattaque : %i\ndefense : %i\nHP : %i\nPA : %i\nPM : %i\ncateg : %d\n",pers.nom,&pers.poids_inv_max,&pers.attaque,&pers.defense,&pers.HP,&pers.PA,&pers.PM,&pers.categ);
  }

  tabPerso[numPerso].stPerso=pers;
    
  fclose(fic);
}

/**
 * \fn void charger_personnage(SDL_Window * pWindow, char * nomFNiveau)
 * \brief Charge un personnage
 * \author Armando Costa
 * \param pWindow Pointeur sur la fenetre deja ouverte
 * \param nomFPersonnage Nom de l image du personnage
 * \param renderer Pointeur sur le renderer ratacher a la fenetre pWindow
 * \param tabPerso tableau contenant tout les personnage ainsi que leur texture
 * \param numeroPerso Le nombre de personnage dans le tableau
 * \param niv Matrice decrivant le niveau
 * \param font Police d ecriture du nom et des HP affichées
 */
void charger_personnage(SDL_Window * pWindow, char * nomFPersonnage, SDL_Renderer * renderer, t_texperso tabPerso[], int * numeroPerso,niveau_t niv, TTF_Font * font){
  SDL_Rect imgDestRect;
  SDL_RWops *rwop=SDL_RWFromFile(nomFPersonnage,"rb");
  SDL_Surface *image;

  image = IMG_LoadPNG_RW(rwop);
  tabPerso[*numeroPerso].Tex= SDL_CreateTextureFromSurface(renderer, image);

  if(!image) {
     printf("IMG_LoadPNG_RW: %s\n", IMG_GetError());
  }
  SDL_FreeSurface(image);

  niv[tabPerso[*numeroPerso].stPerso.pos_Y][tabPerso[*numeroPerso].stPerso.pos_X]=PERSO;

  imgDestRect.x = (LARGEUR/16)* tabPerso[*numeroPerso].stPerso.pos_X;
  imgDestRect.y = (HAUTEUR/9)* tabPerso[*numeroPerso].stPerso.pos_Y;

  SDL_QueryTexture(tabPerso[*numeroPerso].Tex, NULL, NULL, &(imgDestRect.w), &(imgDestRect.h));
  SDL_RenderCopy(renderer, tabPerso[*numeroPerso].Tex, NULL, &imgDestRect);
  affichageHP(tabPerso,renderer,(*numeroPerso),font);

  SDL_RenderPresent(renderer);
  SDL_RWclose(rwop);

  (*numeroPerso)++;
}



/**
 * \fn void Update(t_texperso tabPerso[], SDL_Window * pWindow, SDL_Renderer * rend, SDL_Texture * Texniv,int nbPerso)
 * \brief Rafraichit la position des Texture correspond au personnage
 * \author Armando Costa
 * \param tabPerso tableau contenant tout les personnage ainsi que leur texture
 * \param pWindow Pointeur sur la fenetre deja ouverte
 * \param rend Pointeur sur le renderer ratacher a la fenetre pWindow
 * \param Texniv Texture du niveau
 * \param nbPerso Le nombre de personnage dans le tableau
 * \param font Police d ecriture du nom et des HP affichées
 */

void Update(t_texperso tabPerso[], SDL_Window * pWindow, SDL_Renderer * rend, SDL_Texture * Texniv,int nbPerso,TTF_Font * font){

  SDL_Rect persoPos;
  SDL_Rect nivPos;
  int i;

  SDL_RenderClear(rend);


  nivPos.x=0;
  nivPos.y=0;


  SDL_QueryTexture(Texniv,NULL,NULL,&(nivPos.w),&(nivPos.h));
  SDL_RenderCopy(rend,Texniv,NULL,&nivPos);


  for(i=0;i<nbPerso;i++){

    persoPos.x=(LARGEUR/16)*tabPerso[i].stPerso.pos_X;
    persoPos.y=(HAUTEUR/9)*tabPerso[i].stPerso.pos_Y;

    SDL_QueryTexture((tabPerso[i].Tex),NULL,NULL,&(persoPos.w),&(persoPos.h));

    SDL_RenderCopy(rend,(tabPerso[i].Tex),NULL,&persoPos);

    affichageHP(tabPerso,rend,i,font);
  }


  SDL_RenderPresent(rend);
}

/**
 * \fn void supprimerTexturePersonnage(t_texperso tabPerso[], int * nbPerso, int numeroPerso)
 * \brief Supprime toute les textures lié a un personnage
 * \param tabPerso tableau contenant tout les personnage ainsi que leur texture
 * \param nbPerso Pointeur sur le nombre total de personnage
 * \param numeroPerso Indice du personnage dans le tableau tabPerso dont on veut supprimer les Texture
 */

void supprimerTexturePersonnage(t_texperso tabPerso[], int * nbPerso, int numeroPerso){
  SDL_DestroyTexture(tabPerso[numeroPerso-1].HP);
  SDL_DestroyTexture(tabPerso[numeroPerso-1].Nom);
  SDL_DestroyTexture(tabPerso[numeroPerso-1].Tex);
  (*nbPerso)--;
}

/**
 * \fn void supprimerToutPersonnage(t_texperso tabperso[], int * nbPerso)
 * \brief Supprime les textures de tout les personnages
 * \param tabPerso tableau contenant tout les personnage ainsi que leur texture
 * \param nbPerso Pointeur sur le nombre total de personnage
 */
void supprimerToutPersonnage(t_texperso tabperso[], int * nbPerso){
  while((*nbPerso)!=0){
    supprimerTexturePersonnage(tabperso,nbPerso,(*nbPerso));
  }
}

/**
 * \fn void toutSupprimer(t_texperso tabperso[], int * nbPerso, SDL_Window * pWindow, SDL_Renderer * rend, SDL_Texture * niv)
 * \brief Supprime toute les texture, renderer et fenetre 
 * \param tabPerso tableau contenant tout les personnage ainsi que leur texture
 * \param nbPerso Pointeur sur le nombre total de personnage
 * \param pWindow Pointeur sur la fenetre de jeu
 * \param rend Pointeur sur le renderer ratacher a la fenetre pWindow
 * \param niv Pointeur sur la Texture du niveau 
 */
void toutSupprimer(t_texperso tabperso[], int * nbPerso, SDL_Window * pWindow, SDL_Renderer * rend, SDL_Texture * niv){
  SDL_DestroyTexture(niv);
  supprimerToutPersonnage(tabperso,nbPerso);
  SDL_DestroyRenderer(rend);
  SDL_DestroyWindow(pWindow);
}