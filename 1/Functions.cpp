#include "Lab1.h"

std::uint32_t adler32(std::ifstream& file)
{
    std::uint32_t s1 = 1;
    std::uint32_t s2 = 0;
    unsigned char ch = 0;
    while (file.read((char*)&ch, sizeof(ch)))
    {
        s1 = (s1 + ch) % 65521;
        s2 = (s2 + s1) % 65521;
    }

    return (s2 << 16) | s1;
}


std::uint64_t sum64(std::ifstream& file) {
    std::uint64_t result = 0;
    std::uint64_t part = 0;
    std::uint64_t element = 0;
    std::uint64_t counter = 0;
    while (file.read((char*)&element, sizeof(unsigned char)))
    {
        part += element;
        counter++;
        if (counter == 8) {
            result += part;
            counter = 0;
            part = 0;
        }
        part = part << 8;
        

    }
    if (counter != 0) {
        part = part >> 8;
        result += part;
    }
    return result;
}
