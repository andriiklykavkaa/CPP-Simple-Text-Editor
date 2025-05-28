//
// Created by Andrii Klykavka on 26.05.2025.
//

#include <iostream>
#include <string>
#include "../../include/models/TextEditor.h"

using namespace std;

void TextEditor::reallocate(size_t newCapacity) {
    auto* newLines = new string[newCapacity];
    for (size_t i = 0; i < height; i++) {
        newLines[i] = lines[i];
    }
    delete[] lines;
    lines = newLines;
    capacity = newCapacity;
}

TextEditor::TextEditor(size_t capacity):
lines(new string[capacity]), height(1), capacity(capacity) {}

TextEditor::~TextEditor() {
    delete[] lines;
}

string* TextEditor::getLines() const {
    return lines;
}

size_t TextEditor::getHeight() const {
    return height;
}

size_t TextEditor::getCapacity() const {
    return capacity;
}

string TextEditor::getBufferText() const {
    return bufferText;
}

void TextEditor::setBufferText(string text) {
    bufferText = move(text);
}

void TextEditor::printLines() const {
    for (size_t i = 0; i < height; i++) {
        cout << lines[i]<< endl;
    }
}

void TextEditor::appendText(const string &text) const {
    lines[height-1].append(text);
}

void TextEditor::addLine() {
    if (height >= capacity) {
        reallocate(capacity * 2);
    }
    height++;
}

void TextEditor::deleteLine(size_t lineIdx) {
    for (size_t i = lineIdx; i < height - 1; i++) {
        lines[i] = lines[i+1];
    }
    --height;
}

void TextEditor::insertText(size_t lineIdx, size_t charIdx, const string &text) const {
    if (!areIndicesInRange(lineIdx, charIdx)) return;
    lines[lineIdx].insert(charIdx, text);
}

class IndexTuple {
private:
    size_t lineIdx;
    size_t charIdx;

public:
    IndexTuple(size_t aLineIdx, size_t aCharIdx) :
    lineIdx(aLineIdx), charIdx(aCharIdx) {}

    IndexTuple():
    lineIdx(0), charIdx(0) {}

    ~IndexTuple() = default;

    [[nodiscard]] string getString() const {
        return "(" + to_string(lineIdx) + ", " + to_string(charIdx) + ")";
    }
};

class SearchResult {
private:
    IndexTuple *tuples;
    size_t size;
    size_t capacity;

    void reallocate(size_t newCapacity) {
        auto newTuples = new IndexTuple[newCapacity];
        for (int i = 0; i < size; ++i) {
            newTuples[i] = tuples[i];
        }
        delete[] tuples;
        tuples = newTuples;
        capacity = newCapacity;
    }

public:
    explicit SearchResult(size_t capacity):
    tuples(new IndexTuple[capacity]), size(0), capacity(capacity) {
        if (capacity <= 0 ) {
            cerr << "Error initializing SearchResult. Capacity must be positive" << endl;
            return;
        }
    }

    ~SearchResult() {
        delete[] tuples;
    }

    void add(const IndexTuple &tuple) {
        if (size >= capacity) {
            reallocate(capacity *= 2);
        }
        tuples[size] = tuple;
        ++size;
    }

    void print() const {
        for (int i = 0; i < size; ++i) {
            cout << tuples[i].getString() << " ";
        }
    }
};

void TextEditor::search(const string &text) const {
    SearchResult result(8);

    size_t pos = 0;
    for (size_t i = 0; i < height; i++) {
        while ((pos = lines[i].find(text, pos)) != string::npos) {
            result.add(IndexTuple(i, pos));
            pos += text.length();
        }
        pos = 0;
    }

    cout << "Found at positions: ";
    result.print();
    cout << endl;
}

string TextEditor::getText(size_t lineIdx, size_t charIdx, size_t length) {
    if (!areIndicesInRange(lineIdx, charIdx)) return NULL;
    return lines[lineIdx].substr(charIdx, length);
}

void TextEditor::deleteText(size_t lineIdx, size_t charIdx, size_t length) {
    if (!areIndicesInRange(lineIdx, charIdx)) return;
    lines[lineIdx].erase(charIdx, length);
}

void TextEditor::cutText(size_t lineIdx, size_t charIdx, size_t length) {
    if (!areIndicesInRange(lineIdx, charIdx)) return;
    bufferText = lines[lineIdx].substr(charIdx, length);
    lines[lineIdx].erase(charIdx, length);
}

void TextEditor::copyText(size_t lineIdx, size_t charIdx, size_t length) {
    if (!areIndicesInRange(lineIdx, charIdx)) return;
    bufferText = lines[lineIdx].substr(charIdx, length);
}

void TextEditor::pasteText(size_t lineIdx, size_t charIdx) {
    if (!areIndicesInRange(lineIdx, charIdx)) return;
    lines[lineIdx].insert(charIdx, bufferText);
}

// ==== CURSOR ======

size_t TextEditor::getCursorLineIdx() const {
    return cursor.lineIdx;
}

size_t TextEditor::getCursorCharIdx() const {
    return cursor.charIdx;
}

void TextEditor::moveCursorCharIdx(size_t length, const bool toRight) {
    cursor.moveCharIdx(length, toRight);
}

void TextEditor::setCursorPos(size_t lineIdx, size_t charIdx) {
    if (!areIndicesInRange(lineIdx, charIdx)) return;
    cursor.lineIdx = lineIdx;
    cursor.charIdx = charIdx;
}

void TextEditor::printCursorPos() const {
    cout << "Cursor position: " << cursor.getString() << endl;
}

bool TextEditor::areIndicesInRange(size_t lineIdx, size_t charIdx) const {
    if (lineIdx >= height) {
        cout << "Line index out of bounds." << endl;
        return false;
    }

    string &line = lines[lineIdx];
    if(charIdx > line.length()) {
        cout << "Char index out of bounds." << endl;
        return false;
    }
    return true;
}


void TextEditor::loadLine(string &text) {
    if (height >= capacity) {
        reallocate(capacity *= 2);
    }
    lines[height] = text;
    height++;
}

void TextEditor::free() {
    delete[] lines;
    lines = new string[capacity];
    height = 0;
}