//
// Created by Andrii Klykavka on 27.05.2025.
//

#include "../include/commands.h"
#include "../include/buffer.h"
#include "../include/file_interaction.h"

#include <iostream>

using namespace std;

void showInstructions() {
    cout << "The list of instructions." << endl;
    cout << "0 - show the list of commands." << endl;
    cout << "1 - append text." << endl;
    cout << "2 - add new line." << endl;
    cout << "3 - save to file." << endl;
    cout << "4 - load from file." << endl;
    cout << "5 - print text." << endl;
    cout << "6 - insert in text by line and index." << endl;
    cout << "7 - search in text." << endl;
    cout << "8 - exit program." << endl;
}

void appendText(const Buffer &buffer) {
    string text;
    cout << "Enter text to append: ";
    getline(cin, text);
    buffer.appendText(text);
}

void addNewLine(Buffer &buffer) {
    buffer.addLine();
}

void saveFile(const Buffer &buffer) {
    string path;
    cout << "Enter file path for saving: ";
    cin >> path;
    writeBufferToFile(buffer, path);
}

void loadFile(Buffer &buffer) {
    string path;
    cout << "Enter file path for loading: ";
    cin >> path;
    readFileToBuffer(buffer, path);
}

void printText(const Buffer &buffer) {
    buffer.printBuffer();
}

void insertByLineAndIndex(const Buffer &buffer) {
    size_t lineIdx;
    size_t charIdx;

    while(true) {
        cout << "Enter line index and char index: ";
        cin >> lineIdx >> charIdx;

        if (cin.fail()) {
            cerr << "Invalid input. Please enter two integers." << endl;
        } else {
            break;
        }
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string text;
    cout << "Enter text to insert: ";
    getline(cin, text);

    buffer.insert(lineIdx, charIdx, text);
}

void searchText(const Buffer &buffer) {
    string text;
    cout << "Enter text to search: ";
    getline(cin, text);

    buffer.search(text);
}

void deleteText(Buffer &buffer) {

}

void exitProgram() {
    cout << "Ending program..." << endl;
    exit(101);
}