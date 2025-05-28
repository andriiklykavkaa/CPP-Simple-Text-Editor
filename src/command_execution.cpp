//
// Created by Andrii Klykavka on 27.05.2025.
//

#include <iostream>

#include "../include/command_execution.h"
#include "../include/file_interaction.h"
#include "../include/models/TextEditor.h"
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
    cout << "1 - append text." << endl;
    cout << "2 - add new line." << endl;
    cout << "3 - save to file." << endl;
    cout << "4 - load from file." << endl;
    cout << "5 - print text." << endl;
    cout << "6 - insert in text by line and index." << endl;
    cout << "7 - search in text." << endl;
    cout << "8 - delete in text." << endl;
    cout << "9 - undo." << endl;
    cout << "10 - redo." << endl;
    cout << "11 - cut text." << endl;
    cout << "12 - paste text." << endl;
    cout << "13 - copy text." << endl;
    cout << "14 - replace." << endl;
    cout << "15 - set cursor position." << endl;
    cout << "16 - exit program." << endl;
}

void appendText(const AppContext &context) {
    string text;
    cout << "Enter text to append: ";
    getline(cin, text);

    context.manager.executeCommand(new AppendTextCommand(context.editor, text));
}

void addNewLine(const AppContext &context) {
    context.manager.executeCommand(new AddLineCommand(context.editor));
}

void saveFile(const AppContext &context) {
    string path;
    cout << "Enter file path for saving: ";
    cin >> path;
    writeBufferToFile(context.editor, path);
}

void loadFile(const AppContext &context) {
    string path;
    cout << "Enter file path for loading: ";
    cin >> path;
    readFileToBuffer(context.editor, path);
}

void printText(const AppContext &context) {
    context.editor.printCursorPos();
    context.editor.printLines();
}

void insertByLineAndIndex(const AppContext &context) {
    string text;
    cout << "Enter text to insert: ";
    getline(cin, text);

    context.manager.executeCommand(new InsertTextCommand(
        context.editor,
        context.editor.getCursorLineIdx(),
        context.editor.getCursorCharIdx(),
        text)
        );
}

void searchText(const AppContext &context) {
    string text;
    cout << "Enter text to search: ";
    getline(cin, text);
    context.editor.search(text);
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
    context.manager.executeCommand(new DeleteTextCommand(
        context.editor,
        context.editor.getCursorLineIdx(),
        context.editor.getCursorCharIdx(),
        length));
}

void undoCommand(const AppContext &context) {
    context.manager.undo();
}

void redoCommand(const AppContext &context) {
    context.manager.redo();
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

    const size_t lineIdx = context.editor.getCursorLineIdx();
    const size_t charIdx = context.editor.getCursorCharIdx();
    const string text = context.editor.getText(lineIdx, charIdx, length);

    context.editor.setBufferText(text);
    context.manager.executeCommand(new CutTextCommand(context.editor, lineIdx, charIdx, text));
}

void pasteText(const AppContext &context) {
    const size_t lineIdx = context.editor.getCursorLineIdx();
    const size_t charIdx = context.editor.getCursorCharIdx();
    context.manager.executeCommand(new PasteTextCommand(context.editor, lineIdx, charIdx, context.editor.getBufferText()));
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

    const size_t lineIdx = context.editor.getCursorLineIdx();
    const size_t charIdx = context.editor.getCursorCharIdx();
    context.editor.copyText(lineIdx, charIdx, length);
}

void replaceText(const AppContext &context) {

    string text;
    cout << "Enter text to replace to: ";
    getline(cin, text);

    const size_t lineIdx = context.editor.getCursorLineIdx();
    const size_t charIdx = context.editor.getCursorCharIdx();

    context.manager.executeCommand(new ReplaceTextCommand(context.editor, lineIdx, charIdx, text));
}

void setCursorPos(const AppContext &context) {
    size_t lineIdx;
    size_t charIdx;

    cout << "Enter line index and char index: ";
    cin >> lineIdx >> charIdx;

    if (cin.fail()) {
        cerr << "Invalid input. Try again." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    context.editor.setCursorPos(lineIdx, charIdx);
}


void exitProgram() {
    cout << "Ending program..." << endl;
    exit(101);
}