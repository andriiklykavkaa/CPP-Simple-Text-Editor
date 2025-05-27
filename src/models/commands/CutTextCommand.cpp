//
// Created by Andrii Klykavka on 27.05.2025.
//

#include "../../../include/models/commands/CutTextCommand.h"
#include "../../../include/models/TextEditor.h"


CutTextCommand::CutTextCommand(TextEditor &editor, size_t lineIdx, size_t charIdx, string text) :
editor(editor), lineIdx(lineIdx), charIdx(charIdx), text(move(text)) {}

void CutTextCommand::execute() {
    editor.deleteText(lineIdx, charIdx, text.length());
}

void CutTextCommand::undo() {
    editor.insertText(lineIdx, charIdx, text);
}