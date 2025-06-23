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
    IndexTuple pos;
    string insertedText;
    string deletedText;

public:
    ReplaceTextCommand(TextEditor &editor, IndexTuple pos, string text);
    void execute() override;
    void undo() override;
};

#endif //REPLACECOMMAND_H
