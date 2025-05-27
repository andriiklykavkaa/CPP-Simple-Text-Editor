//
// Created by Andrii Klykavka on 27.05.2025.
//

#include <fstream>
#include <iostream>

#include "../include/file_interaction.h"
#include "../include/models/TextEditor.h"

using namespace std;

void writeBufferToFile(const TextEditor &editor, const string &path) {
    ofstream file(path);
    if (!file.is_open()) {
        cerr << "Could not write to file at path: " << path << endl;
        return;
    }

    const size_t bufHeight = editor.getHeight();
    const string *lines = editor.getLines();
    for (int i = 0; i < bufHeight; ++i) {
        file << lines[i] << "\n";
    }
    file.close();
    cout << "File is successfully written." << endl;
}

void readFileToBuffer(TextEditor &buffer, const string &path) {
    buffer.free();
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