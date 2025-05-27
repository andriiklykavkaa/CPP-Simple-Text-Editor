//
// Created by Andrii Klykavka on 26.05.2025.
//

#ifndef BUFFER_H
#define BUFFER_H
#include <string>

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

    void printBuffer() const;
    void appendText(const string& text) const;
    void addLine();
    void insert(size_t line_idx, size_t char_idx, const string& text) const;
    void search(const string &text) const;
    void loadLine(string &text);
    
    Buffer(const Buffer&) = delete;
    Buffer& operator=(const Buffer&) = delete;
};

#endif //BUFFER_H
