#include <stdio.h>
// Prototipi delle funzioni
void swap_eq(int* arr, int dim, int i, int j, int n);
void swap(int* arr, int dim, int m, int n, int p);

//! SCAMBIO AREE DI UN ARRAY

//! 1) Aree di ampiezza uguali
// Implementazione di swap_eq
void swap_eq(int* arr, int dim, int i, int n,  int j) {
    if (n == 0) {
        return;
    }
    
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
    
    swap_eq(arr, dim, i + 1, n - 1 , j + 1);
}

//! 2) Aree di ampiezza diversa
// Implementazione di swap
void swap(int* arr, int dim, int m, int n, int p) {
    // Condizione di terminazione: se le porzioni sono vuote o uguali
    if (m >= n || n >= p) {
        return;
    }
    
    if (n - m == p - n) {
        // Se le due porzioni sono della stessa lunghezza, usiamo swap_eq
        swap_eq(arr, dim, m,  n - m, n);
        
    } else if (n - m < p - n) {
        // Se la prima porzione è più corta, scambiamo la parte iniziale e richiamiamo swap
        swap_eq(arr, dim, m,  n - m, n);
        swap(arr, dim, n, n + (n - m), p);
        
    } else {
        // Se la seconda porzione è più corta, scambiamo la parte finale e richiamiamo swap
        swap_eq(arr, dim, m,  p - n, n);
        swap(arr, dim, m + (p - n), n, p);
    }
}

//! RETURN 1 SE STESSI CARATTERI NELLO STESSO ORDINE CON SEGNO UGUALE
//! O OPPOSTO,           RETURN 0 ALTRIMENTI

int array_stesso_ordine(int *A, int dimA, int *B, int dimB){
    if(dimB==0){
        return 1;
    }
  
    if(dimA==0){
        return 0;
    }
  
    if(*A==*B || *A==-*B ){
        return array_stesso-ordine(A+1, dimA-1, B+1, dimB-1);
    }
    
    else{
        return array_stesso-ordine(A, dimA, B+1, dimB-1);
    }
}


//! ELIMINA GLI ELEMENTI PALINDROMI DI UN ARRAY

void eliminaPalindromi(char *A) {
    int i = 0;
    int dim = strlen(A);
    printf("%d\n", dim);

    // Spostiamo 'dim' all'ultima posizione valida dell'array
    dim--;

    // Sovrascriviamo i caratteri palindromici con un carattere speciale, ad esempio '\0'
    while (i <= (dim / 2)) {
        if (A[i] == A[dim - i]) {
            A[i] = '\0';
            A[dim - i] = '\0';
        }
        i++;
    }

    // Ricostruire la stringa senza i caratteri '\0'
    int writeIndex = 0;
    for (int j = 0; j <= dim; j++) {
        if (A[j] != '\0') {
            A[writeIndex++] = A[j];
        }
    }
    A[writeIndex] = '\0';  // Aggiungi il terminatore di stringa
}

void filter(char *A, int index){
    if(index == strlen(A)){
        A[index] = '\0';
        return;
    }

    if(*A!='\0'){
        A[index] = *A;
        filter(A+1, index+1);
    }

    else{
        filter(A+1, index);
    }

}

void eliminaPalindromiRec(char *A, int dim){
    if(dim == 0){
        int index = 0;
        filter(A, index);
        return;
    }

    if(*A == A[dim]){
        *A = '\0';
        A[dim] = '\0';
    }

 eliminaPalindromiRec(A, dim-1);
}

//!  TROVA SE SOMMA DI ELEMENTI DI UN ARRAY È UGUALE A TARGET

#include <stdio.h>

int somma(int *X, int dim, int target);

int main(void) {
    int dim = 5, target = 7;
    int X[] = {4, 5, 3, 6, 1};
    
    if (somma(X, dim, target)) {
        printf("Esiste una sequenza che somma a %d\n", target);
    } else {
        printf("Non esiste una sequenza che somma a %d\n", target);
    }

    return 0;
}

int somma(int *X, int dim, int target) {
    if (target == 0) {
        return 1;
    }
    if (target < 0 || dim == 0) {
        return 0;
    }
    return somma(X, dim, target - X[0]) || somma(X + 1, dim - 1, target);
}