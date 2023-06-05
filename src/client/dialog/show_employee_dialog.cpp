#include "show_employee_dialog.hpp"
#include <iomanip>
#include <iostream>

namespace client::dialog_functions
{
    static const int FIELD_WIDTH = 15;

    void show_employee_dialog(employee::employee_collection *_collection)
    {
        if (_collection->get_collection().empty())
        {
            std::cout << "No employee information available" << std::endl;
            return;
        }

        std::cout << std::left << std::setw(FIELD_WIDTH / 2) << "ID" << std::setw(FIELD_WIDTH) << "First name" << std::setw(FIELD_WIDTH) << "Last name" << std::setw(FIELD_WIDTH) << "Salary per month" << std::endl;
        size_t count = 0;

        for (const auto &element : _collection->get_collection())
        {
            const employee::employee *current = element.get();
            std::cout << std::left
                      << std::setw(FIELD_WIDTH / 2) << count++
                      << std::setw(FIELD_WIDTH) << current->get_name()
                      << std::setw(FIELD_WIDTH) << current->get_surname()
                      << std::setw(FIELD_WIDTH) << current->get_salary() << std::endl;
        }
    }
}