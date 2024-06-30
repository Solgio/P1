#include "../tree.h"
#include <math.h>

void init(BST **pptr) {
    *pptr = NULL;
}

void ordinsert_rec(BST **pptr, int val) {
    if((*pptr) != NULL) {
        if(val<=(*pptr)->valore)
            ordinsert_rec(&((*pptr)->leftPtr), val);
        else
            ordinsert_rec(&((*pptr)->rightPtr), val);
    }    
    else {
        (*pptr) = (BST*)malloc(sizeof(BST));
        (*pptr)->valore = val;
        (*pptr)->leftPtr = NULL;
        (*pptr)->rightPtr = NULL;
    }  
}

unsigned int tree_depth(BST *ptr){
    if(ptr==NULL){
        return 0;
    }
    unsigned int d_s = 1 + tree_depth(ptr->leftPtr);
    unsigned int d_d = 1 + tree_depth(ptr->rightPtr);
    return d_s > d_d? d_s: d_d;
}

void delete_tree(BST* ptr){
    if(ptr==NULL) return;
    delete_tree(ptr->leftPtr);
    delete_tree(ptr->rightPtr);
    free(ptr);
}

void print_level_spaces(BST *ptr, unsigned int currentl, int level, unsigned int depth){
    if(ptr==NULL){
        if(currentl == 0){
            printf(" ");
        }
        else{
            print_level_spaces(NULL, currentl-1, level, depth);
            for(int i=0; i < exp2(depth-level) -1; i++){
                printf(" ");
            }
            //printf("(%d)", (depth-level)*2 +1);
            print_level_spaces(NULL, currentl-1, level, depth);
        }
    }
    else if (currentl==0){
        printf("%d", ptr->valore);
    }
    else{
        print_level_spaces(ptr->leftPtr, currentl-1, level, depth);
        for(int i=0; i < exp2(depth-level) -1; i++){
            printf(" ");
        }
        //printf("(%d)", (depth-level)*2 +1);
        print_level_spaces(ptr->rightPtr, currentl-1, level, depth);
    }
}

void print_connections(BST *ptr, unsigned int currentl, int level, unsigned int depth){
    if(ptr==NULL){
        if(currentl == 0){
            printf("  ");
            for(int i=0; i < (level == depth -2? 1: exp2(depth-level-2) -1); i++){
                printf(" ");
            }
        }
        else{
            print_connections(NULL, currentl-1, level, depth);
            for(int i=0; i < (level == depth -2? 1: exp2(depth-level-2) -1); i++){
                printf(" ");
            }
            //printf("(%d)", (depth-level)*2 +1);
            print_connections(NULL, currentl-1, level, depth);
        }
    }
    else if (currentl==0){
        if(ptr->leftPtr!=NULL){
            printf("/");
        }
        else printf(" ");
        for(int i=0; i < (level == depth -2? 1: exp2(depth-level-2) -1); i++){
            printf(" ");
        }
        if(ptr->rightPtr!=NULL){
            printf("\\");
        }
        else printf(" ");
    }
    else{
        print_connections(ptr->leftPtr, currentl-1, level, depth);
        for(int i=0; i < (level == depth -2? 1: (exp2(depth-level) + exp2(depth-1-level))/2 -1); i++){
            printf(" ");
        }
        //printf("(%d)", (depth-level)*2 +1);
        print_connections(ptr->rightPtr, currentl-1, level, depth);
    }
}

void print_scheme(BST *ptr){
    for(int i=0; i<tree_depth(ptr)-1; i++){
        for(int j=0; j < exp2(tree_depth(ptr)-1-i) -1; j++){ //d(i) = d(i+1)*2 +1 
            printf(" ");
        }
        print_level_spaces(ptr, i, i, tree_depth(ptr));
        printf("\n");
        for(int j=0; j < (i==tree_depth(ptr)-2? 0 :(exp2(tree_depth(ptr)-1-i) + exp2(tree_depth(ptr)-2-i))/2 -1); j++){ //d(i) = d(i+1)*2 +1 
            printf(" ");
        }
        print_connections(ptr, i, i, tree_depth(ptr));
        printf("\n");
    }
    print_level_spaces(ptr, tree_depth(ptr)-1, tree_depth(ptr)-1, tree_depth(ptr));
    printf("\n");
}