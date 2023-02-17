#ifndef EMPLOYEES_VIEW_HPP
#define EMPLOYEES_VIEW_HPP

#include "../hr/employee_collection.hpp"

namespace client
{
    class employees_view
    {
    public: 
        void add();
        void print();
    private:
        employee::employee_collection collection;
    };
}

#endif