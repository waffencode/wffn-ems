#ifndef MENU_CONTROLLER_HPP
#define MENU_CONTROLLER_HPP

#include "menu_pool.hpp"

namespace client
{
    enum menu_action
    {
        next_menu,
        prev_menu,
        exit
    };

    class menu_controller
    {
    public:
        void program_loop();
        void show(const size_t menu_id);
    private:
        size_t current_menu_id = 0;
        menu_action current_menu_action;

        menu_pool main_pool;
        menu_action get_action(menu* selected_menu);
    };
}

#endif