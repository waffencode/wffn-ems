#include "employee_profile_dialog.hpp"
#include "show_employee_dialog.hpp"
#include <iostream>
#include <string>

namespace client::dialog_functions
{
    void employee_profile_dialog(employee::employee_collection *collection)
    {
        show_employee_dialog(collection);
        
        if (collection->get_collection().empty())
        {
            std::cout << "Profiles unavailable" << std::endl;
            return;
        }
        
        size_t employee_id = 0;
        std::cout << "> ";
        std::cin >> employee_id;
        const employee::employee *employee = collection->get_collection().at(employee_id).get();
        
        std::cout << "Employee profile: ID " << employee_id << std::endl
            << "Name: " << employee->get_name() << std::endl
            << "Surname: " << employee->get_surname() << std::endl
            << "Email: " << employee->get_email() << std::endl
            << "Department: " << employee->get_department() << std::endl
            << "Position: " << employee->get_position() << std::endl
            << "Current salary: " << employee->get_salary() << std::endl;
    }
}