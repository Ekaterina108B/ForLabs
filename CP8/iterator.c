#include <stdio.h>
#include <stdbool.h>

#include "item.h"
#include "iterator.h"


bool Equal(const Iterator* lhs, const Iterator* rhs){
    return lhs->node == rhs->node;
}

bool NotEqual(const Iterator* lhs, const Iterator* rhs){
    return !Equal(lhs, rhs);
}

Iterator* Next(Iterator* i){
    i->node = i->node->next;
    return i;
}

unsigned int Fetch(const Iterator* i){
    return i->node->data;
}

void Store(const Iterator* i, const unsigned int t){
    i->node->data = t;
}

void StoreLinkNext(const Iterator* i, struct Item* n){
    i->node->next = n;
}
