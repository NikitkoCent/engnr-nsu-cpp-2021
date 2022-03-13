#include "Adler32.h"

uint32_t Adler32::Use(std::istream& file)
{
    uint32_t s1 = 1;
    uint32_t s2 = 0;
    unsigned char byte;

    while (file.read((char*)(&byte), sizeof(unsigned char)))
    {
        s1 = (s1 + byte) % 65521;
        s2 = (s1 + s2) % 65521;
    }

    return (s2 << 16) + s1;
}