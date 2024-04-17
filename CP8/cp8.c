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
        printf("\nN для создания нового листа,\nC для добавления значения в лист,\nD для удаления значения из листа,\nR для удаления диапазона значений из листа,\nF для удаления листа,\nP для печати листа,\nQ для выхода.\n");
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
        }
    }
    printf("\nУдаляем...\n");
    for(int i=0; i < count_list; i++){
        Destroy(stor[i]);
    }
    printf("До свидания!\n");
    
    return 0;
}
