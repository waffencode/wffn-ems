#ifndef EMPLOYEE_COLLECTION_HPP
#define EMPLOYEE_COLLECTION_HPP

#include "employee.hpp"
#include <vector>
#include <memory>

namespace employee
{
    class employee_collection
    {
    public:
        void add_employee(std::unique_ptr<employee> employee) { collection.push_back(std::move(employee)); }
        std::vector<std::unique_ptr<employee>>& get_collection() { return collection; }
    private:
        std::vector<std::unique_ptr<employee>> collection;
    };
}

#endif