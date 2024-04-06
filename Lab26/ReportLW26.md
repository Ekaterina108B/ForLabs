# Отчет по лабораторной работе № 26
## по курсу "Фундаментальная информатика"

Студент группы М8О-108Б-23 Федорова Екатерина Васильевна

Работа выполнена 

Преподаватель: каф. 806 Севастьянов Виктор Сергеевич

1. **Тема**: Алгоритмы и структуры данных.
2. **Цель работы**: Поработать с абстрактными типами данных, рекурсиями и модульным программированием.
3. **Задание (вариант №3 - 5)**:

Составить и отладить модуль определений и модуль реализации по заданной схеме модуля определений для абстрактного типа данных "дек".
Составить программный модуль, сортирующий экземпляр дека методом сортировки слиянием, используя только операции, импортированные из модуля UDT.

УКАЗАНИЯ:
- в программе по возможности должна быть использована рекурсия;
- метод сортировки реализовать с использованием указанной вспомогательной процедуры: слияние двух упорядоченных по возрастанию деков с сохранением порядка;
- использование итераторов для навигации по сериальным структурам приветствуется!
4. **Идея, метод, алгоритм решения задачи**:

Программа представляет собой консольное приложение на языке программирования C, которое реализует работу с деком. Пользователю предлагается выбрать одно из действий:
- N (New): создание нового дека,
- C (Create): добавление значений в дек,
- D (Delete): удаление значений из дека,
- F (Press F to pay respects): удаление дека,
- M (Merge): слияние двух упорядоченных по возрастанию деков с сохранением порядка,
- S (Sort): сортировки дека методом сортировки слиянием,
- P (Paint): печать дека,
- Q (Quit): выход, завершение программы.

Назначение файлов:
- lab26.h содержит объявления функций, реализующие метод сортировки и процедуру, а также вспомогательные функции: получения числа из строки, копирования дека.
- lab26.c содержит реализацию функций, объявленных в lab26.h: `GetNumber`, `Copy`, `Merge` и `SortMerge`.
- deq.h содержит объявление структур и функций, отвечающих за работу с деком.
- deq.c содержит реализацию функций, объявленных в deq.h (UDT).
- client.c представляет собой основную программу, в которой пользователь может взаимодействовать с деками, выполняя различные операции.

Некоторый анализ кода:
- `GetNumber(const char str, int index)`. Эта функция используется для извлечения числа из строки.
Принимает указатель на строку и индекс, с которого начинать поиск числа. Функция сканирует строку, начиная с указанного индекса, и извлекает первое число, на которое наталкивается.
После извлечения числа функция обновляет переданный по ссылке индекс на позицию, следующую за числом, чтобы можно было продолжить поиск следующего числа в строке.
- `deque * Copy(deque d)`. Данная функция предназначена для создания копии дека. Принимает указатель на исходный дек и создает новый дек, в который копируются все элементы из исходного дека.
Функция возвращает указатель на новый дек, являющийся копией исходного.
- `void Merge(deque d1, deque d2)`. Функция используется для слияния двух деков. Принимает указатели на два дека - d1 и d2. После выполнения этой функции все элементы из дека d2 добавляются в дек d1,
при этом порядок элементов сохраняется.
- `void SortMerge(deque d)`. Данная функция предназначена для сортировки элементов в деке. Принимает указатель на дек d и сортирует элементы в порядке возрастания.

5. **Сценарий выполнения работы**:

Текстовые запуски программы:
```
moscow@moscow:~/Рабочий стол/For Labs/ForLabs/Lab26$ make
gcc -std=c99 -pedantic -Wall -c deq.c -o deq.o
gcc -std=c99 -pedantic -Wall -c lab26.c -o lab.o
gcc -std=c99 -pedantic -Wall -o client client.c deq.o lab.o
valgrind --leak-check=yes -s ./client
==13399== Memcheck, a memory error detector
==13399== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==13399== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==13399== Command: ./client
==13399== 
N для создания нового дека,
C для добавления значений в дек,
D для удаления значений из дека,
F для удаления дека,
M для слияния двух деков,
S для сортировки дека,
P для напечатания дека,
Q для выхода.
n
Введите элементы дека №1: 1 4 8 3 7 279 8 7
[1, 4, 8, 3, 7, 279, 8, 7]
Добавлено!
N для создания нового дека,
C для добавления значений в дек,
D для удаления значений из дека,
F для удаления дека,
M для слияния двух деков,
S для сортировки дека,
P для напечатания дека,
Q для выхода.
d
Введите сторону, с которой удалять [право right/лево left]: right
Введите номер дека, из которого удалять значения: 1
Введите количество элементов для удаления: 3
[1, 4, 8, 3, 7]
Удалено!
N для создания нового дека,
C для добавления значений в дек,
D для удаления значений из дека,
F для удаления дека,
M для слияния двух деков,
S для сортировки дека,
P для напечатания дека,
Q для выхода.
d
Введите сторону, с которой удалять [право right/лево left]: left
Введите номер дека, из которого удалять значения: 1
Введите количество элементов для удаления: 2
[8, 3, 7]
Удалено!
N для создания нового дека,
C для добавления значений в дек,
D для удаления значений из дека,
F для удаления дека,
M для слияния двух деков,
S для сортировки дека,
P для напечатания дека,
Q для выхода.
n
Введите элементы дека №2: 1
[1]
Добавлено!
N для создания нового дека,
C для добавления значений в дек,
D для удаления значений из дека,
F для удаления дека,
M для слияния двух деков,
S для сортировки дека,
P для напечатания дека,
Q для выхода.
c
Введите сторону, с которой добавлять [право right/лево left]: right
Введите номер дека, в который добавлять значения: 2
Введите элементы дека (чтение произойдёт справа налево): 4 6
[1, 4, 6]
Добавлено!
N для создания нового дека,
C для добавления значений в дек,
D для удаления значений из дека,
F для удаления дека,
M для слияния двух деков,
S для сортировки дека,
P для напечатания дека,
Q для выхода.
c
Введите сторону, с которой добавлять [право right/лево left]: left
Введите номер дека, в который добавлять значения: 6 5
Дека с таким номером нет.
N для создания нового дека,
C для добавления значений в дек,
D для удаления значений из дека,
F для удаления дека,
M для слияния двух деков,
S для сортировки дека,
P для напечатания дека,
Q для выхода.
N для создания нового дека,
C для добавления значений в дек,
D для удаления значений из дека,
F для удаления дека,
M для слияния двух деков,
S для сортировки дека,
P для напечатания дека,
Q для выхода.
c
Введите сторону, с которой добавлять [право right/лево left]: left
Введите номер дека, в который добавлять значения: 2
Введите элементы дека (чтение произойдёт справа налево): 6 5
[5, 6, 1, 4, 6]
Добавлено!
N для создания нового дека,
C для добавления значений в дек,
D для удаления значений из дека,
F для удаления дека,
M для слияния двух деков,
S для сортировки дека,
P для напечатания дека,
Q для выхода.
s
Введите номер дека, который нужно отсортировать: 1
[3, 7, 8]
Дек отсортирован!
N для создания нового дека,
C для добавления значений в дек,
D для удаления значений из дека,
F для удаления дека,
M для слияния двух деков,
S для сортировки дека,
P для напечатания дека,
Q для выхода.
s
Введите номер дека, который нужно отсортировать: 2
[1, 4, 5, 6, 6]
Дек отсортирован!
N для создания нового дека,
C для добавления значений в дек,
D для удаления значений из дека,
F для удаления дека,
M для слияния двух деков,
S для сортировки дека,
P для напечатания дека,
Q для выхода.
m
Введите номер основного дека: 1
Введите номер второстепенного дека: 2
[1, 3, 4, 5, 6, 6, 7, 8]
Слияние произведено!
N для создания нового дека,
C для добавления значений в дек,
D для удаления значений из дека,
F для удаления дека,
M для слияния двух деков,
S для сортировки дека,
P для напечатания дека,
Q для выхода.
p
Количество деков: 1
Введите номер дека: 1
[1, 3, 4, 5, 6, 6, 7, 8]
N для создания нового дека,
C для добавления значений в дек,
D для удаления значений из дека,
F для удаления дека,
M для слияния двух деков,
S для сортировки дека,
P для напечатания дека,
Q для выхода.
f
Введите номер дека, который хотите удалить: 3
Дека с таким номером нет.
N для создания нового дека,
C для добавления значений в дек,
D для удаления значений из дека,
F для удаления дека,
M для слияния двух деков,
S для сортировки дека,
P для напечатания дека,
Q для выхода.
f
Введите номер дека, который хотите удалить: 1
N для создания нового дека,
C для добавления значений в дек,
D для удаления значений из дека,
F для удаления дека,
M для слияния двух деков,
S для сортировки дека,
P для напечатания дека,
Q для выхода.
p
Количество деков: 0
Введите номер дека: 0
Дека с таким номером нет.
N для создания нового дека,
C для добавления значений в дек,
D для удаления значений из дека,
F для удаления дека,
M для слияния двух деков,
S для сортировки дека,
P для напечатания дека,
Q для выхода.
q
==13399== 
==13399== HEAP SUMMARY:
==13399==     in use at exit: 0 bytes in 0 blocks
==13399==   total heap usage: 88 allocs, 88 frees, 4,112 bytes allocated
==13399== 
==13399== All heap blocks were freed -- no leaks are possible
==13399== 
==13399== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

6. **Протокол**:

client.c
```
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#include "deq.h"
#include "lab26.h"

int main(void){
    char stat = 'e';
    deque *stor[100];
    int count_dec = 0;
    
    while ((stat != 'Q') && (stat != 'q')) {
        printf("N для создания нового дека,\nC для добавления значений в дек,\nD для удаления значений из дека,\nF для удаления дека,\nM для слияния двух деков,\nS для сортировки дека,\nP для напечатания дека,\nQ для выхода.\n");
        scanf(" %c", &stat);
        
        switch(stat){
            
            case 'N':
            case 'n':
            {
                stor[count_dec] = Create();
                int val;
                int i = 0;
                char elem[100];
                printf("Введите элементы дека №%d: ", count_dec+1);
                scanf(" %[^\n]", elem);
                while ((val = GetNumber(elem, &i)) != -1){
                    PushRight(stor[count_dec], val);
                }
                Print(stor[count_dec]);
                printf("Добавлено!\n");
                count_dec++;
            }
            break;
            
            case 'C':
            case 'c':
            {
                char side[10];
                char elem[100];
                int val;
                int index;
                int i = 0;
                printf("Введите сторону, с которой добавлять [право right/лево left]: ");
                scanf("%9s", side);
                printf("Введите номер дека, в который добавлять значения: ");
                scanf("%d", &index);
                if (index > count_dec || index < 1){
                    printf("Дека с таким номером нет.\n");
                    break;
                }
                printf("Введите элементы дека (чтение произойдёт справа налево): ");
                scanf(" %[^\n]", elem);
                if(strcmp(side, "лево") == 0 || strcmp(side, "left") == 0){
                    while ((val = GetNumber(elem, &i)) != -1){
                        PushLeft(stor[index-1], val);
                    }
                } else if(strcmp(side, "право") == 0 || strcmp(side, "right") == 0){
                    while ((val = GetNumber(elem, &i)) != -1){
                        PushRight(stor[index-1], val);
                    }   
                } else {
                    printf("Неправильно введена сторона.\n");
                    break;
                }
                Print(stor[index-1]);
                printf("Добавлено!\n");
            }
            break;
            
            case 'D':
            case 'd':
            {
                char side[10];
                int val;
                int index;
                printf("Введите сторону, с которой удалять [право right/лево left]: ");
                scanf("%9s", side);
                printf("Введите номер дека, из которого удалять значения: ");
                scanf("%d", &index);
                if (index > count_dec || index < 1){
                    printf("Дека с таким номером нет.\n");
                    break;
                }
                printf("Введите количество элементов для удаления: ");
                scanf("%d", &val);
                if (val >= stor[index-1]->size){
                    Delete(stor[index-1]);
                    for(int i=index-1; i < count_dec-1; i++){
                        stor[i] = stor[i+1];
                    }
                    stor[count_dec-1] = 0;
                    count_dec--;
                    printf("Дек удалён!\n");
                    break;
                }
                
                
                if(strcmp(side, "лево") == 0 || strcmp(side, "left") == 0){
                    for(int i=0; i<val; i++){
                        PopLeft(stor[index-1]);
                    }
                } else if(strcmp(side, "право") == 0 || strcmp(side, "right") == 0){
                    for(int i=0; i<val; i++){
                        PopRight(stor[index-1]);
                    }
                } else {
                    printf("Неправильно введена сторона.\n");
                    break;
                }
                Print(stor[index-1]);
                printf("Удалено!\n");
            }
            break;
            
            case 'F':
            case 'f':
            {
                int index;
                printf("Введите номер дека, который хотите удалить: ");
                scanf("%d", &index);
                if (index > count_dec || index < 1){
                    printf("Дека с таким номером нет.\n");
                    break;
                }
                Delete(stor[index-1]);
                for(int i=index-1; i < count_dec-1; i++){
                    stor[i] = stor[i+1];
                }
                stor[count_dec-1] = 0;
                count_dec--;
            }
            break;
            
            case 'M':
            case 'm':
            {
                int index1;
                int index2;
                printf("Введите номер основного дека: ");
                scanf("%d", &index1);
                if (index1 > count_dec || index1 < 1){
                    printf("Дека с таким номером нет.\n");
                    break;
                }
                printf("Введите номер второстепенного дека: ");
                scanf("%d", &index2);
                if (index2 > count_dec || index2 < 1){
                    printf("Дека с таким номером нет.\n");
                    break;
                }
                Merge(stor[index1-1], stor[index2-1]);
                for(int i=index2-1; i < count_dec-1; i++){
                    stor[i] = stor[i+1];
                }
                stor[count_dec-1] = NULL;
                count_dec--;
                Print(stor[index1-1]);
                printf("Слияние произведено!\n");
            }
            break;
            
            case 'S':
            case 's':
            {
                int index;
                printf("Введите номер дека, который нужно отсортировать: ");
                scanf("%d", &index);
                if (index > count_dec || index < 1){
                    printf("Дека с таким номером нет.\n");
                    break;
                }
                stor[index-1] = SortMerge(stor[index-1]);
                Print(stor[index-1]);
                printf("Дек отсортирован!\n");
            }
            break;
            
            case 'P':
            case 'p':
            {
                printf("Количество деков: %d\n", count_dec);
                int index;
                printf("Введите номер дека: ");
                scanf("%d", &index);
                if (index > count_dec || index < 1){
                    printf("Дека с таким номером нет.\n");
                    break;
                }
                Print(stor[index-1]);
            }
            break;
        }
    }
    for(int i=0; i < count_dec; i++){
        Delete(stor[i]);
    }
    
    
    return 0;
}
```

deq.h
```
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
```

deq.c
```
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
```

lab26.h
```
#ifndef _LAB26_H_
#define _LAB26_H_

#include <stdbool.h>

#include "deq.h"

int GetNumber(const char *str, int *index);
deque * Copy(deque *d);
void Merge(deque *d1, deque *d2);
deque * SortMerge(deque *d);

#endif
```

lab26.c
```
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
```

7. **Замечания автора** по существу работы: я забыла реализовать функцию `Size()` из UTD, простите. Но ничего сложного в ней нет.
8. **Выводы**: Во время выполнения лабораторной работы я освоила программирование с использованием модулей, научилась выносить функции в отдельные файлы, что облегчает ориентирование по программе.
Работа заняла много времени, как и отладка, энтузиазма не было, как при выполнении 23-ей лабораторной, однако результатом довольна.
