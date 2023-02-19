#ifndef MENU_HPP
#define MENU_HPP

#include <string>
#include <vector>
#include <memory>

namespace client
{
    class menu
    {
    public:
        menu(std::string _title, std::string _message, std::vector<std::string> _variants) : title(std::move(_title)), message(std::move(_message)), variants(std::move(_variants)) { }
        const std::string& get_title() const { return title; }
        const std::string& get_message() const { return message; }
        const std::vector<std::string>& get_variants() const { return variants; }

    private:
        std::string title;
        std::string message;
        std::vector<std::string> variants;
    };
}

#endif