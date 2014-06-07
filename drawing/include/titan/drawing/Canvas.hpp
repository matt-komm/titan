#ifndef __CANVAS_H__
#define __CANVAS_H__

#include "titan/core/Types.hpp"
#include "titan/core/Quantity.hpp"
#include "titan/drawing/Context.hpp"

#include <memory>

namespace titan
{

class Canvas
{
    protected:
        uint32 _pxWidth;
        uint32 _pxHeight;
        ColorType::type _format;
        Canvas(uint32 pxWidth, uint32 pxHeight, ColorType::type format);
    public:
        virtual ~Canvas();

        virtual Context& getContext() = 0;
        inline uint32 getPixelWidth() const
        {
        	return _pxWidth;
        }
        inline uint32 getPixelHeight() const
		{
			return _pxHeight;
		}
        inline ColorType::type getColorType() const
		{
			return _format;
		}

        virtual void save(std::string name, OutputFormat::type outputFormat) = 0;

};

}

#endif

