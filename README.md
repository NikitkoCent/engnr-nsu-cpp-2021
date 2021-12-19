## engnr-nsu-cpp-2021 Lab1 
# Инструкция по запуску и работе программы.
Сборка:
`git clone https://github.com/ArtyomSh/engnr-nsu-cpp-2021.git`
`cd Cpp-Lab1 && mkdir cmake_dir && cd cmake_dir`
`cmake .. && make`
Теперь утилиту можно запустить из консоли с помощь команд: `./hasher -m <mode> <filename>` или `./hasher <filename> -m <mode>`, 
где <filename> -  название хэшируемого файла, а <mode> : adler32 или sum64 - один из двух вариантов рассчета хэша.
