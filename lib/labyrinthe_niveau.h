#define MAX_ROWS 100
#define MAX_COL 100

    /**
     * \file labyrinthe_niveau.h
     * \brief Définitions des types et fonctions relatifs au labyrinthe de niveau
     */

typedef struct room {
	int open_doors;
	int doors[4]; // index:  0=North,1=Est,2=South,3=West
} Room;

typedef struct lab_room {
	int pos_x;
	int pos_y;
	struct lab_room *next;
} Lab_Room;