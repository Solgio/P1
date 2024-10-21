#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define COUNT 8

struct btree
{
    int valore;
    struct btree *leftPtr;
    struct btree *rightPtr;
};

typedef struct btree BST;

void init(BST **ptrPtr);
int isbst(BST *ptr);

void print_rec(BST *ptr);
void ordinsert_rec(BST **ptrPtr, int val);
void weirdinsert_rec(BST **ptrPtr, int val);

void print_bst2D_uil(BST *root, int space);
void print_bst2D(BST *root);

int main(void)
{
    BST *albero;
    init(&albero);

    // creazione di un BST
    ordinsert_rec(&albero, 2);
    ordinsert_rec(&albero, 1);
    ordinsert_rec(&albero, 0);
    ordinsert_rec(&albero, 2);
    ordinsert_rec(&albero, 6);
    ordinsert_rec(&albero, 6);
    ordinsert_rec(&albero, 9);
    ordinsert_rec(&albero, 5);
    // print_bst2D(albero);
    // printf("\nL'albero è un BST? %d\n", isbst(albero));

    // creazione di un btree non BST
    // inizializza generatore random
    time_t t;
    srand((unsigned)time(&t));
    BST *albero2;
    init(&albero2);

    weirdinsert_rec(&albero2, 2);
    weirdinsert_rec(&albero2, 1);
    weirdinsert_rec(&albero2, 0);
    weirdinsert_rec(&albero2, 3);
    weirdinsert_rec(&albero2, 7);
    weirdinsert_rec(&albero2, 5);
    weirdinsert_rec(&albero2, 9);
    // print_bst2D(albero2);
    // printf("\nL'albero è un BST? %d\n", isbst(albero2));

    // verifichiamo se il primo albero è un BST
    printf("%d ", isbst(albero));
    // verifichiamo se il secondo albero è un BST
    printf("%d ", isbst(albero2));

    return 0;
}

void init(BST **ptrPtr)
{
    *ptrPtr = NULL;
}

// restituisce 1 se l'albero è un BST, 0 altrimenti
int isbst_in_range(BST *ptr, int MIN, int MAX)
{
    if (ptr == NULL)
    {
        return 1;
    }
    else
    {
        if (ptr->valore < MIN || ptr->valore > MAX)
        {
            return 0;
        }
        else
        {
            return isbst_in_range(ptr->leftPtr, MIN, ptr->valore) && isbst_in_range(ptr->rightPtr, ptr->valore, MAX);
        }
    }
}

int isbst(BST *ptr)
{
    if (isbst_in_range(ptr, INT_MIN, INT_MAX))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// visita ricorsiva
void print_rec(BST *ptr)
{
    if (ptr != NULL)
    {
        // printf("%d ", ptr->valore); // visita in pre-ordine
        print_rec(ptr->leftPtr);
        // printf("%d ", ptr->valore); // visita simmetrica (in ordine)
        print_rec(ptr->rightPtr);
        printf("%d ", ptr->valore); // visita in post-ordine (in profondità / "depth-first")
    }
}

// inserimento in ordine (con ricorsione)
void ordinsert_rec(BST **ptrPtr, int val)
{
    if ((*ptrPtr) != NULL)
    {
        if (val <= (*ptrPtr)->valore)
            ordinsert_rec(&((*ptrPtr)->leftPtr), val);
        else
            ordinsert_rec(&((*ptrPtr)->rightPtr), val);
    }
    else
    {
        (*ptrPtr) = (BST *)malloc(sizeof(BST));
        (*ptrPtr)->valore = val;
        (*ptrPtr)->leftPtr = NULL;
        (*ptrPtr)->rightPtr = NULL;
    }
}

// inserimento che genera un albero binario non BST (con ricorsione)
void weirdinsert_rec(BST **ptrPtr, int val)
{

    int rand_val = rand();

    if ((*ptrPtr) != NULL)
    {
        if (rand_val % 2 == 0)
            weirdinsert_rec(&((*ptrPtr)->leftPtr), val);
        else
            weirdinsert_rec(&((*ptrPtr)->rightPtr), val);
    }
    else
    {
        (*ptrPtr) = (BST *)malloc(sizeof(BST));
        (*ptrPtr)->valore = val;
        (*ptrPtr)->leftPtr = NULL;
        (*ptrPtr)->rightPtr = NULL;
    }
}

// funzione di stampa/visualizzazione dell'albero
void print_bst2D_util(BST *root, int space)
{

    // Base case
    if (root == NULL)
        return;

    // Increase distance between levels
    space += COUNT;

    // Process right child first
    print_bst2D_util(root->rightPtr, space);

    // Print current node after space
    // count
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", root->valore);

    // Process left child
    print_bst2D_util(root->leftPtr, space);
}

void print_bst2D(BST *root)
{
    // Pass initial space count as 0
    print_bst2D_util(root, 0);
}