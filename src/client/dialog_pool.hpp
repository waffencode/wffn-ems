#ifndef DIALOG_H
#define DIALOG_H

#include "../hr/employee_collection.hpp"
#include "dialog/add_employee_dialog.hpp"
#include <vector>
#include <memory>

namespace client 
{
    class dialog_pool
    {
    public:
        void add_employee() { dialog::add_employee_dialog(); }
    };
}

#endif