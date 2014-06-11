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
    public:
        class Axis
        {
            protected:
                uint32 _x1Pixel;
                uint32 _x2Pixel;
                uint32 _y1Pixel;
                uint32 _y2Pixel;
                Quantity _length;
            public:
                Axis()
                {
                }
                ~Axis()
                {
                }
        };
    protected:
        const uint32 _pxWidth;
        const uint32 _pxHeight;
        const std::string _outputName;
        const OutputType::type _outputType;
        const ColorType::type _colorType;
        Canvas(uint32 pxWidth, uint32 pxHeight, const std::string& outputName, OutputType::type outputType, ColorType::type colorType=ColorType::OUTPUTDEFAULT);
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
        inline const std::string& getOutputName() const
        {
        	return _outputName;
        }
        inline OutputType::type getOutputType() const
        {
        	return _outputType;
        }
        inline ColorType::type getColorType() const
		{
			return _colorType;
		}

        virtual void freeSurface() = 0;

};

}

#endif

