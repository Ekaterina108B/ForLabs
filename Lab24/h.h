#ifndef _H_H_
#define _H_H_

#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "addfuncs.h"
#include "leaf.h"
#include "tree.h"

typedef struct {
    int data;
    char var;
    int count;
} Ele;

typedef struct {
    Ele* massiv[100];
    int size;
} H;

H* Create_H(void);
void Delete_H(H* h);
void scroll_to_divide(Tree* t, Leaf* l);
void factorization(H* h, int num);
void variant(Tree* t, Leaf* l);
H* Kraft_H(Tree* t, Leaf* l);
int find_data(H* h, int num);
int find_var(H* h, char c);
void U(H* h, H* ri);
H* NOD(H* le, H* ri);
H* NODPlus(H* h2, H* div, int r);
void cut(Tree* t, Leaf* l, H* h);
H* Copy_H(H* h);
void bracketing(Tree* t, Leaf* l, H* h, int elem, int rep);

#endif
