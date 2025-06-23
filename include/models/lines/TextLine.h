//
// Created by Andrii Klykavka on 19.06.2025.
//

#ifndef TEXTLINE_H
#define TEXTLINE_H
#include "../abstract/BaseLine.h"
#include "../abstract/Traversable.h"

class TextLine final : public BaseLine, public ITraversable {
private:
    std::string text;
public:
    explicit TextLine(std::string text) : text(std::move(text)) {};
    explicit TextLine() = default;
    ~TextLine() override = default;

    [[nodiscard]] std::string display() const override;
    void load_data(std::string &text) override;

    char *get_data() override;

    void append_text(const std::string &text) override;
    void insert_text(size_t pos, const std::string &text) override;
    void search(size_t heighPos, const std::string &text) const override;
    void delete_text(size_t pos, size_t length) override;
    [[nodiscard]] std::string get_text(size_t pos, size_t length) const override;
    void cut_text(size_t pos, size_t length, std::string &buffer) override;
    void copy_text(size_t pos, size_t length, std::string &buffer) const override;
    void paste_text(size_t pos, const std::string &buffer) override;

    [[nodiscard]] size_t get_length() const override;
    [[nodiscard]] bool is_index_in_range(size_t pos) const override;
    void free() override;

};

#endif //TEXTLINE_H

