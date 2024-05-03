#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "item.h"
#include "iterator.h"
#include "linli.h"

void CreateList(List* l){
    l->head = l->tail = NULL;
    l->size = 0;
}

Iterator* FirstInList(const List* l){
    Iterator* res = (Iterator*)malloc(sizeof(Iterator));;
    res->node = l->head;
    return res;
}

Iterator* LastInList(const List* l){
    Iterator* res = (Iterator*)malloc(sizeof(Iterator));;
    res->node = l->tail;
    return res;
}

bool EmptyList(const List* l){
    Iterator* fst = FirstInList(l);
    Iterator* lst = LastInList(l);
    return Equal(fst, lst);
}

int SizeList(const List* l){
    return l->size;
}

void InsertInList(List* l, Iterator* i, const unsigned int t){
    if (i->node == NULL){
        printf("Ошибка вводных данных.\n");
        return;
    }
    Iterator* res = (Iterator*)malloc(sizeof(Iterator));
    res->node  = malloc(sizeof(struct Item));
    Store(res, t);
    StoreLinkNext(res, i->node->next);
    StoreLinkNext(i, res->node);
    l->size++;
    free(res);
}

void Delete(List* l, Iterator* res){
    if (res->node == NULL){
        return;
    }
    Iterator* i = (Iterator*)malloc(sizeof(Iterator));
    i->node = res->node;
    Iterator* s = LastInList(l);
    Next(i);
    if (Equal(s, i)){
        l->tail = res->node;
        StoreLinkNext(res, NULL);
        l->size--;
    } else {
        StoreLinkNext(res, i->node->next);
        StoreLinkNext(i, NULL);
        l->size--;
    }
    free(i->node);
    free(i);
    free(s);
}

void DeleteST(List* l){
    Iterator* i = FirstInList(l);
    l->head = i->node->next;
    free(i->node);
    free(i);
    l->size--;
}

void PushInList(List* l, const unsigned int t){
    Iterator* res = (Iterator*)malloc(sizeof(Iterator));
    res->node = malloc(sizeof(struct Item));
    if(!res->node){
        printf("Error.");
        return;
    }
    Store(res, t);
    if (SizeList(l) == 0){
        StoreLinkNext(res, NULL);
        l->head = l->tail = res->node;
        l->size++;
    } else {
        Iterator* i = LastInList(l);
        StoreLinkNext(res, NULL);
        StoreLinkNext(i, res->node);
        l->tail = res->node;
        l->size++;
        free(i);
    }
    free(res);
}

void PushInListFirst(List* l, const unsigned int t){
    Iterator* res = (Iterator*)malloc(sizeof(Iterator));
    res->node = malloc(sizeof(struct Item));
    if(!res->node){
        printf("Error.");
        return;
    }
    Store(res, t);
    Iterator* i = FirstInList(l);
    StoreLinkNext(res, i->node);
    l->head = res->node;
    l->size++;
    free(i);
    free(res);
}
    
void PopInList(List* l){
    Iterator* res = LastInList(l);
    Iterator* i = SearchOneLast(l, Fetch(res));
    StoreLinkNext(i, NULL);
    l->tail = i->node;
    l->size--;
    free(res->node);
    free(res);
    free(i);
}

void Print(List* l){
    if(SizeList(l) == 0){
        printf("List is empty.");
        return;
    }
    Iterator* i = FirstInList(l);
    printf("[%u", Fetch(i));
    Next(i);
    while(i->node != NULL){
        printf(", %u", Fetch(i));
        Next(i);
    }
    printf("]\n");
    free(i);
}

void Destroy(List* l){
    Iterator* i = FirstInList(l);
    Iterator* s = LastInList(l);
    while(NotEqual(i, s)){
	Iterator* pi = (Iterator*)malloc(sizeof(Iterator));
	pi->node = i->node;
	Next(i);
	free(pi->node);
	free(pi);
    }
    free(i);
    free(s->node);
    free(s);
    l->head = NULL;
    l->tail = NULL;
    l->size = 0;
    free(l);
}

bool DeleteRange(List* l, const unsigned int start, const unsigned int stop){
    Iterator* res = FirstInList(l);
    while(res->node != NULL && Fetch(res) <= stop && start <= Fetch(res)){
        Next(res);
        DeleteST(l);
    }
    if (res->node == NULL){
        free(res);
        return false;
    }
    Iterator* d = FirstInList(l);
    Next(res);
    while(res->node != NULL){
        if (Fetch(res) <= stop && start <= Fetch(res)){
            Next(res);
            Delete(l, d);
        } else {
            Next(res);
            Next(d);
        }
    }
    free(res);
    free(d);
    return true;
}

Iterator* Search(List* l, const unsigned int t){
    Iterator* i = FirstInList(l);
    while(i->node != NULL && Fetch(i) != t ){
        Next(i);
    }
    return i;
}

Iterator* SearchOneLast(List* l, const unsigned int t){
    Iterator* i = FirstInList(l);
    if (Fetch(i) == t){
        i->node = NULL;
        return i;
    }
    Iterator* res = (Iterator*)malloc(sizeof(Iterator));
    res->node = i->node;
    Next(i);
    while(i->node != NULL && Fetch(i) != t){
        Next(i);
        Next(res);
    }
    free(i);
    return res;
}



