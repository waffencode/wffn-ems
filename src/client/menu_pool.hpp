#ifndef MENU_POOL_H
#define MENU_POOL_H

#include "menu.hpp"
#include <memory>
#include <string>
#include <vector>

namespace client 
{
    class menu_pool
    {
    public:
        menu_pool();
        void create_menu(const std::string& name, const std::string& message, const std::vector<std::string>& variants, const std::vector<size_t>& next, size_t prev = 0, dialog_id dialog = dialog_id::none);
        [[nodiscard]] auto get_pool() -> std::vector<std::unique_ptr<menu>> & { return pool; }
    
    private:
        std::vector<std::unique_ptr<menu>> pool;
    };
}

#endif