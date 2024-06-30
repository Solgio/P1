#include <stdio.h>
#include <stdlib.h>

//struttura
struct btree {
    int valore;
    struct btree *leftPtr;
    struct btree *rightPtr;
};
typedef struct btree BST;

//PRE: pptr è un puntatore ad un nodo di un albero BST.
void init(BST **pptr);
//POST: il nodo puntato da pptr è inizializzato con NULL.

//PRE: pptr è un puntatore alla radice di un albero BST, val è un valore da aggiungere.
void ordinsert_rec(BST **pptr, int val);
//POST: all'albero puntato da pptr è stato aggiunto un nodo con valore val nella prima 
//posizione disponibile che rispetta la regola degli alberi BST (valore dx <= parent, valore sx > parent).

//PRE: ptr è la radice di un albero BST.
unsigned int tree_depth(BST *ptr);
//POST: restituisce la profondità dell'albero. Un albero vuoto ha profondità 0, la radice ha profondità 1.

//PRE: ptr è la radice di un albero BST.
void delete_tree(BST* ptr);
//POST: l'albero puntato da ptr è stato completamente deallocato.

//PRE: ptr è la radice di un albero BST.
void print_scheme(BST *ptr);
//POST: stampa l'albero di cui ptr è la radice in modo visivo, rispettando le connessioni tra nodi.