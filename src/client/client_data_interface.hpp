#ifndef CLIENT_DATA_INTERFACE_HPP
#define CLIENT_DATA_INTERFACE_HPP

#include "../core/core.hpp"

namespace client
{
    class client_data_interface
    {
    public:
        explicit client_data_interface(core::core* handle) : core_handle(handle) { }

        auto get_employee_collection() -> employee::employee_collection *
        {
            return core_handle->get_hr_handle()->get_main_collection();
        }

    private:
        core::core* core_handle;
    };
}

#endif