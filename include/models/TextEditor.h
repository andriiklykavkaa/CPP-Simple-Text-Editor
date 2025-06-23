//
// Created by Andrii Klykavka on 26.05.2025.
//

#ifndef BUFFER_H
#define BUFFER_H
#include <string>
#include <vector>

#include "../command_execution.h"
#include "lines/TextLine.h"
#include "utility/IndexTuple.h"


class TextEditor {
private:

    std::vector<BaseLine*> lines;
    std::string bufferText;

    struct Cursor {
        IndexTuple pos;

        void set(IndexTuple pos) {
            this->pos = pos;
        }

        void moveCharIdx(const size_t length, const bool toRight) {
            pos.char_idx += (toRight) ? length : -length;
        }

        std::string display() const {
            return "(" + std::to_string(pos.line_idx) + ", " + std::to_string(pos.char_idx) + ")";
        }
    };

    Cursor cursor{};

public:
    explicit TextEditor();
    ~TextEditor();

    [[nodiscard]] std::vector<BaseLine*> getLines() const;
    [[nodiscard]] size_t getHeight() const;
    [[nodiscard]] std::string &getBufferText();
    void setBufferText(std::string &text);

    [[nodiscard]] IndexTuple getCursorPos() const;
    void moveCursorCharIdx(size_t length, bool toRight);
    void printCursorPos() const;
    void setCursorPos(IndexTuple pos);

    void printLines() const;
    void appendText(const std::string& text) const;
    void addLine(LineType type);
    void deleteLine(size_t lineIdx);
    void insertText(IndexTuple pos, const std::string& text) const;
    void search(const std::string &text) const;
    void deleteText(IndexTuple pos, size_t length) const;
    [[nodiscard]] std::string getText(IndexTuple pos, size_t length) const;
    void copyText(IndexTuple pos, size_t length);
    void encryptText();
    void decryptText();

    void loadLine(std::string &text);
    void free();

    TextEditor(const TextEditor&) = delete;
    TextEditor& operator=(const TextEditor&) = delete;
};

#endif //BUFFER_H
