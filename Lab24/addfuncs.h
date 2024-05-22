#ifndef _ADDFUNCS_H_
#define _ADDFUNCS_H_

#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


#define MAX_SIZE 100

typedef struct {
    char stack[MAX_SIZE][MAX_SIZE];
    int size;
} semi_stack;

typedef struct {
    int index;
} Index;

typedef struct Elem {
    struct Elem* r;
    struct Elem* l;
    char data[100];
} Elem;

typedef struct {
    Elem* start;
} semi_list;

typedef struct {
    Elem* point;
} pointer;

bool is_digit(char c);
bool is_oper(char c);
bool is_lit(char c);
bool inss(semi_stack* s, char elem);
bool in(char* s, int len, char elem);
void saw(semi_stack* con, semi_stack* semi_tree, char* m, int l);
semi_stack* CreateSemi_Stack(void);
semi_stack* reverse_polish_notation(char* exp);
void DeleteSemi_Stack(semi_stack* s);
int SizeSS(semi_stack* s);
Index* CreateIndex(int i);
int GetIndex(Index* in);
void NextIndex(Index* in);
void DeleteIndex(Index* in);
int xp(int x, int y);
int char_into_int(char* s);
void PrintTab(int i);
void int_in_char(char* s, int num);
Elem* CreateElem(void);
semi_list* CreateSemi_List(Elem* e);
pointer* CreatePoint(Elem* e);
void fill_with_brackets(pointer* p, char elem);
void fill(pointer* p, char elem);
void Analyze(semi_stack* s, Index* in, pointer* p, int level);
void math_expression(semi_stack* s, char* exp);
char* clear_space(char* exp, char* neww);

#endif
