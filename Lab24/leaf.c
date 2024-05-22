#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "addfuncs.h"
#include "leaf.h"

Leaf* CreateLeaf(void){
    Leaf* l = malloc(sizeof(struct Leaf));
    l->father = NULL;
    l->right = NULL;
    l->left = NULL;
    l->data_int = 0;
    l->data_char = '\0';
    l->is_oper = false;
    l->older = false;
    l->minus = false;
    return l;
}

void DeleteLeaf(Leaf* l){
    if(l->father != NULL){
	if (l->older){
            l->father->left = NULL;
	} else {
            l->father->right = NULL;
	}
    }
    l->father = NULL;
    if (l->left != NULL){
        DeleteLeaf(l->left);
    }
    if (l->right != NULL){
        DeleteLeaf(l->right);
    }
    free(l);
}

pointer_2* CreatePoint2(Leaf* e){
    pointer_2* p = (pointer_2*)malloc(sizeof(pointer_2));
    p->point = e;
    return p;
}
