#include "menu.hpp"
#include <iostream>

namespace client
{
    void menu::show()
    {
        std::cout << "Main menu" << std::endl << "[1] Employees" << std::endl << "[2] Exit" << std::endl;    
    }
}