#include "client/menu_controller.hpp"
#include "core/hr_system.hpp"
int main()
{
    core::hr_system hr_handle;
    client::menu_controller main_menu_controller;
    main_menu_controller.program_loop();
    
    return 0;
}