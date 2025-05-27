//
// Created by Andrii Klykavka on 27.05.2025.
//

#ifndef COMMANDS_H
#define COMMANDS_H
#include "models/AppContext.h"

void showInstructions();
void appendText(const AppContext &context);
void addNewLine(const AppContext &context);
void saveFile(const AppContext &context);
void loadFile(const AppContext &context);
void printText(const AppContext &context);
void insertByLineAndIndex(const AppContext &context);
void searchText(const AppContext &context);
void deleteText(const AppContext &context);
void undoCommand(const AppContext &context);
void redoCommand(const AppContext &context);
void cutText(const AppContext &context);
void pasteText(const AppContext &context);
void copyText(const AppContext &context);
void exitProgram();

#endif //COMMANDS_H