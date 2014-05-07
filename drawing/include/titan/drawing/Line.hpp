#ifndef __LINE_H__
#define __LINE_H__

#include "titan/core/Quantity.hpp"

namespace titan
{

class Line
{
    protected:
        Quantity _x1, _x2, _y1, _y2;
    public:
        Line();
        Line(Quantity x1,Quantity y1,Quantity x2,Quantity y2);
        ~Line();
};

}

#endif

