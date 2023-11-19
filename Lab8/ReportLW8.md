# Отчет по лабораторной работе № 8
## по курсу "Фундаментальная информатика"

Студент группы М8О-108Б-23 Федорова Екатерина Васильевна

Работа выполнена 

Преподаватель: каф. 806 Севастьянов Виктор Сергеевич

1. **Тема**: Системы программирования на языке Си.
2. **Цель работы**: изучение конкретной системы программирования на Си и получение навыков подготовки текстов и отладки программ.
3. **Задание**:
  - изучить и освоить возможности лабораторной СП по содержащейся в практикуме документации и другим источникам подготовки текстов, в том числе основные этапы процесса компиляции и подготовки программ.
  - составить и отладить программу в терминальном классе.
4. **Идея, метод, алгоритм решения задачи**: заварить чай и сесть за изучение темы.
5. **Сценарий выполнения работы**: в начале пришлось скачать и установить все недостающие компаненты (например, vim), а также обновить gcc и операционную систему. После этого же приступить к выполнению лабораторной работы по инструкции из методички. Помимо этого пришлось искать разбор команд в редакторе vim, чтобы суметь написать программу на Си.
6. **Протокол**:

Простейшая программа, выводящая "Htllo, World!"

```
#include <stdio.h>

int main(){
        printf("Hello, World!\n");
        return 0;
}               

```
Как она выглядит в редакторе:

![Снимок экрана от 2023-11-19 18-42-57](https://github.com/Ekaterina108B/ForLabs/assets/144663808/9346cf97-9d2c-477c-9fd4-f9a712642ca0)

Листинг:

```
moscow@moscow:~/Рабочий стол/For Labs/ForLabs$ mkdir Lab8

moscow@moscow:~/Рабочий стол/For Labs/ForLabs$ cd Lab8

moscow@moscow:~/Рабочий стол/For Labs/ForLabs/Lab8$ touch lab8.c

moscow@moscow:~/Рабочий стол/For Labs/ForLabs/Lab8$ vim lab8.c
Команда «vim» не найдена, но может быть установлена с помощью:
sudo apt install vim         # version 2:8.2.3995-1ubuntu2.13, or
sudo apt install vim-tiny    # version 2:8.2.3995-1ubuntu2.13
sudo apt install vim-athena  # version 2:8.2.3995-1ubuntu2.13
sudo apt install vim-gtk3    # version 2:8.2.3995-1ubuntu2.13
sudo apt install vim-nox     # version 2:8.2.3995-1ubuntu2.13
sudo apt install neovim      # version 0.6.1-3

moscow@moscow:~/Рабочий стол/For Labs/ForLabs/Lab8$ sudo apt install vim
[sudo] пароль для moscow: 
Чтение списков пакетов… Готово
Построение дерева зависимостей… Готово
Чтение информации о состоянии… Готово         
...
Обрабатываются триггеры для man-db (2.10.2-1) …

moscow@moscow:~/Рабочий стол/For Labs/ForLabs/Lab8$ vim lab8.c

moscow@moscow:~/Рабочий стол/For Labs/ForLabs/Lab8$ gcc -std=c99 -Wall -pedantic lab8.c

moscow@moscow:~/Рабочий стол/For Labs/ForLabs/Lab8$ ./a.out
Hello, World!

moscow@moscow:~/Рабочий стол/For Labs/ForLabs/Lab8$ gcc --version
gcc (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0
Copyright (C) 2021 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

moscow@moscow:~/Рабочий стол/For Labs/ForLabs/Lab8$ git status
Текущая ветка: master
Эта ветка соответствует «origin/master».
Неотслеживаемые файлы:
  (используйте «git add <файл>...», чтобы добавить в то, что будет включено в коммит)
	./
индекс пуст, но есть неотслеживаемые файлы
(используйте «git add», чтобы проиндексировать их)

moscow@moscow:~/Рабочий стол/For Labs/ForLabs/Lab8$ git branch la

moscow@moscow:~/Рабочий стол/For Labs/ForLabs/Lab8$ git checkout la
Переключились на ветку «la»

moscow@moscow:~/Рабочий стол/For Labs/ForLabs/Lab8$ git add lab8.c

moscow@moscow:~/Рабочий стол/For Labs/ForLabs/Lab8$ git add a.out

moscow@moscow:~/Рабочий стол/For Labs/ForLabs/Lab8$ touch ReportLW8.md

moscow@moscow:~/Рабочий стол/For Labs/ForLabs/Lab8$ git add ReportLW8.md

moscow@moscow:~/Рабочий стол/For Labs/ForLabs/Lab8$ git commit
[la 5495a82] Almost all of the work
 3 files changed, 6 insertions(+)
 create mode 100644 Lab8/ReportLW8.md
 create mode 100755 Lab8/a.out
 create mode 100644 Lab8/lab8.c

moscow@moscow:~/Рабочий стол/For Labs/ForLabs/Lab8$ git push origin --all
Перечисление объектов: 6, готово.
Подсчет объектов: 100% (6/6), готово.
При сжатии изменений используется до 16 потоков
Сжатие объектов: 100% (5/5), готово.
Запись объектов: 100% (5/5), 2.61 КиБ | 2.61 МиБ/с, готово.
Всего 5 (изменений 1), повторно использовано 0 (изменений 0), повторно использовано пакетов 0
remote: Resolving deltas: 100% (1/1), completed with 1 local object.
remote: 
remote: Create a pull request for 'la' on GitHub by visiting:
remote:      https://github.com/Ekaterina108B/ForLabs/pull/new/la
remote: 
To github.com:Ekaterina108B/ForLabs.git
* [new branch]      la -> la

moscow@moscow:~/Рабочий стол/For Labs/ForLabs$ git merge la
Обновление dc3d046..5495a82
Fast-forward
 Lab8/ReportLW8.md |   0
 Lab8/a.out        | Bin 0 -> 15960 bytes
 Lab8/lab8.c       |   6 ++++++
 3 files changed, 6 insertions(+)
 create mode 100644 Lab8/ReportLW8.md
 create mode 100755 Lab8/a.out
 create mode 100644 Lab8/lab8.c

moscow@moscow:~/Рабочий стол/For Labs/ForLabs$ git branch -d la
Ветка la удалена (была 5495a82).

moscow@moscow:~/Рабочий стол/For Labs/ForLabs$ git push origin --all
Всего 0 (изменений 0), повторно использовано 0 (изменений 0), повторно использовано пакетов 0
To github.com:Ekaterina108B/ForLabs.git
   dc3d046..5495a82  master -> master

moscow@moscow:~/Рабочий стол/For Labs/ForLabs$ git push origin -d la
To github.com:Ekaterina108B/ForLabs.git
- [deleted]         la

```
    
7. **Замечания автора** по существу работы: -.
8. **Выводы**: В процессе работы мне пришлось проявить усидчивость, чтобы найти информацию о работе в vim. Я записала свою первую программу на Си (пройденные некогда давным-давно уроки по С++ не пропали даром!), скомпилировала её и запустила. Понравилось, что я притрагиваюсь и наблюдаю за процессами, которые обычно происходят "под капотом", что очень полезно для понимания. Сама работа не вызвала серьёзных затруднений, потратила лишь кружку чая и 6 часов ожидания обновления gcc.
