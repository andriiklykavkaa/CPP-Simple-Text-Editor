//
// Created by Andrii Klykavka on 17.06.2025.
//

#include <string>

#include "../../../include/models/lines/TextLine.h"

std::string TextLine::get_data() {
    return text;
}

void TextLine::set_data(const std::string text) {
    this->text = text;
}

std::string TextLine::to_string() {
    return text;
}


