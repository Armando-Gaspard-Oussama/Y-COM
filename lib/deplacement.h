#include "commun.h"
#include "niveaux.h"

int disponible(niveau_t mat, int posX, int posY);

int valides(int coord_x,int coord_y);

int est_vide(int coord_x, int coord_y, int mat[9][16]);

void simplication_mat(niveau_t mat, int simp[9][16]);

void chercher_chemin(int coordDebut_x,int coordDebut_y,int coordFin_x,int coordFin_y,int mat[9][16]);

void marquer_chemin(int xa, int ya,int mat[9][16]);

void nettoyer(int mat[9][16]);

void afficherMat(int mat[9][16]);

void afficherChemin(int mat[9][16]);

int solvemaze(int xDebut, int yDebut, int xFin, int yFin, int mat[9][16],int soluc[9][16]);