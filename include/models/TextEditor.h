//
// Created by Andrii Klykavka on 26.05.2025.
//

#ifndef BUFFER_H
#define BUFFER_H
#include <string>

using namespace std;

class TextEditor {
private:
    string* lines;
    size_t height;
    size_t capacity;
    string bufferText;

    void reallocate(size_t newCapacity);

public:
    explicit TextEditor(size_t capacity);
    ~TextEditor();

    [[nodiscard]] string* getLines() const;
    [[nodiscard]] size_t getHeight() const;
    [[nodiscard]] size_t getCapacity() const;
    [[nodiscard]] string getBufferText() const;
    void setBufferText(string text);

    void printBuffer() const; // No need
    void appendText(const string& text) const; // DONE
    void addLine(); // DONE
    void insertText(size_t line_idx, size_t char_idx, const string& text) const; // DONE
    void search(const string &text) const; // No need
    void deleteText(size_t line_idx, size_t char_idx, size_t length); // DONE
    void cutText(size_t line_idx, size_t char_idx, size_t length);
    void copyText(size_t line_idx, size_t char_idx, size_t length);
    void pasteText(size_t line_idx, size_t char_idx);
    void replaceText(size_t line_idx, size_t char_idx, string& text);

    [[nodiscard]] bool areIndicesInRange(size_t line_idx, size_t char_idx) const;
    string getText(size_t lineIdx, size_t charIdx, size_t length); // support
    void deleteLine(size_t lineIdx); // support
    void loadLine(string &text); // support
    void free();

    TextEditor(const TextEditor&) = delete;
    TextEditor& operator=(const TextEditor&) = delete;
};

#endif //BUFFER_H
