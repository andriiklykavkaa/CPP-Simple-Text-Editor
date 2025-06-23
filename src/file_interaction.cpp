//
// Created by Andrii Klykavka on 27.05.2025.
//

#include <fstream>
#include <iostream>

#include "../include/file_interaction.h"
#include "../include/models/TextEditor.h"
#include "../include/models/lines/TextLine.h"


void writeBufferToFile(const TextEditor &editor, const std::string &path) {
    std::ofstream file(path);
    if (!file.is_open()) {
        std::cerr << "Could not write to file at path: " << path << std::endl;
        return;
    }

    const size_t bufHeight = editor.getHeight();
    const std::vector<IReadable*> lines = editor.getLines();
    for (int i = 0; i < bufHeight; ++i) {
        file << lines.at(i)->display() << "\n";
    }
    file.close();
    std::cout << "File is successfully written." << std::endl;
}

void readFileToBuffer(TextEditor &buffer, const std::string &path) {
    buffer.free();
    std::ifstream file(path);
    if (!file.is_open()) {
        std::cerr << "Could not read file at path: " << path << std::endl;
        return;
    }

    std::string line;
    while(getline(file, line)) {
        if (line.back() == '\n') line.pop_back();
        buffer.loadLine(line);
    }
    file.close();
    std::cout << "File is successfully read." << std::endl;
}