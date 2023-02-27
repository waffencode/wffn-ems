#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP

#include <string>

namespace employee
{
    class employee
    {
    public:
        employee(std::string _name, std::string _surname, float _salary) : name(std::move(_name)), surname(std::move(_surname)), salary(_salary) { }
        [[nodiscard]] auto get_name() const -> const std::string& { return name; }
        [[nodiscard]] auto get_surname() const -> const std::string& { return surname; }
        [[nodiscard]] auto get_salary() const -> float { return salary; }
        [[nodiscard]] auto get_email() const -> const std::string& { return email; }
        [[nodiscard]] auto get_department() const -> const std::string& { return department; }
        [[nodiscard]] auto get_position() const -> const std::string& { return position; }
        
    private:
        std::string name;
        std::string surname;
        float salary;

        std::string email;
        std::string department;
        std::string position;
    };
}

#endif