#include "calculator.hpp"
#include <memory>
void preprocess_func(std::istream &in) {

    std::unique_ptr<Command> command;
    Context DATA;
    Cmdcreate created;
    std::string str;
    std::vector<std::string> delim_words;
    std::string one_word;
    while (std::getline(in, str, '\n')) {
        if (str.empty())
            continue;
        std::stringstream str_new(str);
        while (std::getline(str_new, one_word, ' '))
            delim_words.push_back(one_word);
        command = created.Fmethod(delim_words);
        command->cmd(DATA, delim_words);
        delim_words.clear();
    }


}
    void Preprocessing(std::stringstream &input1, std::ifstream &input2, int flag){
    if (flag == 1) {
        preprocess_func(std::cin);
    } else if (flag == 2) {
        preprocess_func(input2);
    } else if (flag == 3) {
        preprocess_func(input1);
    }

}
