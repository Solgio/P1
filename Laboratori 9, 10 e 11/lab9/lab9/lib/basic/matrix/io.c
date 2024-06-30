#include "../matrix.h"
#include <stdio.h>

void stampa_matrice(int *M, int r, int c){
    for (int i = 0; i < r; i += 1){ 
        for (int j = 0; j < c; j += 1){ 
            printf("%d ", *(M + j + i*c));
        } 
        printf("\n"); 
    } 
}

void stampa_matrice_double(double *Matrice, int righe, int colonne){
    for (int i = 0; i < righe; i += 1){
        for (int j = 0; j < colonne; j += 1){
            printf("%lf ", *(Matrice + j + i*colonne));
        }
        printf("\n");
    }
}