#ifndef DIALOG_HPP
#define DIALOG_HPP

#include "dialog_id.hpp"

namespace client
{
    class dialog
    {
    public:
        dialog(dialog_id _id, void (*function)()) : id(_id), dialog_function(function) { }
        void execute() { dialog_function(); }

        dialog_id id;
    private:
        void (*dialog_function)();
    };
}

#endif