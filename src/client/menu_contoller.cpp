#include "menu_controller.hpp"
#include <iostream>

namespace client
{
    void menu_controller::program_loop()
    {
        while (current_menu_action != menu_action::exit)
        {
            show(current_menu_id);
            current_menu_action = get_action(main_pool.pool.at(current_menu_id).get());
        }
    }

    void menu_controller::show(const size_t menu_id) 
    {
        if (menu_id > main_pool.pool.size())
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

        std::cout << "[" << ++count << "] " << "Back" << std::endl;
        std::cout << "[" << ++count << "] " << "Exit" << std::endl;
    }

    menu_action menu_controller::get_action(menu* selected_menu) 
    {
        size_t action;
        std::cin >> action;
        auto& next_variants = selected_menu->next;
        menu_action selected_action;

        if (action == next_variants.size() + 1)
        {
            selected_action = menu_action::prev_menu;
            current_menu_id = selected_menu->prev;
        }
        else if (action == next_variants.size() + 2)
        {
            return menu_action::exit;
        }
        else if (std::find(next_variants.begin(), next_variants.end(), action) != next_variants.end())
        {
            selected_action = menu_action::next_menu;
            current_menu_id = selected_menu->next.at(action - 1);
        }
        else
        {
            std::cout << "Error" << std::endl;
            return menu_action::exit;
        }

        return selected_action;
    }
}