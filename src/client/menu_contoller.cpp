#include "menu_controller.hpp"
#include <iostream>

namespace client
{
    menu_controller::menu_controller(core::core* handle) : core_handle(handle) 
    { 
        main_dialog_pool = std::make_unique<dialog_pool>(core_handle); 
    }

    void menu_controller::program_loop()
    {
        do
        {
            show(current_menu_id);
        } while (get_action(main_pool.get_pool().at(current_menu_id).get()) != menu_action::exit);
    }

    void menu_controller::show(const size_t menu_id) 
    {
        if (menu_id > main_pool.get_pool().size())
        {
            std::cout << "Error at menu_controller (menu_id > main_pool.pool.size())" << std::endl;
        }

        current_menu_id = menu_id;
        auto* selected_menu = main_pool.get_pool().at(menu_id).get();
        std::cout << std::endl << "Menu: " << selected_menu->get_title() << std::endl << selected_menu->get_message() << std::endl;
        size_t count = 0;
        
        if (selected_menu->get_dialog() != dialog_id::none)
        {
            main_dialog_pool->call_dialog(selected_menu->get_dialog());
        }

        std::cout << std::endl;

        for (const auto& menu_action : selected_menu->get_variants())
        {
            std::cout << "[" << ++count << "] " << menu_action << std::endl;
        }

        std::cout 
            << "[" << ++count << "] " << "Back" << std::endl 
            << "[" << ++count << "] " << "Exit" << std::endl;
    }

    auto menu_controller::get_action(menu *selected_menu) -> menu_action
    {
        size_t action = menu_action::exit;
        std::cout << "> ";
        std::cin >> action;
        const auto& next_variants = selected_menu->get_next();

        if (action == next_variants.size() + 1)
        {
            current_menu_id = selected_menu->get_prev();
            return menu_action::prev_menu;
        }
        else if (action >= next_variants.size() + 2)
        {
            return menu_action::exit;
        }
        else {
            current_menu_id = selected_menu->get_next().at(action - 1);
            return menu_action::next_menu;
        }
    }
}