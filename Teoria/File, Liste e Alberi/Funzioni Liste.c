#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node *nextPtr;
};

typedef struct node List;

// esempio lista: 17 -> 29 -> 93

void init(List **ptrPtr);
// ritorna 1 se vuota; 0 altrimenti
int isempty(List *ptr);
void print_list(List *ptr);

void pre_insert(List **ptr, int val);
void wrong_insert(List *ptr, int val);
void suf_insert(List **ptr, int val);

void ord_insert(List **ptr, int val);

// versione alternativa con return
List *pre_insert_bis(List *ptr, int val);

// funzioni ricorsive
void print_list_rec(List *ptr);
void suf_insert_rec(List **ptr, int val);

// stack (pila) e queue (coda)
void push(List **ptr, int val);
void pop(List **ptr);

int main()
{

    List *mialista; //= NULL;
    init(&mialista);
    printf("La lista è vuota? %d\n", isempty(mialista));

    // wrong_insert(&mialista, 17);
    // pre_insert(&mialista, 17);
    // suf_insert(mialista, 17);
    // printf("La lista è vuota? %d\n", isempty(mialista));

    // pre_insert(&mialista, 93);
    // pre_insert(&mialista, 29);
    // pre_insert(&mialista, 17);

    suf_insert_rec(&mialista, 93);
    suf_insert_rec(&mialista, 29);
    suf_insert_rec(&mialista, 17);

    print_list(mialista);

    return 0;
}

// liste: funzioni viste nella lezione n.1:
void init(List **ptrPtr)
{
    *ptrPtr = NULL;
}

int isempty(List *ptr)
{
    /*if(ptr == NULL)
        return 1;
    else
        return 0;*/
    return ptr == NULL;
}

void pre_insert(List **ptr, int val)
{
    List *tmpPtr;

    tmpPtr = *ptr;
    *ptr = (List *)malloc(sizeof(List));
    (*ptr)->value = val;
    (*ptr)->nextPtr = tmpPtr;
}

//! NON FUNZIONA
void wrong_insert(List *ptr, int val)
{
    List *tmpPtr;

    tmpPtr = ptr;
    ptr = (List *)malloc(sizeof(List));
    (ptr)->value = val;
    (ptr)->nextPtr = tmpPtr;
}

void suf_insert(List **ptr, int val)
{
    while (*ptr != NULL)
    {
        ptr = &((*ptr)->nextPtr);
    }
    pre_insert(ptr, val);
}

void copy(List *Original, List **Copy)
{
    if (Original->nextPtr == NULL)
    {
        return;
    }

    else
    {
        List *tmpPtr = (List *)malloc(sizeof(List));
        tmpPtr->value = Original->value;
        tmpPtr->nextPtr = NULL;
        if (Copy == NULL)
        {
            *Copy = tmpPtr;
        }
        else
        {
            (*Copy)->nextPtr = tmpPtr;
            copy(&(*(Original)->nextPtr), &(*(Copy)->nextPtr));
        }
    }
}

void copyInvert(List *Original, List **Copy)
{
    if (Original == NULL)
    {
        return;
    }

    else
    {
        pre_insert(Copy, Original->value);
        /* List *tmpPtr;
        tmpPtr = *Copy;
        *Copy = (List *)malloc(sizeof(List));
        (*Copy)->value = Original->val;
        (*Copy)->nextPtr = tmpPtr;*/
        copyInvert(Original->nextPtr, Copy);
    }
}

void print_list(List *ptr)
{
    while (ptr != NULL)
    {
        printf("%d->", ptr->value);
        ptr = ptr->nextPtr;
    }
}

// liste: funzioni viste nella lezione n.2:

List *pre_insert_bis(List *ptr, int val)
{
    List *tmpPtr;

    tmpPtr = ptr;
    ptr = (List *)malloc(sizeof(List));
    ptr->value = val;
    ptr->nextPtr = tmpPtr;
    return ptr;
}

void ord_insert(List **ptr, int val)
{
    while (*ptr != NULL && val > (*ptr)->value)
    {
        ptr = &((*ptr)->nextPtr);
    }
    pre_insert(ptr, val);
}

void print_list_rec(List *ptr)
{
    // if(!ptr) {
    if (ptr == NULL)
    {
        return;
    }
    else
    {
        printf("%d ", ptr->value);
        print_list_rec(ptr->nextPtr);
        // stampa in ordine inverso
        // printf("%d ", ptr->valore);
    }
}

void suf_insert_rec(List **ptr, int val)
{
    /* iterativa:
    while(*ptr != NULL) {
        ptr = &((*ptr)->nextPtr);
    }
    pre_insert(ptr, val);
    */
    if (*ptr != NULL)
    {
        suf_insert_rec(&((*ptr)->nextPtr), val);
    }
    else
    {
        pre_insert(ptr, val);
    }
}

// pila: push e pop

void push(List **ptr, int val)
{
    // è la suf_insert già sviluppata...
    while (*ptr != NULL)
    {
        ptr = &((*ptr)->nextPtr);
    }
    pre_insert(ptr, val);
}

void pop(List **ptr)
{

    // verifica se lista vuota
    if (isempty(*ptr))
    {
        // if(*ptr == NULL) {
        printf("La lista è vuota!\n");
    }
    else if ((*ptr)->nextPtr == NULL)
    {
        //*ptr = NULL;
        free(*ptr);
    }
    else
    {
        List *tmpPtr, *current = *ptr;

        while (current->nextPtr != NULL)
        {
            tmpPtr = current;
            current = current->nextPtr;
        }
        // cancella elemento in coda
        tmpPtr->nextPtr = NULL;
        free(current);
    }
}

// PRE: ptr è il primo nodo di una lista (possibilmente vuota) passato per valore, pos è una posizione valida (tra 0 e lung(ptr)-1)
struct nodo *insert(struct nodo *ptr, int pos, int info)
{
    struct nodo *nodo = new_nodo(info);
    if (ptr == NULL)
        return nodo;
    if (pos == 0)
    {
        nodo->next = ptr;
        return nodo;
    }
    struct nodo *current = ptr;
    while (pos != 1)
    {
        current = current->next;
        pos--;
    }
    nodo->next = current->next;
    current->next = nodo;
    return ptr;
}
// POST: restituisce il primo nodo della lista, che è quella originale, con un nodo aggiunto in posizione pos avente campo info == val

// PRE: ptr è il primo nodo di una lista (possibilmente vuota) passato per valore, pos è una posizione valida (tra 0 e lung(ptr)-1)
struct nodo *delete(struct nodo *ptr, int pos)
{
    if (ptr == NULL)
        return ptr;
    if (pos == 0)
    {
        struct nodo *next = ptr->next;
        free(ptr);
        return next;
    }
    struct nodo *current = ptr;
    while (pos != 1)
    {
        current = current->next;
        pos--;
    }
    struct nodo *next = current->next->next;
    free(current->next);
    current->next = next;
    return ptr;
}

struct nodo *delete_rec(struct nodo *ptr, int pos)
{
    if (ptr == NULL)
        return NULL;
    if (pos == 0)
    {
        struct nodo *next = ptr->next;
        free(ptr);
        return next;
    }
    if (pos == 1)
    {
        struct nodo *next_next = ptr->next->next;
        free(ptr->next);
        ptr->next = next_next;
        return ptr;
    }
    else
    {
        ptr->next = delete_rec(ptr->next, pos - 1);
        return ptr;
    }
}
// POST: restituisce il primo nodo della lista che è quella originale senza il nodo in posizione pos, che è stato eliminato

// PRE: orig è un riferimento ad una lista concatenata, lim1 e lim2 due interi presenti una o zero volte all'interno della lista (non sono ripetuti)
struct nodo *extract(struct nodo **orig, int lim1, int lim2)
{
    struct nodo **init = NULL, **fin = NULL;
    while (*orig != NULL)
    {
        if (fin == NULL && init == NULL && (*orig)->info == lim1)
        {
            init = orig;
        }
        if (init != NULL && fin == NULL && (*orig)->info == lim2)
        {
            fin = &((*orig)->next);
        }
        orig = &((*orig)->next);
    }
    if (init != NULL && fin != NULL)
    {
        struct nodo *tmp = *init;
        *init = *fin; // ricollega la lista originale
        *fin = NULL;  // separa la sottolista
        return tmp;
    }
    return NULL;
}

struct nodo *extract_rec(struct nodo **orig, int lim1, int lim2)
{
    if ((*orig)->info == NULL)
        return NULL;

    if ((*orig)->info == lim1 && *fin == NULL)

        if ((*orig)->info == lim2 && *ini != NULL)

            if (*ini != NULL && *fin != NULL)
            {
                struct nodo *tmp = *ini;
                *ini = *fin;
                *fin = NULL;
            }
}
// POST: se la lista contiene, in qualche posizione i e j con i<=j, l'intero lim1 in i e lim2 in j, ritornare la lista di nodi compresa tra i e j e modificare orig in modo
//       che tale sottolista non sia più inclusa. Altrimenti ritornare NULL e lasciare orig invariato
//       Possibilmente non allocare o eliminare nessun nodo, modificate solo i puntatori
//       ESEMPIO : lista=1 2 3 4 5 6 e lim1=2, lim2=4 -> lista=1 5 6, return=2 3 4
