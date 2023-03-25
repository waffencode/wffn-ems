#ifndef FINANCE_SYSTEM_HPP
#define FINANCE_SYSTEM_HPP

#include "hr_system.hpp"
#include "../finance/finance_presenter.hpp"
#include <memory>

namespace core
{
    class finance_system
    {
    public:
        finance_system(hr_system* handle) : hr_handle(handle) 
        { 
            presenter = std::make_unique<finance::finance_presenter>(handle->get_main_collection());
        }

    private:
        hr_system* hr_handle;
        std::unique_ptr<finance::finance_presenter> presenter;
    };
}

#endif