#include <iostream>
#include <sstream>

#include "../include/command_execution.h"
#include "../include/models/AppContext.h"

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
    undo = 9,
    redo = 10,
    cutout = 11,
    paste = 12,
    duplicate = 13,
    interchange = 14,
    finish = 15,
    COUNT = 16
};

void handleCommand(AppContext &context, CommandType command) {
    switch (command) {
        case help:
            showInstructions();
            break;
        case append:
            appendText(context);
            break;
        case newline:
            addNewLine(context);
            break;
        case save:
            saveFile(context);
            break;
        case load:
            loadFile(context);
            break;
        case print:
            printText(context);
            break;
        case insert:
            insertByLineAndIndex(context);
            break;
        case spot:
            searchText(context);
            break;
        case vanish:
            deleteText(context);
            break;
        case undo:
            undoCommand(context);
            break;
        case redo:
            redoCommand(context);
            break;
        case cutout:
            cutText(context);
            break;
        case paste:
            pasteText(context);
            break;
        case duplicate:
            copyText(context);
            break;
        case interchange:
            replaceText(context);
            break;
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

[[noreturn]] int main() {
    TextEditor editor(16);
    CommandManager manager(5);

    AppContext context(editor, manager);

    std::cout << "Welcome to text editor!" << std::endl;

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
        if (num < 0 || num >= CommandType::COUNT) {
            cerr << "Unrecognized command number." << endl;
        }

        auto command = static_cast<CommandType>(num);
        handleCommand(context, command);
    }
}