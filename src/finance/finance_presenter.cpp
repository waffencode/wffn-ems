#include "finance_presenter.hpp"

namespace finance
{
    double finance_presenter::get_monthly_earnings() const
    {

    }

    double finance_presenter::get_monthly_expenses() const
    {
        double expenses = 0;

        for (const auto& employee : main_employee_collection->get_collection())
        {
            expenses += employee.get()->get_salary();
        }

        return expenses;
    }
}