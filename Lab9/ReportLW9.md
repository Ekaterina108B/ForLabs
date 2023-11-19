# Отчет по лабораторной работе № 9
## по курсу "Фундаментальная информатика"

Студент группы М8О-108Б-23 Федорова Екатерина Васильевна

Работа выполнена 

Преподаватель: каф. 806 Севастьянов Виктор Сергеевич

1. **Тема**: Программирование на языке С и отладка.
2. **Цель работы**: составление и отладка простейшей программы на языке С итеративного характера с целочисленными рекуррентными соотношениями, задающими некоторое регулярное движение точки в целочисленной системе координат (i, j) с дискретным временем k и динамическим параметром движения l.
3. **Задание (вариант №19)**: написать программу на языке С, определяющую, попадает ли точка при заданных константами координатах в заданную область не более, чем за 50 шагов.

Область - полоса, ограниченная прямыми i + j + 10 = 0 и i + j + 20 = 0.

Формулы и данные константы:

![Снимок экрана от 2023-11-20 01-19-35](https://github.com/Ekaterina108B/ForLabs/assets/144663808/9cf1ac6a-594b-4136-9d07-8af560da854e)

![Снимок экрана от 2023-11-20 01-20-07](https://github.com/Ekaterina108B/ForLabs/assets/144663808/7305f2a0-4cd0-431b-ab03-107addbfc34e)

4. **Идея, метод, алгоритм решения задачи**: шаги переберём с помощью цикла for, по параметрам соотношений станем рассчитывать каждые ik, jk и lk.
 
5. **Сценарий выполнения работы**: Так как в задании не указано, что именно подразумевается под mod (modulo или remainer), то составим два варианта программы под оба случая.
На языке С реализован с помощью % remainer, поэтому во втором варианте с modulo придётся самостоятельно задавать правила деления по модулю с помощью функции MOD(a, b).

Программа первая (remainer): [lab9programm.c](https://github.com/Ekaterina108B/ForLabs/blob/master/Lab9/lab9programm.c)

Программа вторая (modulo): [lab9pr_var2.c](https://github.com/Ekaterina108B/ForLabs/blob/master/Lab9/lab9pr_var2.c)

6. **Протокол**:

Программа первая (remainer):
```

#include <stdio.h>

#define MIN(a, b) (a < b ? a : b)
#define MAX(a, b) (a > b ? a : b)


int main() {
    const int I = -22, J = 14, L = -14;
    int ik = I, jk = J, lk = L;
    int i0, j0, l0;
    int stipulation;
    for(int k = 1; k < 51; k++){
	i0 = ik;
        j0 = jk;
        l0 = lk;
        ik = (i0 * MIN(j0, l0) + j0 * MIN(i0, l0) + k * k) % 20;
        jk = (i0 % 10 - k) * (j0 % 10 + k) * (l0 % 10 - k) % 25;
        lk = MAX(MIN(i0 + j0, i0 + l0) % 25, MAX(i0 + l0, j0 + k) % 20) + 10;
        stipulation = ik + jk;
        if((stipulation + 10 <= 0) && (stipulation + 20 >= 10)){
            printf("Точка попала в заданную область плоскости н %d шаге.\n", k);
            printf("Время попадания: %d шагов.\n", k);
            printf("Координаты точки: (%d, %d).\n", ik, jk);
            printf("Значение динамического параметра движения: %d.\n", lk);
            return 0;
        }
        
    }
    printf("ПРОМАХ! Точка не попала в заданную область плоскости не более, чем за 50 шагов.\n");
    printf("Время окончания движения: 50 шагов.\n");
    printf("Координаты точки: (i = %d, j = %d).\n", ik, jk);
    printf("Значение динамического параметра движения: l = %d.\n", lk);
    return 0;
}
```

Программа вторая (modulo):
```
#include <stdio.h>

#define MIN(a, b) (a < b ? a : b)
#define MAX(a, b) (a > b ? a : b)

int MOD(int a, int b){
    int res;
    if((a > 0) && (b > 0)){
	    res = a % b;
    }
    if((a < 0) && (b > 0)){
            res = a % b + a;
    }
    if((a > 0) && (b < 0)){
            res = a % b + b;
    }
    if((a < 0) && (b < 0)){
            res = a % b;
    }
    return res;
}

int main() {
    const int I = -22, J = 14, L = -14;
    int ik = I, jk = J, lk = L;
    int i0, j0, l0, auxiliary_ik, auxiliary_jk, auxiliary_lk_1, auxiliary_lk_2;
    int stipulation;
    for(int k = 1; k < 51; k++){

        j0 = jk;
        l0 = lk;
	auxiliary_ik = i0 * MIN(j0, l0) + j0 * MIN(i0, l0) + k * k;
        ik = MOD(auxiliary_ik, 20);
	auxiliary_jk = (MOD(i0, 10) - k) * (MOD(j0, 10) + k) * (MOD(l0, 10) - k);
        jk = MOD(auxiliary_jk, 25);
	auxiliary_lk_1 = MIN(i0 + j0, i0 + l0);
	auxiliary_lk_2 = MAX(i0 + l0, j0 + k);
        auxiliary_lk_1 = MOD(auxiliary_lk_1, 25);
        auxiliary_lk_2 = MOD(auxiliary_lk_2, 20);
        lk = MAX(auxiliary_lk_1, auxiliary_lk_2) + 10;
        
        stipulation = ik + jk;
        if((stipulation + 10 <= 0) && (stipulation + 20 >= 10)){
            printf("Точка попала в заданную область плоскости н %d шаге.\n", k);
            printf("Время попадания: %d шагов.\n", k);
            printf("Координаты точки: (%d, %d).\n", ik, jk);
            printf("Значение динамического параметра движения: %d.\n", lk);
            return 0;
        }

    }
    printf("ПРОМАХ! Точка не попала в заданную область плоскости не более, чем за 50 шагов.\n");
    printf("Время окончания движения: 50 шагов.\n");
    printf("Координаты точки: (i = %d, j = %d).\n", ik, jk);
    printf("Значение динамического параметра движения: l = %d.\n", lk);
    return 0;
}
```

Листинг:
```
moscow@moscow:~/Рабочий стол/For Labs/ForLabs$ mkdir Lab9

moscow@moscow:~/Рабочий стол/For Labs/ForLabs$ cd Lab9

moscow@moscow:~/Рабочий стол/For Labs/ForLabs/Lab9$ touch lab9programm.c

moscow@moscow:~/Рабочий стол/For Labs/ForLabs/Lab9$ vim lab9programm.c

moscow@moscow:~/Рабочий стол/For Labs/ForLabs/Lab9$ gcc -std=c99 -Wall -pedanticlab9programm.c
gcc: error: unrecognized command-line option ‘-pedanticlab9programm.c’
gcc: fatal error: no input files
compilation terminated.

moscow@moscow:~/Рабочий стол/For Labs/ForLabs/Lab9$ gcc -std=c99 -Wall -pedantic lab9programm.c

moscow@moscow:~/Рабочий стол/For Labs/ForLabs/Lab9$ ./a.out
Точка не попала в заданную область плоскости за 50 шагов.
Время окончания движения: 50.
Координаты точки: (10, 20).
Значение динамического параметра движения: 25.

moscow@moscow:~/Рабочий стол/For Labs/ForLabs/Lab9$ vim lab9programm.c

moscow@moscow:~/Рабочий стол/For Labs/ForLabs/Lab9$ gcc -std=c99 -Wall -pedantic lab9programm.c
lab9programm.c: In function ‘main’:
lab9programm.c:17:64: error: expected ‘;’ before ‘jk’
   17 |         ik = (i0 * MIN(j0, l0) + j0 * MIN(i0, l0) + k * k) % 20
      |                                                                ^
      |                                                                ;
   18 |         jk = (i0 % 10 - k) * (j0 % 10 + k) * (l0 % 10 - k) % 25;
      |         ~~                                                      

moscow@moscow:~/Рабочий стол/For Labs/ForLabs/Lab9$ vim lab9programm.c

moscow@moscow:~/Рабочий стол/For Labs/ForLabs/Lab9$ gcc -std=c99 -Wall -pedantic lab9programm.c

moscow@moscow:~/Рабочий стол/For Labs/ForLabs/Lab9$ ./a.out
ПРОМАХ! Точка не попала в заданную область плоскости не более, чем за 50 шагов.
Время окончания движения: 50 шагов.
Координаты точки: (i = 10, j = 20).
Значение динамического параметра движения: l = 25.

moscow@moscow:~/Рабочий стол/For Labs/ForLabs/Lab9$ touch lab9pr_var2.c

moscow@moscow:~/Рабочий стол/For Labs/ForLabs/Lab9$ vim lab9pr_var2.c

moscow@moscow:~/Рабочий стол/For Labs/ForLabs/Lab9$ gcc -std=c99 -Wall -pedantic lab9pr_var2.c
lab9pr_var2.c: In function ‘MOD’:
lab9pr_var2.c:6:5: warning: type of ‘a’ defaults to ‘int’ [-Wimplicit-int]
    6 | int MOD(a, b){
      |     ^~~
lab9pr_var2.c:6:5: warning: type of ‘b’ defaults to ‘int’ [-Wimplicit-int]
lab9pr_var2.c: In function ‘main’:
lab9pr_var2.c:32:22: warning: ‘i0’ may be used uninitialized [-Wmaybe-uninitialized]
   32 |         ik = MOD((i0 * MIN(j0, l0) + j0 * MIN(i0, l0) + k * k), 20);
      |                      ^

moscow@moscow:~/Рабочий стол/For Labs/ForLabs/Lab9$ vim lab9pr_var2.c

moscow@moscow:~/Рабочий стол/For Labs/ForLabs/Lab9$ gcc -std=c99 -Wall -pedantic lab9pr_var2.c
lab9pr_var2.c: In function ‘main’:
lab9pr_var2.c:32:27: warning: ‘i0’ may be used uninitialized [-Wmaybe-uninitialized]
   32 |         auxiliary_ik = i0 * MIN(j0, l0) + j0 * MIN(i0, l0) + k * k;
      |                           ^

moscow@moscow:~/Рабочий стол/For Labs/ForLabs/Lab9$ ./a.out
ПРОМАХ! Точка не попала в заданную область плоскости не более, чем за 50 шагов.
Время окончания движения: 50 шагов.
Координаты точки: (i = 7, j = 22).
Значение динамического параметра движения: l = 31.
```
   
7. **Замечания автора** по существу работы: С с нуля - это испытание.
8. **Выводы**: Во время выполнения лабораторной работы я частично изучила синтаксис языка С, составила первую "солидную" программу и отладила её. Приобритённые знания и умения пригодятся мне по прямому назначению,
так как хороший программист должен знать несколько языков, а С - довольно хороший выбор. Больше времени потратила на изучение языка, нежели на написание самой программы, так как я знала, как решить задачу,
но на Python, а не на С, отчего пришлось искать различные обучающие ресурсы. Само задание показалось не столь трудным, сколь проверяющим внимательность, что тоже важно, так как все горькие ошибки происходят именно из-за неё.
