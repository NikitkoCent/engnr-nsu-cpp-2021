#include "./inc/Hasher.h"

#include <iostream>
#include <fstream>
#include <filesystem>
#include <vector>
#include <cstring>

uint32_t adler32(std::ifstream &ifs)
{
    uint32_t s1 = 1;
    uint32_t s2 = 0;
    unsigned char curr;
    while (ifs.read(reinterpret_cast<char*>(&curr), sizeof(unsigned char)))
    {
        s1 = (s1 + curr) % 65521;
        s2 = (s2 + s1) % 65521;
    }
    return ((s2 << 16) + s1);
}

uint64_t sum64(std::ifstream &ifs)
{
    unsigned char curr;
    uint64_t result = 0, block = 0;
    uint32_t cnt = 0;
    while (ifs.read(reinterpret_cast<char*>(&curr), sizeof(unsigned char)))
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
    return result + block;
}

Status hashProccessing(const char *file_path, HashMode hm)
{
    namespace fs = std::filesystem;

    fs::path abs_path = fs::current_path() / fs::path(file_path);
    std::ifstream ifs(abs_path, std::ifstream::binary);

    if (ifs)
    {
        std::uint64_t resultSum = 0;
        std::uint32_t resultAdler = 0;

        if (hm == HashMode::_Adler32)
        {
            resultAdler = adler32(ifs);
            std::cout << std::hex << resultAdler << std::endl;
            return Status::_SUCCESS;
        }
        if (hm == HashMode::_Hash64)
        {
            resultSum = sum64(ifs);
            std::cout << std::hex << resultSum << std::endl;
            return Status::_SUCCESS;
        }
        else
        {
            return Status::_ERROR;
        }
    }
    else
    {
        std::cerr << "File NOT found" << std::endl;
        return Status::_ERROR;
    }
}
