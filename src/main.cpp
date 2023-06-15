#include "client/menu_controller.hpp"
#include "core/core.hpp"

auto main() -> int
{
    core::core core_handle;
    client::menu_controller main_menu_controller(&core_handle);
    main_menu_controller.program_loop();

    return 0;
}