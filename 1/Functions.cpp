#include "Lab1.h"

uint16_t adler32(std::ifstream& file)
{
    uint32_t s1 = 1;
    uint32_t s2 = 0;
    unsigned char ch = 0;
    while (file.read((char*)&ch, sizeof(ch)))
    {
        s1 = (s1 + ch) % 65521;
        s2 = (s2 + s1) % 65521;
    }

    return (s2 << 16) + s1;
}


uint16_t sum64(std::ifstream& file) {
    uint64_t result = 0;
    uint64_t part = 0;

    while (file.read((char*)&part, sizeof(uint64_t)))
    {
        part *= 256;
        ~part;
        part <<= 8;
        part *= 256;
        result += part;

    }
    return result;
}
