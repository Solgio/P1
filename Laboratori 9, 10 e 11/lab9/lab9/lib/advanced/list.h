#include <stdlib.h>
#include <stdio.h>

struct nodo{
    int info;
    struct nodo *next;
};

/* read.c */
// PRE: ptr è un puntatore ad una lista (possibilmente vuota)
int isempty(struct nodo* ptr);
// POST: return 1 se la lista è vuota, 0 altrimenti

// PRE: ptr è un puntatore ad una lista (possibilmente vuota)
void print_list(struct nodo* ptr);
// POST: stampa il contenuto della lista (i campi info), "Vuota" se non ci sono elementi

// PRE:  ptr è un puntatore ad una lista (possibilmente vuota)
int lung(struct nodo* ptr);
// POST: return il numero di nodi

// PRE: ptr è un puntatore ad una lista (possibilmente vuota), pos è una posizione valida (tra 0 e lung(ptr)-1)
int get(struct nodo* ptr, int pos);
// POST: return del campo info del nodo pos-esimo


/* write.c */
struct nodo* new_nodo(int info);
// POST: return di un puntatore ad un nuovo nodo (allocato dentro la funzione) con campo info

// PRE: pptr è un puntatore ad una lista (possibilmente vuota) passato per riferimento
void pre_insert(struct nodo** pptr, int val);
// POST: la lista puntata da pptr è quella originale con un nodo aggiunto "in testa" (inizio lista) avente campo info == val

// PRE: pptr è un puntatore ad una lista (possibilmente vuota) passato per riferimento
void suf_insert(struct nodo** pptr, int val);
// POST: la lista puntata da pptr è quella originale con un nodo aggiunto "in coda" (fine lista) avente campo info == val

// PRE: ptr è un puntatore ad una lista (possibilmente vuota) passata per riferimento, pos è una posizione valida (tra 0 e lung(ptr)-1)
void modifica(struct nodo** ptr, int pos, int val);
// POST: la lista puntata da ptr è uguale a quella originale ma il nodo in posizione pos ha info == val

// PRE: ptr è il primo nodo di una lista (possibilmente vuota) passata per riferimento
void delete_list(struct nodo* ptr);
// POST:la lista è stata interamente eliminata
