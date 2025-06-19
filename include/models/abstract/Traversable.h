//
// Created by Andrii Klykavka on 19.06.2025.
//

#ifndef ITRAVERSABLE_H
#define ITRAVERSABLE_H
#include <string>

class ITraversable {

public:
    explicit ITraversable() = default;
    virtual ~ITraversable() = default;

    virtual void append_text(const std::string &text) = 0;
    virtual void insert_text(size_t pos, const std::string &text) = 0;
    virtual void search(size_t heighPos, const std::string &text) const = 0;
    virtual void delete_text(size_t pos, size_t length) = 0;
    [[nodiscard]] virtual std::string get_text(size_t pos, size_t length) const = 0;
    virtual void cut_text(size_t pos, size_t length, std::string &buffer) = 0;
    virtual void copy_text(size_t pos, size_t length, std::string &buffer) const = 0;
    virtual void paste_text(size_t pos, const std::string &buffer) = 0;

    [[nodiscard]] virtual size_t get_length() const = 0;
    [[nodiscard]] virtual bool is_index_in_range(size_t pos) const = 0;
    virtual void free() = 0;
};

#endif //ITRAVERSABLE_H
