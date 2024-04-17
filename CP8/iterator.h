#ifndef _ITERATOR_H_
#define _ITERATOR_H_

#include <stdbool.h>

#include "item.h"

typedef struct {
    struct Item* node;
} Iterator;

bool Equal(const Iterator* lhs, const Iterator* rhs);
bool NotEqual(const Iterator* lhs, const Iterator* rhs);
Iterator* Next(Iterator* i);
unsigned int Fetch(const Iterator* i);
void Store(const Iterator* i, const unsigned int t);
void StoreLinkNext(const Iterator* i, struct Item* n);

#endif
