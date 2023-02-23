#ifndef MENU_HPP
#define MENU_HPP

#include <memory>
#include <string>
#include <vector>

namespace client
{
    class menu
    {
    public:
        menu(std::string _title, std::string _message, std::vector<std::string> _variants) 
            : title(std::move(_title)), message(std::move(_message)), variants(std::move(_variants)) { }
        menu(std::string _title, std::string _message, std::vector<std::string> _variants, std::vector<size_t> _next, size_t _prev) 
            : title(std::move(_title)), message(std::move(_message)), variants(_variants), next(_next), prev(_prev) { }
        menu(std::string _title, std::string _message, std::vector<std::string> _variants, std::vector<size_t> _next, size_t _prev, dialog_id _dialog) 
            : title(std::move(_title)), message(std::move(_message)), variants(_variants), next(_next), prev(_prev), dialog(_dialog) { }
        
        [[nodiscard]] const std::string& get_title() const { return title; }
        [[nodiscard]] const std::string& get_message() const { return message; }
        [[nodiscard]] const std::vector<std::string>& get_variants() const { return variants; }

        std::vector<size_t> next;
        size_t prev;
        dialog_id dialog = dialog_id::none;
    private:
        std::string title;
        std::string message;
        std::vector<std::string> variants;
    };
}

#endif