//
// Created by Mikhail Okan on 06.01.2022.
//

#include "ScenarioViewer.h"

void ScenarioViewer::load(const std::string& scenario) {
    std::string path_to_log_dir = "../Scenario";
    std::string path_to_log = path_to_log_dir + '/' + scenario;
    fs.open(path_to_log);
}

std::string ScenarioViewer::next() {
    if (model->get_turn_number() < 20) {
        fs >> arg1 >> arg2;
        model->set(arg1, arg2);
        return arg1 + " " + arg2;
    } else {
        fs >> arg1;
        model->hit(arg1);
        return arg1;
    }
}

bool ScenarioViewer::eof() {
    return fs.eof();
}