#include "../array.h"
#include <stdio.h>

void stampa_array(int* A, int dim){
    printf("[");
    if(A != NULL & dim > 0){
        printf("%d", A[0]);
    }
    for(int i=1; i<dim; i++){
        printf(",%d", A[i]);
    }
    printf("]");
}


void stampa_array_double(double* A, int dim){
    printf("[");
    if(A != NULL & dim > 0){
        printf("%g", A[0]);
    }
    for(int i=1; i<dim; i++){
        printf(",%lf", A[i]);
    }
    printf("]");
}

void leggi_array(int* A, int dim){
    for(int i =0; i<dim; i++){
        scanf("%d", A+i);
    }
}

void leggi_array_double(double *A, int dim) {

    for(int i=0; i<dim; i+=1) {
        scanf("%lf", &A[i]);
    }
}