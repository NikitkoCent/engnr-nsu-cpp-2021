# Lab2 Стековый калькулятор
## Интрукция по запуску утилиты calculator:
``git clone https://github.com/uchansansan/Cpp-Lab2.git``  
``cd Cpp-Lab2 && mkdir cmake_dir && cd cmake_dir``  
``cmake .. && make``  
``cd src && cd calculator``  

Утилита собрана, можно запускать ее:  
``./calculator -file <filepath>``
или  
``./calculator``


Возможности:
Стековый калькулятор способен выполнять команды:
1. \# - комментарий
2. POP
3. PUSH \<number\>
4. PUSH \<varname\>
5. PEEK \<varname\>
6. ABS
7. PLUS
8. MINUS
9. MUL
10. DIV
11. PRINT
12. READ

Чтобы запустить тесты после клонирования репозитория:
``cd tests``  
``./calculator_tests``
