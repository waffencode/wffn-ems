#ifndef FINANCE_PRESENTER_HPP
#define FINANCE_PRESENTER_HPP

#include "../hr/employee_collection.hpp"
#include <memory>

namespace finance
{
    class finance_presenter
    {
    public:
        finance_presenter(employee::employee_collection* collection) : main_employee_collection(collection) { }
        double get_monthly_earnings() const;
        double get_monthly_expenses() const;

    private:
        employee::employee_collection* main_employee_collection;
    };
}

#endif