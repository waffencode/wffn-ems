#ifndef DIALOG_HPP
#define DIALOG_HPP

namespace client
{
    class dialog
    {
    public:
        void execute() { dialog_function(); }
    private:
        void (*dialog_function)();
    };
}

#endif