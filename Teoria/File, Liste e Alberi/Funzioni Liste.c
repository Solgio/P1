#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *nextPtr;
};

typedef struct node List;

//esempio lista: 17 -> 29 -> 93

void init(List **ptrPtr);
// ritorna 1 se vuota; 0 altrimenti
int isempty(List *ptr);
void print_list(List *ptr);

void pre_insert(List **ptr, int val); 
void wrong_insert(List *ptr, int val); 
void suf_insert(List **ptr, int val);

void ord_insert(List **ptr, int val);

// versione alternativa con return
List* pre_insert_bis(List *ptr, int val);

// funzioni ricorsive
void print_list_rec(List *ptr);
void suf_insert_rec(List **ptr, int val); 

// stack (pila) e queue (coda)
void push(List **ptr, int val);
void pop(List **ptr);

int main() {

    List *mialista; //= NULL;
    init(&mialista);
    printf("La lista è vuota? %d\n", isempty(mialista));

    //wrong_insert(&mialista, 17);
    //pre_insert(&mialista, 17);    
    //suf_insert(mialista, 17);
    //printf("La lista è vuota? %d\n", isempty(mialista));

    //pre_insert(&mialista, 93);
    //pre_insert(&mialista, 29);
    //pre_insert(&mialista, 17);
    
    suf_insert_rec(&mialista, 93);
    suf_insert_rec(&mialista, 29);
    suf_insert_rec(&mialista, 17);    
    
    print_list(mialista);
    
    return 0;
}

// liste: funzioni viste nella lezione n.1:

void init(List **ptrPtr) {
    *ptrPtr = NULL;
}

int isempty(List *ptr) {
    /*if(ptr == NULL)
        return 1;
    else
        return 0;*/
    return ptr == NULL;
}

void pre_insert(List **ptr, int val) {
    List *tmpPtr;

    tmpPtr = *ptr;
    *ptr = (List *)malloc(sizeof(List));
    (*ptr)->value = val;
    (*ptr)->nextPtr = tmpPtr;
}

//! NON FUNZIONA
void wrong_insert(List *ptr, int val) {
    List *tmpPtr;

    tmpPtr = ptr;
    ptr = (List *)malloc(sizeof(List));
    (ptr)->value = val;
    (ptr)->nextPtr = tmpPtr;
}

void suf_insert(List **ptr, int val) {
    while(*ptr != NULL) {
        ptr = &((*ptr)->nextPtr);
    }
    pre_insert(ptr, val);
}



void copy(List *Original, List **Copy){
    if(Original->nextPtr == NULL){
        return;
    }

    else{
        List* tmpPtr = (List *)malloc(sizeof(List));
        tmpPtr->value = Original->value;
        tmpPtr->nextPtr = NULL;
        if(Copy == NULL){
            *Copy = tmpPtr;
        }
        else{
            (*Copy)->nextPtr = tmpPtr;
            copy(&(*(Original)->nextPtr), &(*(Copy)->nextPtr));
        }
    }
}

void copyInvert(List *Original, List **Copy){
    if(Original->nextPtr == NULL){
        return;
    }

    else{
        pre_insert(Copy, Original->value);
        List* tmp=(List*)malloc(sizeof(List));
        tmp->value = Original->value;
        tmp->nextPtr = *Copy;
        copyInvert(Original->nextPtr, Copy);
    }
}

void print_list(List *ptr) {
    while(ptr != NULL) {
        printf("%d ", ptr->value);
        ptr = ptr->nextPtr;
    }
}

// liste: funzioni viste nella lezione n.2:

List* pre_insert_bis(List *ptr, int val) {
    List *tmpPtr;

    tmpPtr = ptr;
    ptr = (List *)malloc(sizeof(List));
    ptr->value = val; 
    ptr->nextPtr = tmpPtr;
    return ptr;
}

void ord_insert(List **ptr, int val){
    while(*ptr != NULL && val > (*ptr)->value) {
        ptr = &((*ptr)->nextPtr);
    }
    pre_insert(ptr, val);   
}

void print_list_rec(List *ptr) {
    //if(!ptr) {
    if(ptr == NULL) {
        return;
    }    
    else {    
        printf("%d ", ptr->value);
        print_list_rec(ptr->nextPtr);
        // stampa in ordine inverso
        //printf("%d ", ptr->valore);
    }
}

void suf_insert_rec(List **ptr, int val) {
    /* iterativa:
    while(*ptr != NULL) {
        ptr = &((*ptr)->nextPtr);
    }
    pre_insert(ptr, val);
    */
    if(*ptr != NULL) {
        suf_insert_rec(&((*ptr)->nextPtr), val);
    }
    else {
        pre_insert(ptr, val);
    }
}

// pila: push e pop

void push(List **ptr, int val) {
    // è la suf_insert già sviluppata...
    while(*ptr != NULL) {
        ptr = &((*ptr)->nextPtr);
    }
    pre_insert(ptr, val);
}

void pop(List **ptr){

    // verifica se lista vuota
    if(isempty(*ptr)) {
    //if(*ptr == NULL) {
        printf("La lista è vuota!\n");
    }
    else if((*ptr)->nextPtr == NULL) {
        //*ptr = NULL;    
        free(*ptr);
    }
    else {    
        List *tmpPtr, *current = *ptr;
        
        while(current->nextPtr != NULL) {
            tmpPtr = current;
            current = current->nextPtr;
        }
        // cancella elemento in coda
        tmpPtr->nextPtr = NULL;
        free(current);
    }
}