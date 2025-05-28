//
// Created by Andrii Klykavka on 28.05.2025.
//

#ifndef REPLACECOMMAND_H
#define REPLACECOMMAND_H


#include "../TextEditor.h"
#include "../abstract/Command.h"

class ReplaceTextCommand: public ICommand {
private:
    TextEditor &editor;
    string insertedText;
    string deletedText;
    size_t lineIdx;
    size_t charIdx;

public:
    ReplaceTextCommand(TextEditor &editor, size_t lineIdx, size_t charIdx, string text);
    void execute() override;
    void undo() override;
};

#endif //REPLACECOMMAND_H
