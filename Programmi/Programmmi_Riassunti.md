# Programmi

## variableVisibility.c

### Considerazioni generali

- Variabili con stesso nome ma tipo diverso sono diverse e indipendenti

- Le parentesi {} definiscono come locali quelle contenute, non esistono al di fuori di esse


ESEMPIO (`variableVisibility.c`):

```c
#include<stdio.h>

int main()
{
    int a = 10;
    {
       float a=20;
       //int a=20; printf restituisce 10
       // a=20; printf restituisce 20
    }
    
    printf("%d",a);
    return 0;
}

```
### variableVisibility3.C

- Niente di nuovo qui, `float x` è globale, `int y` invece è all'interno del main mentre `int z` è definita solo tra le ultime {}

```c
#include <stdio.h>

float x = 2.6;
int main(void) {
    int y = 2;
    {
    if (x<2)
        if (y>2)
            printf("%d ", y); 

        else
            printf("%f ", x);

    int y = 4;
    {
        int z = x * 3;  //il c tronca il float
        printf("%d", z);
    }
    }
}
```

- Importante da ricordare: il c tronca il float. `int z` assume infatti valore 7 pur essendo 7,8 (2.6*3)
## pointer_array.c

```c
void fun(int* a){
   a[1]=a[1]*2;
   a[2]=a[2]*2; 
}
int main(void) {
   int x[]={0,1,2,3,4}; 
   fun(x+2);      
   for(int i=0; i<5; i+=1) {
      printf(" %d", x[i]);
   }
   printf("\n"); 
}
```
### fun(x+2)

La funzione aumenta il valore dell'indice a qui punta il puntatore `int* a`

La funzione poi parte dal secondo valore per moltiplicarlo per 2. L'indice prò non è il 2 e 3 ma in quanto il valore è stato modificato `fun(x+2);`allora saranno modificati il 4 e 5 valore

```c
void fun(int* a){
   a[1]=a[1]*2;
   a[2]=a[2]*2; 
}
```

