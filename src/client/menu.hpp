#ifndef MENU_HPP
#define MENU_HPP

#include "dialog_id.hpp"
#include <memory>
#include <string>
#include <vector>

namespace client
{
    using client::dialog_id;

    class menu
    {
    public:
        menu(std::string _title, std::string _message, std::vector<std::string> _variants, std::vector<size_t> _next, size_t _prev = 0, dialog_id _dialog = dialog_id::none) 
            : title(std::move(_title)), message(std::move(_message)), variants(_variants), next(_next), prev(_prev), dialog(_dialog) { }
        
        [[nodiscard]] const std::string& get_title() const { return title; }
        [[nodiscard]] const std::string& get_message() const { return message; }
        [[nodiscard]] const std::vector<std::string>& get_variants() const { return variants; }
        const std::vector<size_t>& get_next() const { return next; }
        size_t get_prev() const { return prev; }
        dialog_id get_dialog() const { return dialog; }
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