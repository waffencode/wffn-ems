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
            create_menu("Main", "Select menu to continue", std::vector<std::string>{"Employees"});
        }

        void create_menu(std::string name, std::string message, std::vector<std::string> variants)
        {
            auto new_menu = std::make_unique<menu>(name, message, variants);
            pool.push_back(std::move(new_menu));
        } 
    };
}

#endif