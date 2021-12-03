#include "../../inc/App.h"
#include "../../inc/CalcCmds.h"

#include <iostream>
#include <deque>
#include <memory>

ns_Calc::CalcContext proceedWithArgs(const char *path)
{
    std::ifstream ifs(path);
    if (ifs)
    {
        std::cin.rdbuf(ifs.rdbuf());
        return calculate(ifs);
    }
    else
        throw std::runtime_error("File Not Found");
}

ns_Calc::CalcContext proceedNoArgs()
{
    return calculate(std::cin);
}

ns_Calc::CalcContext calculate(std::istream &input)
{
    ns_Calc::CalcContext calc;
    std::string buff;
    std::deque<std::unique_ptr<abstract_command>> pipeline;
    int err_line = 1;
    for (;!input.eof(); std::getline(input, buff))
    {
        try
        {
            if (buff == "" || buff[0] == '#')
                continue;
            pipeline.emplace_back(CreateAbstCmd(buff));
            err_line++;
        }
        catch (std::exception& e)
        {
            auto error = (std::string(e.what())+"\nError was occured in " + 
                                std::to_string(err_line) + " line: " + buff); 
            throw std::runtime_error(error.c_str());
        }
    }

    while (pipeline.empty() != true)
    {
        pipeline.front().get()->execute(calc);
        pipeline.pop_front();
    }
    return calc;
}