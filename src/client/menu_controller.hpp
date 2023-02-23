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
        menu_controller(core::core* handle) : core_handle(handle) 
        { 
            main_dialog_pool = std::make_unique<dialog_pool>(core_handle); 
        }

        void program_loop();
        void show(const size_t menu_id);
    private:
        size_t current_menu_id = 0;
        menu_action current_menu_action;
        core::core* core_handle;
        std::unique_ptr<dialog_pool> main_dialog_pool;
        menu_pool main_pool;
        
        menu_action get_action(menu* selected_menu);
    };
}

#endif