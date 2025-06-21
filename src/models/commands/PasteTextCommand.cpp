//
// Created by Andrii Klykavka on 27.05.2025.
//

#include "../../../include/models/commands/PasteTextCommand.h"
#include "../../../include/models/TextEditor.h"


PasteTextCommand::PasteTextCommand(TextEditor &editor, const IndexTuple pos, const std::string &text) :
editor(editor), pos(pos) {
    this->text = text;
}

void PasteTextCommand::execute() {
    editor.insertText(pos, text);
    editor.moveCursorCharIdx(text.length(), true);
}

void PasteTextCommand::undo() {
    editor.deleteText(pos, text.length());
    editor.moveCursorCharIdx(text.length(), false);
}