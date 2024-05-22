#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "addfuncs.h"
#include "leaf.h"
#include "tree.h"
#include "h.h"

H* Create_H(void){
    H* h = (H*)malloc(sizeof(H));
    for(int e=0; e<100; e++){
    	h->massiv[e] = (Ele*)malloc(sizeof(Ele));
    	h->massiv[e]->data = 0;
    	h->massiv[e]->var = '\0';
    	h->massiv[e]->count = 0;
    }
    h->size = 0;
    return h;
}

void Delete_H(H* h){
    for (int e=0; e<100; e++){ free(h->massiv[e]); }
    free(h);
}

void scroll_to_divide(Tree* t, Leaf* l){
    if (l->data_char != '/'){
    	if (l->left != NULL) { scroll_to_divide(t, l->left); }
    	if (l->right != NULL) { scroll_to_divide(t, l->right); }
    } else {
    	variant(t, l);
    }
}

void factorization(H* h, int num){
    int div = 2;
    while(num > 1){
    	if (num%div==0){
    	    h->massiv[h->size]->data = div;
    	    h->massiv[h->size]->count++;
    	    num /= div;
    	} else {
    	    div++;
    	    if (h->massiv[h->size] != 0) { h->size++; }
    	}
    }
    h->size++;
}

void variant(Tree* t, Leaf* l){
    H* right = Kraft_H(t, l->right);
    H* left = Kraft_H(t, l->left);
    H* res = NOD(right, left);
    H* res2 = Copy_H(res);
    for (int i=0; i<res->size; i++){
    	printf("[%d, %c, count = %d], ", res->massiv[i]->data, res->massiv[i]->var, res->massiv[i]->count);
    }
    printf("\n");
    for (int i=0; i<res2->size; i++){
    	printf("[%d, %c, count = %d], ", res2->massiv[i]->data, res2->massiv[i]->var, res2->massiv[i]->count);
    }
    printf("\n");
    cut(t, l->left, res);
    cut(t, l->right, res2);
    Delete_H(res);
    Delete_H(res2);
    clean_up(t, l);
}

H* Kraft_H(Tree* t, Leaf* l){
    if (!l->is_oper){
    	H* h = Create_H();
    	if (l->data_char == '\0'){
    	    if (l->data_int < 0){ factorization(h, -(l->data_int)); }
    	    else { factorization(h, l->data_int); }
    	} else {
    	    h->massiv[0]->var = l->data_char;
    	    h->massiv[0]->count++;
    	    h->size++;
    	}
    	return h;
    } else {
    	if (l->data_char == '^'){
    	    H* h = Kraft_H(t, l->right);
    	    int rep = l->left->data_int;
    	    if (l->right->is_oper){
    	    	H* h2 = Copy_H(h);	
    	    	bracketing(t, l, h2, 0, l->left->data_int);
    	    	Delete_H(h2);
    	    }
    	    for (int i=0; i<h->size; i++){
    		printf("[%d, %c, count = %d]: ", h->massiv[i]->data, h->massiv[i]->var, h->massiv[i]->count);
    	    }
    	    printf("%d %c", l->left->data_int, l->left->data_char); 
    	    for (int i=0; i<h->size; i++){ h->massiv[i]->count *= rep; }
    	    for (int i=0; i<h->size; i++){
    		printf("[%d, %c, count = %d]: ", h->massiv[i]->data, h->massiv[i]->var, h->massiv[i]->count);
    	    }
    	    printf("\n");
    	    return h;
    	} else if (l->data_char == '*'){
    	    H* h = Kraft_H(t, l->left);
    	    H* ri = Kraft_H(t, l->right);
    	    U(h, ri);
    	    return h;
    	} else if (l->data_char == '/'){
    	    variant(t, l);
    	    H* h = Kraft_H(t, l->right);
    	    return h;
    	} else if (l->data_char == '+' || l->data_char == '-'){
    	    H* le = Kraft_H(t, l->left);
    	    H* ri = Kraft_H(t, l->right);
    	    H* h = NOD(le, ri);
    	    return h;
    	} else if (l->data_char == '~'){
    	    H* h = Kraft_H(t, l->left);
    	    return h;
    	}
    }
    return Create_H();
}

int find_data(H* h, int num){
    for(int i=0; i<h->size; i++){
    	if(h->massiv[i]->data == num){ return i; }
    }
    return -1;
}

int find_var(H* h, char c){
    for(int i=0; i<h->size; i++){
    	if(h->massiv[i]->var == c){ return i; }
    }
    return -1;
}

void U(H* h, H* ri){
    int elem;
    for(int i=0; i<ri->size; i++){
    	if(ri->massiv[i]->var == '\0') { elem = find_data(h, ri->massiv[i]->data); }
    	else { elem = find_var(h, ri->massiv[i]->var); }
    	if (elem == -1){
    	    h->massiv[h->size]->data = ri->massiv[i]->data;
    	    h->massiv[h->size]->var = ri->massiv[i]->var;
    	    h->massiv[h->size]->count = ri->massiv[i]->count;
    	    h->size++;
    	} else {
    	    h->massiv[elem]->count += ri->massiv[i]->count;
    	}
    }
    Delete_H(ri);
}

H* NOD(H* le, H* ri){
    H* h = Create_H();
    int elem;
    for (int i=0; i<ri->size; i++){
    	if(ri->massiv[i]->var == '\0') { elem = find_data(le, ri->massiv[i]->data); }
    	else { elem = find_var(le, ri->massiv[i]->var); }
    	if (elem == -1){ continue; }
    	else {
    	    h->massiv[h->size]->data = ri->massiv[i]->data;
    	    h->massiv[h->size]->var = ri->massiv[i]->var;
    	    if (le->massiv[elem]->count > ri->massiv[i]->count) { h->massiv[h->size]->count = ri->massiv[i]->count; }
    	    else { h->massiv[h->size]->count = le->massiv[elem]->count; }
    	    h->size++;
    	}
    }
    Delete_H(le);
    Delete_H(ri);
    return h;
}

H* NODPlus(H* h2, H* div, int r){
    H* h = Create_H();
    int elem;
    for (int i=0; i<div->size; i++){
    	if(div->massiv[i]->var == '\0') { elem = find_data(h2, div->massiv[i]->data); }
    	else { elem = find_var(h2, div->massiv[i]->var); }
    	if (elem == -1){ continue; }
    	else {
    	    h->massiv[h->size]->data = div->massiv[i]->data;
    	    h->massiv[h->size]->var = div->massiv[i]->var;
    	    if (h2->massiv[elem]->count > r*div->massiv[i]->count) { h->massiv[h->size]->count = div->massiv[i]->count; }
    	    else { h->massiv[h->size]->count = h2->massiv[elem]->count/r; }
    	    h->size++;
    	}
    }
    Delete_H(h2);
    Delete_H(div);
    return h;
}

void cut(Tree* t, Leaf* l, H* h){
    if (!l->is_oper){
    	if (l->data_char == '\0'){
    	    int i=0;
    	    while(i<h->size){
    	    	if(h->massiv[i]->data != 0){
    	    	if(l->data_int%h->massiv[i]->data==0 && h->massiv[i]->count > 0){
    	    	    l->data_int /= h->massiv[i]->data;
    	    	    h->massiv[i]->count--;
    	    	} else { i++; }
    	    } else { i++; }
    	    }
    	} else {
    	    int elem = find_var(h, l->data_char);
    	    if (elem != -1){
    	    	if (h->massiv[elem]->count > 0){
    	    	    l->data_char = '\0';
    	    	    if(l->minus){ l->data_int = -1; }
    	    	    else { l->data_int = 1; }
    	    	    l->minus = false;
    	    	    h->massiv[elem]->count--;
    	    	}
    	    }
    	}
    } else {
    	if (l->data_char == '^'){
    	    if (!l->right->is_oper){
    	    	int elem;
    	    	if (l->right->data_char == '\0'){ elem = find_data(h, l->right->data_int); }
    	    	else { elem = find_var(h, l->right->data_char); }
    	    	if (elem == -1){ return; }
    	    	if(h->massiv[elem]->count > l->left->data_int){
    	    	    h->massiv[elem]->count -= l->left->data_int;
    	    	    l->left->data_int = 0;
    	    	} else {
    	    	    l->left->data_int -= h->massiv[elem]->count;
    	    	    h->massiv[elem]->count = 0;
    	    	}
    	    } else { return; }
    	} else if (l->data_char == '*'){
    	    cut(t, l->left, h);
    	    cut(t, l->right, h);
    	} else if (l->data_char == '/'){
    	    cut(t, l->right, h);
    	} else if (l->data_char == '+' || l->data_char == '-'){
    	    H* h2 = Copy_H(h);
    	    cut(t, l->left, h);
    	    cut(t, l->right, h2);
    	    Delete_H(h2);
    	} else if (l->data_char == '~'){
    	    cut(t, l->left, h);
    	}
    }
}

H* Copy_H(H* h){
    H* h2 = Create_H();
    for(int i=0; i<h->size; i++){
    	h2->massiv[i]->data = h->massiv[i]->data;
    	h2->massiv[i]->var = h->massiv[i]->var;
    	h2->massiv[i]->count = h->massiv[i]->count;
    }
    h2->size = h->size;
    return h2;
}

void bracketing(Tree* t, Leaf* l, H* h, int elem, int rep){
    if (elem >= h->size){ return; }
    if (elem == 0){ cut(t, l->right, h); }
    l->minus = false;
    l->data_char = '*';
    l->left->is_oper = true;
    l->left->data_char = '^';
    l->left->data_int = 0;
    l->left->right = CreateLeaf();
    l->left->right->father = l->left;
    l->left->right->data_char = h->massiv[elem]->var;
    l->left->right->data_int = h->massiv[elem]->data;
    l->left->left = CreateLeaf();
    l->left->left->older = true;
    l->left->left->data_int = rep;
    l->left->left->father = l->left;
    
    l->right->father = CreateLeaf();
    l->right->father->right = l->right;
    l->right->father->is_oper = true;
    l->right->father->data_char = '^';
    l->right->father->father = l;
    l->right = l->right->father;
    l->right->left = CreateLeaf();
    l->right->left->older = true;
    l->right->left->data_int = rep;
    l->right->left->father = l->right;
    
    bracketing(t, l->right, h, elem+1, rep);
}





