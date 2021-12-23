
## Description
This is a console utility that reads the hash from a file.

## Quick start:
On command line, type in the following commands:

`mkdir build`  
`cd build`  
`cmake ..`  
`make`  

After that:
`./hasher -h` - display help information about the usage and exit;
`./hasher <filename> -m <mode>` - calculate the transmitted hash type of the input file;
`./hasher -m <mode> <filename>` - calculate the transmitted hash type of the input file.

The utility supports the following types of hash `<mode> ∈ { adler32, sum64 }`.

