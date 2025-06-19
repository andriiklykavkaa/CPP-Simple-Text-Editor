//
// Created by Andrii Klykavka on 28.05.2025.
//


// ReplaceTextCommand

#include "../../../include/models/commands/ReplaceTextCommand.h"
#include "../../../include/models/TextEditor.h"

ReplaceTextCommand::ReplaceTextCommand(TextEditor &editor, IndexTuple pos, string text) :
editor(editor), pos(pos), insertedText(std::move(text)) {}

void ReplaceTextCommand::execute() {
    deletedText = editor.getText(pos, insertedText.length());
    editor.deleteText(pos, insertedText.length());
    editor.insertText(pos, insertedText);
}

void ReplaceTextCommand::undo() {
    editor.deleteText(pos, deletedText.length());
    editor.insertText(pos, deletedText);
}