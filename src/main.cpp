#include <iostream>
#include <sstream>

#include "../include/commands.h"
#include "../include/file_interaction.h"

enum CommandType {
    help = 0,
    append = 1,
    newline = 2,
    save = 3,
    load = 4,
    print = 5,
    insert = 6,
    spot = 7,
    vanish = 8,
    finish = 9
};

void handleCommand(Buffer &buffer, CommandType command) {
    switch (command) {
        case help:
            showInstructions();
            break;
        case append:
            appendText(buffer);
            break;
        case newline:
            addNewLine(buffer);
            break;
        case save:
            saveFile(buffer);
            break;
        case load:
            loadFile(buffer);
            break;
        case print:
            printText(buffer);
            break;
        case insert:
            insertByLineAndIndex(buffer);
            break;
        case spot:
            searchText(buffer);
            break;
        case vanish:
            deleteText(buffer);
        case finish:
            exitProgram();
            break;

    }
}

bool isDigit(const string &s) {
    istringstream iss(s);
    double d;
    return iss >> std::noskipws >> d && iss.eof();
}

[[noreturn]] int main()
{
    Buffer buffer(8);
    std::cout << "Welcome to text editor." << std::endl;

    while(true) {
        string input;
        cout << "Enter command: ";
        cin >> input;

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        bool isInteger = isDigit(input);
        if(!isInteger) {
            cerr << "Invalid command. The command must be integer." << endl;
            continue;
        }

        int num = stoi(input);
        if (num < 0 || num > 8) {
            cerr << "Unrecognized command number." << endl;
        }

        auto command = static_cast<CommandType>(num);
        handleCommand(buffer, command);
    }
}
