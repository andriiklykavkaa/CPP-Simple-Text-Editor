//
// Created by Andrii Klykavka on 27.05.2025.
//

#include "../../../include/models/commands/CutTextCommand.h"
#include "../../../include/models/TextEditor.h"


CutTextCommand::CutTextCommand(TextEditor &editor, IndexTuple pos, string text) :
editor(editor), pos(pos), text(move(text)) {}

void CutTextCommand::execute() {
    editor.deleteText(pos, text.length());
    editor.moveCursorCharIdx(text.length(), false);
}

void CutTextCommand::undo() {
    editor.insertText(pos, text);
    editor.moveCursorCharIdx(text.length(), true);
}