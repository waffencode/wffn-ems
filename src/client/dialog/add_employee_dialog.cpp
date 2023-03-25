#include "add_employee_dialog.hpp"
#include <iostream>
#include <string>

namespace client::dialog_functions
{
    void add_employee_dialog(employee::employee_collection *collection)
    {
        std::string name;
        std::string surname;
        float salary = 0;

        std::cout << "Enter employee first name: ";
        std::cin >> name;
        std::cout << "Enter employee last name: ";
        std::cin >> surname;
        std::cout << "Enter employee salary per month: ";
        std::cin >> salary;

        collection->add_employee(std::make_unique<employee::employee>(name, surname, salary));
    }
}