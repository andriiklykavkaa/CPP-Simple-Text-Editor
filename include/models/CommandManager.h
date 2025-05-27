//
// Created by Andrii Klykavka on 27.05.2025.
//

#ifndef COMMANDMANAGER_H
#define COMMANDMANAGER_H

#include "abstract/Command.h"

class CommandManager {
private:
    size_t size;
    size_t capacity;
    ICommand **undoStorage;
    size_t maxRedoSize;

public:
    explicit CommandManager(size_t capacity);
    ~CommandManager();

    void executeCommand(ICommand* command);
    void undo();
    void redo();
};

#endif //COMMANDMANAGER_H
