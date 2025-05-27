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
    string text;
    size_t lineIdx;
    size_t charIdx;

public:
    PasteTextCommand(TextEditor &editor, size_t lineIdx, size_t charIdx, string text);
    void execute() override;
    void undo() override;
};


#endif //PASTETEXTCOMMAND_H
