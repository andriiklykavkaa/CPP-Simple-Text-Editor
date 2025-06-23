//
// Created by Andrii Klykavka on 19.06.2025.
//

#include "../../../include/models/lines/CheckboxLine.h"

#include <format>

std::string CheckboxLine::display() const {
    return std::format("(X) {}", text);
}

void CheckboxLine::load_data(std::string &text) {
    this->text = text;
}
