//
// Created by Andrii Klykavka on 27.05.2025.
//

#ifndef COMMANDS_H
#define COMMANDS_H
#include "Buffer.h"

void showInstructions();
void appendText(const Buffer &buffer);
void addNewLine(Buffer &buffer);
void saveFile(const Buffer &buffer);
void loadFile(Buffer &buffer);
void printText(const Buffer &buffer);
void insertByLineAndIndex(const Buffer &buffer);
void searchText(const Buffer &buffer);
void deleteText(Buffer &buffer);
void exitProgram();

#endif //COMMANDS_H
