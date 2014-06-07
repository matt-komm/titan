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

        static Stroke byColor(const Color& color)
		{
        	Stroke s;
			s._color=color;
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
        inline void setColor(const Color& color)
        {
        	_color=color;
        }
};

}

#endif

