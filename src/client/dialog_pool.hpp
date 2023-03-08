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
        explicit dialog_pool(core::core* _handle) : core_handle(_handle) 
        { 
            create_dialog<employee::employee_collection*>(dialog_id::employee_add, dialog_functions::add_employee_dialog);
            create_dialog<employee::employee_collection*>(dialog_id::employee_show, dialog_functions::show_employee_dialog);
            create_dialog<employee::employee_collection*>(dialog_id::employee_profile, dialog_functions::employee_profile_dialog);
        }
        
        void call_dialog(dialog_id selected_dialog) 
        {
            for (const auto& dialog_unique_ptr: pool)
            {
                auto *const ptr = dialog_unique_ptr.get();

                if (ptr->id == selected_dialog)
                {
                    ptr->execute(core_handle->get_hr_handle()->get_main_collection());
                }
            } 
        }

    private:
        core::core* core_handle;
        std::vector<std::unique_ptr<dialog<employee::employee_collection*>>> pool;

        template <typename DialogHandleType>
        void create_dialog(dialog_id id, void (*function)(DialogHandleType arg)) 
        {
            auto new_dialog = std::make_unique<dialog<DialogHandleType>>(id, function);
            pool.push_back(std::move(new_dialog));
        }
    };
}

#endif