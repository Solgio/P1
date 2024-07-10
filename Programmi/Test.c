#include <stdio.h>

void scambia(int A[], int i, int n, int j){
    if(n==0){
        return;
    }
    else{
        int temp=A[i];
        A[i]=A[j];
        A[j]=temp;
        scambia(A, i+1, n-1, j+1);
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