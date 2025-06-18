//
// Created by Andrii Klykavka on 19.06.2025.
//

#ifndef CHECKBOXLINE_H
#define CHECKBOXLINE_H

#include "../abstract/Line.h"

class CheckboxLine : public ILine<std::tuple<std::string, bool>> {
private:
    std::string text;
    bool isDone;
public:
    explicit CheckboxLine(std::string text) : text{move(text)}, isDone{false} {};
    std::tuple<std::string, bool> get_data() override;
    void set_data(std::tuple<std::string, bool> checkbox_info) override;
    std::string to_string() override;
};

#endif //CHECKBOXLINE_H
