//
// Created by Andrii Klykavka on 27.05.2025.
//

#ifndef APPCONTEXT_H
#define APPCONTEXT_H

#include "models/EditorManager.h"
#include "models/CommandManager.h"

struct AppContext {
    EditorManager &e_manager;
    CommandManager &c_manager;
};


#endif //APPCONTEXT_H