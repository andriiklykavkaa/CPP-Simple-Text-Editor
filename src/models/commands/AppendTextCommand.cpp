//
// Created by Andrii Klykavka on 27.05.2025.
//

#include "../../../include/models/commands/AppendTextCommand.h"
#include "../../../include/models/TextEditor.h"

AppendTextCommand::AppendTextCommand(TextEditor &editor, string text) :
editor(editor), text(std::move(text)) {
    if(ITraversable* l = dynamic_cast<ITraversable*>(editor.getLines().at(pos.line_idx))) {
        pos.line_idx = editor.getHeight() - 1;
        pos.char_idx = l->get_length();
    }
}

void AppendTextCommand::execute() {
    editor.appendText(text);
    editor.moveCursorCharIdx(text.length(), true);
}

void AppendTextCommand::undo() {
    editor.deleteText(pos, text.size());
    editor.moveCursorCharIdx(text.length(), false);
}