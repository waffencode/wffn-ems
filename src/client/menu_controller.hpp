#ifndef MENU_CONTROLLER_HPP
#define MENU_CONTROLLER_HPP

#include "menu_pool.hpp"

namespace client
{
    class menu_controller
    {
    public:
        void show(size_t menu_id);
    private:
        menu_pool main_pool;
        void get_action();
    };
}

#endif