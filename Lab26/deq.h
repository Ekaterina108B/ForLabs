#ifndef _DEQ_H_
#define _DEQ_H_

#include <stdbool.h>

typedef struct Item{
    int data;
    struct Item * next;
    struct Item * last;
} Item;

typedef struct deque{
    Item *left;
    Item *right;
    int size;
} deque;

deque * Create(void);
bool Empty(deque *d);
bool PushLeft(deque *d, int i);
bool PushRight(deque *d, int i);
bool PopLeft(deque *d);
bool PopRight(deque *d);
int TopLeft(deque *d);
int TopRight(deque *d);
bool Delete(deque *d);
void Print(deque *d);

#endif
