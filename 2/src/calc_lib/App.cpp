#include "../../inc/App.h"
#include "../../inc/CalcCmds.h"
#include "../../inc/exceptions.h"

#include <iostream>
#include <deque>
#include <memory>

ns_Calc::CalcContext proceedWithArgs(const char *path)
{
    std::ifstream ifs(path);
    if (ifs)
        return calculate(ifs);
    else
        throw std::runtime_error("File Not Found");
}

ns_Calc::CalcContext proceedNoArgs(std::istream &input)
{
    return calculate(input);
}

ns_Calc::CalcContext calculate(std::istream &input)
{
    ns_Calc::CalcContext calc;
    std::string buff;
    std::deque<std::unique_ptr<abstract_command>> pipeline;
    int err_line = 1;
    while (std::getline(input, buff))
    {
        try
        {
            if (buff == "" || buff[0] == '#')
                continue;
            pipeline.emplace_back(CreateAbstCmd(buff));
            err_line++;
        }
        catch (std::exception &e)
        {
            throw CalcRuntimeExc(e.what(), buff, err_line);
        }
    }
    err_line = 1;
    while (pipeline.empty() != true)
    {
        try
        {
            pipeline.front().get()->execute(calc);
        }
        catch (const std::exception &e)
        {
            throw CalcRuntimeExc(e.what(), "", err_line);
        }

        pipeline.front().get()->execute(calc);
        pipeline.pop_front();
    }
    return calc;
}