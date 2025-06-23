//
// Created by Andrii Klykavka on 26.05.2025.
//

#include <iostream>
#include <string>
#include <vector>
#include "../../include/models/TextEditor.h"

#include "../../include/command_execution.h"
#include "../../include/models//utility/IndexTuple.h"
#include "../../include/models/lines/CheckboxLine.h"
#include "../../include/models/lines/ContactLine.h"

TextEditor::TextEditor() {
    IReadable* l = new TextLine();
    lines.push_back(l);
}

TextEditor::~TextEditor() {
    for(IReadable* l : lines)
        delete l;
}

std::vector<IReadable*> TextEditor::getLines() const {
    return lines;
}

size_t TextEditor::getHeight() const {
    return lines.size();
}


std::string& TextEditor::getBufferText() {
    return bufferText;
}

void TextEditor::setBufferText(std::string &text) {
    bufferText = std::move(text);
}

void TextEditor::printLines() const {
    for(IReadable* l : lines)
        std::cout << l->display() << std::endl;
}

void TextEditor::appendText(const std::string &text) const {
    if(ITraversable* l = dynamic_cast<ITraversable*>(lines.back())) {
        l->append_text(text);
    }
    else std::cout << "Unable to append to immutable line." << std::endl;
}

void TextEditor::addLine(const LineType type) {
    switch (type) {
        case text:
            lines.push_back(new TextLine());
            break;
        case contact:
            lines.push_back(new ContactLine());
            break;
        case checkbox:
            lines.push_back(new CheckboxLine());
    }
}

void TextEditor::deleteLine(const size_t lineIdx) {
    if (lineIdx < lines.size()) {
        delete lines.at(lineIdx);
        lines.erase(lines.begin() + static_cast<unsigned long>(lineIdx));
    }
}

void TextEditor::insertText(const IndexTuple pos, const std::string &text) const {
    if(ITraversable* l = dynamic_cast<ITraversable*>(lines.at(pos.line_idx))) {
        l->insert_text(pos.char_idx, text);
    }
    else std::cout << "Unable to insert in immutable line." << std::endl;
}

void TextEditor::search(const std::string &text) const {
    size_t height = lines.size();
    std::cout << "Found at positions: ";
    for (size_t i = 0; i < height; i++) {
        if(ITraversable* l = dynamic_cast<ITraversable*>(lines.at(i))) {
            l->search(i, text);
        }
    }
    std::cout << std::endl;
}

std::string TextEditor::getText(const IndexTuple pos, const size_t length) const {
    if(ITraversable* l = dynamic_cast<ITraversable*>(lines.at(pos.line_idx))) {
        return l->get_text(pos.char_idx, length);
    }
    else {
        std::cout << "Unable to read in immutable line." << std::endl;
        return NULL;
    }
}

void TextEditor::deleteText(const IndexTuple pos, const size_t length) const {
    if(ITraversable* l = dynamic_cast<ITraversable*>(lines.at(pos.line_idx))) {
        l->delete_text(pos.char_idx, length);
    }
    else std::cout << "Unable to delete in immutable line." << std::endl;
}

void TextEditor::copyText(const IndexTuple pos, const size_t length) {
    if(ITraversable* l = dynamic_cast<ITraversable*>(lines.at(pos.line_idx))) {
        l->copy_text(pos.char_idx, length, bufferText);
    }
    else std::cout << "Unable to copy in immutable line." << std::endl;
}


void TextEditor::free() {
    for(IReadable *l : lines)
        delete l;
    lines.clear();
}

// ==== CURSOR ======

IndexTuple TextEditor::getCursorPos() const {
    return cursor.pos;
}

void TextEditor::moveCursorCharIdx(const size_t length, const bool toRight) {
    cursor.moveCharIdx(length, toRight);
}

void TextEditor::setCursorPos(const IndexTuple pos) {
    if (ITraversable* l = dynamic_cast<ITraversable*>(lines.at(pos.line_idx))) {
        size_t height = lines.size();
        cursor.pos.line_idx = pos.line_idx < height ? pos.line_idx : height - 1;
        cursor.pos.char_idx = pos.char_idx < l->get_length() ? pos.char_idx : l->get_length();
    }
}

void TextEditor::printCursorPos() const {
    std::cout << "Cursor position: " << cursor.display() << std::endl;
}

void TextEditor::loadLine(std::string &text) {
    IReadable *l;
    std::string input;
    if (text.length() < 3)
        return;

    std::string pref = text.substr(0, 3);
    if (pref == "(T)") {
        l = new TextLine();
        input = text.substr(4);
    }
    else if (pref == "(C)") {
        l = new ContactLine();
        input = text.substr(4);
    }
    else if (pref == "(X)") {
        l = new CheckboxLine();
        input = text.substr(4);
    }
    else {
        l = new TextLine();
        input = text;
    }

    l->load_data(input);
    lines.push_back(l);
}
