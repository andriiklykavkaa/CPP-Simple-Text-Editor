//
// Created by Andrii Klykavka on 27.05.2025.
//

#include "../../../include/models/commands/DeleteTextCommand.h"
#include "../../../include/models/TextEditor.h"

DeleteTextCommand::DeleteTextCommand(TextEditor &editor, size_t lineIdx, size_t charIdx, size_t length) :
editor(editor), lineIdx(lineIdx), charIdx(charIdx), length(length) {}

void DeleteTextCommand::execute() {
    deletedText = editor.getText(lineIdx, charIdx, length);
    editor.deleteText(lineIdx, charIdx, length);
    editor.moveCursorCharIdx(length, false);
}

void DeleteTextCommand::undo() {
    editor.insertText(lineIdx, charIdx, deletedText);
    editor.moveCursorCharIdx(deletedText.length(), true);
}
