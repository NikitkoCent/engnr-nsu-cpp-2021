#include "../../inc/App.h"
#include "../../inc/CalcCmds.h"

#include <iostream>
#include <deque>
#include <memory>
#include <filesystem>

ns_Calc::CalcContext proceedWithArgs(const char *path)
{
    std::ifstream ifs(path);
    if (ifs)
        return calculateWithArgs(ifs);
    else
        throw std::runtime_error("File Not Found");
}

ns_Calc::CalcContext calculateWithArgs(std::ifstream &ifs)
{
    ns_Calc::CalcContext calc;
    std::string buff;
    std::deque<std::unique_ptr<abstract_command>> pipeline;
    while (ifs.good())
    {
        std::getline(ifs, buff);
        if (buff == "" || buff[0] == '#')
            continue;
        pipeline.emplace_back(CreateAbstCmd(buff));
    }

    while (pipeline.empty() != true)
    {
        pipeline.front().get()->execute(calc);
        pipeline.pop_front();
    }
    return calc;
}

ns_Calc::CalcContext proceedNoArgs()
{
    return calculateNoArgs();
}

CalcContext calculateNoArgs()
{
    ns_Calc::CalcContext calc;
    std::string buff;
    std::deque<std::unique_ptr<abstract_command>> pipeline;
    while (buff != "exit")
    {
        std::cin >> buff;
        pipeline.emplace_back(CreateAbstCmd(buff));
    }

    while (pipeline.empty() != true)
    {
        pipeline.front().get()->execute(calc);
        pipeline.pop_front();
    }
    return calc;
}