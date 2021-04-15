#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
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
		  //printf("rand_room: %d\n",i);
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
      i=random() % 4; // Random door creation
    } while (m[x][y].doors[i]); // repeat if already existing


    // Find the room on the other side
	if (i==0)      { y2++; } // North 
	else if (i==1) { x2++; } // Est 
	else if (i==2) { y2--; } // South 
	else if (i==3) { x2--; } // West 

    j=(i+2)%4; // Find the opposite door on the other room
	m[x][y].doors[i]=1; m[x2][y2].doors[j]=1;
	//printf("Add door %d, on Room(%d,%d)\n",i,x,y);
	//printf("Add door %d, on Room(%d,%d)\n",j,x2,y2);
	m[x][y].open_doors++;
	m[x2][y2].open_doors++;
	
	if (m[x2][y2].open_doors==1) { // First door in that room
		//printf("Create Room(%d,%d)\n",x2,y2);
		new_room = (Lab_Room *)malloc(sizeof(Lab_Room));
		new_room->pos_x=x2;
		new_room->pos_y=y2;
	}

	return(new_room); // return new room created or NULL
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


int main(int argc, char *argv[]) {

  Room Map[MAX_ROWS][MAX_COL];   
  Lab_Room *Lab, *ri, *nr;
  int nb_rooms=13,nb_current_rooms=1;
  struct timeval t;

  gettimeofday(&t,0);
  srandom(t.tv_usec);

  memset(Map,0,MAX_ROWS*MAX_COL*sizeof(Room));

  if (argc > 1) { nb_rooms = atoi(argv[1]); } // check nb_rooms < sqrt(MAX_ROWS)

  //printf("nb rooms = %d\n",nb_rooms);
 
  Lab = (Lab_Room *)malloc(sizeof(Lab_Room));
  Lab->pos_x=nb_rooms;
  Lab->pos_y=nb_rooms;
  Lab->next=NULL;

  while (nb_current_rooms < nb_rooms) {
	ri=rand_room(Map,Lab,nb_current_rooms);
	nr=add_door(Map,ri);
	if (nr!=NULL) {
		//printf("Adding new Room(%d,%d) to Room list\n",nr->pos_x,nr->pos_y);
		nr->next=Lab;
		Lab=nr;
    	nb_current_rooms++;
	}
  }	

  print_lab(Map,Lab);

  return 0;

}
