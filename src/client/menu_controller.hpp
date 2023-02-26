#ifndef MENU_CONTROLLER_HPP
#define MENU_CONTROLLER_HPP

#include "dialog_pool.hpp"
#include "menu_pool.hpp"

namespace client
{
    enum menu_action
    {
        next_menu,
        prev_menu,
        show_dialog,
        exit
    };

    class menu_controller
    {
    public:
        explicit menu_controller(core::core* handle) : core_handle(handle) 
        { 
            main_dialog_pool = std::make_unique<dialog_pool>(core_handle); 
        }

        void program_loop();
        void show(size_t menu_id);
    private:
        size_t current_menu_id = 0;
        core::core* core_handle;
        std::unique_ptr<dialog_pool> main_dialog_pool;
        menu_pool main_pool;

        auto get_action(menu *selected_menu) -> menu_action;
    };
}

#endif