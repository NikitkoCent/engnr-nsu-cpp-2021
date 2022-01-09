#include "Lab_2.h"
#include "Operations.h"


void input_processing(ifstream &ins, string &line, Param &p) {
    OperationsFactory create_stack;
    Operations* cmd_stack;
    split(p, line, ' ');
    if (p.vst.size() >= 1)
    {
        if (check(p)) {
            cmd_stack = create_stack.Create(p);
            cmd_stack->execute(p);
            delete cmd_stack;
         }
         p.vst.clear();
    }

}
int main(int argc, char* argv[]) {

    std::string s;
    Param p;
    string filename;
    string line;
    if (argc >= 2)
    {
        filename = argv[1];
    }
    ifstream in(filename);
    if (argc >= 2 && in.is_open() == 1)
    {
        std::cerr << "File not found" << endl;
        return 1;
    }
    else {
        try {
            if (in.is_open())
            {
                while (getline(in, line)) {
                    input_processing(ins, line, p);
                }
            }
            else {
                while (getline(cin, line))
                {
                    input_processing(ins, line, p);
                }
            }

        }
        catch (Exception& expn) {
            std::cerr << expn.what();
            return 1;
        }
        catch (const char* exceptions) {
            std::cerr << exceptions;
            return 1;
        }
    }
    

    return 0;
}
