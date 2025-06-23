//
// Created by Andrii Klykavka on 23.06.2025.
//

#ifndef EDITORMANAGER_H
#define EDITORMANAGER_H

#include "models/TextEditor.h"

class  EditorManager {
public:
    std::vector<TextEditor*> tabs;
    size_t curr = 0;
};

#endif //EDITORMANAGER_H
