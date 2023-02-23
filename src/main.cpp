#include "client/menu_controller.hpp"
#include "core/core.hpp"

int main()
{
    std::unique_ptr<core::core> core_handle = std::make_unique<core::core>();
    client::menu_controller main_menu_controller(core_handle.get());
    main_menu_controller.program_loop();
    
    return 0;
}