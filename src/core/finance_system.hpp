#ifndef FINANCE_SYSTEM_HPP
#define FINANCE_SYSTEM_HPP

#include "../finance/finance_presenter.hpp"
#include "hr_system.hpp"
#include <memory>

namespace core
{
    class finance_system
    {
    public:
        explicit finance_system(hr_system* handle) : hr_handle(handle) 
        { 
            presenter = std::make_unique<finance::finance_presenter>(hr_handle->get_main_collection());
        }

    private:
        hr_system* hr_handle;
        std::unique_ptr<finance::finance_presenter> presenter;
    };
}

#endif