#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#include "deq.h"
#include "lab26.h"  

int GetNumber(const char *str, int *index){
    int num;
    while (!isdigit(str[*index]) && str[*index] != '\n' && str[*index] != '\0') {
        (*index)++;
    }
    if (str[*index] == '\n' || str[*index] == '\0') {
        return -1;
    }
    sscanf(&str[*index], "%d", &num);
    while (isdigit(str[*index])) {
        (*index)++;
    }
    
    return num;
}

deque * Copy(deque *d){
    deque *res = Create();
    while(!Empty(d)){
        PushRight(res, TopLeft(d));
        PopLeft(d);
    }
    return res;
}

void Merge(deque *d1, deque *d2){
    deque *auxiliary = Copy(d1);
    while(!Empty(auxiliary) && !Empty(d2)){
        if(TopLeft(auxiliary) <= TopLeft(d2)){
            PushRight(d1, TopLeft(auxiliary));
            PopLeft(auxiliary);
        } else {
            PushRight(d1, TopLeft(d2));
            PopLeft(d2);
        }
    }
    while(!Empty(auxiliary)){
        PushRight(d1, TopLeft(auxiliary));
        PopLeft(auxiliary);
    }
    while(!Empty(d2)){
        PushRight(d1, TopLeft(d2));
        PopLeft(d2);
    }
    Delete(auxiliary);
    Delete(d2);
}

deque * SortMerge(deque *d){
    if(d->size <= 1){
        return d;
    }
    
    deque *left_wing = Create();
    deque *right_wing = Create();
    int middle = d->size / 2;
    
    for(int i=0; i<middle; i++){
        PushRight(left_wing, TopLeft(d));
        PopLeft(d);
    }
    while (!Empty(d)) {
        PushRight(right_wing, TopLeft(d));
        PopLeft(d);
    }
    
    left_wing = SortMerge(left_wing);
    right_wing = SortMerge(right_wing);
    Merge(left_wing, right_wing);
    
    Delete(d);
    
    return left_wing;
}
