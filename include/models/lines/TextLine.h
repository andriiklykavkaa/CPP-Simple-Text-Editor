//
// Created by Andrii Klykavka on 19.06.2025.
//

#ifndef TEXTLINE_H
#define TEXTLINE_H
#include "../abstract/Line.h"

class TextLine : public ILine<std::string> {
private:
    std::string text;
public:
    explicit TextLine(std::string text) : text(move(text)) {};
    std::string get_data() override;
    void set_data(std::string data) override;
    std::string to_string() override;
};

#endif //TEXTLINE_H

