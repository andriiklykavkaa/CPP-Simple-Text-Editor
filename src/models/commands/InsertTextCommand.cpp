//
// Created by Andrii Klykavka on 27.05.2025.
//

#include "../../../include/models/commands/InsertTextCommand.h"
#include "../../../include/models/TextEditor.h"

InsertTextCommand::InsertTextCommand(TextEditor &editor, const IndexTuple pos, string &text) :
editor(editor), text(move(text)), pos(pos) {}

void InsertTextCommand::execute() {
    editor.insertText(pos, text);
    editor.moveCursorCharIdx(text.length(), true);
}

void InsertTextCommand::undo() {
    editor.deleteText(pos, text.length());
    editor.moveCursorCharIdx(text.length(), false);
}

