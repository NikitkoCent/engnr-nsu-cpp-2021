# Hasher
## How to run?
### 1. Generate a Project Buildsystem
`$ cmake [<options>] -S <path-to-source> -B <path-to-build>`

`<path-to-source>` -- must contain a CMakeLists.txt file and must not contain a CMakeCache.txt;

`<path-to-build>` -- the build tree will be created automatically if it does not already exist.
### 2. Build a Project
`$ cmake --build <path-to-build> [<options>] [-- <build-tool-options>]`
### 3. Run Hasher
`$ cd <path-to-build>`
#### 3.1. Help
`$ ./hasher -h`
#### 3.2. Calculate hash
`$ ./hasher -m <mode> <filepath>`

`$ ./hasher <filepath> -m <mode>`
### Modes:
* adler32
* sum64

