//
// Created by Andrii Klykavka on 17.06.2025.
//

#include "../../../include/models/lines/TextLine.h"

#include <iostream>
#include <string>
#include <format>
#include <dlfcn.h>

std::string TextLine::display() const {
    return std::format("(T) {}", text);
}

void TextLine::load_data(std::string &text) {
    this->text = text;
}

char *TextLine::get_data() {
    return text.data();
}

void TextLine::append_text(const std::string& text) {
    this->text.append(text);
}

void TextLine::insert_text(size_t pos, const std::string& text) {
    if (pos > this->text.size()) return;
    this->text.insert(pos, text);
}

void TextLine::search(const size_t heighPos, const std::string &text) const {
    size_t pos = 0;
    while ((pos = this->text.find(text, pos)) != std::string::npos) {
        printf("(%lu, %lu)", heighPos, pos);
        pos += text.length();
    }
}

void TextLine::delete_text(size_t pos, size_t length) {
    this->text.erase(pos, length);
}

void TextLine::cut_text(size_t pos, size_t length, std::string &buffer) {
    buffer = this->text.substr(pos, length);
    this->text.erase(pos, length);
}

void TextLine::copy_text(size_t pos, size_t length, std::string &buffer) const {
    buffer = this->text.substr(pos, length);
}

void TextLine::paste_text(size_t pos, const std::string& buffer) {
    this->text.insert(pos, buffer);
}

bool TextLine::is_index_in_range(size_t pos) const {
    return pos < this->text.length();
}

std::string TextLine::get_text(size_t pos, size_t length) const {
    return this->text.substr(pos, length);
}

size_t TextLine::get_length() const {
    return this->text.length();
}

void TextLine::free() {
    this->text.clear();
}