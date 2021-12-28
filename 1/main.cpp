#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

uint32_t adler32(ifstream &file) {
    uint32_t a = 1;
    uint32_t b = 0;
    unsigned char buf;
    while (file.read((char *) &buf, sizeof(buf))) {
        a = (a + buf) % 65521;
        b = (b + a) % 65521;
    }
    return (b << 16u) + a;
}

uint64_t sum64(ifstream &file) {
    uint64_t result = 0, block = 0;
    uint8_t size = 0;
    unsigned char buf;
    while (file.read((char *) &buf, sizeof(buf))) {
        if (size == 8) {
            result += block;
            block = 0;
            size = 0;
        }
        block <<= 8u;
        block += buf;
        size++;

    }
    return result + block;
}

int main(int argc, char **argv) {

    string help = "Usage:\n"
                  "-h                   : display usage help and exit\n"
                  "<filename> -m <mode> : calculate the transmitted hash variant of the transmitted file\n"
                  "-m <mode> <filename> : calculate the transmitted hash variant of the transmitted file\n"
                  "\n"
                  "<mode> ∈ { adler32, sum64 }\n";
    ifstream in;
    string filename, mode;
    bool isHelp = false;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-h") == 0) {
            isHelp = true;
        } else if (strcmp(argv[i], "-m") == 0) {
            mode = argv[++i];
        } else {
            filename = argv[i];
        }
    }

    if ((isHelp) && (!mode.empty() || !filename.empty())) {
        cerr << "ERROR: invalid help option" << endl;
        cerr << help;
        return 1;
    } else if (isHelp){
    	cout << help;
    	return 0;
    }
    if ((mode != "adler32") && (mode != "sum64")) {
        cerr << "ERROR: invalid mode. Correct modes are {adler32, sum64}" << endl;
        cerr << help;
        return 1;
    }
    

    in.open(filename, ios::binary);

    if (!in.is_open()) {
        cerr << "ERROR: can`t open file" << endl;
        cerr << help;
        return 1;
    }

    if (mode == "adler32") {
        cout << hex << adler32(in);
    }

    if (mode == "sum64") {
        cout << hex << sum64(in);
    }
    
    return 0;
}
