#include "../lista.h"

struct nodo* new_nodo(int info){
    struct nodo *temp =  (struct nodo*)malloc(sizeof(struct nodo));
    temp->info = info;
    temp->next = NULL;
    return temp;
}

void pre_insert(struct nodo** pptr, int val){
    struct nodo* nuovo = new_nodo(val);
    nuovo->next = *pptr;
    *pptr = nuovo;
}

void suf_insert(struct nodo** pptr, int val){
    struct nodo* nuovo = new_nodo(val);
    while(isempty(*pptr)==0){
        pptr = &((*pptr)->next);
    }
    *pptr = nuovo;
}

void delete_list(struct nodo* ptr){
    if (ptr == NULL) return;
    delete_list(ptr->next);
    free(ptr);
}

void modifica(struct nodo** ptr, int pos, int val){
     int count=1;
    if(isempty(*ptr)==1 || pos>lung(*ptr)){
        printf("Stringa Vuota o Posizione NON valida\n");
        return -1;
    }
     else{
        while(count!=pos){
            ptr=&((*ptr)->next);
            count++;
        }
        (*ptr)->info=val;
    }
}

struct nodo* filter(struct nodo* ptr, int thres){
    struct nodo* list = NULL;

    int val;
    for(int i=0; i<lung(ptr); i++){
        val = get(ptr, i);
        if(val>=thres) suf_insert(&list, val);
    }
    return list;
}
// Data una lista di partenza, restituire una nuova lista con tutti e soli gli elementi maggiori o uguali di una certa soglia (nello stesso ordine) 
