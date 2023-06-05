#ifndef DIALOG_HPP
#define DIALOG_HPP

#include "dialog_id.hpp"

namespace client
{
    template <typename DialogHandleType>
    class dialog
    {
    public:
        dialog(dialog_id new_dialog_id, void (*function)(DialogHandleType)) : _id(new_dialog_id), dialog_function(function) { }
        void execute(DialogHandleType arg) { dialog_function(arg); }

        auto get_id() -> dialog_id { return _id; }

    private:
        dialog_id _id;
        void (*dialog_function)(DialogHandleType);
    };
}

#endif