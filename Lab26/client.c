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
