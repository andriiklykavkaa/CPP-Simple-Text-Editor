//
// Created by Andrii Klykavka on 26.05.2025.
//

#include <iostream>
#include <string>
#include <vector>
#include "../../include/models/TextEditor.h"
#include "../../include/models//utility/IndexTuple.h"

TextEditor::TextEditor() {
    TextLine* l = new TextLine();
    lines.push_back(l);
}

TextEditor::~TextEditor() {
    for(TextLine* l : lines)
        delete l;
}

std::vector<TextLine*> TextEditor::getLines() const {
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
    size_t height = getHeight();
    for (size_t i = 0; i < height; i++) {
        std::cout << lines.at(i)->display() << std::endl;
    }
}

void TextEditor::appendText(const std::string &text) const {
    lines.back()->append_text(text);
}

void TextEditor::addLine() {
    lines.push_back(new TextLine());
}

void TextEditor::deleteLine(const size_t lineIdx) {
    if (lineIdx < lines.size()) {
        delete lines.at(lineIdx);
        lines.erase(lines.begin() + static_cast<unsigned long>(lineIdx));
    }

}

void TextEditor::insertText(const IndexTuple pos, const std::string &text) const {
    lines.at(pos.line_idx)->insert_text(pos.char_idx, text);
}

void TextEditor::search(const std::string &text) const {
    size_t height = lines.size();
    std::cout << "Found at positions: ";
    for (size_t i = 0; i < height; i++) {
        lines.at(i)->search(i, text);
    }
    std::cout << std::endl;
}

std::string TextEditor::getText(const IndexTuple pos, const size_t length) const {
    return lines.at(pos.line_idx)->get_text(pos.char_idx, length);
}

void TextEditor::deleteText(const IndexTuple pos, const size_t length) const {
    lines.at(pos.line_idx)->delete_text(pos.char_idx, length);
}

// void TextEditor::cutText(const IndexTuple pos, const size_t length) {
//     lines.at(pos.line_idx)->cut_text(pos.line_idx, length, bufferText);
// }

void TextEditor::copyText(const IndexTuple pos, const size_t length) {
    lines.at(pos.line_idx)->copy_text(pos.char_idx, length, bufferText);
}

// void TextEditor::pasteText(const IndexTuple pos) const {
//     lines.at(pos.line_idx)->paste_text(pos.char_idx, bufferText);
// }

// ==== CURSOR ======

IndexTuple TextEditor::getCursorPos() const {
    return cursor.pos;
}

void TextEditor::moveCursorCharIdx(const size_t length, const bool toRight) {
    cursor.moveCharIdx(length, toRight);
}

void TextEditor::setCursorPos(const IndexTuple pos) {
    size_t height = lines.size();;
    if (!(pos.line_idx < height && pos.char_idx < lines.at(pos.line_idx)->get_length()))
        return;
    cursor.pos.line_idx = pos.line_idx;
    cursor.pos.char_idx = pos.char_idx;
}

void TextEditor::printCursorPos() const {
    std::cout << "Cursor position: " << cursor.display() << std::endl;
}

void TextEditor::loadLine(std::string &text) {
    TextLine* l = static_cast<TextLine *>(malloc(sizeof(TextLine)));
    l->load_data(text);
    lines.push_back(l);
}

void TextEditor::free() {
    for(TextLine *l : lines)
        delete l;
    lines.clear();
}