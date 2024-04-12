# Отчет по лабораторной работе № 6
## по курсу "Фундаментальная информатика"

Студент группы М8О-108Б-23 Федорова Екатерина Васильевна

Работа выполнена 

Преподаватель: каф. 806 Севастьянов Виктор Сергеевич

1. **Тема**: Инструментальные средства UNIX, алгоритмы и структуры данных.
2. **Цель работы**: Обработка последовательной файловой структуры на языке Си.
3. **Задание (вариант №26)**: 
Разработать последовательную структуру данных для представления простейшей базы данных на файлах в СП Си. Составить программу генерации внешнего нетекстового файла заданной структуры,
содержащего представительный набор записей (15-20). Распечатать содержимое файла; выполнить над ним заданное действие и распечатать результат. 
Сведения о вступительных экзаменах абитуриентов: фамилия, инициалы, пол, номер школы, наличие медали, оценки в баллах и зачет/незачет по сочинению. 
Найти абитуриентов-немедалистов, суммарный балл которых выше среднего.
4. **Идея, метод, алгоритм решения задачи**:

Файл "print.c" содержит следующую функцию:

1. `main(int argc, char *argv[]):`
- Проверяет количество переданных аргументов командной строки, если их количество не равно 2, выводит сообщение об использовании программы и завершает выполнение.
- Открывает файл с данными об участниках для чтения.
- Использует функцию `applicant_read_bin` для считывания информации об участнике из файла в структуру "Applicant".
- Затем вызывает функцию "applicant_print" для вывода информации об участнике в консоль.
- После завершения работы с файлом, закрывает его.

Файл "io.h" содержит объявления следующих функций:
1. `void applicant_read_bin(Applicant *a, FILE *in):`
- Функция считывает информацию об участнике из бинарного файла и записывает её в структуру "Applicant".
2. `void applicant_print(Applicant *a):`
- Функция выводит информацию об участнике в консоль.
3. `void applicants_write_bin(Applicant *a, FILE *out):`
- Функция записывает информацию об участнике в бинарный файл.

Файл "io.c" содержит реализацию вышеописанных функций для работы с данными об участниках.

Файл "generate.c" содержит следующую функцию:
1. `main(int argc, char *argv[]):`
- Проверяет количество переданных аргументов командной строки. Если их количество не равно 3, выводит сообщение об использовании программы и завершает выполнение.
- Открывает входной файл для чтения и выходной файл для записи в бинарном режиме.
- Если есть проблемы с открытием файлов, выводит соответствующие сообщения об ошибке.
- Создает структуру "Applicant".
- Считывает информацию об участнике из текстового файла с помощью функции `applicant_read_txt` и записывает ее в бинарный файл с помощью функции `applicant_write_bin`.
- После завершения работы с файлами, закрывает их.

Файл "execute.c" содержит следующие функции:
1. `float average(FILE *in):`
- Эта функция вычисляет среднее значение оценок по трем предметам (русский язык, математика, информатика) для участников, данные о которых считываются из бинарного файла.
- В цикле считывает данные об участниках с помощью функции `applicant_read_bin`.
- Подсчитывает сумму оценок и количество участников.
- Если данные в файле некорректны, выводит сообщение об ошибке и завершает выполнение программы.
- Возвращает среднее значение оценок.

2. `main(int argc, char *argv[]):`
- Эта функция является точкой входа в программу.
- Проверяет количество переданных аргументов командной строки. Если их количество не равно 2, выводит сообщение об использовании программы и завершает выполнение.
- Открывает файл с данными об участниках в бинарном режиме.
- Вычисляет среднюю оценку с помощью функции `average`.
- Затем считывает информацию об участниках и проверяет, у кого сумма оценок превышает среднюю и у кого нет медали, и выводит это в консоль.
- После завершения работы с файлом, закрывает его.

5. **Сценарий выполнения работы**:
Запуск программы по умолчанию
```
moscow@moscow:~/Рабочий стол/For Labs/ForLabs/CP6$ make
cc    -c -o io.o io.c
cc    -c -o generate.o generate.c
gcc -std=c99 -pedantic -Wall -o gen io.o generate.o
cc    -c -o print.o print.c
gcc -std=c99 -pedantic -Wall -o print io.o print.o
cc    -c -o execute.o execute.c
gcc -std=c99 -pedantic -Wall -o exe io.o execute.o
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./gen input output
==6779== Memcheck, a memory error detector
==6779== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==6779== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==6779== Command: ./gen input output
==6779== 
==6779== 
==6779== HEAP SUMMARY:
==6779==     in use at exit: 0 bytes in 0 blocks
==6779==   total heap usage: 4 allocs, 4 frees, 9,136 bytes allocated
==6779== 
==6779== All heap blocks were freed -- no leaks are possible
==6779== 
==6779== For lists of detected and suppressed errors, rerun with: -s
==6779== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./print output
==6780== Memcheck, a memory error detector
==6780== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==6780== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==6780== Command: ./print output
==6780== 
Name: Akranova QW
Gender: F
School: 25
Medal: no
Russian language: 0
Profile math: 0
Informatics: 0
Essay: fail

Name: Alvehov ER
Gender: M
School: 33
Medal: no
Russian language: 0
Profile math: 0
Informatics: 0
Essay: fail

Name: Bigarov TY
Gender: M
School: 4
Medal: no
Russian language: 0
Profile math: 0
Informatics: 0
Essay: fail

Name: Bavanora UI
Gender: F
School: 81
Medal: no
Russian language: 100
Profile math: 100
Informatics: 0
Essay: fail

Name: Bechiveg OP
Gender: M
School: 32
Medal: no
Russian language: 0
Profile math: 0
Informatics: 0
Essay: fail

Name: Bosirov AS
Gender: M
School: 46
Medal: no
Russian language: 100
Profile math: 100
Informatics: 0
Essay: fail

Name: Grigrchuk DF
Gender: M
School: 58
Medal: no
Russian language: 0
Profile math: 0
Informatics: 0
Essay: fail

Name: Dmitrovana GH
Gender: M
School: 10
Medal: no
Russian language: 0
Profile math: 0
Informatics: 0
Essay: fail

Name: Karavecha JK
Gender: F
School: 32
Medal: no
Russian language: 0
Profile math: 0
Informatics: 0
Essay: fail

Name: Kinarsov LZ
Gender: M
School: 77
Medal: yes
Russian language: 100
Profile math: 100
Informatics: 100
Essay: fail

Name: Mamagaev XC
Gender: M
School: 5
Medal: no
Russian language: 0
Profile math: 0
Informatics: 0
Essay: fail

Name: Ratich VB
Gender: M
School: 37
Medal: no
Russian language: 0
Profile math: 0
Informatics: 0
Essay: fail

Name: Timoschuk NM
Gender: F
School: 17
Medal: no
Russian language: 100
Profile math: 100
Informatics: 100
Essay: fail

Name: Tovirsyan QW
Gender: M
School: 17
Medal: no
Russian language: 0
Profile math: 0
Informatics: 0
Essay: fail

==6780== 
==6780== HEAP SUMMARY:
==6780==     in use at exit: 0 bytes in 0 blocks
==6780==   total heap usage: 3 allocs, 3 frees, 5,592 bytes allocated
==6780== 
==6780== All heap blocks were freed -- no leaks are possible
==6780== 
==6780== For lists of detected and suppressed errors, rerun with: -s
==6780== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./exe output
==6781== Memcheck, a memory error detector
==6781== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==6781== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==6781== Command: ./exe output
==6781== 
Bavanora UI, school 81
Bosirov AS, school 46
Timoschuk NM, school 17
==6781== 
==6781== HEAP SUMMARY:
==6781==     in use at exit: 0 bytes in 0 blocks
==6781==   total heap usage: 3 allocs, 3 frees, 5,592 bytes allocated
==6781== 
==6781== All heap blocks were freed -- no leaks are possible
==6781== 
==6781== For lists of detected and suppressed errors, rerun with: -s
==6781== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

Запуск тестовых данных (5 штук):
```
moscow@moscow:~/Рабочий стол/For Labs/ForLabs/CP6$ make tests
gcc -std=c99 -pedantic -Wall -o gen io.o generate.o
gcc -std=c99 -pedantic -Wall -o exe io.o execute.o
./gen input output
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./exe output
==6802== Memcheck, a memory error detector
==6802== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==6802== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==6802== Command: ./exe output
==6802== 
Bavanora UI, school 81
Bosirov AS, school 46
Timoschuk NM, school 17
==6802== 
==6802== HEAP SUMMARY:
==6802==     in use at exit: 0 bytes in 0 blocks
==6802==   total heap usage: 3 allocs, 3 frees, 5,592 bytes allocated
==6802== 
==6802== All heap blocks were freed -- no leaks are possible
==6802== 
==6802== For lists of detected and suppressed errors, rerun with: -s
==6802== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
./gen input2 output
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./exe output
==6813== Memcheck, a memory error detector
==6813== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==6813== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==6813== Command: ./exe output
==6813== 
Mamagaev XC, school 5
Ratich VB, school 37
==6813== 
==6813== HEAP SUMMARY:
==6813==     in use at exit: 0 bytes in 0 blocks
==6813==   total heap usage: 3 allocs, 3 frees, 5,592 bytes allocated
==6813== 
==6813== All heap blocks were freed -- no leaks are possible
==6813== 
==6813== For lists of detected and suppressed errors, rerun with: -s
==6813== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
./gen input3 output
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./exe output
==6815== Memcheck, a memory error detector
==6815== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==6815== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==6815== Command: ./exe output
==6815== 
Alvehov ER, school 33
Grigrchuk DF, school 58
Dmitrovana GH, school 10
Ratich VB, school 37
==6815== 
==6815== HEAP SUMMARY:
==6815==     in use at exit: 0 bytes in 0 blocks
==6815==   total heap usage: 3 allocs, 3 frees, 5,592 bytes allocated
==6815== 
==6815== All heap blocks were freed -- no leaks are possible
==6815== 
==6815== For lists of detected and suppressed errors, rerun with: -s
==6815== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
./gen input4 output
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./exe output
==6817== Memcheck, a memory error detector
==6817== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==6817== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==6817== Command: ./exe output
==6817== 
Akranova QW, school 25
Bechiveg OP, school 32
Grigrchuk DF, school 58
Mamagaev XC, school 5
Ratich VB, school 37
==6817== 
==6817== HEAP SUMMARY:
==6817==     in use at exit: 0 bytes in 0 blocks
==6817==   total heap usage: 3 allocs, 3 frees, 5,592 bytes allocated
==6817== 
==6817== All heap blocks were freed -- no leaks are possible
==6817== 
==6817== For lists of detected and suppressed errors, rerun with: -s
==6817== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
./gen input5 output
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./exe output
==6819== Memcheck, a memory error detector
==6819== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==6819== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==6819== Command: ./exe output
==6819== 
Dmitrovana GH, school 10
Mamagaev XC, school 5
Tovirsyan QW, school 17
==6819== 
==6819== HEAP SUMMARY:
==6819==     in use at exit: 0 bytes in 0 blocks
==6819==   total heap usage: 3 allocs, 3 frees, 5,592 bytes allocated
==6819== 
==6819== All heap blocks were freed -- no leaks are possible
==6819== 
==6819== For lists of detected and suppressed errors, rerun with: -s
==6819== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
6. **Протокол**:
Файл applicant.h
```
#ifndef _APPLICANT_H_
#define _APPLICANT_H_

#define STR_SIZE 24

typedef struct{
    char name[STR_SIZE];
    char initials[STR_SIZE];
    char gender[STR_SIZE];
    int school;
    char medal[STR_SIZE];
    int rus;
    int math;
    int inf;
    char essay[STR_SIZE];
} Applicant;

#endif

```
Файл io.h
```
#ifndef _IO_H_
#define _IO_H_

#include "applicant.h"

int  applicant_read_txt(Applicant *a, FILE *in);
int  applicant_read_bin(Applicant *a, FILE *in);
void applicant_write_bin(Applicant *a, FILE *out);
void applicant_print(Applicant *a);

#endif
```
Файл io.c
```
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "applicant.h"
#include "io.h"

/* Applicant IO */
int applicant_read_txt(Applicant *a, FILE *in){
    fscanf(in, "%s", a->name);
    fscanf(in, "%s", a->initials);
    fscanf(in, "%s", a->gender);
    fscanf(in, "%d", &(a->school));
    fscanf(in, "%s", a->medal);
    fscanf(in, "%d", &(a->rus));
    fscanf(in, "%d", &(a->math));
    fscanf(in, "%d", &(a->inf));
    fscanf(in, "%s", a->essay);
    
    return !feof(in);

}

int  applicant_read_bin(Applicant *a, FILE *in){
    fread(a->name, sizeof(char), STR_SIZE, in);
    fread(a->initials, sizeof(char), STR_SIZE, in);
    fread(a->gender, sizeof(char), STR_SIZE, in);
    fread(&(a->school), sizeof(int), 1, in);
    fread(a->medal, sizeof(char), STR_SIZE, in);
    fread(&(a->rus), sizeof(int), 1, in);
    fread(&(a->math), sizeof(int), 1, in);
    fread(&(a->inf), sizeof(int), 1, in);
    fread(a->essay, sizeof(char), STR_SIZE, in);
    
    return !feof(in);
}

void applicant_write_bin(Applicant *a, FILE *out){
    fwrite(a->name, sizeof(char), STR_SIZE, out);
    fwrite(a->initials, sizeof(char), STR_SIZE, out);
    fwrite(a->gender, sizeof(char), STR_SIZE, out);
    fwrite(&(a->school), sizeof(int), 1, out);
    fwrite(a->medal, sizeof(char), STR_SIZE, out);
    fwrite(&(a->rus), sizeof(int), 1, out);
    fwrite(&(a->math), sizeof(int), 1, out);
    fwrite(&(a->inf), sizeof(int), 1, out);
    fwrite(a->essay, sizeof(char), STR_SIZE, out);
}

void applicant_print(Applicant *a){
    printf("Name: %s %s\n", a->name, a->initials);
    printf("Gender: %s\n", a->gender);
    printf("School: %d\n", a->school);
    printf("Medal: %s\n", a->medal);
    printf("Russian language: %d\n", a->rus);
    printf("Profile math: %d\n", a->math);
    printf("Informatics: %d\n", a->inf);
    printf("Essay: %s\n", a->essay);
    printf("\n");
}

```
Файл generate.c
```
#include <stdio.h>
#include <stdlib.h>

#include "applicant.h"
#include "io.h"

int main(int argc, char *argv[]){
    if (argc != 3){
        printf("Usage:\n\t./generate FILE_FROM FILE_TO\n");
        exit(0);
    }
    
    FILE *in = fopen(argv[1], "r");
    FILE *out = fopen(argv[2], "wb");
    
    if (!in){
        printf("I/O Error: can't open input file.\n");
        fclose(out);
        exit(1);
    }
    if (!out){
        printf("I/O Error: can't open output file.\n");
        fclose(in);
        exit(1);
    }
    
    Applicant a = {0};
    
    while (applicant_read_txt(&a, in)){
            applicant_write_bin(&a, out);
    }
    
    fclose(in);
    fclose(out);
    
    return 0;
}
```
Файл execute.c
```
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "applicant.h"
#include "io.h"

float average(FILE *in){
    double sum = 0;
    int count_of_applicants = 0;
    Applicant a;
    float result = 0;
    while(applicant_read_bin(&a, in)){
        sum = sum + a.rus + a.math + a.inf;
        count_of_applicants++;
    }
    if (count_of_applicants != 0){
        result = sum / count_of_applicants;
        return result;
    } else {
        printf("Error: incorrect data in the file.\n");
        fclose(in);
        exit(0);
    }
}


int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Usage:\n\t./execute DB_FILE\n");
        exit(0);
    }

    FILE *in = fopen(argv[1], "rb");
    if (!in) {
        printf("I/O Error: can't open file.\n");
        exit(1);
    }
    
    float aver = average(in);
    int sum = 0;
    Applicant a;
    rewind(in);
    
    while(applicant_read_bin(&a, in)){
        sum = a.rus + a.math + a.inf;
        if (sum > aver && strcmp(a.medal, "no") == 0){
            printf("%s %s, school %d\n", a.name, a.initials, a.school);
        }
    }
    
    fclose(in);
    
    return 0;
}
```

7. **Замечания автора** по существу работы: -.
8. **Выводы**: Работа была тяжёлой, полностью понять её смогла только после выполнения лабораторной №26. Долго отлаживала и искала единственную ошибку, которая заключалась в моей невнимательности.
С другой стороны, выполнить лабораторную можно было намного быстрее, чем это получилось у меня. Попытки-пытки. Задание отработала и закрепила полученный опыт работы с согласованием нескольких
файлов, хотя отношусь к этой лабораторной холодно, возвращаться бы не хотелось.
