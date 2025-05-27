//
// Created by Andrii Klykavka on 27.05.2025.
//

#ifndef DELETETEXTCOMMAND_H
#define DELETETEXTCOMMAND_H

#include "../TextEditor.h"
#include "../abstract/Command.h"

class DeleteTextCommand: public ICommand {
private:
    TextEditor &editor;
    size_t lineIdx;
    size_t charIdx;
    size_t length;
    string deletedText;

public:
    explicit DeleteTextCommand(TextEditor &editor, size_t lineIdx, size_t charIdx, size_t length);
    void execute() override;
    void undo() override;
};

#endif //DELETETEXTCOMMAND_H
