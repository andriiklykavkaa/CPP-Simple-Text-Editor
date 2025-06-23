//
// Created by Andrii Klykavka on 27.05.2025.
//

#ifndef ADDLINECOMMAND_H
#define ADDLINECOMMAND_H

#include "../TextEditor.h"
#include "../../command_execution.h"
#include "../abstract/Command.h"


class AddLineCommand: public ICommand {
private:
    TextEditor &editor;
    LineType type;

public:
    explicit AddLineCommand(TextEditor &editor, LineType type);
    void execute() override;
    void undo() override;
};

#endif //ADDLINECOMMAND_H
