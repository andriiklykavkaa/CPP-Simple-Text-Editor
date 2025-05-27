//
// Created by Andrii Klykavka on 27.05.2025.
//

#include <fstream>
#include <iostream>

#include "../include/file_interaction.h"
#include "../include/Buffer.h"

using namespace std;

void writeBufferToFile(const Buffer &buffer, const string &path) {
    ofstream file(path);
    if (!file.is_open()) {
        cerr << "Could not write to file at path: " << path << endl;
        return;
    }

    const size_t bufHeight = buffer.getHeight();
    const string *lines = buffer.getLines();
    for (int i = 0; i < bufHeight; ++i) {
        file << lines[i] << "\n";
    }
    file.close();
    cout << "File is successfully written." << endl;
}

void readFileToBuffer(Buffer &buffer, const string &path) {
        ifstream file(path);
    if (!file.is_open()) {
        cerr << "Could not read file at path: " << path << endl;
        return;
    }

    string line;
    while(getline(file, line)) {
        if (line.back() == '\n') line.pop_back();
        buffer.loadLine(line);
    }
    file.close();
    cout << "File is successfully read." << endl;
}