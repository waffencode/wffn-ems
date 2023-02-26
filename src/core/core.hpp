#ifndef CORE_HPP
#define CORE_HPP

#include "hr_system.hpp"
#include <memory>

namespace core
{
    class core
    {
    public:
        auto get_hr_handle() -> hr_system * { return hr_handle.get(); }

    private:
        std::unique_ptr<hr_system> hr_handle = std::make_unique<hr_system>();
    };
}

#endif