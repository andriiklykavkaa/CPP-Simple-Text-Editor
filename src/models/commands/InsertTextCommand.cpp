//
// Created by Andrii Klykavka on 27.05.2025.
//

#include "../../../include/models/commands/InsertTextCommand.h"
#include "../../../include/models/TextEditor.h"

InsertTextCommand::InsertTextCommand(TextEditor &editor, size_t lineIdx, size_t charIdx, string text) :
editor(editor), lineIdx(lineIdx), charIdx(charIdx), text(move(text)) {}

void InsertTextCommand::execute() {
    editor.insertText(lineIdx, charIdx, text);
    editor.moveCursorCharIdx(text.length(), true);
}

void InsertTextCommand::undo() {
    editor.deleteText(lineIdx, charIdx, text.length());
    editor.moveCursorCharIdx(-text.length(), false);
}

