//
// Created by Andrii Klykavka on 17.06.2025.
//

#ifndef LINE_H
#define LINE_H

#include <string>

class BaseLine {

public:
    virtual ~BaseLine() = default;

    [[nodiscard]] virtual std::string display() const = 0;
    virtual void load_data(std::string &text) = 0;
    virtual char *get_data() = 0;
};

#endif //LINE_H
