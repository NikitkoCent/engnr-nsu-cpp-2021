# ЧЕЛ ТЫ............................................................

```shell
Microsoft Windows [Version 10.0.19042.1415]
(c) Корпорация Майкрософт (Microsoft Corporation). Все права защищены.

C:\Users\nedobitaia>cd CLionProjects

C:\Users\nedobitaia\CLionProjects>cd untitled15

C:\Users\nedobitaia\CLionProjects\untitled15>cd build

C:\Users\nedobitaia\CLionProjects\untitled15\build>dir
 Том в устройстве C имеет метку Windows
 Серийный номер тома: 3465-3BE6

 Содержимое папки C:\Users\nedobitaia\CLionProjects\untitled15\build

20.12.2021  11:52    <DIR>          .
20.12.2021  11:52    <DIR>          ..
               0 файлов              0 байт
               2 папок   1 004 261 376 байт свободно

C:\Users\nedobitaia\CLionProjects\untitled15\build>cmake -G "MinGW Makefiles" --target all ..
-- The C compiler identification is GNU 8.1.0
-- The CXX compiler identification is GNU 8.1.0
-- Check for working C compiler: C:/Program Files (x86)/mingw-w64/i686-8.1.0-posix-dwarf-rt_v6-rev0/mingw32/bin/gcc.exe
-- Check for working C compiler: C:/Program Files (x86)/mingw-w64/i686-8.1.0-posix-dwarf-rt_v6-rev0/mingw32/bin/gcc.exe - works
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Detecting C compile features
-- Detecting C compile features - done
-- Check for working CXX compiler: C:/Program Files (x86)/mingw-w64/i686-8.1.0-posix-dwarf-rt_v6-rev0/mingw32/bin/g++.exe
-- Check for working CXX compiler: C:/Program Files (x86)/mingw-w64/i686-8.1.0-posix-dwarf-rt_v6-rev0/mingw32/bin/g++.exe - works
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Configuring done
-- Generating done
-- Build files have been written to: C:/Users/nedobitaia/CLionProjects/untitled15/build

C:\Users\nedobitaia\CLionProjects\untitled15\build>mingw32-make
Scanning dependencies of target hasher
[ 33%] Building CXX object CMakeFiles/hasher.dir/main.cpp.obj
```