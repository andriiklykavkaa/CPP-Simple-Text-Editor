//
// Created by Andrii Klykavka on 27.05.2025.
//

#include "../../../include/models/commands/AddLineCommand.h"
#include "../../../include/models/TextEditor.h"

AddLineCommand::AddLineCommand(TextEditor &editor) :
editor(editor) {}

void AddLineCommand::execute() {
    editor.addLine();
}

void AddLineCommand::undo() {
    editor.deleteLine(editor.getHeight()-1);
}