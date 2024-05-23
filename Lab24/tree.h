#ifndef _TREE_H_
#define _TREE_H_

#include "addfuncs.h"
#include "leaf.h"

#include <stdbool.h>

typedef struct {
    Leaf* root;
    int size;
    int count_opers;
} Tree;

Tree* CreateTree(void);
void NewRoot(Tree* t, Leaf* l);
void SplittingOper(Tree* tree, Leaf* leaf, semi_stack* exp, Index* in);
Tree* ExpressionIntoTree(semi_stack* exp);
void DeleteTree(Tree* t);
void PrintTree(Leaf* l, int len);
void Join(Leaf* l, semi_stack* s);
semi_stack* TreeIntoExpression(Tree* t);
int clean_up(Tree* t, Leaf* l);
void relocate(Leaf* e, bool x, bool y);
void copy(Leaf* l, Leaf* x);

#endif
