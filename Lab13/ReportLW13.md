# Отчет по лабораторной работе № 13
## по курсу "Фундаментальная информатика"

Студент группы М8О-108Б-23 Федорова Екатерина Васильевна

Работа выполнена 

Преподаватель: каф. 806 Севастьянов Виктор Сергеевич

1. **Тема**: Множества
2. **Цель работы**: Практикум по курсам "Основы информатики" и "Алгоритмы и структуры данных", работа с множествами.
3. **Задание (вариант №17)**:

Входные строки представляют собой последовательности слов, разделенных пробелами, 
запятыми, табуляциями или границами строк. В соответствии с вариантом задания составить программу 
проверки характеристик введенных последовательностей слов и печати развернутого ответа. Тестирование 
проводить не менее чем на трех строках вплоть до конца входного файла. В качестве алфавита берется один 
из европейских алфавитов, соответствующих заданию (кириллица, греческий, латиница,...). При использовании 
русских букв необходимо учитывать особенности их кодировки на разных платформах и лексические стандарты конкретных 
систем программирования.

Вариант задания: указать, имеется ли два соседних слова с пересекающимся набором гласных.

4. **Идея, метод, алгоритм решения задачи**:

Алфавит взят латиницей. Данную задачу планирую решать при помощи состояний. В переменные будут записываться все встречающиеся гласные 
слова, после чего сравниваться. Если найдётся такая пара слов, то результат сохраним для будущего вывода, 
а специально заведённый флаг поставим в позицию 1 (True).

5. **Сценарий выполнения работы**: 

Для решения использую 2 различных состояния: WORD и CONNECTION.

WORD.

Начальное и "главное" состояние: считывает буквы слова, запоминает их  переменной `word_2` и все гласные 
записывает в переменную `set_word_2`. При встрече с символом-разделителем, переводит в состояние CONNECTION.

CONNECTION.

Состояние, проверяющее условие. Если хоть какие-то гласные пересекаются, то переменная-флаг принимает значение 1, 
а слова добавляются в результирующий список.

Проверка корректной обработки символов-разделителей и конца файла:
```
moscow@moscow:~/Рабочий стол/For Labs/ForLabs/Lab13$ ./a.out
a ae
e	ei

We found 3 neighboring pairs of words with intersecting vowels:
<<a>> and <<ae>>;
<<ae>> and <<e>>;
<<e>> and <<ei>>;
and took them out.
```
Проверка на корректную обработку всех гласных букв:
```
moscow@moscow:~/Рабочий стол/For Labs/ForLabs/Lab13$ ./a.out
ee ee
qq qq
ww ww
rr rr
tt tt
yy yy
uu uu
ii ii
oo oo
pp pp
aa aa
ss ss
dd dd
ff ff
gg gg
hh hh
jj jj
kk kk
ll ll
zz zz
xx xx
cc cc
vv vv
bb bb
nn nn
mm mm

We found 6 neighboring pairs of words with intersecting vowels:
<<ee>> and <<ee>>;
<<yy>> and <<yy>>;
<<uu>> and <<uu>>;
<<ii>> and <<ii>>;
<<oo>> and <<oo>>;
<<aa>> and <<aa>>;
and took them out.
```

Проверка на поиск пересечений гласных в словах:
```
moscow@moscow:~/Рабочий стол/For Labs/ForLabs/Lab13$ ./a.out
qwertyuiop asdfghjkl zxcvbnm
qwer wert tyui tyuio
asd ghj asd
zxci6 io7*76 io

We found 4 neighboring pairs of words with intersecting vowels:
<<qwer>> and <<wert>>;
<<tyui>> and <<tyuio>>;
<<zxci6>> and <<io7*76>>;
<<io7*76>> and <<io>>;
and took them out.
```

6. **Протокол**:

Программа:
```
#include <stdio.h>
#include <ctype.h>
#include <string.h>

typedef enum _kState
{
	WORD,
	CONNECTION
} kState;

unsigned int char_to_set(char literal){
    literal = tolower(literal);
    if(literal < 'a' || literal > 'z'){
        return 0;
    }
    else{
        return (1 << (literal-'a'));
    }
}

unsigned int vowel_generation(void){
    unsigned int gen = 0;
    gen |= (1 << ('e'-'a'));
    gen |= (1 << ('y'-'a'));
    gen |= (1 << ('u'-'a'));
    gen |= (1 << ('i'-'a'));
    gen |= (1 << ('o'-'a'));
    gen |= (1 << ('a'-'a'));
    return gen;
}

int is_delimiter(int literal){
    if (literal == ' ' || literal == ',' || literal == '\t' || literal == '\n'){
        return 1;
    }
    return 0;
}

int main(void){
	char ch;
	unsigned int VOWELS  = 17842449;
	unsigned int set_word_1 = 0, set_word_2 = 0;
	int flag_of_connection = 0;
	char result[1000000] = {0}, word_1[1000] = {0}, word_2[1000] = {0};
	int index = 0, count = 0;
	kState state = WORD;
	while ((ch = getchar()) != EOF){
		switch (state)
		{
			case WORD:
			{
			    if (is_delimiter(ch)) state = CONNECTION;
			    else{
			        set_word_2 |= char_to_set(ch);
			        word_2[index] = ch;
			        index++;
			    }
			}
			break;
			
			case CONNECTION:
			{
			    set_word_2 = set_word_2 & VOWELS;
			    if((set_word_2 & set_word_1) != 0){
			        flag_of_connection = 1;
			        strcat(result, "<<");
			        strcat(result, word_1);
			        strcat(result, ">> and <<");
			        strcat(result, word_2);
			        strcat(result, ">>;\n");
			        count++;
			    }
			    index = 1;
			    set_word_1 = set_word_2 & VOWELS;
			    set_word_2 = 0;
			    set_word_2 |= char_to_set(ch);
			    strcpy(word_1, word_2);
			    memset(word_2, 0, strlen(word_2) * sizeof(int));
			    word_2[0] = ch;
			    state = WORD;
			}
			break;
		}
	}
	set_word_2 = set_word_2 & VOWELS;
	if((set_word_2 & set_word_1) != 0){
		flag_of_connection = 1;
		strcat(result, "<<");
		strcat(result, word_1);
		strcat(result, ">> and <<");
		strcat(result, word_2);
		strcat(result, ">>;\n");
		count++;
	}
	
	if (flag_of_connection){
	    printf("\n\nWe found %d neighboring pairs of words with intersecting vowels:\n%sand took them out.\n", count, result);
	}
	else{
	    printf("\n\nThere are no neighboring words with intersecting vowels.\n");
	}
    return 0;
}
```

7. **Замечания автора** по существу работы: Python удобнее в работе с переменными.
8. **Выводы**: во время выполнения данной лабораторной работы я осмелилась наконец притронуться к массивам на языке С и к строкам,
пришлось научиться базово работать с ними, а также осознала, что операция `!=` более приоритетная, чем `&` (я пыталась найти ошибку несколько часов).
К тому же мне понравилось интересное представление множества символов через переменную `unsigned int` - просто и одновременно гениально.
