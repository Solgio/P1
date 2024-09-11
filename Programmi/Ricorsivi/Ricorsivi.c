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
    if (dim == 0)
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

// Trova il minimo elemento dispari di una lista
// Funzione per trovare il puntatore al minimo elemento dispari
struct Node *first_odd(struct Node *head)
{

    if (head == NULL)
    {
        return NULL;
    }

    // Ricorsione: ottieni il puntatore al minimo elemento dispari nei successivi nodi
    struct Node *next_odd = first_odd(head->next);
    return next_odd;
    if (head->data % 2 != 0)
    {
        if (next_odd == NULL)
        {
            return head;
        }
        else
        {
            return (head->data < next_odd->data) ? head : next_odd;
        }
    }
    else
    {
        return next_odd;
    }
}

// Cerca una combinazione in un array che somma a target
int somma(int *X, int dim, int target)
{
    if (target == 0)
    {
        return 1;
    }
    if (target < 0 || dim == 0)
    {
        return 0;
    }
    return somma(X, dim, target - X[0]) || somma(X + 1, dim - 1, target);
}

// Elimina caratteri ricorsivi
void eliminaPalindromiRec(char *A, int dim)
{
    if (dim == 0)
    {
        int index = 0;
        filter(A, index);
        return;
    }
    if (*A == A[dim])
    {
        *A = '\0';
        A[dim] = '\0';
    }
    eliminaPalindromiRec(A, dim - 1);
}

// Restituisce se gli elementi sono nello stesso ordine con lo stesso segno o segno opposto
int array_stesso_ordine(int *A, int dimA, int *B, int dimB)
{
    if (dimB == 0)
    {
        return 1;
    }

    if (dimA == 0)
    {
        return 0;
    }
    if (*A == *B || *A == -*B)
    {
        return array_stesso - ordine(A + 1, dimA - 1, B + 1, dimB - 1);
    }
    else
    {
        return array_stesso - ordine(A, dimA, B + 1, dimB - 1);
    }
}

//! SCAMBIO AREE DI UN ARRAY

//! 1) Aree di ampiezza uguali
// Implementazione di swap_eq
void swap_eq(int *arr, int dim, int i, int n, int j)
{
    if (n == 0)
    {
        return;
    }

    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
    swap_eq(arr, dim, i + 1, n - 1, j + 1);
}

//! 2) Aree di ampiezza diversa
// Implementazione di swap
void swap(int *arr, int dim, int m, int n, int p)
{
    // Condizione di terminazione: se le porzioni sono vuote o uguali
    if (m >= n || n >= p)
    {
        return;
    }
    if (n - m == p - n)
    {
        // Se le due porzioni sono della stessa lunghezza, usiamo swap_eq
        swap_eq(arr, dim, m, n - m, n);
    }
    else if (n - m < p - n)
    {
        // Se la prima porzione è più corta, scambiamo la parte iniziale e richiamiamo swap
        swap_eq(arr, dim, m, n - m, n);
        swap(arr, dim, n, n + (n - m), p);
    }
    else
    {
        // Se la seconda porzione è più corta, scambiamo la parte finale e richiamiamo swap
        swap_eq(arr, dim, m, p - n, n);
        swap(arr, dim, m + (p - n), n, p);
    }
}