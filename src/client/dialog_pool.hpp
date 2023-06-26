#ifndef DIALOG_POOL_HPP
#define DIALOG_POOL_HPP

#include "client_data_interface.hpp"
#include "dialog.hpp"
#include "dialog/add_employee_dialog.hpp"
#include "dialog/employee_profile_dialog.hpp"
#include "dialog/show_employee_dialog.hpp"
#include "dialog_id.hpp"

namespace client
{
    class dialog_pool
    {
    public:
        explicit dialog_pool(core::core* _handle) : core_handle(_handle) 
        { 
            interface = std::make_unique<client_data_interface>(core_handle);
            
            create_dialog(dialog_id::employee_add, dialog_functions::add_employee_dialog);
            create_dialog(dialog_id::employee_show, dialog_functions::show_employee_dialog);
            create_dialog(dialog_id::employee_profile, dialog_functions::employee_profile_dialog);
        }
        
        void call_dialog(dialog_id selected_dialog) 
        {
            for (const auto& dialog_unique_ptr: pool)
            {
                if (dialog_unique_ptr->get_id() == selected_dialog)
                {
                    dialog_unique_ptr->execute(interface.get());
                }
            } 
        }

    private:
        core::core* core_handle;
        std::unique_ptr<client_data_interface> interface;
        std::vector<std::unique_ptr<dialog<client_data_interface*>>> pool;

        void create_dialog(dialog_id new_dialog_id, void (*dialog_function)(client_data_interface*)) 
        {
            auto new_dialog = std::make_unique<dialog<client_data_interface*>>(new_dialog_id, dialog_function);
            pool.push_back(std::move(new_dialog));
        }
    };
}

#endif