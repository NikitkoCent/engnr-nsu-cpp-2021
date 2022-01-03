#include "Hasher.h"

Hasher::Hasher(fstream* name, bool metod)
{
	file = name;
	metod_ = metod;
    out_ = 0;
}

uint64_t Hasher::Hash()
{
    if (metod_)
        Adler32();
    else
        Sum64();
    return (out_);
}

void Hasher::Sum64() 
{
    unsigned char curr;
    uint64_t result = 0, block = 0;
    uint32_t cnt = 0;
    while ((*file) >> curr)
    {
        block <<= 8;
        block |= curr;
        cnt++;
        if (cnt == 8)
        {
            result += block;
            cnt = 0;
            block = 0;
        }
    }
    out_ = result + block;
}

void Hasher::Adler32()
{
    uint32_t s1 = 1;
    uint32_t s2 = 0;
    unsigned char curr;
    while ((*file)>>curr)
    {
        s1 = (s1 + curr) % 65521;
        s2 = (s2 + s1) % 65521;
    }
    out_ = ((s2 << 16) + s1);
}
