#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "deq.h"

deque * Create(void){
    deque * d = (deque*)malloc(sizeof(deque));
    d->size = 0;
    d->left = 0;
    d->right = 0;
    
    return d;
}

bool Empty(deque *d){
    if(d->size == 0){
        return true;
    }
    return false;
}

bool PushLeft(deque *d, int i){
    Item *q = 0;
    
    if(d->left){
        q = d->left;
        d->left = d->left->last;
    }
    d->left = (Item*)malloc(sizeof(Item));
    d->left->data = i;
    d->left->next = q;
    if(d->left->next){
        d->left->next->last = d->left;
    }
    d->left->last = 0;
    if(!q){
        d->right = d->left;
    }
    d->size++;
    
    return true;
}

bool PushRight(deque *d, int i){
    Item *q = 0;
    
    if(d->right != 0){
        q = d->right;
        d->right = d->right->next;
    }
    d->right = (Item*)malloc(sizeof(Item));
    d->right->data = i;
    d->right->next = 0;
    d->right->last = q;
    if(d->right->last){
        d->right->last->next = d->right;
    }
    if(!q){
        d->left = d->right;
    }
    d->size++;
    return true;
}

bool PopLeft(deque *d){
    if(Empty(d)){
        return false;
    } else if(d->size == 0){
        return false;
    }
    Item *q;
    q = d->left->next;
    free(d->left);
    d->size--;
    d->left = q;
    if(d->size == 0){
        d->right = d->left;
        return true;
    }
    d->left->last = 0;
    return true;
}

bool PopRight(deque *d){
    if(Empty(d)){
        return false;
    } else if(d->size == 0){
        return false;
    }
    Item *q;
    q = d->right->last;
    free(d->right);
    d->size--;
    d->right = q;
    if(d->size == 0){
        d->left = d->right;
        return true;
    }
    d->right->next = 0;
    return true;
}

int TopLeft(deque *d){
    if(Empty(d)){
        printf("Deque is empty, a value of 0 is returned.\n");
        return 0;
    }
    return d->left->data;
}

int TopRight(deque *d){
    if(Empty(d)){
        printf("Deque is empty, a value of 0 is returned.\n");
        return 0;
    }
    return d->right->data;
}

bool Delete(deque *d){
    if(Empty(d)){
        free(d);
        return true;
    }
    
    Item *q;
    q = d->left->next;
    free(d->left);
    d->size--;
    if(q == NULL){
        d->left = d->right = NULL;
        d->size = 0;
        free(d);
        return true;
    } else {
        d->left = q;
        d->left->last = NULL;
    }
    
    return Delete(d);
}

void Print(deque *d){
    if(Empty(d)){
        return;
    }
    
    Item *q;
    q = d->left;
    printf("[%d", q->data);
    while(q != d->right){
        q = q->next;
        printf(", %d", q->data);
    }
    printf("]\n");
}


