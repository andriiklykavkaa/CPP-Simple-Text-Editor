//
// Created by Andrii Klykavka on 27.05.2025.
//

#ifndef APPCONTEXT_H
#define APPCONTEXT_H

#include "TextEditor.h"
#include "CommandManager.h"

struct AppContext {
    TextEditor &editor;
    CommandManager &manager;
};


#endif //APPCONTEXT_H