//
// Created by Andrii Klykavka on 27.05.2025.
//

#ifndef CUTTEXTCOMMAND_H
#define CUTTEXTCOMMAND_H

#include "../TextEditor.h"
#include "../abstract/Command.h"

class CutTextCommand: public ICommand {
private:
    TextEditor &editor;
    string text;
    IndexTuple pos;

public:
    CutTextCommand(TextEditor &editor, IndexTuple pos, string text);
    void execute() override;
    void undo() override;
};

#endif //CUTTEXTCOMMAND_H
