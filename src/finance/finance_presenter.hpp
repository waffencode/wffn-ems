#ifndef FINANCE_PRESENTER_HPP
#define FINANCE_PRESENTER_HPP

#include "../hr/employee_collection.hpp"

namespace finance
{
    class finance_presenter
    {
    public:
        explicit finance_presenter(employee::employee_collection* collection) : main_employee_collection(collection) { }
        [[nodiscard]] auto get_monthly_earnings() const -> double;
        [[nodiscard]] auto get_monthly_expenses() const -> double;

    private:
        employee::employee_collection* main_employee_collection;
    };
}

#endif