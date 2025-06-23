//
// Created by Andrii Klykavka on 27.05.2025.
//

#ifndef APPCONTEXT_H
#define APPCONTEXT_H

class TextEditor;
class CommandManager;

struct AppContext {
    TextEditor &editor;
    CommandManager &manager;
};


#endif //APPCONTEXT_H