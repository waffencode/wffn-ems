#ifndef DIALOG_POOL_HPP
#define DIALOG_POOL_HPP

#include "dialog/add_employee_dialog.hpp"
#include "dialog/show_employee_dialog.hpp"
#include "dialog_id.hpp"
#include <memory>
#include <vector>

namespace client
{
    class dialog_pool
    {
    public:
        explicit dialog_pool(core::core* _handle) : core_handle(_handle) { }
        
        void call_dialog(dialog_id selected_dialog) 
        { 
            switch (selected_dialog)
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