#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP

#include <string>

namespace employee
{
    class employee
    {
    public:
        employee(std::string _name, std::string _surname, float _salary) : name(_name), surname(_surname), salary(_salary) { }

        const std::string& get_name() const { return name; }
        const std::string& get_surname() const { return surname; }
        float get_salary() const { return salary; }
    private:
        std::string name;
        std::string surname;
        float salary;
    };
}

#endif