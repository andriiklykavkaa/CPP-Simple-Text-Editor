//
// Created by Andrii Klykavka on 27.05.2025.
//

#include "../../../include/models/commands/DeleteTextCommand.h"
#include "../../../include/models/TextEditor.h"

DeleteTextCommand::DeleteTextCommand(TextEditor &editor, IndexTuple pos, size_t length) :
editor(editor), pos(pos), length(length) {}

void DeleteTextCommand::execute() {
    deletedText = editor.getText(pos, length);
    editor.deleteText(pos, length);
    editor.moveCursorCharIdx(length, false);
}

void DeleteTextCommand::undo() {
    editor.insertText(pos, deletedText);
    editor.moveCursorCharIdx(deletedText.length(), true);
}
