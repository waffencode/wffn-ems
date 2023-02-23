#ifndef DIALOG_H
#define DIALOG_H

#include "dialog/add_employee_dialog.hpp"
#include "../core/core.hpp"
#include <memory>
#include <vector>

namespace client
{
    class dialog_pool
    {
    public:
        dialog_pool(core::core* _handle) : core_handle(_handle) { }
        void add_employee() { dialog::add_employee_dialog(core_handle->get_hr_handle()->get_main_collection()); }
    private:
        core::core* core_handle;
    };
}

#endif