#include "show_employee_dialog.hpp"
#include <iomanip>
#include <iostream>

namespace client::dialog_functions
{
    static const int FIELD_WIDTH = 15;

    void show_employee_dialog(client_data_interface *interface)
    {
        const auto& main_collection = interface->get_employee_collection()->get_collection();

        if (main_collection.empty())
        {
            std::cout << "No employee information available" << std::endl;
            return;
        }

        std::cout << std::left << std::setw(FIELD_WIDTH / 2) << "ID" << std::setw(FIELD_WIDTH) << "First name" << std::setw(FIELD_WIDTH) << "Last name" << std::setw(FIELD_WIDTH) << "Salary per month" << std::endl;
        size_t count = 0;

        for (const auto& element : main_collection)
        {
            std::cout << std::left
                      << std::setw(FIELD_WIDTH / 2) << count++
                      << std::setw(FIELD_WIDTH) << element->get_name()
                      << std::setw(FIELD_WIDTH) << element->get_surname()
                      << std::setw(FIELD_WIDTH) << element->get_salary() << std::endl;
        }
    }
}