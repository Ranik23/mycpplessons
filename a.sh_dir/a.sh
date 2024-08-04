#!/bin/bash

# Проходим по всем файлам в текущей директории
for file in *; do
    # Проверяем, является ли текущий элемент файлом
    if [[ -f "$file" ]]; then
        # Получаем имя файла без расширения
        filename=$(basename "$file")
        
        # Создаём директорию с именем файла и суффиксом "_dir"
        dirname="${filename}_dir"
        mkdir "$dirname"
        
        # Перемещаем файл в соответствующую директорию
        mv "$file" "$dirname/"
    fi
done

