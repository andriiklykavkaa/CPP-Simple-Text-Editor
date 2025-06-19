//
// Created by Andrii Klykavka on 26.05.2025.
//

#include <iostream>
#include <string>
#include "../../include/models/TextEditor.h"
#include "../../include/models//utility/IndexTuple.h"


using namespace std;

TextEditor::TextEditor(size_t capacity):
lines(new TextLine[capacity]), height(1), capacity(capacity) {}

void TextEditor::reallocate(size_t newCapacity) {
    auto* newLines = new TextLine[newCapacity];
    for (size_t i = 0; i < height; i++) {
        newLines[i] = lines[i];
    }
    delete[] lines;
    lines = newLines;
    capacity = newCapacity;
}

TextEditor::~TextEditor() {
    delete[] lines;
}

TextLine* TextEditor::getLines() const {
    return lines;
}

size_t TextEditor::getHeight() const {
    return height;
}

size_t TextEditor::getCapacity() const {
    return capacity;
}

string& TextEditor::getBufferText() {
    return bufferText;
}

void TextEditor::setBufferText(string &text) {
    bufferText = std::move(text);
}

void TextEditor::printLines() const {
    for (size_t i = 0; i < height; i++) {
        cout << lines[i].display() << endl;
    }
}

void TextEditor::appendText(const string &text) const {
    lines[height-1].append_text(text);
}

void TextEditor::addLine() {
    if (height >= capacity) {
        reallocate(capacity * 2);
    }
    height++;
}

void TextEditor::deleteLine(const size_t lineIdx) {
    for (size_t i = lineIdx; i < height - 1; i++) {
        lines[i] = lines[i+1];
    }
    --height;
}

void TextEditor::insertText(const IndexTuple pos, const string &text) const {
    lines[pos.line_idx].insert_text(pos.char_idx, text);
}

void TextEditor::search(const string &text) const {
    cout << "Found at positions: ";
    for (size_t i = 0; i < height; i++) {
        lines[i].search(i, text);
    }
    cout << endl;
}

string TextEditor::getText(const IndexTuple pos, const size_t length) const {
    return lines[pos.line_idx].get_text(pos.char_idx, length);
}

void TextEditor::deleteText(const IndexTuple pos, const size_t length) const {
    lines[pos.line_idx].delete_text(pos.char_idx, length);
}

void TextEditor::cutText(const IndexTuple pos, const size_t length) {
    lines[pos.line_idx].cut_text(pos.line_idx, length, bufferText);
}

void TextEditor::copyText(const IndexTuple pos, const size_t length) {
    lines[pos.line_idx].copy_text(pos.char_idx, length, bufferText);
}

void TextEditor::pasteText(const IndexTuple pos) const {
    lines[pos.line_idx].paste_text(pos.char_idx, bufferText);
}

// ==== CURSOR ======


IndexTuple TextEditor::getCursorPos() const {
    return cursor.pos;
}

void TextEditor::moveCursorCharIdx(const size_t length, const bool toRight) {
    cursor.moveCharIdx(length, toRight);
}

void TextEditor::setCursorPos(const IndexTuple pos) {
    if (!(pos.line_idx < height && pos.char_idx < lines[pos.line_idx].get_length()))
        return;
    cursor.pos.line_idx = pos.line_idx;
    cursor.pos.char_idx = pos.char_idx;
}

void TextEditor::printCursorPos() const {
    cout << "Cursor position: " << cursor.display() << endl;
}

void TextEditor::loadLine(string &text) {
    if (height >= capacity) {
        reallocate(capacity *= 2);
    }
    lines[height].load_data(text);
    height++;
}

void TextEditor::free() {
    delete[] lines;
    lines = new TextLine[capacity];
    height = 0;
}