#include <stdlib.h>
#include <stdio.h>
#include <../lib/advanced/lista.h>

int main(){
    struct nodo *list = NULL;

    int len;
    scanf("%d", &len);

    int val;
    for(int i=0; i<len; i++){
        scanf("%d", &val);
        if(i%2==0){
            pre_insert(&list, val);
        }
        else suf_insert(&list, val);
    }
    print_list(list);
    printf("%d\n",lung(list));

    int pos;
    scanf("%d", &pos);
    printf("%d\n", get(list, pos));

    int pos2;
    scanf("%d", &pos2);
    int val2;
    scanf("%d", &val2);
    modifica(&list, pos2, val2);

    print_list(list);
    
   
}
