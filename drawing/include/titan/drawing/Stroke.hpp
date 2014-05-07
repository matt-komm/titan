#ifndef __STROKE_H__
#define __STROKE_H__

#include "titan/drawing/Color.hpp"

namespace titan
{

class Stroke
{
    protected:
		Color _color;
    public:
        Stroke();
        ~Stroke();
};

}

#endif

