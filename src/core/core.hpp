#ifndef CORE_HPP
#define CORE_HPP

#include <memory>

#include "finance_system.hpp"
#include "hr_system.hpp"

namespace core
{
    class core
    {
    public:
        core() { finance_handle = std::make_unique<finance_system>(hr_handle.get()); }
        auto get_hr_handle() -> hr_system * { return hr_handle.get(); }
        auto get_finance_handle() -> finance_system * { return finance_handle.get(); }

    private:
        std::unique_ptr<hr_system> hr_handle = std::make_unique<hr_system>();
        std::unique_ptr<finance_system> finance_handle;
    };
}

#endif