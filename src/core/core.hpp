#ifndef CORE_HPP
#define CORE_HPP

#include "hr_system.hpp"
#include "finance_system.hpp"
#include <memory>

namespace core
{
    class core
    {
    public:
        core() { finance_handle = std::make_unique<finance_system>(hr_handle.get()); }
        auto get_hr_handle() -> hr_system * { return hr_handle.get(); }

    private:
        std::unique_ptr<hr_system> hr_handle = std::make_unique<hr_system>();
        std::unique_ptr<finance_system> finance_handle;
    };
}

#endif