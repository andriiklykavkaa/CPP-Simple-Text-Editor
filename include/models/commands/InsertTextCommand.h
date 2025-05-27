//
// Created by Andrii Klykavka on 27.05.2025.
//

#ifndef INSERTTEXTCOMMAND_H
#define INSERTTEXTCOMMAND_H

#include "../TextEditor.h"
#include "../abstract/Command.h"

class InsertTextCommand: public ICommand {
private:
    TextEditor &editor;
    string text;
    size_t lineIdx;
    size_t charIdx;

public:
    InsertTextCommand(TextEditor &editor, size_t lineIdx, size_t charIdx, string text);

    void execute() override;
    void undo() override;
};

#endif //INSERTTEXTCOMMAND_H
