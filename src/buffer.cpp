//
// Created by Andrii Klykavka on 26.05.2025.
//



#include <iostream>
#include <string>
#include "../include/buffer.h"

using namespace std;

void Buffer::reallocate(size_t newCapacity) {
    auto* newLines = new string[newCapacity];
    for (size_t i = 0; i < height; i++) {
        newLines[i] = lines[i];
    }
    delete[] lines;
    lines = newLines;
    capacity = newCapacity;
}

Buffer::Buffer(size_t capacity):
lines(new string[capacity]), height(1), capacity(capacity) {}

Buffer::~Buffer() {
    delete[] lines;
}

string* Buffer::getLines() const {
    return lines;
}

size_t Buffer::getHeight() const {
    return height;
}

size_t Buffer::getCapacity() const {
    return capacity;
}

void Buffer::printBuffer() const {
    for (size_t i = 0; i < height; i++) {
        cout << lines[i]<< endl;
    }
}

void Buffer::appendText(const string &text) const {
    lines[height-1].append(text);
}

void Buffer::addLine() {
    if (height >= capacity) {
        reallocate(capacity * 2);
    }
    height++;
}

void Buffer::insert(size_t line_idx, size_t char_idx, const string &text) const {
    if (line_idx >= height) {
        printf("Line index out of bounds.");
        return;
    }

    if(lines[line_idx].length() > char_idx) {
        printf("Char index out of bounds.");
        return;
    }

    lines[line_idx].insert(char_idx, text);
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

} ;

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
        cout << "Deleting SearchResult...";
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

void Buffer::search(const string &text) const {
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

void Buffer::loadLine(string &text) {
    if (height >= capacity) {
        reallocate(capacity *= 2);
    }
    lines[height] = text;
    height++;
}
