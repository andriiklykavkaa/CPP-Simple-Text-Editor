//
// Created by Andrii Klykavka on 27.05.2025.
//

#ifndef FILE_INTERACTION_H
#define FILE_INTERACTION_H
#include "models/TextEditor.h"

void writeBufferToFile(const TextEditor &editor, const string &path);
void readFileToBuffer(TextEditor &editor, const string &path);


#endif //FILE_INTERACTION_H
