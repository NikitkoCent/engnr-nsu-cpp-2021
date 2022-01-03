#include "Lab_2.h"
#include "Operation.cpp"
int main(int argc, char* argv[]) {

    std::string s;
    stack <int64_t> st;
    vector<string> result;
    map<string, int64_t>variables;
    string filename;
    string line;
    OperationsFactory create_stack;
    Operations *cmd_stack;
    if (argc >= 2)
    {
        filename = argv[1];
    }
    ifstream in(filename);
    if (in.is_open())
    {
        //        std::cout << filename << std::endl;
        while (getline(in, line))
        {

            split(result, line, ' ');
            if (result.size() >= 1)
            {
                
                try {
                    if (check(result)){
                        cmd_stack = create_stack.Create(result);
                        cmd_stack->execute(result, st, variables);
                    }
                }
                catch (Exception &expn){
                    std::cerr << expn.what();
                    return 1;
                }
                catch (const char* exceptions) {
                    std::cerr << exceptions;
                    return 1;
                }
                result.clear();
            }
        }
    }
    else if (argc >= 2 && in.is_open() == 1)
    {
        std::cerr << "File not found" << endl;
        return 1;
    }
    else
    {
        while (getline(cin, line))
        {
            split(result, line, ' ');
            if (result.size() >= 1)
            {

                try {
                    if (check(result)){
                        cmd_stack = create_stack.Create(result);
                        cmd_stack->execute(result, st, variables);
                    }
                }
                catch (Exception &expn) {
                    std::cerr << expn.what();
                    return 1;
                }
                catch (const char* exceptions) {
                    std::cerr << exceptions;
                    return 1;
                }
                result.clear();
            }
        }
    }

    return 0;
}
