//
// Created by Andrii Klykavka on 19.06.2025.
//

#ifndef CONTACTLINE_H
#define CONTACTLINE_H

#include "../abstract/BaseLine.h"

class ContactLine : public BaseLine {
private:
    std::string text;
public:
    explicit ContactLine() = default;
    explicit ContactLine(std::string text) : text{std::move(text)} {};
    [[nodiscard]] std::string display() const override;
    void load_data(std::string &text) override;

    char *get_data() override;
};


#endif //CONTACTLINE_H
