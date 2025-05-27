//
// Created by Andrii Klykavka on 27.05.2025.
//

#ifndef APPENDTEXTCOMMAND_H
#define APPENDTEXTCOMMAND_H

#include "../TextEditor.h"
#include "../abstract/Command.h"

class AppendTextCommand: public ICommand {
private:
    TextEditor &editor;
    string text;

public:
    AppendTextCommand(TextEditor &editor, string text);
    void execute() override;
    void undo() override;
};

#endif //APPENDTEXTCOMMAND_H
