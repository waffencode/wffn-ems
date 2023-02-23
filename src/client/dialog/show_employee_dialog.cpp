#include "show_employee_dialog.hpp"
#include <iostream>
#include <iomanip>

namespace client 
{
    namespace dialog 
    {
        void show_employee_dialog(employee::employee_collection* collection)
        {
            std::cout << std::left << std::setw(15) << "First name" << std::setw(15) << "Last name" << std::setw(15) << "Salary per month" << std::endl;              
            for (const auto& element : collection->collection)
            {
                const employee::employee* current = element.get();
                std::cout << std::left << std::setw(15) << current->get_name();
                std::cout << std::left << std::setw(15) << current->get_surname();
                std::cout << std::left << std::setw(15) << current->get_salary() << std::endl;
            }
        }
    }
}