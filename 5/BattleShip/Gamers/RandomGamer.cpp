//
// Created by Mikhail Okan on 06.01.2022.
//

#include "RandomGamer.h"

std::vector<std::string> RandomGamer::turn_set_stage() {
    return random_generate_next_turn();
}

std::vector<std::string> RandomGamer::turn_attack_stage() {
    return random_generate_next_turn();
}