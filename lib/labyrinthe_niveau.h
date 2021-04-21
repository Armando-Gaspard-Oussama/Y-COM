#define MAX_ROWS 100
#define MAX_COL 100

    /**
     * \file labyrinthe_niveau.h
     * \brief Définitions des types et fonctions relatifs aux labyrinthes de niveaux
     */

typedef struct room {
	int open_doors;
	int doors[4]; // index:  0=Nord,1=Est,2=Sud,3=Ouest
} Room;

typedef struct lab_room {
	int pos_x;
	int pos_y;
	struct lab_room *next;
} Lab_Room;
