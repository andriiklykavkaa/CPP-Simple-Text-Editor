cmake_minimum_required(VERSION 3.29)
project(TextEditorCPP)

set(CMAKE_CXX_STANDARD 20)

include_directories(${PROJECT_SOURCE_DIR}/include)

file(GLOB_RECURSE SOURCES src/*.cpp)

add_executable(TextEditorCPP src/main.cpp
        src/models/TextEditor.cpp
        include/models/TextEditor.h
        src/command_execution.cpp
        include/command_execution.h
        src/file_interaction.cpp
        include/file_interaction.h
        include/models/abstract/Command.h
        src/models/commands/AppendTextCommand.cpp
        include/models/commands/AppendTextCommand.h
        include/models/commands/AddLineCommand.h
        src/models/commands/AddLineCommand.cpp
        src/models/commands/InsertTextCommand.cpp
        include/models/commands/InsertTextCommand.h
        include/models/commands/DeleteTextCommand.h
        src/models/commands/DeleteTextCommand.cpp
        src/models/CommandManager.cpp
        include/models/CommandManager.h
        include/models/AppContext.h
        include/models/commands/CutTextCommand.h
        include/models/commands/PasteTextCommand.h
        src/models/commands/CutTextCommand.cpp
        src/models/commands/PasteTextCommand.cpp
        include/models/commands/ReplaceTextCommand.h
        src/models/commands/ReplaceTextCommand.cpp
        include/models/abstract/BaseLine.h
        src/models/lines/TextLine.cpp
        include/models/lines/TextLine.h
        src/models/lines/ContactLine.cpp
        include/models/lines/ContactLine.h
        include/models/lines/CheckboxLine.h
        src/models/lines/CheckboxLine.cpp
        include/models/utility/IndexTuple.h
        include/models/abstract/Traversable.h
        include/models/EditorManager.h
        include/models/utility/LineType.h
)

add_custom_command(TARGET TextEditorCPP POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${CMAKE_SOURCE_DIR}/dlls/libcryption.so
        $<TARGET_FILE_DIR:TextEditorCPP>)