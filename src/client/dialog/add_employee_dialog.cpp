#include "add_employee_dialog.hpp"
#include <iostream>
#include <string>

namespace client 
{
    namespace dialog 
    {
        void add_employee_dialog(employee::employee_collection& collection)
        {
            std::string name = "", surname = "";
            float salary = 0;

            std::cout << "Enter employee first name: ";
            std::cin >> name;
            std::cout << "Enter employee last name: ";
            std::cin >> surname;
            std::cout << "Enter employee salary per year: ";
            std::cin >> salary;

            collection.add(std::move(std::make_unique<employee::employee>(name, surname, salary)));
        }
    }
}