#include "show_employee_dialog.hpp"
#include <iostream>
#include <iomanip>

namespace client 
{
    namespace dialog 
    {
        void show_employee_dialog(employee::employee_collection* collection)
        {
            std::cout << "Employees list:" << std::endl;
            for (const auto& v : collection->collection)
            {
                const employee::employee* current = v.get();
                std::cout << std::left << std::setw(15) << current->get_name() << current->get_surname() << current->get_salary() << std::endl;
            }
        }
    }
}