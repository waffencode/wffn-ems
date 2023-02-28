#include "employee_profile_dialog.hpp"
#include "show_employee_dialog.hpp"
#include <iostream>
#include <string>

namespace client 
{
    namespace dialog 
    {
        void employee_profile_dialog(employee::employee_collection *collection)
        {
            show_employee_dialog(collection);

            size_t employee_id;
            const employee::employee* employee = collection->get_collection().at(employee_id).get();
        }
    }
}