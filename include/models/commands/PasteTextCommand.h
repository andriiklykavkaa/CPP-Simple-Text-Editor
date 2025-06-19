//
// Created by Andrii Klykavka on 27.05.2025.
//

#ifndef PASTETEXTCOMMAND_H
#define PASTETEXTCOMMAND_H

#include "../TextEditor.h"
#include "../abstract/Command.h"

class PasteTextCommand: public ICommand {
private:
    TextEditor &editor;
    IndexTuple pos;
    string text;

public:
    PasteTextCommand(TextEditor &editor, IndexTuple pos, string &text);
    void execute() override;
    void undo() override;
};


#endif //PASTETEXTCOMMAND_H
