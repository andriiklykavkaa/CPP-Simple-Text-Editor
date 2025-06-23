//
// Created by Andrii Klykavka on 19.06.2025.
//

#ifndef CONTACTLINE_H
#define CONTACTLINE_H

#include "../abstract/Readable.h"

class ContactLine : public IReadable {
private:
    std::string text;
public:
    explicit ContactLine() = default;
    explicit ContactLine(std::string text) : text{std::move(text)} {};
    [[nodiscard]] std::string display() const override;
    void load_data(std::string &text) override;
    void set_data(std::string &name, std::string &email);
};


#endif //CONTACTLINE_H
