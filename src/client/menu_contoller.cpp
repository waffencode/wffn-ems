#include "menu_controller.hpp"
#include <iostream>

namespace client
{
    void menu_controller::show(const size_t menu_id) 
    {
        if (menu_id == -1 || menu_id > main_pool.pool.size())
        {
            std::cout << "Error" << std::endl;
        }

        current_menu_id = menu_id;
        auto* selected_menu = main_pool.pool.at(menu_id).get();
        std::cout << selected_menu->get_title() << std::endl << selected_menu->get_message() << std::endl;
        size_t count = 0;
        
        for (const auto& menu_action : selected_menu->get_variants())
        {
            std::cout << "[" << ++count << "] " << menu_action << std::endl;
        }

        std::cout << "[" << ++count << "] " << "Exit" << std::endl;

        get_action(selected_menu);
    }

    void menu_controller::get_action(menu* selected_menu) 
    {
        size_t action;
        std::cin >> action;

        auto& next_variants = selected_menu->next;

        if (action == next_variants.size() + 1)
        {
            show(selected_menu->prev);
        }
        else if (std::find(next_variants.begin(), next_variants.end(), action) != next_variants.end())
        {
            show(selected_menu->next.at(action));
        }
        else
        {
            std::cout << "Error" << std::endl;
        }
    }
}