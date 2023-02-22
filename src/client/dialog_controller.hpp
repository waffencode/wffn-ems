#ifndef DIALOG_CONTROLLER_HPP
#define DIALOG_CONTROLLER_HPP

#include "dialog_pool.hpp"

namespace client
{
    class dialog_controller
    {
    public:
        void show(const size_t dialog_id);
    private:
        size_t current_menu_id = 0;
        dialog_pool main_pool;
    };
}

#endif