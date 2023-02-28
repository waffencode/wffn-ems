#include "menu_pool.hpp"

namespace client
{
    menu_pool::menu_pool()
    {
        create_menu("Main", "Select menu to continue", std::vector<std::string>{"Employees"}, std::vector<size_t>{1}, 0);
        create_menu("Employees", "Select action to continue", std::vector<std::string>{"Show all", "Add"}, std::vector<size_t>{2, 3}, 0);
        create_menu("Show employees", "Employees list", std::vector<std::string>{"Add", "Employee profile"}, std::vector<size_t>{3, 4}, 1, dialog_id::employee_show);
        create_menu("Add employees", "Provide required information about employee:", std::vector<std::string>{"Add", "Show"}, std::vector<size_t>{3, 2}, 1, dialog_id::employee_add);
        create_menu("Employee profile", "Select employee from the list below", std::vector<std::string>(), std::vector<size_t>(), 2, dialog_id::employee_profile);
    }

    void menu_pool::create_menu(const std::string& name, const std::string& message, const std::vector<std::string>& variants, const std::vector<size_t>& next, const size_t prev, dialog_id dialog)
    {
        auto new_menu = std::make_unique<menu>(name, message, variants, next, prev, dialog);
        pool.push_back(std::move(new_menu));
    }
}