#include <stdio.h>
#include <stdlib.h>

struct nodoLista
{
    int valore;
    struct nodoLista *nextPtr;
};

typedef struct nodoLista Lista;

void suf_insert(Lista **ptrPtr, int val);
void print_list(Lista *ptr);
void intersection(Lista *list1, Lista *list2, Lista **destPtr);

int main()
{
    Lista *l1 = NULL, *l2 = NULL;

    suf_insert(&l1, 9);
    suf_insert(&l1, 5);
    suf_insert(&l1, 11);
    suf_insert(&l1, 42);
    suf_insert(&l1, 7);
    print_list(l1);

    suf_insert(&l2, 7);
    suf_insert(&l2, 13);
    suf_insert(&l2, 22);
    suf_insert(&l2, 5);
    print_list(l2);

    Lista *l3 = NULL;
    intersection(l1, l2, &l3);
    print_list(l3);

    return 0;
}

void suf_insert(Lista **ptrPtr, int val)
{
    while (*ptrPtr != NULL)
    {
        ptrPtr = &((*ptrPtr)->nextPtr);
    }
    Lista *tmpPtr = *ptrPtr;
    *ptrPtr = malloc(sizeof(Lista));
    (*ptrPtr)->valore = val;
    (*ptrPtr)->nextPtr = tmpPtr;
}

void print_list(Lista *ptr)
{
    while (ptr != NULL)
    {
        printf("%d ", ptr->valore);
        ptr = ptr->nextPtr;
    }
    printf("\n");
}

int search(int valore, Lista *list)
{
    if (list == NULL)
    {
        return 0;
    }
    if (list->valore == valore)
    {
        return 1;
    }
    else
    {
        search(valore, list->nextPtr);
    }
}

void intersection(Lista *list1, Lista *list2, Lista **destPtr)
{
    if (list1 != NULL)
    {
        if (search(list1->valore, list2))
        {
            suf_insert(destPtr, list1->valore);
        }
        intersection(list1->nextPtr, list2, destPtr);
    }
}