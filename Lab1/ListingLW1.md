# Отчет по лабораторной работе № 1
## по курсу "Фундаментальная информатика"

Студент группы М8О-108Б-23 Федорова Екатерина Васильевна

Работа выполнена

Преподаватель: каф. 806 Севастьянов Виктор Сергеевич

1. **Тема**: Знакомство с Git. 
2. **Цель работы**: научиться работать с Git. 
3. **Задание**: 
- завести репозиторий (**общий под все лабораторные работы с отдельной папкой под каждую лр!**)
- отчет с листингом в Markdown (листинг - ctrl+c -> ctrl+v из терминала с форматированием в markdown)
- создать отдельную ветку в репозитории под задание
- создать коммит с листингом и отчетом
- смержить ветку в мейн
4. **Идея, метод, алгоритм решения задачи**: -. 
5. **Сценарий выполнения работы**: -. 
6. **Протокол**: 
```
tsar_belyash@Tsar--Belyash:~/Рабочий стол/ForLabs$ git init
подсказка: Using 'master' as the name for the initial branch. This default branch name
подсказка: is subject to change. To configure the initial branch name to use in all
подсказка: of your new repositories, which will suppress this warning, call:
подсказка: 
подсказка: 	git config --global init.defaultBranch <name>
подсказка: 
подсказка: Names commonly chosen instead of 'master' are 'main', 'trunk' and
подсказка: 'development'. The just-created branch can be renamed via this command:
подсказка: 
подсказка: 	git branch -m <name>
Инициализирован пустой репозиторий Git в /home/tsar_belyash/Рабочий стол/ForLabs/.git/

tsar_belyash@Tsar--Belyash:~/Рабочий стол/ForLabs$ touch README.md

tsar_belyash@Tsar--Belyash:~/Рабочий стол/ForLabs$ git add README.md

tsar_belyash@Tsar--Belyash:~/Рабочий стол/ForLabs$ git commit
[master (корневой коммит) ed63703] The first commit
 1 file changed, 0 insertions(+), 0 deletions(-)
 create mode 100644 README.md

tsar_belyash@Tsar--Belyash:~/Рабочий стол/ForLabs$ git status
Текущая ветка: master
нечего коммитить, нет изменений в рабочем каталоге

tsar_belyash@Tsar--Belyash:~/Рабочий стол/ForLabs$ git remote add origin git@github.com:Ekaterina108B/ForLabs.git

tsar_belyash@Tsar--Belyash:~/Рабочий стол/ForLabs$ git push -u origin master
Перечисление объектов: 3, готово.
Подсчет объектов: 100% (3/3), готово.
Запись объектов: 100% (3/3), 218 байтов | 218.00 КиБ/с, готово.
Всего 3 (изменений 0), повторно использовано 0 (изменений 0), повторно использовано пакетов 0
To github.com:Ekaterina108B/ForLabs.git
 * [new branch]      master -> master
Ветка «master» отслеживает внешнюю ветку «master» из «origin».

tsar_belyash@Tsar--Belyash:~/Рабочий стол/ForLabs$ mkdir Lab1

tsar_belyash@Tsar--Belyash:~/Рабочий стол/ForLabs$ cd Lab1

tsar_belyash@Tsar--Belyash:~/Рабочий стол/ForLabs/Lab1$ touch readme.md

tsar_belyash@Tsar--Belyash:~/Рабочий стол/ForLabs/Lab1$ git status
Текущая ветка: master
Эта ветка соответствует «origin/master».
Неотслеживаемые файлы:
  (используйте «git add <файл>...», чтобы добавить в то, что будет включено в коммит)
	./
индекс пуст, но есть неотслеживаемые файлы
(используйте «git add», чтобы проиндексировать их)

tsar_belyash@Tsar--Belyash:~/Рабочий стол/ForLabs/Lab1$ git add readme.md

tsar_belyash@Tsar--Belyash:~/Рабочий стол/ForLabs/Lab1$ git push -u origin master
Ветка «master» отслеживает внешнюю ветку «master» из «origin».
Everything up-to-date

tsar_belyash@Tsar--Belyash:~/Рабочий стол/ForLabs/Lab1$ git status
Текущая ветка: master
Эта ветка соответствует «origin/master».
Изменения, которые будут включены в коммит:
  (используйте «git restore --staged <файл>...», чтобы убрать из индекса)
	новый файл:    readme.md

tsar_belyash@Tsar--Belyash:~/Рабочий стол/ForLabs/Lab1$ git commit
[master 14a5d1a] New file and new dir
 1 file changed, 0 insertions(+), 0 deletions(-)
 create mode 100644 Lab1/readme.md

tsar_belyash@Tsar--Belyash:~/Рабочий стол/ForLabs/Lab1$ git push -u origin master
Перечисление объектов: 4, готово.
Подсчет объектов: 100% (4/4), готово.
При сжатии изменений используется до 4 потоков
Сжатие объектов: 100% (2/2), готово.
Запись объектов: 100% (3/3), 321 байт | 160.00 КиБ/с, готово.
Всего 3 (изменений 0), повторно использовано 0 (изменений 0), повторно использовано пакетов 0
To github.com:Ekaterina108B/ForLabs.git
   ed63703..14a5d1a  master -> master
Ветка «master» отслеживает внешнюю ветку «master» из «origin».

tsar_belyash@Tsar--Belyash:~/Рабочий стол/ForLabs/Lab1$ git branch lab1

tsar_belyash@Tsar--Belyash:~/Рабочий стол/ForLabs/Lab1$ git checkout lab1
Переключились на ветку «lab1»

tsar_belyash@Tsar--Belyash:~/Рабочий стол/ForLabs/Lab1$ touch ListingLW1.md

tsar_belyash@Tsar--Belyash:~/Рабочий стол/ForLabs/Lab1$ git add ListingLW1.md

tsar_belyash@Tsar--Belyash:~/Рабочий стол/ForLabs/Lab1$ git commit
[lab1 a5b4db1] New branch and new file with Listing
 1 file changed, 0 insertions(+), 0 deletions(-)
 create mode 100644 Lab1/ListingLW1.md

tsar_belyash@Tsar--Belyash:~/Рабочий стол/ForLabs/Lab1$ git push origin --all
Перечисление объектов: 5, готово.
Подсчет объектов: 100% (5/5), готово.
При сжатии изменений используется до 4 потоков
Сжатие объектов: 100% (3/3), готово.
Запись объектов: 100% (3/3), 351 байт | 351.00 КиБ/с, готово.
Всего 3 (изменений 0), повторно использовано 0 (изменений 0), повторно использовано пакетов 0
remote: 
remote: Create a pull request for 'lab1' on GitHub by visiting:
remote:      https://github.com/Ekaterina108B/ForLabs/pull/new/lab1
remote: 
To github.com:Ekaterina108B/ForLabs.git
 * [new branch]      lab1 -> lab1

tsar_belyash@Tsar--Belyash:~/Рабочий стол/ForLabs/Lab1$ git checkout master
Переключились на ветку «master»
Эта ветка соответствует «origin/master».

tsar_belyash@Tsar--Belyash:~/Рабочий стол/ForLabs/Lab1$ git merge lab1Обновление 14a5d1a..a5b4db1
Fast-forward
 Lab1/ListingLW1.md | 0
 1 file changed, 0 insertions(+), 0 deletions(-)
 create mode 100644 Lab1/ListingLW1.md

tsar_belyash@Tsar--Belyash:~/Рабочий стол/ForLabs/Lab1$ git branch -d lab1
Ветка lab1 удалена (была a5b4db1).

tsar_belyash@Tsar--Belyash:~/Рабочий стол/ForLabs/Lab1$ git status
Текущая ветка: master
Ваша ветка опережает «origin/master» на 1 коммит.
  (используйте «git push», чтобы опубликовать ваши локальные коммиты)
нечего коммитить, нет изменений в рабочем каталоге

tsar_belyash@Tsar--Belyash:~/Рабочий стол/ForLabs/Lab1$ git push origin --all
Всего 0 (изменений 0), повторно использовано 0 (изменений 0), повторно использовано пакетов 0
To github.com:Ekaterina108B/ForLabs.git
   14a5d1a..a5b4db1  master -> master

tsar_belyash@Tsar--Belyash:~/Рабочий стол/ForLabs/Lab1$ git push origin -d lab1
To github.com:Ekaterina108B/ForLabs.git
 - [deleted]         lab1

```
7. **Замечания автора** по существу работы: -. 
8. **Выводы**: в процессе выполнения лабораторной работы познакомилась с "базой", с основой Git: узнала, для чего он нужен, разобралась, что такое ветки и коммиты, изучила основные команды. Во время лабораторной работы я научилась создавать репозитории, коммиты, ветки (а также сливать их), пушить изменения в GitHub, а также скачивать их из него. 
