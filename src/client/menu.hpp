#ifndef MENU_HPP
#define MENU_HPP

#include "dialog_id.hpp"
#include <memory>
#include <string>
#include <vector>

namespace client
{
    class menu
    {
    public:
        menu(std::string _title, std::string _message, std::vector<std::string> _variants, std::vector<size_t> _next, size_t _prev = 0, dialog_id _dialog = dialog_id::none) 
            : title(std::move(_title)), message(std::move(_message)), variants(std::move(_variants)), next(std::move(_next)), prev(_prev), dialog(_dialog) { }

        [[nodiscard]] auto get_title() const -> const std::string & { return title; }
        [[nodiscard]] auto get_message() const -> const std::string & { return message; }
        [[nodiscard]] auto get_variants() const -> const std::vector<std::string> & { return variants; }
        [[nodiscard]] auto get_next() const -> const std::vector<size_t> & { return next; }
        [[nodiscard]] auto get_prev() const -> size_t { return prev; }
        [[nodiscard]] auto get_dialog() const -> dialog_id { return dialog; }

    private:
        std::string title;
        std::string message;
        std::vector<std::string> variants;
        std::vector<size_t> next;
        size_t prev = 0;
        dialog_id dialog = dialog_id::none;
    };
}

#endif