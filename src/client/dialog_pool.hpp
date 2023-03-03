#ifndef DIALOG_POOL_HPP
#define DIALOG_POOL_HPP

#include "dialog/add_employee_dialog.hpp"
#include "dialog/show_employee_dialog.hpp"
#include "dialog/employee_profile_dialog.hpp"
#include "dialog_id.hpp"
#include "dialog.hpp"

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
            case dialog_id::employee_profile: { employee_profile(); break; }
            }
        }

        void add_employee() { dialog_functions::add_employee_dialog(core_handle->get_hr_handle()->get_main_collection()); }
        void show_employee() { dialog_functions::show_employee_dialog(core_handle->get_hr_handle()->get_main_collection()); }
        void employee_profile() { dialog_functions::employee_profile_dialog(core_handle->get_hr_handle()->get_main_collection()); }
    private:
        core::core* core_handle;
        std::vector<std::unique_ptr<dialog>> pool;
    };
}

#endif