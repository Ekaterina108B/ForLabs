#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "addfuncs.h"
#include "leaf.h"
#include "tree.h"
#include "h.h"

int main(void){
    printf("\nLKJH!\n\n");
    char new[MAX_SIZE];
    //semi_stack* s = reverse_polish_notation("2+3(4-(8^(-0)+5/1))\0");
    //semi_stack* s = reverse_polish_notation("(4-5(10^a-(b-2)))/(8-b^2)+2\0");
    semi_stack* s = reverse_polish_notation(clear_space("(1^6+1^7+4*2)/15*9/((16/8)^2)+(21/7+a-b/c)^(1/2)/a*c\0", new));
    //semi_stack* s = reverse_polish_notation(clear_space(" ( 13 - 10 + 2 ) ^ 2 * 4 / 10 - 169 / 13 * ( 39 - 40 + 1 ) - 14 * ( 15 - 20 ) / ( 10 - 3 ) \0", new));
    
    Tree* t = ExpressionIntoTree(s);
    semi_stack* s2 = TreeIntoExpression(t);
    PrintTree(t->root, 0);
    char exp[MAX_SIZE];
    for (int i=0; i<MAX_SIZE; i++) { exp[i] = '\0'; }
    math_expression(s2, exp);
    printf("%s\n", exp);
    
    printf("------------------\n");
    
    int error = clean_up(t, t->root);
    if (error == 1){ printf("error 1: присутствует явное деление на нуль.\n"); }
    else if (error == 2){ printf("error 2: степень не целое число.\n"); }
    else { printf("error 0\n");
    scroll_to_divide(t, t->root);
    }
    PrintTree(t->root, 0);
    semi_stack* s3 = TreeIntoExpression(t);
    char exp2[MAX_SIZE];
    for (int i=0; i<MAX_SIZE; i++) { exp2[i] = '\0'; }
    math_expression(s3, exp2);
    printf("После сжатия: %s\n", exp2);
    
    DeleteTree(t);
    DeleteSemi_Stack(s2);
    DeleteSemi_Stack(s3);
    return 0;
}
