//
// Created by Andrii Klykavka on 19.06.2025.
//

#include "../../../include/models/lines/CheckboxLine.h"

#include <format>

std::tuple<std::string, bool> CheckboxLine::get_data() {
    return std::make_tuple(text, isDone);
}

void CheckboxLine::set_data(std::tuple<std::string, bool> contact_info) {
    text = std::get<0>(contact_info);
    isDone = std::get<1>(contact_info);
}

std::string CheckboxLine::to_string() {
    char checkpoit = isDone ? 'X' : ' ';
    return std::format("[ {} ] {}", checkpoit, text);
}



