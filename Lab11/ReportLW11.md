# Отчет по лабораторной работе № 11
## по курсу "Фундаментальная информатика"

Студент группы М8О-108Б-23 Федорова Екатерина Васильевна

Работа выполнена 

Преподаватель: каф. 806 Севастьянов Виктор Сергеевич

1. **Тема**: Алгоритмы и структуры данных
2. **Цель работы**: ознакомиться с конечными автоматами. Составить программу на С, выполняющую анализ и обработку вводимого текста без ограничения на количество и длину строк исходного текста.
3. **Задание (вариант №42)**: Выделить шестнадцатиричные целые числа без знака и напечатать шестнадцатиричную сумму их нечётных цифр.
4. **Идея, метод, алгоритм решения задачи**:

![изображение](https://github.com/Ekaterina108B/ForLabs/assets/144663808/f5682cf4-fbfc-4fd3-9221-d1aa94d6594e)

Для решения задачи я использовала всего 2 состояния: NUMDER_CHECK и FIND.

Первое состояние проверяет, является ли слово числом.

Если буква - нечётная цифра числа 16СС, то она добавляется к промежуточной сумме.

Если буква - чётная цифра, выполняется холостой ход.

Если встречается символ-разделитель - промежуточная сумма добавляется к общей и обнуляется, состояние 
переходит к проверке следующего слова.

Если в слове встречается хотя бы одна буква, не являющаяся цифрой, то промежуточная сумма обнуляется, состояние переводится в FIND.

Второе состояние пробегает слово, пока не найдёт символ-разделитель, после чего переводит в состояние NUMBER_CHECK.

5. **Сценарий выполнения работы**:

(Предположим, что ваша программа должна уметь складывать числа)
| Входные данные                      | Выходные данные  | Описание тестируемого случая                    |
|-------------------------------------|------------------|-------------------------------------------------|
| 01 23\n45\t6789AbCDeF 1g\nju\n1.3   | 40               | Все сложные ситуации                            |
| 1 1                                 | 2                | Правильная обработка конца вводимых данных      |


6. **Протокол**:

Программа:

```
#include <stdio.h>
#include <ctype.h>

typedef enum _kState
{
	FIND,
	NUMBER_CHECK
} kState;

int is_digit(char literal){
    if ((literal >= '0' && literal <= '9') || (literal == 'a' || literal == 'b' || literal == 'c' || literal == 'd' || literal == 'e' || literal == 'f' || literal == 'A' || literal == 'B' || literal == 'C' || literal == 'D' || literal == 'E' || literal == 'F')) {
        return 1;
    }
    return 0;
}

int is_delimiter(int literal){
    if (isspace(literal) || literal == ',' || literal == '\t' || literal == '\n'){
        return 1;
    }
    return 0;
}

int hex_to_dec(char literal){
    if (literal == '0') return 0;
    if (literal == '1') return 1;
    if (literal == '2') return 2;
    if (literal == '3') return 3;
    if (literal == '4') return 4;
    if (literal == '5') return 5;
    if (literal == '6') return 6;
    if (literal == '7') return 7;
    if (literal == '8') return 8;
    if (literal == '9') return 9;
    if (literal == 'a' || literal == 'A') return 10;
    if (literal == 'b' || literal == 'B') return 11;
    if (literal == 'c' || literal == 'C') return 12;
    if (literal == 'd' || literal == 'D') return 13;
    if (literal == 'e' || literal == 'E') return 14;
    if (literal == 'f' || literal == 'F') return 15;
}

int main(void){
	char ch;
	unsigned int number = 0, sum_number = 0;
	int if_number = 0;
	kState state = NUMBER_CHECK;
	while ((ch = getchar()) != EOF){
		switch (state)
		{
			case FIND:
			{
			    if (is_delimiter(ch)) state = NUMBER_CHECK;
			}
			break;
			
			case NUMBER_CHECK:
			{
			    if((is_digit(ch)) && (hex_to_dec(ch) & 1)){
			        number += hex_to_dec(ch);
			    }
			    else if(is_digit(ch)){
			        number = number;
			    }
			    else if(is_delimiter(ch)){
			        sum_number += number;
			        number = 0;
			    }
			    else{
			        number = 0;
			        state = FIND;
			    }
			}
			break;
		}
	}
	sum_number += number;	
	printf("\n%X\n", sum_number);
    return 0;
}
```

Листинг:
```
moscow@moscow:~/Рабочий стол/For Labs/ForLabs/Lab11$ vim lab11.c
moscow@moscow:~/Рабочий стол/For Labs/ForLabs/Lab11$ gcc -std=c99 -Wall -pedantic lab11.c
lab11.c: In function ‘main’:
lab11.c:46:13: warning: unused variable ‘if_number’ [-Wunused-variable]
   46 |         int if_number = 0;
      |             ^~~~~~~~~
lab11.c: In function ‘hex_to_dec’:
lab11.c:41:1: warning: control reaches end of non-void function [-Wreturn-type]
   41 | }
      | ^
moscow@moscow:~/Рабочий стол/For Labs/ForLabs/Lab11$ ./a.out
1 1
2

```

8. **Замечания автора** по существу работы: -.
9. **Выводы**: Во время выполнения лабораторной работы я намного ближе познакомилась с синтаксисом языка C и программированием на нём,
а также узнала о состояниях. Выполнение данной работы было для меня тяжёлым из-за скудных познаний языка,
однако мне понравился итог, особенно видя, как программа работает. Данная лабораторная работа не только заставила меня
обучаться новому языку, но и прививала усидчивость и концентрацию внимания, чтобы суметь перерыть много информации,
запомнить её и не бросить начатое дело.
