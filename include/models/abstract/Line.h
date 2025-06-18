//
// Created by Andrii Klykavka on 17.06.2025.
//

#ifndef LINE_H
#define LINE_H

#include <string>

template <typename T>
class ILine {

public:
    explicit ILine() = default;
    virtual ~ILine() = default;

    virtual T get_data() = 0;
    virtual void set_data(T data) = 0;
    virtual std::string to_string() = 0;
};

#endif //LINE_H
