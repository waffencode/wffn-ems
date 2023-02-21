#ifndef DIALOG_H
#define DIALOG_H

#include "dialog.hpp"
#include <vector>
#include <memory>

namespace client 
{
    class dialog_pool
    {
    public:
        std::vector<std::unique_ptr<dialog>> pool;
    };
}

#endif