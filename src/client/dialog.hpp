#ifndef DIALOG_HPP
#define DIALOG_HPP

#include "dialog_id.hpp"

namespace client
{
    template <typename DialogHandleType>
    class dialog
    {
    public:
        dialog(dialog_id _id, void (*function)(DialogHandleType)) : id(_id), dialog_function(function) { }
        void execute(DialogHandleType arg) { dialog_function(arg); }

        dialog_id id;
    private:
        void (*dialog_function)(DialogHandleType);
    };
}

#endif