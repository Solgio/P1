#include <stdio.h>
int array_pari(int X[], int dim);
int ricorrenze(int X[], int dim, int n);

int main()
{
    int X[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int dim = 10;
    int n = 2;
    if (array_pari(X, dim))
        printf("Tutti pari\n");
    else
        printf("Non tutti pari\n");

    int result = ricorrenze(X, dim, n);
    printf("Le ricorrenze sono %d", result);
}

// Controlla se un array è contiene solo numeri pari
int array_pari(int X[], int dim)
{
    if (dim == 0)
        return 1;

    if (X[0] % 2 == 1)
        return 0;

    return array_pari(X + 1, dim - 1);
}

// Conta quante volte un numero n è presente nell'array
int ricorrenze(int X[], int dim, int n)
{
    if (dim == 0)
        return 0;

    if (X[0] == n)
        return 1 + ricorrenze(X + 1, dim - 1, n);

    else
        return ricorrenze(X + 1, dim - 1, n);
}

// Stampa il valore del triangolo magico in date le coordinate
int triangolo_magico(int x, int y)
{
    if (x == 0 && y == 0)
    {
        return 1;
    }

    else if (y > x || y < 0 || x < 0)
    {
        return 0;
    }

    else
    {
        return (magico(x - 1, y) + magico(x - 1, y - 1));
    }
}

// Controlla se un array è ordinato in modo crescente o decrescente, altrimenti ritorna 0
int ordinato(int X[], int dim)
{
    if (dim == 1)
    {
        return 1;
    }
    if (X[0] <= X[1])
    {
        return ordinato(X + 1, dim - 1);
    }
    if (X[dim - 1] <= X[dim - 2])
    {
        return ordinato(X + dim - 2, dim - 1);
    }
    else
        return 0;
}

// Dato un array e un numero restituisce se il numero è ottenibile sommando valori dell'array
void somma_estremi(int *A, int dim, int *somma)
{
    0 if (dim == 0)
    {
        *somma = *somma + 0;
    }

    else if (dim == 1)
    {
        *somma = *somma + *(A) * *(A);
    }

    else if (dim >= 2)
    {
        *somma = *somma + (*(A)) * (*(A + dim - 1));
        somma_estremi(A + 1, dim - 2, somma);
    }
}

// Data una matrice, un campo, calcola se esiste un percorso per raggiungere (basso verso alto, destra) il campo senza passare per campi con valore 0
int campo_fiorito(int dim_x, int dim_y, int campo[dim_x][dim_y], int pos_x, int pos_y)
{

    if ((pos_x < 0) || (pos_y < 0) || (pos_y >= dim_y) || (pos_x >= dim_x))
    {
        return 0;
    }

    if (campo[pos_x][pos_y] == 0)
    {
        return 0;
    }

    if (pos_x == 0)
    {
        return 1;
    }

    return ((mossa(dim_x, dim_y, campo, pos_x - 1, pos_y)) || (mossa(dim_x, dim_y, campo, pos_x, pos_y + 1)));
}

// Converte da decimale a binario
int converti_binario(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else
    {

        return (10 * converti_binario(n / 2) + n % 2);
    }
}

// Confronta due stringhe, facendo riferimento al loro ordine alfabetico(es: a<b; confronti numerici)
int confronta_stringhe(char *s1, char *s2)
{
    if (((int)*s1 < (int)*s2) || (*s1 == '\0' && *s2 != '\0'))
    {
        return -1;
    }

    else if (((int)*s2 < (int)*s1) || (*s2 == '\0' && *s1 != '\0'))
    {
        return 1;
    }

    else if (*s1 == '\0' && *s2 == '\0')
    {
        return 0;
    }

    else
    {
        return (confronta_stringhe(s1 + 1, s2 + 1));
    }
}
