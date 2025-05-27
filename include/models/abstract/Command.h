//
// Created by Andrii Klykavka on 27.05.2025.
//

#ifndef COMMAND_H
#define COMMAND_H
#include <string>

using namespace std;

class ICommand {
public:
    virtual void execute() = 0;
    virtual void undo() = 0;
    virtual ~ICommand() = default;
};

#endif //COMMAND_H
