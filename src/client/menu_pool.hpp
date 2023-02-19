#ifndef MENU_POOL_H
#define MENU_POOL_H

#include "menu.hpp"
#include <vector>
#include <string>
#include <memory>

namespace client 
{
    class menu_pool
    {
    public:
        std::vector<std::unique_ptr<menu>> pool;

        menu_pool()
        {
            create_menu("Main", "Select menu to continue", std::vector<std::string>{{"Employees"}}, std::vector<size_t>{1}, 0);
            create_menu("Employees", "Select action to continue", std::vector<std::string>{{"Show all", "Add", "Remove"}}, std::vector<size_t>{2, 3, 4}, 0);
        }

        void create_menu(const std::string& name, const std::string& message, const std::vector<std::string>& variants)
        {
            auto new_menu = std::make_unique<menu>(name, message, variants);
            pool.push_back(std::move(new_menu));
        }

        void create_menu(const std::string& name, const std::string& message, const std::vector<std::string>& variants, const std::vector<size_t>& next, const size_t prev)
        {
            auto new_menu = std::make_unique<menu>(name, message, variants, next, prev);
            pool.push_back(std::move(new_menu));
        }  
    };
}

#endif