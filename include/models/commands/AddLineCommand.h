//
// Created by Andrii Klykavka on 27.05.2025.
//

#ifndef ADDLINECOMMAND_H
#define ADDLINECOMMAND_H

#include "../TextEditor.h"
#include "../abstract/Command.h"


class AddLineCommand: public ICommand {
private:
    TextEditor &editor;

public:
    explicit AddLineCommand(TextEditor &editor);
    void execute() override;
    void undo() override;
};

#endif //ADDLINECOMMAND_H
