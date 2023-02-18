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
        std::string title;
        std::string message;
        std::vector<std::string> variants;

        menu(std::string _title, std::string _message, std::vector<std::string> _variants) : title(_title), message(_message), variants(_variants) { }
    };
}

#endif