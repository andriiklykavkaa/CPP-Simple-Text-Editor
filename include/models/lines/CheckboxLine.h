//
// Created by Andrii Klykavka on 19.06.2025.
//

#ifndef CHECKBOXLINE_H
#define CHECKBOXLINE_H

#include "../abstract/BaseLine.h"

class CheckboxLine : public BaseLine {
private:
    std::string text;
public:
    explicit CheckboxLine() = default;
    explicit CheckboxLine(std::string text) : text{std::move(text)} {};
    [[nodiscard]] std::string display() const override;
    void load_data(std::string &text) override;

    char *get_data() override;
};

#endif //CHECKBOXLINE_H
