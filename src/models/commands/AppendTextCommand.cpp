//
// Created by Andrii Klykavka on 27.05.2025.
//

#include "../../../include/models/commands/AppendTextCommand.h"
#include "../../../include/models/TextEditor.h"

AppendTextCommand::AppendTextCommand(TextEditor &editor, string text) :
editor(editor), text(move(text)) {}

void AppendTextCommand::execute() {
        editor.appendText(text);
    }

void AppendTextCommand::undo() {
    const size_t bufHeight = editor.getHeight();
    const string *line = &editor.getLines()[bufHeight-1];
    editor.deleteText(bufHeight-1, line->length() - text.size(), text.size());
}