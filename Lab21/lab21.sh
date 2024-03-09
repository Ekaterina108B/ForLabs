#!/bin/bash


# переименновывание файлов в директории
modification(){
    directory="$1"
    min_size="$2"
    
    find "$directory" -type f | while read file; do
        size=$(stat -c %s "$file")
        if [ -f "$file" ] && [ $size -lt $min_size ]; then
            file_name="${file%.*}"
            extension=$(basename "$file" | head -c 1)
            new_name="${file_name}.${extension}"
            mv "$file" "$new_name"
            echo "Файл $(basename "$file") переименован в $(basename "$new_name")"
        fi
    done
    echo "Программа завершена."
    echo "________________"
    exit 1       
}


# проверка существования и пустоты директории
check(){
    directory="$1"
    min_size="$2"
    
    if [ ! -d "$directory" ] || [ -n "$(find "$directory" -maxdepth 0 -empty)" ]; then
        echo "Директории не существует или она пуста. Попробуйте снова."
        echo "________________"
        main
    else
        modification "$directory" "$min_size"
    fi
}


# подтверждение введённых данных
confirmation(){
    directory="$1"
    min_size="$2"
    
    # проверка данных и установка их по умолчанию
    if [ -z "$directory" ]; then
        echo "Вы не указали директорию. По умолчанию взята текущая."
        directory=$(pwd)
    fi
    REGEX="^[0-9]+$"
    if [ -z "$min_size" ] || [[ ! $min_size =~ $REGEX ]]; then
        echo "Вы не указали минимальный размер файла. По умолчанию взят 1 байт."
        min_size=1
    fi
    
    # запрос подтверждения
    echo "Выедены данные:"
    echo "Директория: $directory"
    echo "Минимальный размер: " $min_size
    echo "Желаете изменить введённые данные? [Да Yes|Нет No]"
    read restart
    if [ "$restart" == "Да" ] || [ "$restart" == "да" ] || [ "$restart" == "Yes" ] || [ "$restart" == "yes" ]; then
        echo "________________"
        main
    else
        if [ "$restart" == "Нет" ] || [ "$restart" == "нет" ] || [ "$restart" == "No" ] || [ "$restart" == "no" ]; then
            check "$directory" "$min_size"
        else
            echo "Введён некорректный ответ. Программа остановлена."
            exit 0
        fi
    fi
}


# считывание данных
main(){
    echo "Введите имя директории (каталога) или '?' для помощи:"
    read directory
    if [ "$directory" == "?" ]; then
        specification
    else
        echo "Введите минимальный размер файла:"
        read min_size
        confirmation "$directory" "$min_size"
    fi
}


# начальное окно и вывод спецификации
specification(){
    echo "________________"
    echo "Спецификация программы:"
    echo "Программа находит файлы, размером меньше заданного, и меняет суффиксы их имён на первые литеры имён файлов."
    echo " "
    echo "Значения по умолчанию:"
    echo "Имя дирректории: текущая;"
    echo "Минимальный размер файла: 1 байт"
    echo " "
    echo "Перезапустить программу? [Да Yes|Нет No]"
    read restart
    if [ "$restart" == "Да" ] || [ "$restart" == "да" ] || [ "$restart" == "Yes" ] || [ "$restart" == "yes" ]; then
        echo "________________"
        main
    else
        if [ "$restart" == "Нет" ] || [ "$restart" == "нет" ] || [ "$restart" == "No" ] || [ "$restart" == "no" ]; then
            echo "Программа завершена."
            exit 0
        else
            echo "Введён некорректный ответ. Программа остановлена."
            exit 0
        fi
    fi
}


# запуск программы
confirmation "$1" "$2"
