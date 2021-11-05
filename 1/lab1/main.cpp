#include <iostream>

using namespace std;

uint32_t adler32(const unsigned char *buf, size_t buf_length) {
    uint32_t a = 1;
    uint32_t b = 0;

    while (buf_length--) {
        a = (a + *(buf++)) % 65521;
        b = (b + a) % 65521;
    }
    return (b << 16) + a;
}   

int main(int argc, char **argv) {
    //fopen()
    cout << "Hello, World!\n" << std::endl;
    //cerr<<"\n&ERROR LOH: NU TI I LOH";

    return 0;
}
