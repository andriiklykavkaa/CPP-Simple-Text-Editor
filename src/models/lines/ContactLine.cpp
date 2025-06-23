//
// Created by Andrii Klykavka on 19.06.2025.
//

#include "../../../include/models/lines/ContactLine.h"

#include <dlfcn.h>
#include <format>

std::string ContactLine::display() const {
    return std::format("(C) {}", text);
}

void ContactLine::load_data(std::string &text) {
    this->text = std::move(text);
}

char *ContactLine::get_data() {
    return text.data();
}