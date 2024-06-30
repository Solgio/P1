#include "../array.h"

int confronta_array(int* A, int* B, int dim){
    for(int i=0; i<dim; i++){
        if(A[i] != B[i]){
            return 0;
        }
    }
    return 1;
}


int confronta_array_double(double *X, double *Y, int dim, double toll) {

   for(int i=0; i<dim; i+=1) {
       if(X[i]-Y[i]>toll || X[i]-Y[i]<-toll){
        return 0;
       }
   }
   return 1;
}