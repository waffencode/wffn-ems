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
        void add(std::unique_ptr<employee> employee) { collection.push_back(std::move(employee)); } 
        void load();
        void save();
    private:
        std::vector<std::unique_ptr<employee>> collection;
    };
}

#endif