#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *nextPtr;
};
typedef struct node List;


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
    *ptr = (List*)malloc(sizeof(List));
    (*ptr)->value = val;
    (*ptr)->nextPtr = tmpPtr;
}
/*//! INSERT SBAGLIATA !
void wrong_insert(List *ptr, int val) {
    List *tmpPtr;

    tmpPtr = ptr;
    ptr = malloc(sizeof(List));
    (ptr)->value = val;
    (ptr)->nextPtr = tmpPtr;
}

//? SECONDA VERSIONE DI pre_insert
void pre_insert(List** pptr, int val){
    struct nodo* nuovo = new_nodo(val);
    nuovo->nextPtr = *pptr;
    *pptr = nuovo;
}

//? NEW_NODO
struct nodo* new_nodo(int info){
    struct nodo *temp = (List*)malloc(sizeof(List));
    temp->value = info;
    temp->nextPtr = NULL;
    return temp;
}*/



void suf_insert(List **ptr, int val) {
    while(*ptr != NULL) {
        ptr = &((*ptr)->nextPtr);
    }
    pre_insert(ptr, val);
}
 
/*//? SECONDA VERSIONE DI suf_insert
void suf_insert(List** pptr, int val){
    struct nodo* nuovo = new_nodo(val);
    while(isempty(*pptr)==0){
        pptr = &((*pptr)->nextPtr);
    }
    *pptr = nuovo;
}
*/

void suf_insert_rec(List **ptr, int val) {
    if(*ptr != NULL) {
        suf_insert_rec(&((*ptr)->nextPtr), val);
    }
    else {
        pre_insert(ptr, val);
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
    ptr = malloc(sizeof(List));
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



// pila: push e pop

void push(List **ptr, int val) {
    // è la suf_insert già sviluppata...
    while(*ptr != NULL) {
        *ptr = (*ptr)->nextPtr;
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





void delete_list(List* ptr){
    if (ptr == NULL) return;
    delete_list(ptr->nextPtr);
    free(ptr);
}

void modifica(List** ptr, int pos, int val){
     int count=1;
    if(isempty(*ptr)==1 || pos>lung(*ptr)){
        printf("Stringa Vuota o Posizione NON valida\n");
        return -1;
    }
     else{
        while(count!=pos){
            ptr=&((*ptr)->nextPtr);
            count++;
        }
        (*ptr)->value=val;
    }
}

struct nodo* filter(List* ptr, int thres){
    struct nodo* list = NULL;

    int val;
    for(int i=0; i<lung(ptr); i++){
        val = get(ptr, i);
        if(val>=thres) suf_insert(&list, val);
    }
    return list;
}
// Data una lista di partenza, restituire una nuova lista con tutti e soli gli elementi maggiori o uguali di una certa soglia (nello stesso ordine) 

int lung(List *ptr){
    if(ptr==NULL){
        return 0;
    }
    else{
        return 1+lung(ptr->nextPtr);
    }
}

int get(List* ptr, int pos){
    int count=1;
    if(isempty(ptr)==1 || pos>lung(ptr)){
        printf("Stringa Vuota o Posizione NON valida\n");
        return -1;
    }
    else{
        while(count!=pos){
            ptr=ptr->nextPtr;
            count++;
        }
        return ptr->value;
    }
}


/*
1) Usando la struttura nodo e le funzioni scritte durante il laboratorio precedente, scrivere le seguenti funzioni:
    -struct nodo* insert(struct nodo* ptr, int pos, int info), per aggiungere un nodo in una posizione generica della lista.
	Bisogna procedere nel seguente modo:
		1- verificare se la lista è vuota, in tal caso allocare e restituire un nuovo nodo con valore info.
		2- se la lista non è vuota, verificare se il nodo va inserito nella posizione iniziale. Se si, allocare un nuovo nodo con valore info, assegnare al campo next del nuovo nodo la lista originale e restiuire il nodo appena allocato.
		3- se la posizione non è quella iniziale, percorrere la lista fino al nodo pos-1 e poi:
			3.1- allocare un nuovo nodo con valore info.
			3.2- assegnare al campo next del nuovo nodo il nodo che correntemente è in posizione pos.
			3.3- assegnare al campo next del nodo a pos-1 il nuovo nodo.
			3.4- restituire il nodo iniziale della lista.
    -struct nodo* delete(struct nodo* ptr, int pos), per eliminare un nodo in una posizione generica della lista.
	Bisogna procedere nel seguente modo:
		1- verificare se la lista è vuota, in tal caso restituire il nodo corrente (niente da eliminare).
		2- se la lista non è vuota, verificare se il nodo da eliminare è nella posizione iniziale. Se si, creare un puntatore al secondo nodo, eliminare il nodo iniziale e restituire il secondo nodo della lista originale.
		3- se la posizione non è quella iniziale, percorrere la lista fino al nodo pos-1 e poi:
			3.1- creare un puntatore al nodo in posizione pos+1.
			3.2- eliminare il nodo in posizione pos.
			3.3- assegnare al campo next del nodo a pos-1 il nodo che precedentemente era in posizione pos+1.
			3.4- restituire il nodo iniziale della lista.

2) Aggiungere le funzioni alla libreria nella cartella advanced/list

NB: rispettare le PRE e POST che sono indicate ne codice.
*/

//PRE: ptr è il primo nodo di una lista (possibilmente vuota) passato per valore, pos è una posizione valida (tra 0 e lung(ptr)-1)
List* insert(List* ptr, int pos, int info){
    struct nodo* nodo = new_nodo(info);
    if(ptr == NULL) return nodo;
    if(pos == 0){
        nodo->next = ptr;
        return nodo;
    }
    struct nodo* current = ptr;
    while(pos != 1){
        current = current->next;
        pos--;
    }
    nodo->next = current->next;
    current->next = nodo;
    return ptr;
}
//POST: restituisce il primo nodo della lista, che è quella originale, con un nodo aggiunto in posizione pos avente campo info == val

//PRE: ptr è il primo nodo di una lista (possibilmente vuota) passato per valore, pos è una posizione valida (tra 0 e lung(ptr)-1)
struct nodo* delete(struct nodo* ptr, int pos){
    if(ptr == NULL) return ptr;
    if(pos == 0){
        struct nodo* next = ptr->next;
        free(ptr);
        return next;
    }
    struct nodo* current = ptr;
    while(pos != 1){
        current = current->next;
        pos--;
    }
    struct nodo* next = current->next->next;
    free(current->next);
    current->next = next;
    return ptr;
}
//POST: restituisce il primo nodo della lista che è quella originale senza il nodo in posizione pos, che è stato eliminato


/*In questo esercizio vi chiediamo di scrivere una funzione extract che, data una lista di interi e due interi lim1 e lim2,
restituisca una lista con tutti i nodi compresi tra il nodo con campo dati == lim1 e il nodo con campo dati == lim2 se presenti all'interno della lista.
La funzione deve rispettare le PRE e POST riportate nel codice.
La lista al termine della funzione non deve più contenere i nodi tra lim1 e lim2 compresi.
Il valore lim1 è assunto essere l'inizio dell'intervallo e lim2 la fine.

ESEMPIO : lista=1 2 3 4 5 6 e lim1=2, lim2=4 -> lista=1 5 6, return=2 3 4

La firma della funzione deve essere struct nodo* extract(struct nodo** orig, int lim1, int lim2).*/

//PRE: orig è un riferimento ad una lista concatenata, lim1 e lim2 due interi presenti una o zero volte all'interno della lista (non sono ripetuti)
struct nodo* extract(struct nodo** orig, int lim1, int lim2){
    struct nodo **init = NULL, **fin = NULL;
    while(*orig != NULL){
        if(fin == NULL && init == NULL && (*orig)->info == lim1){
            init = orig;
        }
        if(init != NULL && fin == NULL && (*orig)->info == lim2){
            fin = &((*orig)->next);
        }
        orig = &((*orig)->next);
    }
    if(init != NULL && fin != NULL){
        struct nodo* tmp = *init;
        *init = *fin;
        *fin = NULL;
        return tmp;
    }
    return NULL;
}
//POST: se la lista contiene, in qualche posizione i e j con i<=j, l'intero lim1 in i e lim2 in j, ritornare la lista di nodi compresa tra i e j e modificare orig in modo
//      che tale sottolista non sia più inclusa. Altrimenti ritornare NULL e lasciare orig invariato
//      Possibilmente non allocare o eliminare nessun nodo, modificate solo i puntatori
//      ESEMPIO : lista=1 2 3 4 5 6 e lim1=2, lim2=4 -> lista=1 5 6, return=2 3 4






//?ESAME DEL 2022/23
void ord_insert(struct nodo **ptr, int val){
    if(*ptr==NULL) *ptr=(struct nodo*)malloc(sizeof(struct nodo));
    
    else{
        struct nodo* pre;
        
        if(val>(*ptr)->info){
            struct nodo* new=(struct nodo*)malloc(sizeof(struct nodo));
            new->info=val;
            new->next=*ptr;
            *ptr=new;
        }
        else{
            while( ((*ptr)->info)>val && (*ptr)->next!=NULL){
                pre=*ptr;
                ptr=&((*ptr)->next);
            }
            
            struct nodo* new=(struct nodo*)malloc(sizeof(struct nodo));
            new->info=val;
            new->next=*ptr;
            pre->next=new;
        }
    }
}