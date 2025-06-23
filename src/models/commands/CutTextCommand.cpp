//
// Created by Andrii Klykavka on 27.05.2025.
//

#include "../../../include/models/commands/CutTextCommand.h"
#include "../../../include/models/TextEditor.h"


CutTextCommand::CutTextCommand(TextEditor &editor, const IndexTuple pos, size_t length) :
editor(editor), pos(pos), length(length) {}

void CutTextCommand::execute() {
    cutted_text = editor.getText(pos, length);
    editor.deleteText(pos, cutted_text.length());
    // editor.moveCursorCharIdx(cutted_text.length(), false);
}

void CutTextCommand::undo() {
    editor.insertText(pos, cutted_text);
    // editor.moveCursorCharIdx(cutted_text.length(), true);
}