#ifndef EMPLOYEE_COLLECTION_HPP
#define EMPLOYEE_COLLECTION_HPP

#include "employee.hpp"
#include <vector>

namespace employee
{
    class employee_collection
    {
    public:
        void add(std::unique_ptr<employee> employee); 
        void load();
        void save();
    private:
        std::vector<employee&> collection;
    };
}

#endif