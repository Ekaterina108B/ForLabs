#ifndef _LEAF_H_
#define _LEAF_H_

#include "addfuncs.h"

#include <stdbool.h>

typedef struct Leaf {
    struct Leaf* father;
    struct Leaf* right;
    struct Leaf* left;
    int data_int;
    char data_char;
    bool is_oper;
    bool older;
    bool minus;
} Leaf;

typedef struct {
    Leaf* point;
} pointer_2;

Leaf* CreateLeaf(void);
void DeleteLeaf(Leaf* l);
pointer_2* CreatePoint2(Leaf* e);

#endif
