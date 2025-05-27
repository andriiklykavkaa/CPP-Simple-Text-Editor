//
// Created by Andrii Klykavka on 26.05.2025.
//

#ifndef BUFFER_H
#define BUFFER_H
#include <string>

#include "abstract/Command.h"

using namespace std;

class Buffer {
private:
    string* lines;
    size_t height;
    size_t capacity;

    void reallocate(size_t newCapacity);

public:
    explicit Buffer(size_t capacity);
    ~Buffer();

    [[nodiscard]] string* getLines() const;
    [[nodiscard]] size_t getHeight() const;
    [[nodiscard]] size_t getCapacity() const;

    void printBuffer() const; // No need
    void appendText(const string& text) const; // DONE
    void addLine(); // DONE
    void insertText(size_t line_idx, size_t char_idx, const string& text) const; // DONE
    void search(const string &text) const; // No need
    void deleteText(size_t line_idx, size_t char_idx, size_t length); // DONE
    string getText(size_t lineIdx, size_t charIdx, size_t length); // support
    void deleteLine(size_t lineIdx); // support
    void loadLine(string &text); // support
    void free();

    Buffer(const Buffer&) = delete;
    Buffer& operator=(const Buffer&) = delete;
};

#endif //BUFFER_H
