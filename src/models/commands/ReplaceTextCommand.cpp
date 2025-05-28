//
// Created by Andrii Klykavka on 28.05.2025.
//


// ReplaceTextCommand

#include "../../../include/models/commands/ReplaceTextCommand.h"
#include "../../../include/models/TextEditor.h"

ReplaceTextCommand::ReplaceTextCommand(TextEditor &editor, size_t lineIdx, size_t charIdx, string text) :
editor(editor), lineIdx(lineIdx), charIdx(charIdx), insertedText(move(text)) {}

void ReplaceTextCommand::execute() {
    deletedText = editor.getText(lineIdx, charIdx, insertedText.length());
    editor.deleteText(lineIdx, charIdx, insertedText.length());
    editor.insertText(lineIdx, charIdx, insertedText);
}

void ReplaceTextCommand::undo() {
    editor.deleteText(lineIdx, charIdx, deletedText.length());
    editor.insertText(lineIdx, charIdx, deletedText);
}