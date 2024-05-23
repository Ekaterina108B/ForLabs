#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "addfuncs.h"
#include "leaf.h"
#include "tree.h"
#include "h.h"

void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void clean_lab24(Tree* t, Tree* t2, char* input, char* new, char* exp){
    DeleteTree(t2);
    DeleteTree(t);
    for (int i=0; i<MAX_SIZE; i++) { input[i] = '\0'; }
    for (int i=0; i<MAX_SIZE; i++) { new[i] = '\0'; }
    for (int i=0; i<MAX_SIZE; i++) { exp[i] = '\0'; }
}

int main(void){
    char stat;
    char input[MAX_SIZE];
    char new[MAX_SIZE];
    char exp[MAX_SIZE];
    Tree* t;
    Tree* t2;
    printf("Добро пожаловать!\n\n");
    printf("Прежде, чем вводить математические выражения, пожалуйста, ознакомьтесь с особенностями:\n");
    printf("	1. Делить на нуль нельзя.\n");
    printf("	2. Показатель степени обязан быть вычислимым (т.е. не содержать букв или дробей).\n");
    printf("	3. Внимательно следите за скобками! Программа не обработает корректно введённое выражение.\n");
    printf("	4. Авторские пробелы не помешают работе программы.\n");
    printf("	5. Опускать знак умножения между буквами или перед скобкой можно.\n");
    printf("Данную справку можно вызвать с помощью буквы h.\n");
    printf("Введите что-нибудь для продолжения.\n");
    scanf("%c", &stat);
    stat = 'n';
    printf("Приятного пользования!\n\n");
    printf("Запускаем...\n\n");
    t = CreateTree();
    NewRoot(t, CreateLeaf());
    t2 = CreateTree();
    NewRoot(t2, CreateLeaf());
    
    while(stat != 'Q' && stat != 'q'){
 	
    	    if (stat == '0'){
    		printf("Что желаете сделать?\n");
    		printf("N для ввода нового выражения,\nI для печати исходного выражения и соответствующего дерева,\nA для печати выражения после сокращения и соответствующего дерева,\nT для просмотра тестов,\nH для печати памятки,\nQ для выхода.\n");
    		printf("Введите букву действия: ");
    		scanf(" %c", &stat);
    		continue;
    	    }
    	    
    	    if (stat == 'N' || stat == 'n'){
    	    	clean_lab24(t, t2, input, new, exp);
    	    	clearBuffer();
    	    	printf("Введите математическое выражение: ");
    		fgets(input, MAX_SIZE, stdin);
    		semi_stack* s = reverse_polish_notation(clear_space(input, new));
    		t = ExpressionIntoTree(s);
    		t->size += 0;
    		semi_stack* s2 = reverse_polish_notation(new);
    		t2 = ExpressionIntoTree(s2);
    	    	int error = clean_up(t2, t2->root);
    		if (error == 1){
    		    printf("error 1: присутствует явное деление на нуль.\n");
    		    stat = 'n';
    		    continue;
    		} else if (error == 2){
    		    printf("error 2: степень не целое число.\n");
    		    stat = 'n';
    		    continue;
    		}
    		scroll_to_divide(t2, t2->root);
    		error = clean_up(t2, t2->root);
    		if (error == 1){
    		    printf("error 1: присутствует явное деление на нуль.\n");
    		    stat = 'n';
    		    continue;
    		} else if (error == 2){
    		    printf("error 2: степень не целое число.\n");
    		    stat = 'n';
    		    continue;
    		}
		semi_stack* s3 = TreeIntoExpression(t2);
		math_expression(s3, exp);
    		stat = '0';
    		continue;
    	    }
    	    
    	    if (stat == 'I' || stat == 'i'){
    	    	printf("------------------\n");
    	    	PrintTree(t->root, 0);
    	    	printf("Выражение: %s\n", new);
    	    	printf("------------------\n\n");
    	    	stat = '0';
    	    	continue;
    	    }
    	    
    	    if (stat == 'A' || stat == 'a'){
    	    	printf("------------------\n");
    	    	PrintTree(t2->root, 0);
    	    	printf("Сокращённое выражение: %s\n", exp);
    	    	printf("------------------\n\n");
    	    	stat = '0';
    	    	continue;
    	    }
    	    
    	    if(stat == 'T' || stat == 't'){
    	    FILE* file;
    	    int num = 0;
    	    
    	    printf("\nВыберете пакет тестов:\n");
    	    printf("	1. Проверка ввода данных.\n");
    	    printf("	2. Простые (наглядные) тесты.\n");
    	    printf("	3. Сложные выражения.\n");
    	    while(num < 1 || num > 3){
    	    	printf("Введите число: ");
    	    	scanf(" %d", &num);
    	    }
    	    if (num == 1){
    	    	file = fopen("test1.txt", "r");
    	    	char test_exp[MAX_SIZE];
    	    	char test_new[MAX_SIZE];
    	    	char test_in[MAX_SIZE];
    	    	char holost;
    	    	for (int i=0; i<MAX_SIZE; i++) { test_in[i] = '\0'; }
    	    	char* ans[] = {"Деление на нуль\n", "Явное деление на нуль\n", "Неявное деление на нуль\n", "Буква в показателе степени\n", "Невычислимое выражение в показателе степени\n"};
    	    	for (int i=0; i<5; i++){
    	    	    printf("%s", ans[i]);
    	    	    printf("\n");
    	    	    for (int i=0; i<MAX_SIZE; i++) { test_exp[i] = '\0'; }
    	    	    fscanf(file, "%s", &test_exp[0]);
    	    	    printf("Выражение: %s\n", test_exp);
    	    	    scanf("%c", &holost);
    	    	    semi_stack* s = reverse_polish_notation(clear_space(test_exp, test_in));
    		    Tree* test_t = ExpressionIntoTree(s);
    		    PrintTree(test_t->root, 0);
    		    printf("\n");
    		    int error = clean_up(test_t, test_t->root);
    		    if (error == 1){
    		    	PrintTree(test_t->root, 0);
    		    	printf("error 1: присутствует явное деление на нуль.\n");
    		    } else if (error == 2){
    		    	PrintTree(test_t->root, 0);
    		    	printf("error 2: степень не целое число.\n");
    		    } else {
    			scroll_to_divide(test_t, test_t->root);
    			error = clean_up(test_t, test_t->root);
    			if (error == 1){
    		    	    PrintTree(test_t->root, 0);
    		    	    printf("error 1: присутствует явное деление на нуль.\n");
    			} else if (error == 2){
    		    	    PrintTree(test_t->root, 0);
    		    	    printf("error 2: степень не целое число.\n");
    			} else {
    			    printf("error 0: ошибок не найдено.\n");
    			}
    		    }
		    semi_stack* s3 = TreeIntoExpression(test_t);
		    for (int i=0; i<MAX_SIZE; i++) { test_new[i] = '\0'; }
		    math_expression(s3, test_new);
		    printf("%s\n", test_new);
		    scanf("%c", &holost);
		    DeleteTree(test_t);
		    printf("------------------\n");
		    printf("------------------\n");
    	    	}
    	    	fclose(file);
    	    	
    	    } else if (num == 2){
    	    	file = fopen("test2.txt", "r");
    	    	char test_exp[MAX_SIZE];
    	    	char test_new[MAX_SIZE];
    	    	char test_in[MAX_SIZE];
    	    	char holost;
    	    	for (int i=0; i<MAX_SIZE; i++) { test_in[i] = '\0'; }
    	    	char* ans[] = {"1.\n", "2.\n", "3.\n", "4.\n", "5.\n", "6.\n"};
    	    	for (int i=0; i<6; i++){
    	    	    printf("%s", ans[i]);
    	    	    printf("\n");
    	    	    for (int i=0; i<MAX_SIZE; i++) { test_exp[i] = '\0'; }
    	    	    fscanf(file, "%s", &test_exp[0]);
    	    	    printf("Выражение: %s\n", test_exp);
    	    	    scanf("%c", &holost);
    	    	    semi_stack* s = reverse_polish_notation(clear_space(test_exp, test_in));
    		    Tree* test_t = ExpressionIntoTree(s);
    		    PrintTree(test_t->root, 0);
    		    printf("\n");
    		    int error = clean_up(test_t, test_t->root);
    		    if (error == 1){
    		    	PrintTree(test_t->root, 0);
    		    	printf("error 1: присутствует явное деление на нуль.\n");
    		    } else if (error == 2){
    		    	PrintTree(test_t->root, 0);
    		    	printf("error 2: степень не целое число.\n");
    		    } else {
    			scroll_to_divide(test_t, test_t->root);
    			error = clean_up(test_t, test_t->root);
    			if (error == 1){
    		    	    PrintTree(test_t->root, 0);
    		    	    printf("error 1: присутствует явное деление на нуль.\n");
    			} else if (error == 2){
    		    	    PrintTree(test_t->root, 0);
    		    	    printf("error 2: степень не целое число.\n");
    			} else {
    			    PrintTree(test_t->root, 0);
    			    printf("error 0: ошибок не найдено.\n");
    			}
    		    }
		    semi_stack* s3 = TreeIntoExpression(test_t);
		    for (int i=0; i<MAX_SIZE; i++) { test_new[i] = '\0'; }
		    math_expression(s3, test_new);
		    printf("%s\n", test_new);
		    scanf("%c", &holost);
		    DeleteTree(test_t);
		    printf("------------------\n");
		    printf("------------------\n");
    	    	}
    	    	fclose(file);
    	    } else {
    	    	file = fopen("test3.txt", "r");
    	    	char test_exp[MAX_SIZE];
    	    	char test_new[MAX_SIZE];
    	    	char test_in[MAX_SIZE];
    	    	char holost;
    	    	for (int i=0; i<MAX_SIZE; i++) { test_in[i] = '\0'; }
    	    	char* ans[] = {"1.\n", "2.\n", "3.\n"};
    	    	for (int i=0; i<3; i++){
    	    	    printf("%s", ans[i]);
    	    	    printf("\n");
    	    	    for (int i=0; i<MAX_SIZE; i++) { test_exp[i] = '\0'; }
    	    	    fscanf(file, "%s", &test_exp[0]);
    	    	    printf("Выражение: %s\n", test_exp);
    	    	    scanf("%c", &holost);
    	    	    semi_stack* s = reverse_polish_notation(clear_space(test_exp, test_in));
    		    Tree* test_t = ExpressionIntoTree(s);
    		    PrintTree(test_t->root, 0);
    		    printf("\n");
    		    int error = clean_up(test_t, test_t->root);
    		    if (error == 1){
    		    	PrintTree(test_t->root, 0);
    		    	printf("error 1: присутствует явное деление на нуль.\n");
    		    } else if (error == 2){
    		    	PrintTree(test_t->root, 0);
    		    	printf("error 2: степень не целое число.\n");
    		    } else {
    			scroll_to_divide(test_t, test_t->root);
    			error = clean_up(test_t, test_t->root);
    			if (error == 1){
    		    	    PrintTree(test_t->root, 0);
    		    	    printf("error 1: присутствует явное деление на нуль.\n");
    			} else if (error == 2){
    		    	    PrintTree(test_t->root, 0);
    		    	    printf("error 2: степень не целое число.\n");
    			} else {
    			    PrintTree(test_t->root, 0);
    			    printf("error 0: ошибок не найдено.\n");
    			}
    		    }
		    semi_stack* s3 = TreeIntoExpression(test_t);
		    for (int i=0; i<MAX_SIZE; i++) { test_new[i] = '\0'; }
		    math_expression(s3, test_new);
		    printf("%s\n", test_new);
		    scanf("%c", &holost);
		    DeleteTree(test_t);
		    printf("------------------\n");
		    printf("------------------\n");
    	    	}
    	    	fclose(file);
    	    }
    	    
    	    stat = '0';
    	    continue;
    	    }
    	    
    	    if(stat == 'H' || stat == 'h'){
    	    	printf("Особенности ввода:\n");
    		printf("	1. Делить на нуль нельзя.\n");
    		printf("	2. Показатель степени обязан быть вычислимым (т.е. не содержать букв или дробей).\n");
    		printf("	3. Внимательно следите за скобками! Программа не обработает некорректно введённое выражение.\n");
    		printf("	4. Авторские пробелы не помешают работе программы.\n");
    		printf("	5. Опускать знак умножения между буквами или перед скобкой можно.\n");
    		printf("\n");
    		stat = '0';
    		continue;
    	    }
    	    stat = '0';
    	}
    DeleteTree(t);
    DeleteTree(t2);   	
}
