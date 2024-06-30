#include <advanced/lista.h>
#include <stdlib.h>
#include <stdio.h>
/* Il seguente esercizio richiede la creazione di una funzione che filtra una lista creandone una nuova 
* con tutti e soli gli elementi, nello stesso ordine,che hanno un campo val maggiore o uguale a un certo 
* valore (la firma della funzione non è fornita).
*/

// filter(...)
void filter(struct nodo* ptr, struct nodo** nuova_lista, int thres);
/*Data una lista di partenza, restituire una nuova lista con tutti e soli gli elementi maggiori o uguali 
di una certa soglia (nello stesso ordine) */

void precise_delete(struct nodo** ptr,  int pos);

int main(){
	struct nodo* list = NULL;

    int len;
    scanf("%d", &len);

    int val;
    for(int i=0; i<len; i++){
        scanf("%d", &val);
        suf_insert(&list, val);
    }
    print_list(list);

    int thres;
    scanf("%d", &thres);
    
    //filtra qui
    struct nodo* nuova_lista = filter(list, &nuova_lista, thres);

    print_list(nuova_lista);

    //precise_delete
    int pos;
    scanf("%d", &pos);

    
}

void filter(struct nodo* ptr, struct nodo** nuova_lista, int thres){
    if(ptr==NULL){
        return;
    }
    if((ptr->info)>=thres){
        suf_insert(nuova_lista, ptr->info);
        return filter(ptr->next, nuova_lista, thres);
    }
    else{
         return filter(ptr->next, nuova_lista, thres);
    }
}

void precise_delete(struct nodo** ptr,  int pos){
    if(pos==0){
       
    }
    else{
         return precise_delete(&(*(ptr)->next), pos--);
    }
}

