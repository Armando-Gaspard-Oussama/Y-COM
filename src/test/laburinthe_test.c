#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include "../lib/labyrinthe_niveau.h"
#include "../lib/commun.h"

int main(int argc, char *argv[]) {

  Room Map[MAX_ROWS][MAX_COL];   
  Lab_Room *Lab, *ri, *nr;
  int nb_rooms=13,nb_current_rooms=1;
  struct timeval t;

  gettimeofday(&t,0);
  srandom(t.tv_usec);

  memset(Map,0,MAX_ROWS*MAX_COL*sizeof(Room));

  if (argc > 1) { nb_rooms = atoi(argv[1]); } // nb_rooms < sqrt(MAX_ROWS)

 
  Lab = (Lab_Room *)malloc(sizeof(Lab_Room));
  Lab->pos_x=nb_rooms;
  Lab->pos_y=nb_rooms;
  Lab->next=NULL;

  while (nb_current_rooms < nb_rooms) {
	ri=rand_room(Map,Lab,nb_current_rooms);
	nr=add_door(Map,ri);
	if (nr!=NULL) {
		nr->next=Lab;
		Lab=nr;
    	nb_current_rooms++;
	}
  }	

  print_lab(Map,Lab);

  return 0;

}
