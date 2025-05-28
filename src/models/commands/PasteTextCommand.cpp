//
// Created by Andrii Klykavka on 27.05.2025.
//

#include "../../../include/models/commands/PasteTextCommand.h"
#include "../../../include/models/TextEditor.h"


PasteTextCommand::PasteTextCommand(TextEditor &editor, size_t lineIdx, size_t charIdx, string text) :
editor(editor), lineIdx(lineIdx), charIdx(charIdx), text(move(text)) {}

void PasteTextCommand::execute() {
    editor.insertText(lineIdx, charIdx, text);
    editor.moveCursorCharIdx(text.length(), true);
}

void PasteTextCommand::undo() {
    editor.deleteText(lineIdx, charIdx, text.length());
    editor.moveCursorCharIdx(text.length(), false);
}