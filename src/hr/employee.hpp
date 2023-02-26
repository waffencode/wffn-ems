#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP

#include <string>

namespace employee
{
    class employee
    {
    public:
        employee(std::string _name, std::string _surname, float _salary) : name(std::move(_name)), surname(std::move(_surname)), salary(_salary) { }

        [[nodiscard]] auto get_name() const -> const std::string & { return name; }
        [[nodiscard]] auto get_surname() const -> const std::string & { return surname; }
        [[nodiscard]] auto get_salary() const -> float { return salary; }

    private:
        std::string name;
        std::string surname;
        float salary;
    };
}

#endif