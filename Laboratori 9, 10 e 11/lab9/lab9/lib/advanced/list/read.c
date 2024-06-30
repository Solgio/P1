#include "../list.h"

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
    return (isempty(ptr)==1)? 0 : 1+lung(ptr->next);
}

int get(struct nodo* ptr, int pos){
    while(pos!=0){
        ptr = ptr->next;
        pos--;
    }
    return ptr->info;
}



