//
// Created by Andrii Klykavka on 19.06.2025.
//

#ifndef CONTACTLINE_H
#define CONTACTLINE_H

#include "../abstract/Line.h"

class ContactLine : public ILine<std::tuple<std::string, std::string>> {
private:
    std::string name;
    std::string email;
public:
    explicit ContactLine(std::string name, std::string email) : name{move(name)}, email{move(email)} {};
    std::tuple<std::string, std::string> get_data() override;
    void set_data(std::tuple<std::string, std::string> contact_info) override;
    std::string to_string() override;
};


#endif //CONTACTLINE_H
