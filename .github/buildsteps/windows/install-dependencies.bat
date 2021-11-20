cd "%LAB_INDEX%"    || exit /b 1

vcpkg --version     || exit /b 1
vcpkg install boost --triplet x64-windows
vcpkg install boost --triplet x32-windows
