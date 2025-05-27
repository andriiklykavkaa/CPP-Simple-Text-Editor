//
// Created by Andrii Klykavka on 27.05.2025.
//

#ifndef FILE_INTERACTION_H
#define FILE_INTERACTION_H
#include "Buffer.h"

void writeBufferToFile(const Buffer &buffer, const string &path);
void readFileToBuffer(Buffer &buffer, const string &path);


#endif //FILE_INTERACTION_H
