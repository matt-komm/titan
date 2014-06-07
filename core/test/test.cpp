#include "titan/core/Quantity.hpp"

#include <iostream>

using namespace titan;

int main()
{
    Quantity q = 14324*mm+452.0*dpi;
    Quantity q2 = 4324*mm+q+6*mm;
    std::cout<<q2.toString()<<std::endl;
    return 0;
}


