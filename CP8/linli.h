#ifndef _LINLI_H_
#define _LINLI_H_

#include <stdbool.h>

#include "item.h"
#include "iterator.h"

typedef struct{
    struct Item* head;
    struct Item* tail;
    int size;
} List;

void CreateList(List* l);
Iterator* FirstInList(const List* l);
Iterator* LastInList(const List* l);
bool EmptyList(const List* l);
int SizeList(const List* l);
void InsertInList(List* l, Iterator* i, const unsigned int t);
void Delete(List* l, Iterator* i);
void DeleteST(List* l);
void PushInList(List* l, const unsigned int t);
void PushInListFirst(List* l, const unsigned int t);
void PopInList(List* l);
void Print(List* l);
void Destroy(List* l);
bool DeleteRange(List* l, const unsigned int start, const unsigned int stop);
Iterator* Search(List* l, const unsigned int t);
Iterator* SearchOneLast(List* l, const unsigned int t);

#endif
