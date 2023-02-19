#include "menu_controller.hpp"
#include <iostream>

namespace client
{
    void menu_controller::show(size_t menu_id) const 
    {
        if (menu_id == -1 || menu_id > main_pool.pool.size())
        {
            std::cout << "Error" << std::endl;
        }

        auto* selected_menu = main_pool.pool.at(menu_id).get();
        std::cout << selected_menu->get_title() << std::endl << selected_menu->get_message() << std::endl;
        size_t count = 0;
        
        for (auto& menu_action : selected_menu->get_variants())
        {
            std::cout << "[" << ++count << "] " << menu_action << std::endl;
        }

        get_action();
    }

    void menu_controller::get_action() const 
    {
        char c;
        std::cin >> c;
    }
}