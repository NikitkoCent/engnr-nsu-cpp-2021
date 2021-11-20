#include "./inc/Hasher.h"

#include <iostream>
#include <fstream>
#include <filesystem>
#include <vector>
#include <functional>

uint32_t adler32( unsigned char *buf, ptrdiff_t byte_length)
{
    uint32_t s1 = 1;
    uint32_t s2 = 0;

    while (byte_length--)
    {
        s1 = (s1 + *(buf++)) % 65521;
        s2 = (s2 + s1) % 65521;
    }
    return (s2 << 16) + s1;
}

uint64_t sum64( unsigned char *buf, ptrdiff_t byte_length)
{
    uint64_t result = 0;
    for (int i = 0; i < byte_length; i = i + 8)
        result += static_cast<uint64_t>(buf[i]) << 56 |
                  static_cast<uint64_t>(buf[i + 1]) << 48 |
                  static_cast<uint64_t>(buf[i + 2]) << 40 |
                  static_cast<uint64_t>(buf[i + 3]) << 32 |
                  static_cast<uint64_t>(buf[i + 4]) << 24 |
                  static_cast<uint64_t>(buf[i + 5]) << 16 |
                  static_cast<uint64_t>(buf[i + 6]) << 8 |
                  static_cast<uint64_t>(buf[i + 7]) << 0;
    return result;
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

        std::vector<char> buff(1024,0);

        if (hm == HashMode::_Adler32)
        { 
            while (!ifs.eof())
            {
                ifs.read(buff.data(), static_cast<int64_t>(buff.size()));
                std::streamsize ss = ifs.gcount();
                resultAdler += adler32(reinterpret_cast<unsigned char*>(buff.data()), ss);
            }
            std::cout  << std::hex << resultAdler << std::endl;
            return Status::_SUCCESS;
        }
        if (hm == HashMode::_Hash64)
        {
            while (!ifs.eof())
            {
                ifs.read(buff.data(), static_cast<int64_t>(buff.size()));
                std::streamsize ss = ifs.gcount();
                resultSum += sum64(reinterpret_cast<unsigned char*>(buff.data()), ss);
            }
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
