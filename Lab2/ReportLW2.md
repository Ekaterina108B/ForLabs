tsar_belyash@Tsar--Belyash:~/Рабочий стол/ForLabs$ git status
Текущая ветка: master
Эта ветка соответствует «origin/master».
нечего коммитить, нет изменений в рабочем каталоге

tsar_belyash@Tsar--Belyash:~/Рабочий стол/ForLabs$ mkdir Lab2

tsar_belyash@Tsar--Belyash:~/Рабочий стол/ForLabs$ cd Lab2

tsar_belyash@Tsar--Belyash:~/Рабочий стол/ForLabs/Lab2$ touch readme.md

tsar_belyash@Tsar--Belyash:~/Рабочий стол/ForLabs/Lab2$ add readme.md
Команда «add» не найдена. Возможно, вы имели в виду:
  command 'hadd' from snap root-framework (v6-28-06)
  command 'adb' from deb adb (1:10.0.0+r36-9)
  command 'ddd' from deb ddd (1:3.3.12-5.3build1)
  command 'adr' from deb adr-tools (3.0.0-2)
  command 'dd' from deb coreutils (8.32-4.1ubuntu1)
  command 'aid' from deb id-utils (4.6.28-20200521ss15dab)
  command 'atd' from deb at (3.2.5-1ubuntu1)
  command 'and' from deb and (1.2.2-4.2)
  command 'pdd' from deb pdd (1.5-1)
  command 'ad' from deb netatalk (3.1.12~ds-9ubuntu0.22.04.1)
  command 'tdd' from deb devtodo (0.1.20+git20200830.0ad52b0-1)
  command 'axd' from deb afnix (3.5.0-3)
  command 'ldd' from deb libc-bin (2.35-0ubuntu3.3)
See 'snap info <snapname>' for additional versions.

tsar_belyash@Tsar--Belyash:~/Рабочий стол/ForLabs/Lab2$ git add readme.md

tsar_belyash@Tsar--Belyash:~/Рабочий стол/ForLabs/Lab2$ git commit
[master 2d8b4ca] create dir for lab2
 1 file changed, 0 insertions(+), 0 deletions(-)
 create mode 100644 Lab2/readme.md

tsar_belyash@Tsar--Belyash:~/Рабочий стол/ForLabs/Lab2$ git status
Текущая ветка: master
Ваша ветка опережает «origin/master» на 1 коммит.
  (используйте «git push», чтобы опубликовать ваши локальные коммиты)
нечего коммитить, нет изменений в рабочем каталоге

tsar_belyash@Tsar--Belyash:~/Рабочий стол/ForLabs/Lab2$ git push
Перечисление объектов: 4, готово.
Подсчет объектов: 100% (4/4), готово.
При сжатии изменений используется до 4 потоков
Сжатие объектов: 100% (2/2), готово.
Запись объектов: 100% (3/3), 343 байта | 171.00 КиБ/с, готово.
Всего 3 (изменений 0), повторно использовано 0 (изменений 0), повторно использовано пакетов 0
To github.com:Ekaterina108B/ForLabs.git
   5d3047c..2d8b4ca  master -> master

tsar_belyash@Tsar--Belyash:~/Рабочий стол/ForLabs/Lab2$ who

tsar_belyash tty2         2023-09-25 12:00 (tty2)

tsar_belyash@Tsar--Belyash:~/Рабочий стол/ForLabs/Lab2$ pwd
/home/tsar_belyash/Рабочий стол/ForLabs/Lab2

tsar_belyash@Tsar--Belyash:~/Рабочий стол/ForLabs/Lab2$ ls
readme.md

tsar_belyash@Tsar--Belyash:~/Рабочий стол/ForLabs/Lab2$ cp
cp: пропущен операнд, задающий файл
По команде «cp --help» можно получить дополнительную информацию.

tsar_belyash@Tsar--Belyash:~/Рабочий стол/ForLabs/Lab2$ cp --help
Использование: cp [ПАРАМЕТР]… [-T] ИСТОЧНИК НАЗНАЧЕНИЕ
       или:    cp [ПАРАМЕТР]… ИСТОЧНИК… КАТАЛОГ
       или:    cp [ПАРАМЕТР]… -t КАТАЛОГ ИСТОЧНИК…
Копирует ИСТОЧНИК в НАЗНАЧЕНИЕ, или несколько ИСТОЧНИКОВ в КАТАЛОГ.

Аргументы, обязательные для длинных параметров, обязательны и для коротких.
  -a, --archive                то же, что и -dPR --preserve=all
      --attributes-only        не копировать данные файла, только атрибуты
      --backup[=КОГДА]         создавать резервную копию каждого целевого
                               файла
  -b                           то же, что и --backup, но без аргумента
      --copy-contents          копировать содержимое специальных файлов при
                               рекурсивной обработке
  -d                           то же, что и --no-dereference --preserve=link
  -f, --force                  если невозможно открыть существующий файл, то
                               удалить его и попробовать ещё раз (этот параметр
                               игнорируется, если также указан параметр -n)
  -i, --interactive            спрашивать перед тем как переписывать
                               (отменяет ранее указанный параметр -n)
  -H                           следовать по символьным ссылкам в ИСТОЧНИКЕ
  -l, --link                   создавать жёсткие ссылки вместо копирования
  -L, --dereference            всегда следовать символьным ссылкам в ИСТОЧНИКЕ
  -n, --no-clobber             не перезаписывать существующий файл (отменяет
                               ранее указанный ключ -i)
  -P, --no-dereference         не следовать по символьным ссылкам в ИСТОЧНИКЕ
  -p                           то же, что и
                               --preserve=mode,ownership,timestamps
      --preserve[=СПИС_АТТР]   сохранять указанные атрибуты (по умолчанию:
                               mode,ownership,timestamps) и, если возможно,
                               дополнительные атрибуты: context, links, xattr,
                               all
      --no-preserve=СПИС_АТТР  не сохранять указанные атрибуты
      --parents                добавить исходный путь к КАТАЛОГУ
  -R, -r, --recursive          рекурсивно копировать каталоги
      --reflink[=КОГДА]        контролировать копии clone/CoW. См. ниже.
      --remove-destination     удалять каждый файл назначения перед
                               попыткой его открыть (обратно к --force)
      --sparse=КОГДА           управлять созданием разреженных файлов.
                               См. ниже.
      --strip-trailing-slashes удалять все конечные косые черты из каждого
                               аргумента ИСТОЧНИК
  -s, --symbolic-link          создавать символьные ссылки вместо копирования
  -S, --suffix=СУФФИКС         использовать для запасных копий заданный
                               СУФФИКС
      --target-directory=КАТ   скопировать все ИСТОЧНИКИ в КАТАЛОГ
  -T, --no-target-directory    считать НАЗНАЧЕНИЕ обычным файлом
  -u, --update                 копировать только тогда когда исходный файл
                               новее чем файл назначения, или когда файл
                               назначения отсутствует
  -v, --verbose                пояснять что будет сделано
  -x, --one-file-system        оставаться в пределах одной файловой системы
  -Z                           установить контекст безопасности SELinux
                               файла назначения равным типу по умолчанию
      --context[=CTX]          подобно -Z, или если указан CTX, то установить
                               контекст безопасности SELinux
                               или SMACK равным CTX
      --help     показать эту справку и выйти
      --version  показать информацию о версии и выйти

По умолчанию, разреженные файлы ИСТОЧНИКА распознаются при помощи грубой
эвристической процедуры и соответственно создаются разреженные НАЗНАЧЕНИЯ.
Такое поведение задаётся при помощи параметр --sparse=auto.
С параметром --sparse=always всегда создаётся разреженный файл НАЗНАЧЕНИЯ, вне
зависимости от того, содержит ли ИСТОЧНИК достаточно длинные
последовательности нулевых байтов. Используйте параметр --sparse=never для
запрещения создания разреженных файлов.

Если указано --reflink[=always], выполняется облегчённое копирование, при
котором блоки данных копируются только при изменении. Если это невозможно,
или если указано --reflink=auto, то используется обычное копирование.
При указании --reflink=never всегда выполняется обычное копирование.

По умолчанию суффикс для запасных копий «~», если только не установлена
переменная окружения SIMPLE_BACKUP_SUFFIX или не задан параметр --suffix.
Способ контроля версий может быть установлен при помощи ключа --backup
или переменной окружения VERSION_CONTROL. Допустимые значения:

  none, off       никогда не создавать резервных копий (даже если
                  указан параметр --backup)
  numbered, t     создавать нумерованные копии
  existing, nil   пронумеровать, если уже существуют пронумерованные
                  резервные копии, иначе создавать простые
  simple. never   всегда создавать простые копии

Как исключение, cp создает резервную копию ИСТОЧНИКА, если заданы
параметры -f и -b, а если ИСТОЧНИК совпадает с НАЗНАЧЕНИЕМ, то cp создает
резервную копию НАЗНАЧЕНИЯ.

Страница справки по GNU coreutils: <https://www.gnu.org/software/coreutils/>
Об ошибках в переводе сообщений сообщайте по адресу <https://translationproject.org/team/ru.html>
Полная документация: <https://www.gnu.org/software/coreutils/cp>
или доступная локально: info '(coreutils) cp invocation'

tsar_belyash@Tsar--Belyash:~/Рабочий стол/ForLabs/Lab2$ history
    1  apt install -y software-properties-common~
    2  pethon
    3  python
    4  python3
    5  sudo apt install git
    6  git
    7  hostname
    8  whoami
    9  tree -d
   10  lwss
   11  less
   12  sudo apt install less
   13  less
   14  tree -d /
   15  sudo apt install tree
   16  tree -d /
   17  ls -al ~/.ssh
   18  git config -- global user.name "Tsar_Belyash"
   19  git config --global user.name "Tsar_Belyash"
   20  git config --global user.email fev1792@gmail.com
   21  git config --list
   22  git config --global.ui true
   23  git config --global color.ui true
   24  git config --global color.status auto
   25  git config --global color.branch auto
   26  git config --list
   27  mkdir Dekstop/git_example/
   28  mkdir Desktop/git_example/
   29  mkdir Desktop/git_exercise/
   30  mkdir Desktop/git_example/
   31  git init
   32  ls -al ~/.ssh
   33  gh auth login
   34  sudo apt install gh
   35  gh auth login
   36  mkdir repository
   37  cd repository
   38  git init
   39  git log
   40  dit status
   41  git status
   42  git clone
   43  git clone ~https://github.com/Ekaterina108B/WeTryToSurvive~
   44  git fetch https://github.com/Ekaterina108B/WeTryToSurvive
   45  git status
   46  git fetch https://github.com/Ekaterina108B/WeTryToSurvive
   47  git status
   48  git checkout main
   49  git push -u origin master
   50  git remote add origin https://github.com/Ekaterina108B/WeTryToSurvive
   51  git push -u origin master
   52  git clone https://github.com/Ekaterina108B/WeTryToSurvive
   53  git status
   54  git add Listing.md
   55  git add WeTryToSurvive/LW_1/Listing.md
   56  git status
   57  git commit
   58  git push -u origin master
   59  git branch f
   60  git push
   61  git status
   62  mkdir repository_lw1
   63  cd repository_lw1
   64  git init
   65  cp tmp.txt
   66  cp --help
   67  git status
   68  git add --help
   69  who
   70  pwd
   71  ls
   72  touch textt.txt
   73  ls
   74  git status
   75  git add textt.txt
   76  git status
   77  git commit
   78  git branch dopol
   79  git status
   80  git checkout dopol
   81  touch Listing.md
   82  git add Listing.md
   83  git status
   84  git commit
   85  git status
   86  git commit
   87  it remote add origin https://github.com/Ekaterina108B/ForLab.git
   88  git remote add origin https://github.com/Ekaterina108B/ForLab.git
   89  git push -u origin master
   90  ls -al ~/.ssh
   91  git config --global
   92  git config --global user.name
   93  git config --global user.email
   94  clear
   95  git status
   96  git checkout master
   97  git push -u origin master
   98  clear
   99  ls -al ~/.ssh
  100  ssh-keygen -t ed25519 -C "fwv1792@gmail.com"
  101  eval "$(ssh-agent -s)"
  102  ssh-keygen -t ed25519 -C "fev1792@gmail.com"
  103  eval "$(ssh-agent -s)"
  104  cat ~/.ssh/id_ed25519.pub
  105  ls -al ~/.ssh
  106  clear
  107  git remote add origin https://github.com/Ekaterina108B/ForLab.git
  108  git push -u origin master
  109  git remote add origin git@github.com:Ekaterina108B/ForLab.git
  110  git push -u origin master
  111  {{ secrets.GITHUB_TOKEN }}
  112  git push -u origin master
  113  git push -u origin dopol
  114  ls -al ~/.ssh
  115  git checkout dopol
  116  git merge master
  117  git status
  118  git tree
  119  git checkout master
  120  git merge dopol
  121  git status
  122  git push
  123  git status
  124  git rm
  125  git rm master
  126  rm - rf .git
  127  rm -rf .git
  128  ls -lah
  129  rm -rf .git*
  130  ls -lah
  131  mkdir LW
  132  cd LW
  133  mkdir 1
  134  cd 1
  135  ~
  136  cd Рабочий стол
  137  mkdir lab1
  138  cd lab1
  139  git init
  140  git add README.md
  141  touch README.md
  142  git add README.md
  143  git commit -m "first commit'
  144  "
  145  git remote add origin git@github.com:Ekaterina108B/ForLabs.git
  146  git push -u origin master
  147  git remote add origin https://github.com/Ekaterina108B/ForLabs.git
  148  git push -u origin master
  149  git status
  150  git diff
  151  git log
  152  git fetch
  153  git status
  154  git pull
  155  git log
  156  git branch dopol
  157  git checkout dopol
  158  touch Listing.md
  159  git status
  160  git add Listing.md
  161  git status
  162  git commit
  163  git push
  164  git push --set-upstream origin dopol
  165  git fetch
  166  git pull
  167  git branch
  168  git status
  169  git merge master
  170  git checkout master
  171  git merge dopol
  172  git push
  173  mkdir LW1
  174  cd LW1
  175  git init
  176  touch README.md
  177  git add README.md
  178  git status
  179  git commit
  180  git status
  181  git remote add origin git@github.com:Ekaterina108B/ForLabs.git
  182  git push -u origin master
  183  git fetch
  184  git status
  185  git pull
  186  git branch lab1
  187  git branch
  188  git checkout lab1
  189  touch ListingLW1.md
  190  git add ListingLW1.md
  191  git commit
  192  git push
  193  git push -u origin lab1
  194  git checkout master
  195  git merge lab1
  196  git brance -d lab1
  197  git branch -d lab1
  198  git push -u origin master
  199  git push -u origin lab1
  200  git commit
  201  git push --delete origin lab1
  202  git fretch
  203  git fetch
  204  git status
  205  git pull
  206  git init
  207  touch README.md
  208  git add README.md
  209  git commit
  210  gir status
  211  git status
  212  git remote add origin git@github.com:Ekaterina108B/ForLabs.git
  213  git push -u origin master
  214  mkdir Lab1
  215  cd Lab1
  216  touch readme.md
  217  git status
  218  git add Lab1
  219  git add readme.nd
  220  git add readme.md
  221  git push -u origin master
  222  git status
  223  git commit
  224  git push -u origin master
  225  git branch lab1
  226  git checkout lab1
  227  touch ListingLW1.md
  228  git add ListingLW.md
  229  git add ListingLW1.md
  230  git commit
  231  git push origin --all
  232  git checout master
  233  git checkout master
  234  git merge lab1
  235  git branch -d lab1
  236  git status
  237  git push origin --all
  238  git push origin -d lab1
  239  git fetch
  240  git pull
  241  git status
  242  mkdir Lab2
  243  cd Lab2
  244  touch readme.md
  245  add readme.md
  246  git add readme.md
  247  git commit
  248  git status
  249  git push
  250  who
  251  pwd
  252  ls
  253  cp
  254  cp --help
  255  history

tsar_belyash@Tsar--Belyash:~/Рабочий стол/ForLabs/Lab2$ mkdir Something

tsar_belyash@Tsar--Belyash:~/Рабочий стол/ForLabs/Lab2$ ls
readme.md  Something

tsar_belyash@Tsar--Belyash:~/Рабочий стол/ForLabs/Lab2$ rmdir Something

tsar_belyash@Tsar--Belyash:~/Рабочий стол/ForLabs/Lab2$ ls
readme.md

tsar_belyash@Tsar--Belyash:~/Рабочий стол/ForLabs/Lab2$ sudo apt-get update
[sudo] пароль для tsar_belyash: 
Сущ:1 http://ru.archive.ubuntu.com/ubuntu jammy InRelease
Пол:2 http://ru.archive.ubuntu.com/ubuntu jammy-updates InRelease [119 kB]
Пол:3 http://ru.archive.ubuntu.com/ubuntu jammy-backports InRelease [109 kB]
Пол:4 http://security.ubuntu.com/ubuntu jammy-security InRelease [110 kB]
Пол:5 http://ru.archive.ubuntu.com/ubuntu jammy-updates/main amd64 DEP-11 Metadata [101 kB]
Пол:6 http://ru.archive.ubuntu.com/ubuntu jammy-updates/universe amd64 DEP-11 Metadata [289 kB]
Пол:7 http://ru.archive.ubuntu.com/ubuntu jammy-updates/multiverse amd64 DEP-11 Metadata [940 B]
Пол:8 http://ru.archive.ubuntu.com/ubuntu jammy-backports/main amd64 DEP-11 Metadata [4 944 B]
Пол:9 http://ru.archive.ubuntu.com/ubuntu jammy-backports/universe amd64 DEP-11 Metadata [17,9 kB]
Пол:10 http://security.ubuntu.com/ubuntu jammy-security/main amd64 DEP-11 Metadata [43,2 kB]
Пол:11 http://security.ubuntu.com/ubuntu jammy-security/universe amd64 DEP-11 Metadata [40,0 kB]
Получено 834 kB за 2с (469 kB/s)              
Чтение списков пакетов… Готово

tsar_belyash@Tsar--Belyash:~/Рабочий стол/ForLabs/Lab2$ sudo apt-get upgrade
Чтение списков пакетов… Готово
Построение дерева зависимостей… Готово
Чтение информации о состоянии… Готово         
Расчёт обновлений… Готово
Следующие пакеты будут оставлены в неизменном виде:
  gjs libgjs0g
Следующие пакеты будут обновлены:
  ubuntu-advantage-tools xserver-xorg-video-amdgpu
Обновлено 2 пакетов, установлено 0 новых пакетов, для удаления отмечено 0 пакетов, и 2 пакетов не обновлено.
Необходимо скачать 262 kB архивов.
После данной операции объём занятого дискового пространства возрастёт на 85,0 kB.
Хотите продолжить? [Д/н] y
Пол:1 http://ru.archive.ubuntu.com/ubuntu jammy-updates/main amd64 ubuntu-advantage-tools amd64 29.4~22.04 [190 kB]
Пол:2 http://ru.archive.ubuntu.com/ubuntu jammy-updates/main amd64 xserver-xorg-video-amdgpu amd64 22.0.0-1ubuntu0.2 [71,8 kB]
Получено 262 kB за 0с (1 421 kB/s)                    
Предварительная настройка пакетов …
(Чтение базы данных … на данный момент установлено 204745 файлов и каталогов.)
Подготовка к распаковке …/ubuntu-advantage-tools_29.4~22.04_amd64.deb …
Распаковывается ubuntu-advantage-tools (29.4~22.04) на замену (28.1~22.04) …
Подготовка к распаковке …/xserver-xorg-video-amdgpu_22.0.0-1ubuntu0.2_amd64.deb …
Распаковывается xserver-xorg-video-amdgpu (22.0.0-1ubuntu0.2) на замену (22.0.0-1ubuntu0.1) …
Настраивается пакет xserver-xorg-video-amdgpu (22.0.0-1ubuntu0.2) …
Настраивается пакет ubuntu-advantage-tools (29.4~22.04) …
Устанавливается новая версия файла настройки /etc/ubuntu-advantage/help_data.yaml …
Обрабатываются триггеры для man-db (2.10.2-1) …

tsar_belyash@Tsar--Belyash:~/Рабочий стол/ForLabs/Lab2$ echo Linux
Linux

tsar_belyash@Tsar--Belyash:~/Рабочий стол/ForLabs/Lab2$ echo This is just a simple string for my education
This is just a simple string for my education

tsar_belyash@Tsar--Belyash:~/Рабочий стол/ForLabs/Lab2$ cat readme.md

tsar_belyash@Tsar--Belyash:~/Рабочий стол/ForLabs/Lab2$ cat -b readme.md

tsar_belyash@Tsar--Belyash:~/Рабочий стол/ForLabs/Lab2$ cat ListingLW1.md
cat: ListingLW1.md: Нет такого файла или каталога

tsar_belyash@Tsar--Belyash:~/Рабочий стол/ForLabs/Lab2$ cat
ggggggg
ggggggg
ldldl
ldldl
Reading...
Reading...
1%...
1%...
2%...
2%...
60%...
60%...
100%
100%

tsar_belyash@Tsar--Belyash:~/Рабочий стол/ForLabs/Lab2$ cat > readme.md
Reading string...
Writing.
I try to do labs for Computer Arhitecture and it make me sad, because I don't understand it. So all I have to do is play here.
Freedom is not free.

tsar_belyash@Tsar--Belyash:~/Рабочий стол/ForLabs/Lab2$ cat readme.md
Reading string...
Writing.
I try to do labs for Computer Arhitecture and it make me sad, becoause I don't understand it. So all I have to do is play here.
Freedom is not free.

tsar_belyash@Tsar--Belyash:~/Рабочий стол/ForLabs/Lab2$ tail readme.mdReading string...
Writing.
I try to do labs for Computer Arhitecture and it make me sad, becoause I don't understand it. So all I have to do is play here.
Freedom is not free.

tsar_belyash@Tsar--Belyash:~/Рабочий стол/ForLabs/Lab2$ tail -n 1 readme.md
Freedom is not free.

tsar_belyash@Tsar--Belyash:~/Рабочий стол/ForLabs/Lab2$ head -n 1 readme.md
Reading string...

tsar_belyash@Tsar--Belyash:~/Рабочий стол/ForLabs/Lab2$ head -n 3 readme.md
Reading string...
Writing.
I try to do labs for Computer Arhitecture and it make me sad, becoause I don't understand it. So all I have to do is play here.

tsar_belyash@Tsar--Belyash:~/Рабочий стол/ForLabs/Lab2$ ls | grep readme.md
readme.md

tsar_belyash@Tsar--Belyash:~/Рабочий стол/ForLabs/Lab2$ grep 'not free' readme.md
Freedom is not free.

tsar_belyash@Tsar--Belyash:~/Рабочий стол/ForLabs/Lab2$ grep 'ng' readme.md
Reading string...
Writing.

tsar_belyash@Tsar--Belyash:~/Рабочий стол/ForLabs/Lab2$ touch ListindLW2.md

tsar_belyash@Tsar--Belyash:~/Рабочий стол/ForLabs/Lab2$ git add ListingLW.md
fatal: спецификатор пути «ListingLW.md» не соответствует ни одному файлу

tsar_belyash@Tsar--Belyash:~/Рабочий стол/ForLabs/Lab2$ git add ListingLW2.md
fatal: спецификатор пути «ListingLW2.md» не соответствует ни одному файлу

tsar_belyash@Tsar--Belyash:~/Рабочий стол/ForLabs/Lab2$ rm -i ListindLW2.md
rm: удалить пустой обычный файл 'ListindLW2.md'? yes

tsar_belyash@Tsar--Belyash:~/Рабочий стол/ForLabs/Lab2$ touch ListingLW2.md

tsar_belyash@Tsar--Belyash:~/Рабочий стол/ForLabs/Lab2$ git add ListingLW2.md

tsar_belyash@Tsar--Belyash:~/Рабочий стол/ForLabs/Lab2$ git status
Текущая ветка: master
Эта ветка соответствует «origin/master».
Изменения, которые будут включены в коммит:
  (используйте «git restore --staged <файл>...», чтобы убрать из индекса)
	новый файл:    ListingLW2.md
Изменения, которые не в индексе для коммита:
  (используйте «git add <файл>...», чтобы добавить файл в индекс)
  (используйте «git restore <файл>...», чтобы отменить изменения в рабочем каталоге)
	изменено:      readme.md

tsar_belyash@Tsar--Belyash:~/Рабочий стол/ForLabs/Lab2$ git commit
[master 3a33926] Playing is with commands from lab2. Using is it.
 1 file changed, 0 insertions(+), 0 deletions(-)
 create mode 100644 Lab2/ListingLW2.md

tsar_belyash@Tsar--Belyash:~/Рабочий стол/ForLabs/Lab2$ mv readme.md notreadme.md

tsar_belyash@Tsar--Belyash:~/Рабочий стол/ForLabs/Lab2$ ls
ListingLW2.md  notreadme.md

tsar_belyash@Tsar--Belyash:~/Рабочий стол/ForLabs/Lab2$ touch file.txttsar_belyash@Tsar--Belyash:~/Рабочий стол/ForLabs/Lab2$ touch jfile.txt

tsar_belyash@Tsar--Belyash:~/Рабочий стол/ForLabs/Lab2$ mv -b file.txt jfile.txt

tsar_belyash@Tsar--Belyash:~/Рабочий стол/ForLabs/Lab2$ ls
jfile.txt  jfile.txt~  ListingLW2.md  notreadme.md

tsar_belyash@Tsar--Belyash:~/Рабочий стол/ForLabs/Lab2$ mkdir Try

tsar_belyash@Tsar--Belyash:~/Рабочий стол/ForLabs/Lab2$ mv jfile.txt Try/

tsar_belyash@Tsar--Belyash:~/Рабочий стол/ForLabs/Lab2$ ls
jfile.txt~  ListingLW2.md  notreadme.md  Try

tsar_belyash@Tsar--Belyash:~/Рабочий стол/ForLabs/Lab2$ cd Try

tsar_belyash@Tsar--Belyash:~/Рабочий стол/ForLabs/Lab2/Try$ ls
jfile.txt

tsar_belyash@Tsar--Belyash:~/Рабочий стол/ForLabs/Lab2/Try$ cd Lab2
bash: cd: Lab2: Нет такого файла или каталога

tsar_belyash@Tsar--Belyash:~/Рабочий стол/ForLabs/Lab2/Try$ cd -
/home/tsar_belyash/Рабочий стол/ForLabs/Lab2

tsar_belyash@Tsar--Belyash:~/Рабочий стол/ForLabs/Lab2$ cp file.txt Try/
cp: не удалось выполнить stat для 'file.txt': Нет такого файла или каталога

tsar_belyash@Tsar--Belyash:~/Рабочий стол/ForLabs/Lab2$ ls
jfile.txt~  ListingLW2.md  notreadme.md  Try

tsar_belyash@Tsar--Belyash:~/Рабочий стол/ForLabs/Lab2$ cp notreadme.md Try/

tsar_belyash@Tsar--Belyash:~/Рабочий стол/ForLabs/Lab2$ cd Try

tsar_belyash@Tsar--Belyash:~/Рабочий стол/ForLabs/Lab2/Try$ ls
jfile.txt  notreadme.md

tsar_belyash@Tsar--Belyash:~/Рабочий стол/ForLabs/Lab2/Try$ cd -
/home/tsar_belyash/Рабочий стол/ForLabs/Lab2

tsar_belyash@Tsar--Belyash:~/Рабочий стол/ForLabs/Lab2$ cat notreadme.md
Reading string...
Writing.
I try to do labs for Computer Arhitecture and it make me sad, becoause I don't understand it. So all I have to do is play here.
Freedom is not free.

tsar_belyash@Tsar--Belyash:~/Рабочий стол/ForLabs/Lab2$ ps
    PID TTY          TIME CMD
   3939 pts/0    00:00:00 bash
  18303 pts/0    00:00:00 ps

tsar_belyash@Tsar--Belyash:~/Рабочий стол/ForLabs/Lab2$ ps -e
    PID TTY          TIME CMD
      1 ?        00:00:07 systemd
      2 ?        00:00:00 kthreadd
      3 ?        00:00:00 rcu_gp
      4 ?        00:00:00 rcu_par_gp
      5 ?        00:00:00 slub_flushwq
      6 ?        00:00:00 netns
     10 ?        00:00:00 mm_percpu_wq
     11 ?        00:00:00 rcu_tasks_kthread
     12 ?        00:00:00 rcu_tasks_rude_kthread
     13 ?        00:00:00 rcu_tasks_trace_kthread
     14 ?        00:00:00 ksoftirqd/0
     15 ?        00:00:06 rcu_preempt
     16 ?        00:00:00 migration/0
     17 ?        00:00:00 idle_inject/0
     18 ?        00:00:01 kworker/0:1-events
     19 ?        00:00:00 cpuhp/0
     20 ?        00:00:00 cpuhp/1
     21 ?        00:00:00 idle_inject/1
     22 ?        00:00:00 migration/1
     23 ?        00:00:00 ksoftirqd/1
     26 ?        00:00:00 cpuhp/2
     27 ?        00:00:00 idle_inject/2
     28 ?        00:00:00 migration/2
     29 ?        00:00:00 ksoftirqd/2
     32 ?        00:00:00 cpuhp/3
     33 ?        00:00:00 idle_inject/3
     34 ?        00:00:00 migration/3
     35 ?        00:00:00 ksoftirqd/3
     38 ?        00:00:00 kdevtmpfs
     39 ?        00:00:00 inet_frag_wq
     40 ?        00:00:00 kauditd
     41 ?        00:00:00 khungtaskd
     42 ?        00:00:00 oom_reaper
     44 ?        00:00:00 writeback
     46 ?        00:00:00 kcompactd0
     47 ?        00:00:00 ksmd
     48 ?        00:00:00 khugepaged
     49 ?        00:00:00 kintegrityd
     50 ?        00:00:00 kblockd
     51 ?        00:00:00 blkcg_punt_bio
     52 ?        00:00:00 tpm_dev_wq
     53 ?        00:00:00 ata_sff
     54 ?        00:00:00 md
     55 ?        00:00:00 edac-poller
     56 ?        00:00:00 devfreq_wq
     57 ?        00:00:00 watchdogd
     61 ?        00:00:00 kswapd0
     62 ?        00:00:00 ecryptfs-kthread
     64 ?        00:00:00 kthrotld
     65 ?        00:00:00 irq/25-pciehp
     66 ?        00:00:00 acpi_thermal_pm
     67 ?        00:00:00 xenbus_probe
     72 ?        00:00:00 mld
     73 ?        00:00:00 ipv6_addrconf
     83 ?        00:00:00 kstrp
     85 ?        00:00:00 zswap-shrink
     86 ?        00:00:00 kworker/u9:0-hci0
     90 ?        00:00:00 charger_manager
    141 ?        00:00:00 sdhci
    143 ?        00:00:00 scsi_eh_0
    144 ?        00:00:00 scsi_tmf_0
    145 ?        00:00:00 scsi_eh_1
    146 ?        00:00:00 scsi_tmf_1
    174 ?        00:00:01 jbd2/sdb5-8
    175 ?        00:00:00 ext4-rsv-conver
    214 ?        00:00:01 systemd-journal
    271 ?        00:00:02 systemd-udevd
    305 ?        00:00:00 ccp-1-q1
    306 ?        00:00:00 ccp-1-q2
    307 ?        00:00:00 ccp-1-q3
    308 ?        00:00:00 ccp-1-q4
    311 ?        00:00:00 hwrng
    326 ?        00:00:00 cryptd
    358 ?        00:00:00 cfg80211
    484 ?        00:00:00 kmemstick
    492 ?        00:00:00 card0-crtc0
    493 ?        00:00:00 card0-crtc1
    544 ?        00:00:12 systemd-oomd
    545 ?        00:00:05 systemd-resolve
    546 ?        00:00:00 systemd-timesyn
    560 ?        00:00:00 kworker/u9:2-hci0
    663 ?        00:00:00 accounts-daemon
    664 ?        00:00:00 acpid
    666 ?        00:01:26 avahi-daemon
    667 ?        00:00:00 bluetoothd
    668 ?        00:00:00 cron
    669 ?        00:00:05 dbus-daemon
    670 ?        00:00:06 NetworkManager
    677 ?        00:00:00 irqbalance
    678 ?        00:00:00 networkd-dispat
    679 ?        00:00:06 polkitd
    680 ?        00:00:00 power-profiles-
    681 ?        00:00:00 rsyslogd
    696 ?        00:00:04 snapd
    697 ?        00:00:00 switcheroo-cont
    698 ?        00:00:01 systemd-logind
    700 ?        00:00:03 udisksd
    701 ?        00:00:00 wpa_supplicant
    703 ?        00:00:00 avahi-daemon
    780 ?        00:00:00 ModemManager
    805 ?        00:00:00 unattended-upgr
    828 ?        00:00:00 gdm3
    939 ?        00:00:00 rtkit-daemon
    961 ?        00:00:00 kerneloops
    963 ?        00:00:00 kerneloops
   1116 ?        00:00:00 upowerd
   1123 ?        00:00:24 packagekitd
   1324 ?        00:00:00 colord
   1367 ?        00:00:00 gdm-session-wor
   1414 ?        00:00:02 systemd
   1415 ?        00:00:00 (sd-pam)
   1421 ?        00:00:00 pipewire
   1422 ?        00:00:00 pipewire-media-
   1423 ?        00:01:29 pulseaudio
   1435 ?        00:00:02 dbus-daemon
   1442 ?        00:00:00 gvfsd
   1452 ?        00:00:00 gvfsd-fuse
   1463 ?        00:00:00 xdg-document-po
   1467 ?        00:00:00 xdg-permission-
   1473 ?        00:00:00 fusermount3
   1477 ?        00:00:00 gnome-keyring-d
   1490 tty2     00:00:00 gdm-wayland-ses
   1493 tty2     00:00:00 gnome-session-b
   1548 ?        00:00:00 gnome-session-c
   1567 ?        00:00:00 gnome-session-b
   1568 ?        00:00:00 krfcommd
   1592 ?        00:00:00 at-spi-bus-laun
   1599 ?        00:08:16 gnome-shell
   1601 ?        00:00:00 dbus-daemon
   1660 ?        00:00:00 gnome-shell-cal
   1665 ?        00:00:01 gvfs-udisks2-vo
   1670 ?        00:00:00 gvfs-goa-volume
   1674 ?        00:00:00 goa-daemon
   1681 ?        00:00:00 goa-identity-se
   1686 ?        00:00:00 gvfs-afc-volume
   1696 ?        00:00:00 gvfs-mtp-volume
   1700 ?        00:00:00 gvfs-gphoto2-vo
   1707 ?        00:00:00 evolution-sourc
   1718 ?        00:00:00 evolution-calen
   1721 ?        00:00:00 gvfsd-trash
   1731 ?        00:00:00 gjs
   1733 ?        00:00:00 at-spi2-registr
   1744 ?        00:00:00 sh
   1745 ?        00:00:00 gsd-a11y-settin
   1748 ?        00:00:15 ibus-daemon
   1749 ?        00:00:00 gsd-color
   1750 ?        00:00:00 gsd-datetime
   1752 ?        00:00:00 gsd-housekeepin
   1756 ?        00:00:00 gsd-keyboard
   1758 ?        00:00:00 gsd-media-keys
   1765 ?        00:00:00 gsd-power
   1766 ?        00:00:00 gsd-print-notif
   1767 ?        00:00:00 gsd-rfkill
   1768 ?        00:00:00 gsd-screensaver
   1769 ?        00:00:00 gsd-sharing
   1773 ?        00:00:00 gsd-smartcard
   1783 ?        00:00:00 gsd-sound
   1785 ?        00:00:00 gsd-wacom
   1822 ?        00:00:00 snapd-desktop-i
   1833 ?        00:00:00 evolution-alarm
   1839 ?        00:00:00 ibus-dconf
   1840 ?        00:00:06 ibus-extension-
   1844 ?        00:00:00 gsd-disk-utilit
   1879 ?        00:00:00 gsd-printer
   1894 ?        00:00:00 ibus-portal
   1973 ?        00:00:00 snapd-desktop-i
   1982 ?        00:00:00 xdg-desktop-por
   1991 ?        00:00:08 snap-store
   2015 ?        00:00:00 dconf-service
   2019 ?        00:00:00 evolution-addre
   2048 ?        00:00:04 ibus-engine-sim
   2054 ?        00:00:01 xdg-desktop-por
   2137 ?        00:00:02 tracker-miner-f
   2150 ?        00:00:00 gjs
   2198 ?        00:00:00 xdg-desktop-por
   2303 ?        00:00:00 gvfsd-metadata
   2351 ?        00:00:01 fwupd
   2370 ?        00:00:00 kworker/1:2H-kblockd
   2421 ?        00:00:00 kworker/3:2H-kblockd
   2508 ?        00:01:34 Xwayland
   2521 ?        00:00:00 gsd-xsettings
   2559 ?        00:00:00 ibus-x11
   2601 ?        00:00:00 update-notifier
   2675 ?        00:12:12 firefox
   2859 ?        00:00:01 Socket Process
   2883 ?        00:00:14 Privileged Cont
   2918 ?        00:00:00 snap
   3007 ?        00:00:01 WebExtensions
   3180 ?        00:00:47 Isolated Web Co
   3182 ?        00:01:02 Isolated Web Co
   3340 ?        00:00:00 irq/16-mmc0
   3537 ?        00:00:08 gjs
   3888 ?        00:00:14 nautilus
   3913 ?        00:00:51 gnome-terminal-
   3939 pts/0    00:00:00 bash
   3959 ?        00:00:00 oosplash
   3976 ?        00:01:16 soffice.bin
   4038 ?        00:00:00 ssh-agent
   4154 ?        00:00:02 speech-dispatch
   4166 ?        00:00:00 sd_espeak-ng-mb <defunct>
   4170 ?        00:00:01 sd_espeak-ng
   4178 ?        00:00:00 sd_dummy
   4188 ?        00:00:01 kworker/0:0H-kblockd
   4190 ?        00:00:02 kworker/3:1H-radeon-crtc
   4766 ?        00:00:03 kworker/2:1H-radeon-crtc
   4769 ?        00:00:01 kworker/1:0H-radeon-crtc
   4917 ?        00:00:00 cupsd
   4921 ?        00:00:00 cups-browsed
   4939 ?        00:00:29 Isolated Web Co
   5076 ?        00:00:00 dbus
   5077 ?        00:00:00 dbus
   5078 ?        00:00:00 dbus
  12592 ?        00:00:00 xfsalloc
  12593 ?        00:00:00 xfs_mru_cache
  12596 ?        00:00:00 jfsIO
  12597 ?        00:00:00 jfsCommit
  12598 ?        00:00:00 jfsCommit
  12599 ?        00:00:00 jfsCommit
  12600 ?        00:00:00 jfsCommit
  12601 ?        00:00:00 jfsSync
  15208 ?        00:00:01 kworker/u8:1-events_power_efficient
  15418 ?        00:00:00 gvfsd-network
  15444 ?        00:00:00 gvfsd-dnssd
  16399 ?        00:00:00 kworker/3:1-mm_percpu_wq
  16505 ?        00:00:00 kworker/2:2H
  16919 ?        00:00:00 kworker/2:1-events
  17088 ?        00:00:24 RDD Process
  17090 ?        00:00:11 Utility Process
  17251 ?        00:00:00 kworker/1:0-events
  17368 ?        00:00:00 kworker/u8:3-events_unbound
  17437 ?        00:00:00 kworker/3:0-inet_frag_wq
  17554 ?        00:00:00 kworker/1:2-events
  17558 ?        00:00:00 kworker/u8:0-events_unbound
  17604 ?        00:00:00 kworker/2:2-events
  17713 ?        00:00:00 kworker/0:2H-radeon-crtc
  18092 ?        00:00:00 kworker/0:2-cgroup_destroy
  18135 ?        00:00:08 Isolated Web Co
  18163 ?        00:00:00 Web Content
  18192 ?        00:00:00 kworker/1:1-events
  18215 ?        00:00:00 kworker/0:0-events
  18229 ?        00:00:00 kworker/0:1H-kblockd
  18231 ?        00:00:00 Web Content
  18248 ?        00:00:00 kworker/2:0-events
  18250 ?        00:00:00 kworker/3:2-events
  18251 ?        00:00:00 kworker/3:3-events
  18262 ?        00:00:00 Web Content
  18305 pts/0    00:00:00 ps

tsar_belyash@Tsar--Belyash:~/Рабочий стол/ForLabs/Lab2$ ls
jfile.txt~  ListingLW2.md  notreadme.md  Try

tsar_belyash@Tsar--Belyash:~/Рабочий стол/ForLabs/Lab2$ rm jfile.txt~

tsar_belyash@Tsar--Belyash:~/Рабочий стол/ForLabs/Lab2$ rmdir Try
rmdir: не удалось удалить 'Try': Каталог не пуст

tsar_belyash@Tsar--Belyash:~/Рабочий стол/ForLabs/Lab2$ cd Try

tsar_belyash@Tsar--Belyash:~/Рабочий стол/ForLabs/Lab2/Try$ ls
jfile.txt  notreadme.md

tsar_belyash@Tsar--Belyash:~/Рабочий стол/ForLabs/Lab2/Try$ rm notreadme.md

tsar_belyash@Tsar--Belyash:~/Рабочий стол/ForLabs/Lab2/Try$ rm jfile.txt

tsar_belyash@Tsar--Belyash:~/Рабочий стол/ForLabs/Lab2/Try$ ls

tsar_belyash@Tsar--Belyash:~/Рабочий стол/ForLabs/Lab2/Try$ cd -
/home/tsar_belyash/Рабочий стол/ForLabs/Lab2

tsar_belyash@Tsar--Belyash:~/Рабочий стол/ForLabs/Lab2$ rmdir Try

tsar_belyash@Tsar--Belyash:~/Рабочий стол/ForLabs/Lab2$ ls
ListingLW2.md  notreadme.md

tsar_belyash@Tsar--Belyash:~/Рабочий стол/ForLabs/Lab2$ mv notreadme.md readme.md

tsar_belyash@Tsar--Belyash:~/Рабочий стол/ForLabs/Lab2$ ls
ListingLW2.md  readme.md

tsar_belyash@Tsar--Belyash:~/Рабочий стол/ForLabs/Lab2$ git status
Текущая ветка: master
Ваша ветка опережает «origin/master» на 1 коммит.
  (используйте «git push», чтобы опубликовать ваши локальные коммиты)
Изменения, которые не в индексе для коммита:
  (используйте «git add <файл>...», чтобы добавить файл в индекс)
  (используйте «git restore <файл>...», чтобы отменить изменения в рабочем каталоге)
	изменено:      readme.md
индекс пуст (используйте «git add» и/или «git commit -a»)

tsar_belyash@Tsar--Belyash:~/Рабочий стол/ForLabs/Lab2$ git add readme.md

tsar_belyash@Tsar--Belyash:~/Рабочий стол/ForLabs/Lab2$ git commit
[master b1bd8ff] Played with the commands a little bit.
 1 file changed, 4 insertions(+)

tsar_belyash@Tsar--Belyash:~/Рабочий стол/ForLabs/Lab2$ ssh-keygen -t ed25519 -C "fev1792@gmail.com"
Generating public/private ed25519 key pair.
Enter file in which to save the key (/home/tsar_belyash/.ssh/id_ed25519): 
/home/tsar_belyash/.ssh/id_ed25519 already exists.
Overwrite (y/n)? y
Enter passphrase (empty for no passphrase): 
Enter same passphrase again: 
Your identification has been saved in /home/tsar_belyash/.ssh/id_ed25519
Your public key has been saved in /home/tsar_belyash/.ssh/id_ed25519.pub
The key fingerprint is:
SHA256:+izvzo1Lvk8eBy3M+psKP8p7or7+0r1AZujCEb8XMyw fev1792@gmail.com
The key's randomart image is:
+--[ED25519 256]--+
|                 |
|                 |
|  .              |
|   o o   o .     |
|  . E O S = .    |
| . o * = . o     |
|  o o.=.o o .    |
|   ..o+X+* +     |
|   o===X/BB.     |
+----[SHA256]-----+

tsar_belyash@Tsar--Belyash:~/Рабочий стол/ForLabs/Lab2$ ls -al ~/.ssh
итого 24
drwx--x--x  2 tsar_belyash tsar_belyash 4096 сен 18 11:45 .
drwxr-x--- 17 tsar_belyash tsar_belyash 4096 сен 25 11:00 ..
-rw-------  1 tsar_belyash tsar_belyash  464 сен 25 11:08 id_ed25519
-rw-r--r--  1 tsar_belyash tsar_belyash   99 сен 25 11:08 id_ed25519.pub
-rw-------  1 tsar_belyash tsar_belyash  978 сен 18 11:45 known_hosts
-rw-r--r--  1 tsar_belyash tsar_belyash  142 сен 18 11:43 known_hosts.old

tsar_belyash@Tsar--Belyash:~/Рабочий стол/ForLabs/Lab2$ cat ~/.ssh/id_ed25519.pub
ssh-ed25519 AAAAC3NzaC1lZDI1NTE5AAAAIIT1378urkWp+s40WrtI714VYI1U64EZ+Q+ylYzESmJR fev1792@gmail.com

tsar_belyash@Tsar--Belyash:~/Рабочий стол/ForLabs/Lab2$ git status
Текущая ветка: master
Ваша ветка опережает «origin/master» на 2 коммита.
  (используйте «git push», чтобы опубликовать ваши локальные коммиты)
нечего коммитить, нет изменений в рабочем каталоге

tsar_belyash@Tsar--Belyash:~/Рабочий стол/ForLabs/Lab2$ ssh e_fedorova@185.5.249.140
The authenticity of host '185.5.249.140 (185.5.249.140)' can't be established.
ED25519 key fingerprint is SHA256:gMWpghci4jH+8KckY83J+zLNE4DrwfrDZorZZU2IRGI.
This key is not known by any other names
Are you sure you want to continue connecting (yes/no/[fingerprint])? y
Please type 'yes', 'no' or the fingerprint: yes
Warning: Permanently added '185.5.249.140' (ED25519) to the list of known hosts.
e_fedorova@185.5.249.140's password: 
Welcome to Ubuntu 20.04.6 LTS (GNU/Linux 5.4.0-162-generic x86_64)

 * Documentation:  https://help.ubuntu.com
 * Management:     https://landscape.canonical.com
 * Support:        https://ubuntu.com/advantage
New release '22.04.3 LTS' available.
Run 'do-release-upgrade' to upgrade to it.


The programs included with the Ubuntu system are free software;
the exact distribution terms for each program are described in the
individual files in /usr/share/doc/*/copyright.

Ubuntu comes with ABSOLUTELY NO WARRANTY, to the extent permitted by
applicable law.

e_fedorova@vds2476450:~$ exit
logout
Connection to 185.5.249.140 closed.

tsar_belyash@Tsar--Belyash:~/Рабочий стол/ForLabs/Lab2$ ssh-copy-id 
e_fedorova@185.5.249.140
/usr/bin/ssh-copy-id: INFO: attempting to log in with the new key(s), to filter out any that are already installed
/usr/bin/ssh-copy-id: INFO: 2 key(s) remain to be installed -- if you are prompted now it is to install the new keys
e_fedorova@185.5.249.140's password: 

Number of key(s) added: 2

Now try logging into the machine, with:   "ssh 'e_fedorova@185.5.249.140'"
and check to make sure that only the key(s) you wanted were added.

tsar_belyash@Tsar--Belyash:~/Рабочий стол/ForLabs/Lab2$ ssh e_fedorova@185.5.249.140
Welcome to Ubuntu 20.04.6 LTS (GNU/Linux 5.4.0-162-generic x86_64)

 * Documentation:  https://help.ubuntu.com
 * Management:     https://landscape.canonical.com
 * Support:        https://ubuntu.com/advantage
New release '22.04.3 LTS' available.
Run 'do-release-upgrade' to upgrade to it.

Last login: Mon Sep 25 11:36:42 2023 from 185.5.249.140

e_fedorova@vds2476450:~$ exit
logout
Connection to 185.5.249.140 closed.

tsar_belyash@Tsar--Belyash:~/Рабочий стол/ForLabs/Lab2$ tar -cvf archive.tar.gz readme.md
readme.md

tsar_belyash@Tsar--Belyash:~/Рабочий стол/ForLabs/Lab2$ ls
archive.tar.gz  ListingLW2.md  readme.md

tsar_belyash@Tsar--Belyash:~/Рабочий стол/ForLabs/Lab2$ tar -rvf arhive.tar ListingLW2.md
ListingLW2.md

tsar_belyash@Tsar--Belyash:~/Рабочий стол/ForLabs/Lab2$ ls
archive.tar.gz  arhive.tar  ListingLW2.md  readme.md

tsar_belyash@Tsar--Belyash:~/Рабочий стол/ForLabs/Lab2$ rm arhive.tar.gz
rm: невозможно удалить 'arhive.tar.gz': Нет такого файла или каталога

tsar_belyash@Tsar--Belyash:~/Рабочий стол/ForLabs/Lab2$  tar -xvf archive.tar.gz
readme.md

tsar_belyash@Tsar--Belyash:~/Рабочий стол/ForLabs/Lab2$ ls
archive.tar.gz  arhive.tar  ListingLW2.md  readme.md

tsar_belyash@Tsar--Belyash:~/Рабочий стол/ForLabs/Lab2$ ssh archive.tar e_fedorova@185.5.249.140:
ssh: Could not resolve hostname archive.tar: Name or service not known

tsar_belyash@Tsar--Belyash:~/Рабочий стол/ForLabs/Lab2$ ssh e_fedorova@185.5.249.140
Welcome to Ubuntu 20.04.6 LTS (GNU/Linux 5.4.0-162-generic x86_64)

 * Documentation:  https://help.ubuntu.com
 * Management:     https://landscape.canonical.com
 * Support:        https://ubuntu.com/advantage
New release '22.04.3 LTS' available.
Run 'do-release-upgrade' to upgrade to it.

Last login: Mon Sep 25 11:41:22 2023 from 85.143.224.24

e_fedorova@vds2476450:~$ mkdir A

e_fedorova@vds2476450:~$ ls
A

e_fedorova@vds2476450:~$ exit
logout
Connection to 185.5.249.140 closed.

tsar_belyash@Tsar--Belyash:~/Рабочий стол/ForLabs/Lab2$ ssh archive.tar 
e_fedorova@185.5.249.140:/A
ssh: Could not resolve hostname archive.tar: Name or service not known

tsar_belyash@Tsar--Belyash:~/Рабочий стол/ForLabs/Lab2$ ls
archive.tar.gz  arhive.tar  ListingLW2.md  readme.md
