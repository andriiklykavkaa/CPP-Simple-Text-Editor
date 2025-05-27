//
// Created by Andrii Klykavka on 27.05.2025.
//

#include <iostream>
#include "../../include/models/abstract/Command.h"
#include "../../include/models/CommandManager.h"

using namespace std;

CommandManager::CommandManager(size_t capacity) :
size(0), capacity(capacity), maxRedoSize(0) {
    undoStorage = new ICommand*[capacity];
    for (size_t i = 0; i < capacity; i++) {
        undoStorage[i] = nullptr;
    }
}

CommandManager::~CommandManager() {
    for (size_t i = 0; i < size; ++i) {
        delete undoStorage[i];
    }
    delete[] undoStorage;
}

void CommandManager::executeCommand(ICommand* command) {
    if (size == capacity) {
        delete undoStorage[0];
        for (size_t i = 1; i < capacity; ++i) {
            undoStorage[i - 1] = undoStorage[i];
        }
        --size;
    }
    undoStorage[size] = command;
    size++;
    maxRedoSize = size;

    command->execute();
}

void CommandManager::undo() {
    if (size == 0) {
        cout << "No commands to undo." << endl;
        return;
    }
    undoStorage[size-1]->undo();
    --size;
}

void CommandManager::redo() {
    if (size >= maxRedoSize) {
        cout << "No commands to redo." << endl;
        return;
    }
    undoStorage[size]->execute();
    ++size;
}