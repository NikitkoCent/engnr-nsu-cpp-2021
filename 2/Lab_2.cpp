#include "Lab_2.h"

int main(int argc, char* argv[]) {

    string s;
    stack <double> st;
    vector<string> result;
    map<string, double>variables;
    string filename;
    string line;
    if (argc >= 2) 
    {
        filename = argv[1];
    }
    ifstream in(filename);
    if (in.is_open())
    {
        std::cout << filename << std::endl;
        while (getline(in, line))
        {

            split(result, line, ' ');
            if (size(result) >= 1) 
            {
                stack_case(result, st, variables);
                result.clear();
            }
        }

        in.close();
    }
    else if (argc >= 2 && in.is_open() == 0)
    {
        cout << "File not found" << endl;
    }
    else 
    {
        while (getline(cin, line))
        {
            split(result, line, ' ');
            if (size(result) >= 1) {
                stack_case(result, st, variables);
                result.clear();
            }
        }
    }


    return 0;
}
