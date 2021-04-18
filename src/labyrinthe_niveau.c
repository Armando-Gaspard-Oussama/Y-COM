#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../lib/labyrinthe_niveau.h"
#include "../lib/commun.h"


/**
 * \fn Lab_Room *rand_room(Room m[MAX_ROWS][MAX_COL], Lab_Room *L, int n)
 * \brief Générer aléatoirement une pièce
 * \author Belkadi Oussama
 * \param m matrice de taille nombre max de ligne , max de colonne
 * \param L pointeur sur la structure b_room
 * \param n nombre de pièce dans le niveau
 */
Lab_Room *rand_room(Room m[MAX_ROWS][MAX_COL], Lab_Room *L, int n) {

	int i,j,x,y;
	Lab_Room *r;

	do {
		  i=random() % n;
		  j=0;
		  r=L;
		  while (j<i){
			r=r->next;
			j++;
		  }
		  x=r->pos_x;
		  y=r->pos_y;
    } while (m[x][y].open_doors==4);

	return(r); 
}


/**
 * \fn Lab_Room *add_door(Room m[MAX_ROWS][MAX_COL], Lab_Room *r)
 * \brief Ajouter des portes aux pièces
 * \param m matrice de taille nombre max de ligne , max de colonne
 * \param r pointeur sur la structure b_room
 */

Lab_Room *add_door(Room m[MAX_ROWS][MAX_COL], Lab_Room *r) {

	int i,j,x,y;
	int x2,y2;
	Lab_Room *new_room=NULL;

    x=r->pos_x;
    y=r->pos_y;
	x2=x;
	y2=y;

    do {
      i=random() % 4; //création d'une pièce alétoirement
    } while (m[x][y].doors[i]); // recommencer si elle existe deja


    //Ttrouver la pièce de l'autre coté
	if (i==0)      { y2++; } // Nord 
	else if (i==1) { x2++; } // Est 
	else if (i==2) { y2--; } // Sud 
	else if (i==3) { x2--; } // Ouest 

    j=(i+2)%4; // Trouver la porte opposé dans la pièce
	m[x][y].doors[i]=1; m[x2][y2].doors[j]=1;
	m[x][y].open_doors++;
	m[x2][y2].open_doors++;
	
	if (m[x2][y2].open_doors==1) { // Premièere porte dans la pièce
		new_room = (Lab_Room *)malloc(sizeof(Lab_Room));
		new_room->pos_x=x2;
		new_room->pos_y=y2;
	}

	return(new_room); // retourne la pièece créer ou NULL si elle n'a pas été créer
}

/**
 * \fn Lab_Room *add_door(Room m[MAX_ROWS][MAX_COL], Lab_Room *r)
 * \brief Afficher les pièces
 * \param m matrice de taille nombre max de ligne , max de colonne
 * \param r pointeur sur la structure b_room
 */
void print_lab(Room m[MAX_ROWS][MAX_COL], Lab_Room *r) {
	int x,y;

	do {
      x=r->pos_x;
      y=r->pos_y;
	  printf("Room (%d,%d) has %d door(s):\n",x,y,m[x][y].open_doors);
	  if (m[x][y].doors[0]) { printf ("\t porte Nord"); }
	  if (m[x][y].doors[1]) { printf ("\t porte Est"); }
	  if (m[x][y].doors[2]) { printf ("\t porte Sud"); }
	  if (m[x][y].doors[3]) { printf ("\t Porte Ouest"); }
	  printf ("\n");
	  r=r->next;
	} while (r!=NULL);

}
