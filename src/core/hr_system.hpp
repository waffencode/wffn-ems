#ifndef HR_SYSTEM_HPP
#define HR_SYSTEM_HPP

#include "../hr/employee_collection.hpp"

namespace core
{
    class hr_system
    {
    public:
        employee::employee_collection* get_main_collection() { return &collection; }
    private:
        employee::employee_collection collection;
    };
}

#endif