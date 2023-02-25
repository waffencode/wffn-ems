#include "show_employee_dialog.hpp"
#include <iostream>
#include <iomanip>

namespace client 
{
    namespace dialog 
    {
        static const int FIELD_WIDTH = 15;

        void show_employee_dialog(employee::employee_collection* _collection)
        {
            std::cout << std::left << std::setw(FIELD_WIDTH) << "First name" << std::setw(FIELD_WIDTH) << "Last name" << std::setw(FIELD_WIDTH) << "Salary per month" << std::endl;              
            for (const auto& element : _collection->get_collection())
            {
                const employee::employee* current = element.get();
                std::cout << std::left << std::setw(FIELD_WIDTH) << current->get_name();
                std::cout << std::left << std::setw(FIELD_WIDTH) << current->get_surname();
                std::cout << std::left << std::setw(FIELD_WIDTH) << current->get_salary() << std::endl;
            }
        }
    }
}