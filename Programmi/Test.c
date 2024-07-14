#include <stdio.h>
// Prototipi delle funzioni
void swap_eq(int* arr, int dim, int i, int j, int n);
void swap(int* arr, int dim, int m, int n, int p);

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

int main(void) {
    printf("Seleziona una dimensione\n");
    int size;
    scanf("%d", &size);

    int A[size];
    int c=0;
    while(c<size){
        A[c]=c;
        c++;
    }

    for(int i=0; i<size; i++){
        printf("%d ", A[i]);
    }

    int i, n, j;
    do{
        printf("Seleziona i\n");
        scanf("%d", &i);
        printf("Seleziona n\n");
        scanf("%d", &n);
        printf("Seleziona j\n");
        scanf("%d", &j);
    }while(j+n>size || i+n>j || i<0 || n<0 || j<0);

    scambia(A, i, n, j);

    for(int i=0; i<size; i++){
        printf("%d ", A[i]);
    }
}




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