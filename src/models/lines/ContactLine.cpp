//
// Created by Andrii Klykavka on 19.06.2025.
//

#include "../../../include/models/lines/ContactLine.h"

#include <format>

std::tuple<std::string, std::string> ContactLine::get_data() {
    return std::make_tuple(name, email);
}

void ContactLine::set_data(std::tuple<std::string, std::string> contact_info) {
    name = std::get<0>(contact_info);
    email = std::get<1>(contact_info);
}

std::string ContactLine::to_string() {
    return std::format('Name: {}. Email: {}', name, email);
}


