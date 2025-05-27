cmake_minimum_required(VERSION 3.29)
project(TextEditorCPP)

set(CMAKE_CXX_STANDARD 20)

add_executable(TextEditorCPP src/main.cpp
        src/models/Buffer.cpp
        include/buffer.h
        src/commands.cpp
        include/commands.h
        src/file_interaction.cpp
        include/file_interaction.h
)
