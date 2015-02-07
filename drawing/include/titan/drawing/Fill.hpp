#ifndef __FILL_H__
#define __FILL_H__

#include "titan/drawing/Color.hpp"

namespace titan
{

class Fill
{
    protected:
        Color _color;
    public:
        Fill();
        ~Fill();

        static Fill byColor(const Color& color)
        {
            Fill f;
            f._color=color;
            return f;
        }

        inline const Color& getColor() const
        {
            return _color;
        }

        inline Color& getColor()
        {
            return _color;
        }

        inline void setColor(const Color& color)
        {
            _color=color;
        }
};

}

#endif

