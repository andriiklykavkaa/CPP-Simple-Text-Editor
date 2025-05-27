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
    size_t lineIdx;
    size_t charIdx;

public:
    CutTextCommand(TextEditor &editor, size_t lineIdx, size_t charIdx, string text);
    void execute() override;
    void undo() override;
};

#endif //CUTTEXTCOMMAND_H
