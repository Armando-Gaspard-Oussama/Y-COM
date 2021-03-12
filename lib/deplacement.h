typedef struct noeuds_s noeuds_t;

typedef struct noeuds_s{
    int pos_X;
    int pos_Y;
    noeuds_t * pere;
    noeuds_t * F1;
    noeuds_t * F2;
    noeuds_t * F3;
    noeuds_t * F4;
};
