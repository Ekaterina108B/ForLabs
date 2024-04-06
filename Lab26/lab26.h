#ifndef _LAB26_H_
#define _LAB26_H_

#include <stdbool.h>

#include "deq.h"

int GetNumber(const char *str, int *index);
deque * Copy(deque *d);
void Merge(deque *d1, deque *d2);
deque * SortMerge(deque *d);

#endif
