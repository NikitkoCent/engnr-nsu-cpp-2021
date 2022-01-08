#include "Lab_2.h"
#include "Operations.h"
//#include "Exceptions.h"

int main(int argc, char* argv[]) {

    std::string s;
    Param p;
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

            split(p, line, ' ');
            if (p.vst.size() >= 1)
            {
                
                try {
                    if (check(p)){
                        cmd_stack = create_stack.Create(p);
                        cmd_stack->execute(p);
                        delete cmd_stack;
                    }
                    p.vst.clear();
                }
                catch (Exception &expn){
                    std::cerr << expn.what();
                    return 1;
                }
                catch (const char* exceptions) {
                    std::cerr << exceptions;
                    return 1;
                }
                catch (...) {
                    std::cerr << "Program run error";
                    return 1;
                }
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
            split(p, line, ' ');
            if (p.vst.size() >= 1)
            {

                try {
                    if (check(p)){
                        cmd_stack = create_stack.Create(p);
                        cmd_stack->execute(p);
                        delete cmd_stack;
                    }
                    p.vst.clear();
                }
                catch (Exception &expn) {
                    std::cerr << expn.what();
                    return 1;
                }
                catch (const char* exceptions) {
                    std::cerr << exceptions;
                    return 1;
                }
                catch (...) {
                    std::cerr << "Program run error";
                    return 1;
                }
            }
        }
    }

    return 0;
}
