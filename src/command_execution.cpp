//
// Created by Andrii Klykavka on 27.05.2025.
//

#include <iostream>

#include "../include/command_execution.h"
#include "../include/file_interaction.h"
#include "../include/models/AppContext.h"
#include "../include/models/commands/AddLineCommand.h"
#include "../include/models/commands/AppendTextCommand.h"
#include "../include/models/commands/CutTextCommand.h"
#include "../include/models/commands/DeleteTextCommand.h"
#include "../include/models/commands/InsertTextCommand.h"
#include "../include/models/commands/PasteTextCommand.h"
#include "../include/models/commands/ReplaceTextCommand.h"

using namespace std;

void showInstructions() {
    cout << "The list of instructions." << endl;
    cout << "0 - show the list of commands." << endl;
    cout << "=====================" << endl;
    cout << "1 - append text." << endl;
    cout << "2 - add new line." << endl;
    cout << "3 - save to file." << endl;
    cout << "4 - load from file." << endl;
    cout << "5 - print text." << endl;
    cout << "6 - insert in text." << endl;
    cout << "7 - search in text." << endl;
    cout << "8 - delete in text." << endl;
    cout << "=====================" << endl;
    cout << "9 - undo." << endl;
    cout << "10 - redo." << endl;
    cout << "=====================" << endl;
    cout << "11 - cut text." << endl;
    cout << "12 - paste text." << endl;
    cout << "13 - copy text." << endl;
    cout << "=====================" << endl;
    cout << "14 - replace." << endl;
    cout << "15 - set cursor position." << endl;
    cout << "=====================" << endl;
    cout << "16 - encrypt text" << endl;
    cout << "17 - decrept text" << endl;
    cout << "=====================" << endl;
    cout << "18 - switch tabs" << endl;
    cout << "19 - see current tab." << endl;
    cout << "=====================" << endl;
    cout << "20 - exit program." << endl;
}

void appendText(const AppContext &context) {
    string text;
    cout << "Enter text to append: ";
    getline(cin, text);

    context.c_manager.executeCommand(new AppendTextCommand(*context.e_manager.tabs[context.e_manager.curr], text));
}

void addNewLine(const AppContext &context) {
    LineType type;
    char ch;
    std::cout << "Enter line type: ('t' - Text, 'c' - contact, 'x' - checkbox) ";
    cin >> ch;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    switch (ch) {
        case 't': {
            context.c_manager.executeCommand(new AddLineCommand(*context.e_manager.tabs[context.e_manager.curr], text));
            break;
        }
        case 'c': {
            string name, email;
            cout << "Enter name: ";
            getline(cin, name);
            cout << "Enter email: ";
            getline(cin, email);
            string input = std::format("Name: {}, Email: {}", name, email);

            context.c_manager.executeCommand(new AddLineCommand(*context.e_manager.tabs[context.e_manager.curr], contact));
            context.e_manager.tabs[context.e_manager.curr]->getLines().back()->load_data(input);
            break;
        }

        case 'x': {
            string text;
            char status;
            cout << "Enter text: ";
            getline(cin, text);
            cout << "Is checkbox done [y/n]: ";
            cin >> status;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::string input = std::format("[{}] {}", (status == 'y' ? "X" : " "), text);

            context.c_manager.executeCommand(new AddLineCommand(*context.e_manager.tabs[context.e_manager.curr], checkbox));
            context.e_manager.tabs[context.e_manager.curr]->getLines().back()->load_data(input);
            break;
        }
        default:
            cout << "Unrecognized line type." << endl;
            break;
    }
}

void saveFile(const AppContext &context) {
    string path;
    cout << "Enter file path for saving: ";
    cin >> path;
    writeBufferToFile(*context.e_manager.tabs[context.e_manager.curr], path);
}

void loadFile(const AppContext &context) {
    string path;
    cout << "Enter file path for loading: ";
    cin >> path;
    readFileToBuffer(*context.e_manager.tabs[context.e_manager.curr], path);
}

void printText(const AppContext &context) {
    context.e_manager.tabs[context.e_manager.curr]->printCursorPos();
    context.e_manager.tabs[context.e_manager.curr]->printLines();
}

void insertByLineAndIndex(const AppContext &context) {
    string text;
    cout << "Enter text to insert: ";
    getline(cin, text);

    context.c_manager.executeCommand(new InsertTextCommand(
        *context.e_manager.tabs[context.e_manager.curr],
        context.e_manager.tabs[context.e_manager.curr]->getCursorPos(),
        text)
        );
}

void searchText(const AppContext &context) {
    string text;
    cout << "Enter text to search: ";
    getline(cin, text);
    context.e_manager.tabs[context.e_manager.curr]->search(text);
}

void deleteText(const AppContext &context) {

    size_t length;

    cout << "Enter length: ";
    cin >> length;

    if (cin.fail()) {
        cerr << "Invalid input. Try again." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    context.c_manager.executeCommand(new DeleteTextCommand(
        *context.e_manager.tabs[context.e_manager.curr],
        context.e_manager.tabs[context.e_manager.curr]->getCursorPos(),
        length));
}

void undoCommand(const AppContext &context) {
    context.c_manager.undo();
}

void redoCommand(const AppContext &context) {
    context.c_manager.redo();
}

void cutText(const AppContext &context) {
    size_t length;

    cout << "Enter length: ";
    cin >> length;

    if (cin.fail()) {
        cerr << "Invalid input. Try again." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    const IndexTuple pos = context.e_manager.tabs[context.e_manager.curr]->getCursorPos();
    std::string text = context.e_manager.tabs[context.e_manager.curr]->getText(pos, length);

    context.e_manager.tabs[context.e_manager.curr]->setBufferText(text);
    context.c_manager.executeCommand(new CutTextCommand(*context.e_manager.tabs[context.e_manager.curr], pos, length));
}

void pasteText(const AppContext &context) {
    const IndexTuple pos = context.e_manager.tabs[context.e_manager.curr]->getCursorPos();
    context.c_manager.executeCommand(new PasteTextCommand(*context.e_manager.tabs[context.e_manager.curr], pos, context.e_manager.tabs[context.e_manager.curr]->getBufferText()));
}

void copyText(const AppContext &context) {
    size_t length;

    cout << "Enter length: ";
    cin >> length;

    if (cin.fail()) {
        cerr << "Invalid input. Try again." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    const IndexTuple pos = context.e_manager.tabs[context.e_manager.curr]->getCursorPos();
    context.e_manager.tabs[context.e_manager.curr]->copyText(pos, length);
}

void replaceText(const AppContext &context) {

    string text;
    cout << "Enter text to replace to: ";
    getline(cin, text);

    const IndexTuple pos = context.e_manager.tabs[context.e_manager.curr]->getCursorPos();

    context.c_manager.executeCommand(new ReplaceTextCommand(*context.e_manager.tabs[context.e_manager.curr], pos, text));
}

void setCursorPos(const AppContext &context) {

    IndexTuple pos;
    cout << "Enter line index and char index: ";
    cin >> pos.line_idx >> pos.char_idx;

    if (cin.fail()) {
        cerr << "Invalid input. Try again." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    context.e_manager.tabs[context.e_manager.curr]->setCursorPos(pos);
}

// Encryption & Decryption with DLL

void encryptText(const AppContext &context) {
    context.e_manager.tabs[context.e_manager.curr]->encryptText();
}

void decryptText(const AppContext &context) {
    context.e_manager.tabs[context.e_manager.curr]->decryptText();
}

// Tabs logic
void switchTabs(const AppContext &context) {
    size_t idx;

    cout << "Enter tab index: ";
    cin >> idx;

    if (cin.fail()) {
        cerr << "Invalid input. Try again." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    if (idx >= context.e_manager.tabs.size()) {
        TextEditor *e = new TextEditor();
        context.e_manager.tabs.push_back(e);
        size_t new_curr = context.e_manager.tabs.size() - 1;
        context.e_manager.curr = new_curr;
        cout << "New Tab: " << new_curr << endl;
    } else {
        context.e_manager.curr = idx;
        cout << "Switched to tab: " << idx << endl;
    }
}

void getTab(const AppContext &context) {
    cout << "You are in Tab: " << context.e_manager.curr << endl;
}

void exitProgram() {
    cout << "Ending program..." << endl;
    exit(101);
}