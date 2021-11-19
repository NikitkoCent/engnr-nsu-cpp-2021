#include "Hasher.h"

#include <iostream>
#include <fstream>
#include <filesystem>
#include <vector>
#include <functional>

void adler32(const unsigned char* buf, uint16_t byte_length, uint64_t* ref)
{
    int32_t s1 = 1;
    uint32_t s2 = 0;

    while (byte_length--)
    {
        s1 = (s1 + *(buf++)) % 65521;
        s2 = (s2 + s1) % 65521;
    }
    *ref = ((s2 << 16) + s1);
}

void sum64(const unsigned char* buf, uint16_t byte_length, uint64_t* ref)
{
    uint64_t result = 0xb1f875b9;
    for (int i=0;i<byte_length;i=i+8)
        result+= static_cast<uint64_t>(buf[i] * 0xab+ buf[i+1]) |
                 static_cast<uint64_t>(buf[i+1] * 0x1a + buf[i+2]) << 8 |
                 static_cast<uint64_t>(buf[i+2] * 0x1f + buf[i+3]) << 16 |
                 static_cast<uint64_t>(buf[i+3] * 0xba + buf[i+4]) << 24 |
                 static_cast<uint64_t>(buf[i+4] * 0x8d + buf[i+5]) << 32 |
                 static_cast<uint64_t>(buf[i+5] * 0x9f + buf[i+6]) << 40 |
                 static_cast<uint64_t>(buf[i+6] * 0x11 + buf[i+7]) << 48 |
                 static_cast<uint64_t>(buf[i+7] * 0xba + buf[i]) << 56;
    *ref = result;
}

Status hashProccessing(const char* file_path, HashMode hm)
{
    namespace fs = std::filesystem;

    using hash_func_map = std::map<HashMode, std::function<void(const unsigned char*, uint16_t, uint64_t*)>>;

    //Insert your hash function -----------------------------
    const hash_func_map HashFuncMap =
            {
                    {HashMode::_Adler32, adler32},
                    {HashMode::_Hash64, sum64},
            };
    //--------------------------------------------------------

    fs::path abs_path = fs::current_path() / fs::path(file_path);
    std::ifstream ifs(abs_path, std::ifstream::binary);
    if (ifs) {
        std::uintmax_t fsize = fs::file_size(abs_path);
        std::vector<char> buff (BUFFER_SIZE, 0);
        std::uint64_t result = 0;
        std::uint64_t ref;
        while (!ifs.eof())
        {
            ifs.read(buff.data(), static_cast<int64_t>(buff.size()));
            std::streamsize ss = ifs.gcount();
            if (ss % sizeof(uint64_t) != 0) continue;
            HashFuncMap.find(hm)->second(reinterpret_cast<const unsigned char*>(buff.data()),
                    static_cast<int64_t>(buff.size()), &ref);
            result += ref;
        }
        std::cout << "Hash of file = " << std::hex << result <<std::endl;
        return Status::_SUCCESS;
    }
    else {
        std::cerr << "File NOT found" << std::endl;
        return Status::_ERROR;
    }
}
