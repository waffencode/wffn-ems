#ifndef DIALOG_H
#define DIALOG_H

#include "dialog/add_employee_dialog.hpp"
#include "dialog/show_employee_dialog.hpp"
#include "../core/core.hpp"
#include <memory>
#include <vector>

namespace client
{
    enum dialog_id
    {
        none,
        employee_add,
        employee_show
    };

    class dialog_pool
    {
    public:
        dialog_pool(core::core* _handle) : core_handle(_handle) { }
        
        void call_dialog(dialog_id id) 
        { 
            switch (id)
            {
            case dialog_id::none: { break; }
            case dialog_id::employee_add: { add_employee(); break; }
            case dialog_id::employee_show: { show_employee(); break; }
            }
        }

        void add_employee() { dialog::add_employee_dialog(core_handle->get_hr_handle()->get_main_collection()); }
        void show_employee() { dialog::show_employee_dialog(core_handle->get_hr_handle()->get_main_collection()); }
    private:
        core::core* core_handle;
    };
}

#endif