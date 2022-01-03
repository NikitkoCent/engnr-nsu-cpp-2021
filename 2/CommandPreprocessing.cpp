#include "calculator.hpp"

    void Preprocessing(std::stringstream &input1, std::ifstream &input2, int flag){
    Command *command;
    Context DATA;
    Cmdcreate created;
    std::string str;
    std::vector<std::string> delim_words;
    std::string one_word;
    if (flag == 1)
    {
        while(std::getline(std::cin, str, '\n')){
            if(str.empty())
                continue;
            std::stringstream str_new(str);
            while(std::getline(str_new,one_word,' '))
                delim_words.push_back(one_word);    
            command = created.Fmethod(delim_words);
            command->cmd(DATA,delim_words);
            delim_words.clear();
            delete command;
        }
    }
    else if (flag == 2) {
        while (std::getline(input1, str, '\n')) {
            if (str.empty())
                continue;
            std::stringstream str_new(str);
            while (std::getline(str_new, one_word, ' '))
                delim_words.push_back(one_word);
            command = created.Fmethod(delim_words);
            command->cmd(DATA, delim_words);
            delim_words.clear();
            delete command;
        }
    }
    else if (flag == 3) {
        while (std::getline(input2, str, '\n')) {
            if (str.empty())
                continue;
            std::stringstream str_new(str);
            while (std::getline(str_new, one_word, ' '))
                delim_words.push_back(one_word);
            command = created.Fmethod(delim_words);
            command->cmd(DATA, delim_words);
            delim_words.clear();
            delete command;
        }
    }

}
