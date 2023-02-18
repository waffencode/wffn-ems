#include "menu_controller.hpp"
#include <iostream>

namespace client
{
    void menu_controller::show(size_t menu_id)
    {
        if (menu_id == -1 || menu_id > main_pool.pool.size())
        {
            std::cout << "Error" << std::endl;
        }

        auto *selected_menu = main_pool.pool.at(menu_id).get();

        std::cout << selected_menu->title << std::endl << selected_menu->message << std::endl;

        for (size_t i = 0, j = selected_menu->variants.size(); i < j; ++i)
        {
            std::cout << "[" << i << "] " << selected_menu->variants.at(i) << std::endl;
        }

        get_action();
    }

    void menu_controller::get_action()
    {
        char c;
        std::cin >> c;
    }
}