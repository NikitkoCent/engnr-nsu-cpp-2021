# Cpp-Lab1
## Интрукция по запуску утилиты Hasher:
``git clone https://github.com/dan-taranetc/Cpp-Lab1.git``  
``cd Cpp-Lab1 && mkdir cmake_dir && cd cmake_dir``  
``cmake .. && make``  

Утилита собрана, можно запускать ее:  
``./hasher -m <mode> <filename>``   
или  
``./hasher <filename> -m <mode>``   

Где mode adler32 или sum64

Возможности:
Программа считает 2 варианта кэша от файла:
1. Adler32
2. Sum64

Утилита принимает имя файла и вариант расчета хеша как аргументы командной строки.
