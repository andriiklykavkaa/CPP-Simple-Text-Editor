//
// Created by Andrii Klykavka on 26.05.2025.
//

#ifndef BUFFER_H
#define BUFFER_H
#include <string>

#include "lines/TextLine.h"
#include "utility/IndexTuple.h"


using namespace std;

class TextEditor {
private:

    TextLine* lines;
    size_t height;
    size_t capacity;
    std::string bufferText;

    struct Cursor {
        IndexTuple pos;

        void set(IndexTuple pos) {
            this->pos = pos;
        }

        void moveCharIdx(const size_t length, const bool toRight) {
            pos.char_idx += (toRight) ? length : -length;
        }

        string display() const {
            return "(" + to_string(pos.line_idx) + ", " + to_string(pos.char_idx) + ")";
        }
    };

    Cursor cursor;

    void reallocate(size_t newCapacity);

public:
    explicit TextEditor(size_t capacity);
    ~TextEditor();

    [[nodiscard]] TextLine* getLines() const;
    [[nodiscard]] size_t getHeight() const;
    [[nodiscard]] size_t getCapacity() const;
    [[nodiscard]] string &getBufferText();
    void setBufferText(string &text);

    [[nodiscard]] IndexTuple getCursorPos() const;
    void moveCursorCharIdx(size_t length, bool toRight);
    void printCursorPos() const;
    void setCursorPos(IndexTuple pos);

    void printLines() const;
    void appendText(const string& text) const;
    void addLine();
    void insertText(IndexTuple pos, const string& text) const;
    void search(const string &text) const;
    void deleteText(IndexTuple pos, size_t length) const;
    [[nodiscard]] std::string getText(IndexTuple pos, size_t length) const;
    void cutText(IndexTuple pos, size_t length);
    void copyText(IndexTuple pos, size_t length);
    void pasteText(IndexTuple pos) const;

    void deleteLine(size_t lineIdx);
    void loadLine(string &text);
    void free();

    TextEditor(const TextEditor&) = delete;
    TextEditor& operator=(const TextEditor&) = delete;
};

#endif //BUFFER_H
