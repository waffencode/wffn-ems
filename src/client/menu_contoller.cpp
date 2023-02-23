#include "menu_controller.hpp"
#include <iostream>
#include <algorithm>

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
            std::cout << "Error at menu_controller (menu_id > main_pool.pool.size())" << std::endl;
        }

        current_menu_id = menu_id;
        auto* selected_menu = main_pool.pool.at(menu_id).get();
        std::cout << selected_menu->get_title() << std::endl << selected_menu->get_message() << std::endl;
        size_t count = 0;
        
        if (selected_menu->get_dialog() != dialog_id::none)
        {
            main_dialog_pool.get()->call_dialog(selected_menu->get_dialog());
        }

        for (const auto& menu_action : selected_menu->get_variants())
        {
            std::cout << "[" << ++count << "] " << menu_action << std::endl;
        }

        std::cout << "[" << ++count << "] " << "Back" << std::endl;
        std::cout << "[" << ++count << "] " << "Exit" << std::endl;
    }

    menu_action menu_controller::get_action(menu* selected_menu) 
    {
        size_t action = menu_action::exit;
        std::cin >> action;
        auto& next_variants = selected_menu->get_next();

        if (action == next_variants.size() + 1)
        {
            current_menu_id = selected_menu->get_prev();
            return menu_action::prev_menu;
        }
        else if (action == next_variants.size() + 2)
        {
            return menu_action::exit;
        }
        else {
            current_menu_id = selected_menu->get_next().at(action - 1);
            return menu_action::next_menu;
        }

        return menu_action::exit;
    }
}