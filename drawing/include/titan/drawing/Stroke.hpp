#ifndef __STROKE_H__
#define __STROKE_H__

#include "titan/drawing/Color.hpp"

namespace titan
{

class Stroke
{
    protected:
        Color _color;
        float32 _width;
    public:
        Stroke();
        ~Stroke();

        static Stroke byColor(const Color& color=Color::argb32(),float32 width=1.0)
        {
            Stroke s;
            s._color=color;
            s._width=width;
            return s;
        }

        inline const Color& getColor() const
        {
            return _color;
        }
        inline Color& getColor()
        {
            return _color;
        }
        inline float32 getWidth() const
        {
            return _width;
        }
        inline void setColor(const Color& color)
        {
            _color=color;
        }
        inline void setWidth(float32 width)
        {
            _width=width;
        }
};

}

#endif

