# STACK CALCULATOR
## Интрукция по запуску утилиты stack calculator: 
``cmake {-G "something generator if you need"} -S  <path-to-source> -B <path-to-build>``  
``cmake --build``  
``cd src && cd calculator``

Утилита собрана, можно запускать ее:  
``./2 -file <filepath>``
или  
``./2``


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
