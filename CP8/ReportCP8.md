# Отчет по лабораторной работе № 8
## по курсу "Фундаментальная информатика"

Студент группы М8О-108Б-23 Федорова Екатерина Васильевна

Работа выполнена 

Преподаватель: каф. 806 Севастьянов Виктор Сергеевич

1. **Тема**: Инструментальные средства UNIX, алгоритмы и структуры данных.
2. **Цель работы**: Линейные списки.
3. **Задание (вариант №7-2-7)**:

Составить и отладить программу на языке Си для обработки линейного списка с отображением списка на динамические структуры. Навигацию по списку следует реализовать с применением итераторов.
Предусмотреть выполнение одного нестандартного и четырех стандартных действий:
1. Печать списка.
2. Вставка нового элемента в список.
3. Удаление элемента из списка.
4. Подсчет длины списка.

Тип элемента списка: машинное слово (unsigned int).

Вид списка: линейный однонаправленный.

Нестандартное действие: удалить элементы списка со значениями, находящимися в заданном диапазоне.

4. **Идея, метод, алгоритм решения задачи**:

Файл iterator.h содержит описание интерфейса итератора. В нем объявляется структура Iterator, которая содержит указатель на элемент Item. Также объявлены функции:
- `Equal`: сравнивает два итератора и возвращает true, если они указывают на один и тот же элемент, иначе false.
- `NotEqual`: возвращает true, если два итератора указывают на разные элементы, иначе false.
- `Next`: переходит к следующему элементу в итераторе.
- `Fetch`: возвращает данные текущего элемента, на который указывает итератор.
- `Store`: сохраняет значение в данных текущего элемента, на который указывает итератор.
- `StoreLinkNext`: устанавливает следующий элемент для текущего элемента, на который указывает итератор.

Файл iterator.c содержит определения этих функций. Функции реализованы следующим образом:

Файл item.h содержит объявление структуры Item, которая представляет элемент содержимого для использования в итераторе. Структура содержит указатель на следующий элемент того же типа и целочисленное значение данных текущего элемента.

Файлы linli.h и linli.c содержат реализацию работы с однонаправленным линейным списком (linked list). 
- `CreateList(List* l):` функция создает новый пустой список с указателями на начало и конец равными NULL, а также инициализирует размер списка нулем.
- `FirstInList(const List* l):` возвращает итератор на первый элемент списка l.
- `LastInList(const List* l):` возвращает итератор на последний элемент списка l.
- `EmptyList(const List* l):` возвращает true, если список пуст, иначе false.
- `SizeList(const List* l):` возвращает количество элементов в списке l.
- `InsertInList(List* l, Iterator* i, const unsigned int t):` вставляет новый элемент со значением t после элемента, на который указывает итератор i.
- `Delete(List* l, Iterator* res):` удаляет элемент, на который указывает итератор res, из списка l.
- `DeleteST(List* l):` удаляет первый элемент списка l.
- `PushInList(List* l, const unsigned int t):` добавляет новый элемент в конец списка l.
- `PushInListFirst(List* l, const unsigned int t):` добавляет новый элемент в начало списка l.
- `PopInList(List* l):` удаляет последний элемент из списка l.
- `Print(List* l):` выводит содержимое списка l на экран.
- `Destroy(List* l):` удаляет все элементы списка l и освобождает память.
- Функции `DeleteRange` и `DeleteRangeST` удаляют диапазон элементов из списка по заданным итераторам.
- Функции `Search` и `SearchOneLast` выполняют поиск элемента в списке и возвращают итератор на найденный элемент.

Файл "cp8.c" содержит исходный код программы, которая работает с динамическим списком, позволяя пользователю создавать, изменять и удалять элементы из списка.
1. В программе используются следующие заголовочные файлы: <stdio.h>, <stdbool.h>, <stdlib.h>, <ctype.h>, а также пользовательские заголовочные файлы "item.h", "iterator.h" и "linli.h".
2. Определена функция GetNumber, которая извлекает числовое значение из строки, переданной в качестве аргумента, начиная с указанного индекса. Функция читает число из строки и обновляет индекс до следующего символа после числа.
3. В функции main реализован цикл, в котором предлагается пользователю выбирать действия для работы с динамическим списком:
- Создание нового списка с возможностью добавления элементов.
- Добавление значений в список: в конец, после указанного значения, в начало.
- Удаление значений из списка: с конца, указанного значения, диапазона значений.
- Удаление списка целиком.
- Вывод содержимого списка.
- Выход из программы.
4. Пользователь выбирает одно из вышеперечисленных действий, вводя соответствующую команду.
5. Реализованы различные функции в зависимости от выбора пользователя:
- Создание нового списка с указанием его элементов.
- Добавление элементов в список: в конец, после указанного значения, в начало.
- Удаление элементов из списка: с конца, по заданному значению, в заданном диапазоне.
- Подсчет длины списка.
- Удаление списка целиком.
6. В конце программы освобождаются выделенные ранее ресурсы (удаление всех списков).

Программа предоставляет интерактивный интерфейс для управления динамическим списком, использование различных функций работы с данными, и обрабатывает ситуации, когда список не может быть изменен.

5. **Сценарий выполнения работы**: 
```
moscow@moscow:~/Рабочий стол/For Labs/ForLabs/CP8$ make
gcc -std=c99 -pedantic -Wall -c iterator.c -o iter.o
gcc -std=c99 -pedantic -Wall -c linli.c -o linli.o
gcc -std=c99 -pedantic -Wall -o client cp8.c iter.o linli.o
valgrind --leak-check=yes -s ./client
==5454== Memcheck, a memory error detector
==5454== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==5454== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==5454== Command: ./client
==5454== 
Запуск программы...

N для создания нового листа,
C для добавления значения в лист,
D для удаления значения из листа,
R для удаления диапазона значений из листа,
F для удаления листа,
S для подсчёта длины листа,
P для печати листа,
Q для выхода.
n
Введите элементы дека №1: 1 2 3 4 5 6 7 8 9
[1, 2, 3, 4, 5, 6, 7, 8, 9]
Добавлено!

N для создания нового листа,
C для добавления значения в лист,
D для удаления значения из листа,
R для удаления диапазона значений из листа,
F для удаления листа,
S для подсчёта длины листа,
P для печати листа,
Q для выхода.
r
Введите номер листа, из которого удалить значение: 1
Введите значение начало диапазона: 3
Введите значение конца диапазона: 9
[1, 2]
Удалено!

N для создания нового листа,
C для добавления значения в лист,
D для удаления значения из листа,
R для удаления диапазона значений из листа,
F для удаления листа,
S для подсчёта длины листа,
P для печати листа,
Q для выхода.
s
Введите номер листа, в который добавлять значение: 1
Размер листа - 2.

N для создания нового листа,
C для добавления значения в лист,
D для удаления значения из листа,
R для удаления диапазона значений из листа,
F для удаления листа,
S для подсчёта длины листа,
P для печати листа,
Q для выхода.
n
Введите элементы дека №2: 1 2 3 
[1, 2, 3]
Добавлено!

N для создания нового листа,
C для добавления значения в лист,
D для удаления значения из листа,
R для удаления диапазона значений из листа,
F для удаления листа,
S для подсчёта длины листа,
P для печати листа,
Q для выхода.
c
Выберете действие из списка, введя его номер:
1. Добавить в конец листа.
2. Добавить после введённого значения.
3. Добавить в начало листа.
1
Введите номер листа, в который добавлять значение: 1
Введите значение: 8
[1, 2, 8]
Добавлено!

N для создания нового листа,
C для добавления значения в лист,
D для удаления значения из листа,
R для удаления диапазона значений из листа,
F для удаления листа,
S для подсчёта длины листа,
P для печати листа,
Q для выхода.
s
Введите номер листа, в который добавлять значение: 1
Размер листа - 3.

N для создания нового листа,
C для добавления значения в лист,
D для удаления значения из листа,
R для удаления диапазона значений из листа,
F для удаления листа,
S для подсчёта длины листа,
P для печати листа,
Q для выхода.
q

Удаляем...
До свидания!
==5454== 
==5454== HEAP SUMMARY:
==5454==     in use at exit: 0 bytes in 0 blocks
==5454==   total heap usage: 64 allocs, 64 frees, 2,680 bytes allocated
==5454== 
==5454== All heap blocks were freed -- no leaks are possible
==5454== 
==5454== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

6. **Протокол**:
item.h
```
#ifndef _ITEM_H_
#define _ITEM_H_

struct Item {
    struct Item* next;
    unsigned int data;
};

#endif
```

iterator.h
```
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
```

iterator.c
```
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
```

linli.h
```
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
void DeleteRange(List* l, Iterator* start, Iterator* stop);
void DeleteRangeST(List* l, Iterator* stop);
Iterator* Search(List* l, const unsigned int t);
Iterator* SearchOneLast(List* l, const unsigned int t);

#endif
```

linli.c
```
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

void DeleteRange(List* l, Iterator* start, Iterator* stop){
    Iterator* i = (Iterator*)malloc(sizeof(Iterator));
    i->node = start->node;
    Next(start);
    StoreLinkNext(i, stop->node->next);
    Iterator* s = LastInList(l);
    if (Equal(s, stop)){
        l->tail = i->node;
    }
    free(i);
    while(NotEqual(start, stop)){
	Iterator* i = (Iterator*)malloc(sizeof(Iterator));
	i->node = start->node;
	Next(start);
        free(i->node);
        free(i);
        l->size--;
    }
    free(stop->node);
    free(s);
    l->size--;
}

void DeleteRangeST(List* l, Iterator* stop){
    Iterator* start = FirstInList(l);
    l->head = stop->node->next;
    while(NotEqual(start, stop)){
	Iterator* i = (Iterator*)malloc(sizeof(Iterator));
	i->node = start->node;
        Next(start);
        free(i->node);
        free(i);
        l->size--;
    }
    free(start->node);
    free(start);
    l->size--;
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
```

cp8.c
```
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

#include "item.h"
#include "iterator.h"
#include "linli.h"


unsigned int GetNumber(const char *str, int *index){
    unsigned int num;
    while (!isdigit(str[*index]) && str[*index] != '\n' && str[*index] != '\0') {
        (*index)++;
    }
    if (str[*index] == '\n' || str[*index] == '\0') {
        return -1;
    }
    sscanf(&str[*index], "%u", &num);
    while (isdigit(str[*index])) {
        (*index)++;
    }
    
    return num;
}



int main(void){
    printf("Запуск программы...\n");
    char stat = 'e';
    List* stor[100];
    int count_list = 0;
    
    while ((stat != 'Q') && (stat != 'q')) {
        printf("\nN для создания нового листа,\nC для добавления значения в лист,\nD для удаления значения из листа,\nR для удаления диапазона значений из листа,\nF для удаления листа,\nS для подсчёта длины листа,\nP для печати листа,\nQ для выхода.\n");
        scanf(" %c", &stat);
        
        switch(stat){
            
            case 'N':
            case 'n':
            {
                stor[count_list] = (List*)malloc(sizeof(List));
                CreateList(stor[count_list]);
                unsigned int val;
                int i = 0;
                char elem[100];
                printf("Введите элементы дека №%d: ", count_list+1);
                scanf(" %[^\n]", elem);
                while ((val = GetNumber(elem, &i)) != -1){
                    PushInList(stor[count_list], val);
                }
                Print(stor[count_list]);
                printf("Добавлено!\n");
                count_list++;
            }
            break;
            
            case 'C':
            case 'c':
            {
                int command;
                printf("Выберете действие из списка, введя его номер:\n");
                printf("1. Добавить в конец листа.\n");
                printf("2. Добавить после введённого значения.\n");
                printf("3. Добавить в начало листа.\n");
                scanf("%d", &command);
                if (command == 1){
                    unsigned int val;
                    int index;
                    printf("Введите номер листа, в который добавлять значение: ");
                    scanf("%d", &index);
                    if (index > count_list || index < 1){
                        printf("Листа с таким номером нет.\n");
                        break;
                    }
                    printf("Введите значение: ");
                    scanf("%u", &val);
                    PushInList(stor[index-1], val);
                    Print(stor[index-1]);
                    printf("Добавлено!\n");
                } else if (command == 2){
                    unsigned int val;
                    unsigned int start;
                    int index;
                    printf("Введите номер листа, в который добавлять значение: ");
                    scanf("%d", &index);
                    if (index > count_list || index < 1){
                        printf("Листа с таким номером нет.\n");
                        break;
                    }
                    printf("Введите значение, после которого добавлять: ");
                    scanf("%u", &start);
                    printf("Введите значение, какое добавлять: ");
                    scanf("%u", &val);
                    Iterator* s = Search(stor[index-1], start);
                    Iterator* f = LastInList(stor[index-1]);
                    if (Equal(s, f)){
                        PushInList(stor[index-1], val);
                    } else {
                        InsertInList(stor[index-1], s, val);
                    }
                    Print(stor[index-1]);
                    printf("Добавлено!\n");
                    free(s);
                    free(f);
                } else if (command == 3){
                    unsigned int val;
                    int index;
                    printf("Введите номер листа, в который добавлять значение: ");
                    scanf("%d", &index);
                    if (index > count_list || index < 1){
                        printf("Листа с таким номером нет.\n");
                        break;
                    }
                    printf("Введите значение, какое добавлять: ");
                    scanf("%u", &val);
                    PushInListFirst(stor[index-1], val);
                    Print(stor[index-1]);
                    printf("Добавлено!\n");
                } else {
                   printf("Некорректное значение.");
                   break;
                }
            }
            break;
            
            case 'D':
            case 'd':
            {
                int command;
                printf("Выберете действие из списка, введя его номер:\n");
                printf("1. Удалить из конца листа.\n");
                printf("2. Удалить введённое значение.\n");
                scanf("%d", &command);
                if (command == 1){
                    int index;
                    printf("Введите номер листа, из которого удалить значение: ");
                    scanf("%d", &index);
                    if (index > count_list || index < 1){
                        printf("Листа с таким номером нет.\n");
                        break;
                    } else if (SizeList(stor[index-1]) == 1){
                        Destroy(stor[index-1]);
                        for(int i=index-1; i < count_list-1; i++){
                            stor[i] = stor[i+1];
                        }
                        stor[count_list-1] = 0;
                        count_list--;
                        printf("Лист удалён!\n");
                        break;
                    } else {
                        PopInList(stor[index-1]);
                        Print(stor[index-1]);
                        printf("Удалено!\n");
                    }
                } else if (command == 2){
                    unsigned int val;
                    int index;
                    printf("Введите номер листа, из которого удалить значение: ");
                    scanf("%d", &index);
                    if (index > count_list || index < 1){
                        printf("Листа с таким номером нет.\n");
                        break;
                    } else if (SizeList(stor[index-1]) == 1){
                        Destroy(stor[index-1]);
                        for(int i=index-1; i < count_list-1; i++){
                            stor[i] = stor[i+1];
                        }
                        stor[count_list-1] = 0;
                        count_list--;
                        printf("Лист удалён!\n");
                        break;
                    } else {
                        Iterator* f = FirstInList(stor[index-1]);                    
                        printf("Введите значение: ");
                        scanf("%u", &val);
                        Iterator* s = SearchOneLast(stor[index-1], val);
                        if (s->node != NULL){
                            Delete(stor[index-1], s);
                            Print(stor[index-1]);
                            printf("Удалено!\n");
                        } else {
                            Iterator* s2 = Search(stor[index-1], val);
                            if (s2->node != NULL){
                                DeleteST(stor[index-1]);
                                Print(stor[index-1]);
                                printf("Удалено!\n");
                            }
                            free(s2);
                        }
                        free(f);
                        free(s);
                    }
                } else {
                   printf("Некорректное значение.");
                   break;
                }
            }
            break;
            
            case 'F':
            case 'f':
            {
                int index;
                printf("Введите номер листа, который хотите удалить: ");
                scanf("%d", &index);
                if (index > count_list || index < 1){
                    printf("Листа с таким номером нет.\n");
                    break;
                }
                Destroy(stor[index-1]);
                for(int i=index-1; i < count_list-1; i++){
                    stor[i] = stor[i+1];
                }
                stor[count_list-1] = 0;
                count_list--;
                printf("Лист удалён!\n");
            }
            break;
            
            case 'P':
            case 'p':
            {
                printf("Количество листов: %d\n", count_list);
                int index;
                printf("Введите номер листа: ");
                scanf("%d", &index);
                if (index > count_list || index < 1){
                    printf("Листа с таким номером нет.\n");
                    break;
                }
                Print(stor[index-1]);
            }
            break;
            
            case 'R':
            case 'r':
            {
                int index;
                printf("Введите номер листа, из которого удалить значение: ");
                scanf("%d", &index);
                if (index > count_list || index < 1){
                    printf("Листа с таким номером нет.\n");
                    break;
                }
                unsigned int start;
                unsigned int stop;
                printf("Введите значение начало диапазона: ");
                scanf("%u", &start);
                printf("Введите значение конца диапазона: ");
                scanf("%u", &stop);
                Iterator* start_i = SearchOneLast(stor[index-1], start);
                Iterator* stop_i = Search(stor[index-1], stop);
                if (start_i->node != NULL && stop_i->node != NULL){
                    DeleteRange(stor[index-1], start_i, stop_i);
                } else {
                    Iterator* start_i2 = Search(stor[index-1], start);
                    Iterator* f = FirstInList(stor[index-1]);
                    Iterator* s = LastInList(stor[index-1]);
                    if (Equal(start_i2, f) && Equal(stop_i, s)){
                        Destroy(stor[index-1]);
                        for(int i=index-1; i < count_list-1; i++){
                            stor[i] = stor[i+1];
                        }
                        stor[count_list-1] = 0;
                        count_list--;
                        printf("Лист удалён!\n");
                        free(start_i);
                        free(stop_i);
                        free(f);
                        free(s);
                        free(start_i2);
                        break;
                    } else if (Equal(start_i2, f)){
                        DeleteRangeST(stor[index-1], stop_i);
                    } else {
                        printf("Ошибка ввода.\n");
                        free(start_i2);
                        free(start_i);
                        free(stop_i);
                        free(f);
                        free(s);
                        break;
                    }
                    free(f);
                    free(s);
                    free(start_i2);
                }
                free(start_i);
                free(stop_i);
                Print(stor[index-1]);
                printf("Удалено!\n");
            }
            break;
            
            case 'S':
            case 's':
            {
                int index;
                printf("Введите номер листа, в который добавлять значение: ");
                scanf("%d", &index);
                if (index > count_list || index < 1){
                    printf("Листа с таким номером нет.\n");
                    break;
                }
                int s = SizeList(stor[count_list-1]);
                printf("Размер листа - %d.\n", s);
            }
            break;
        }
    }
    printf("\nУдаляем...\n");
    for(int i=0; i < count_list; i++){
        Destroy(stor[i]);
    }
    printf("До свидания!\n");
    
    return 0;
}
```
7. **Замечания автора** по существу работы: -.
8. **Выводы**: Работа выдалась интересной. Я над ней не страдала, чётко понимала, что нужно делать и как, хотя времени всё равно потратила много, особенно потом на исправление утечек памяти.
С каждым разом количество файлов становится всё больше, но это не плохо. Видимо, из-за Питония где-то в середине выполнения лабораторной (курсовой) перестала переводить слово "list" так что все списки стали листами. Но это не критично. Работу считаю сугубо прикладной, однако она помогает понять работу итераторов и списков. Без эффекта "вау", но мне понравилось.
