#ifndef CLIENT_DATA_INTERFACE_HPP
#define CLIENT_DATA_INTERFACE_HPP

#include "../core/core.hpp"

namespace client
{
    class client_data_interface
    {
    public:
        explicit client_data_interface(core::core* handle) : core_handle(handle) { }

        void add_employee()
        {

        }

        void show_employee()
        {

        }

    private:
        core::core* core_handle;
    };
}

#endif