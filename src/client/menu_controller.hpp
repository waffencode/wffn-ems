#ifndef MENU_CONTROLLER_HPP
#define MENU_CONTROLLER_HPP

#include "dialog_pool.hpp"
#include "client_data_interface.hpp"
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
        explicit menu_controller(core::core* handle);
        void program_loop();
        void show(size_t menu_id);

    private:
        size_t current_menu_id = 0;
        core::core* core_handle;
        std::unique_ptr<dialog_pool> main_dialog_pool;
        std::unique_ptr<client_data_interface> data_interface;
        menu_pool main_pool;

        auto get_action(menu *selected_menu) -> menu_action;
    };
}

#endif