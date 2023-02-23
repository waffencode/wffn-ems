#ifndef HR_SYSTEM_HPP
#define HR_SYSTEM_HPP

#include "../hr/employee_collection.hpp"

namespace core
{
    class hr_system
    {
    public:
        hr_system() { collection = std::make_unique<employee::employee_collection>(); }
        employee::employee_collection* get_main_collection() { return collection.get(); }
    private:
        std::unique_ptr<employee::employee_collection> collection;
    };
}

#endif