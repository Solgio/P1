#include "../lista.h"

int isempty(struct nodo* ptr){
    return ptr==NULL? 1: 0;
}

void print_list(struct nodo* ptr){
    if(isempty(ptr)==1){
        printf("Vuota\n");
    }
    else{
        while(isempty(ptr)==0){
            printf("%d ", ptr->info);
            ptr = ptr->next;
        }
        printf("\n");
    }
}

int lung(struct nodo* ptr){
    if(ptr==NULL){
        return 0;
    }
    else{
        return 1+lung(ptr->next);
    }
}

int get(struct nodo* ptr, int pos){
    int count=1;
    if(isempty(ptr)==1 || pos>lung(ptr)){
        printf("Stringa Vuota o Posizione NON valida\n");
        return -1;
    }
    else{
        while(count!=pos){
            ptr=ptr->next;
            count++;
        }
        return ptr->info;
    }
}