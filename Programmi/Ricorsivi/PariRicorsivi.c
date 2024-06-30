#include<stdio.h>
 int array_pari(int X[], int dim);
 int ricorrenze(int X[], int dim, int n);


int main()
{
    int X[] = {1,2,3,4,5,6,7,8,9,10};
    int dim = 10;
    int n=2;
    if(array_pari(X, dim))
        printf("Tutti pari\n");
    else
        printf("Non tutti pari\n");


    int result = ricorrenze(X, dim, n);
    printf("Le ricorrenze sono %d", result);
}



int array_pari(int X[], int dim)
{
    if(dim==0)
        return 1;

    if(X[0]%2==1)
        return 0;

 return  array_pari(X+1, dim-1);
}



int ricorrenze(int X[], int dim, int n)
{
    if(dim==0)
        return 0;

    if(X[0]==n)
        return 1+ricorrenze(X+1, dim-1, n);

    else
        return  ricorrenze(X+1, dim-1, n);
}