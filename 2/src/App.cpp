#include "../inc/App.h"
#include "../inc/CalcCmds.h"

#include <iostream>
#include <deque>
#include <memory>

void proceedWithArgs(const char *path) {
    std::ifstream ifs(path);
    if (ifs) {
        calculateWithArgs(ifs);
    } else {
        throw std::runtime_error("File Not Found");
    }
}

void calculateWithArgs(std::ifstream& ifs)
{
    ns_Calc::CalcContext calc;
    std::string buff;
    std::deque<std::unique_ptr<abstract_command>> pipeline;
    while (ifs.good())
    {
        std::getline(ifs,buff);
        if (buff == "") continue;
        pipeline.emplace_back(CreateAbstCmd(buff));
    }

    while (pipeline.empty() != true)
    {
        pipeline.front().get()->execute(calc);
        pipeline.pop_front();
    }
}

void proceedNoArgs()
{
    calculateNoArgs();
}

void calculateNoArgs()
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
}