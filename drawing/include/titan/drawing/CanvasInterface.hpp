#ifndef __CANVAS_H__
#define __CANVAS_H__

#include "titan/core/Types.hpp"
#include "titan/core/Quantity.hpp"
#include "titan/drawing/ContextInterface.hpp"

#include <memory>

namespace titan
{

class CanvasInterface
{
    public:

    protected:
        const uint32 _pxWidth;
        const uint32 _pxHeight;
        const std::string _outputName;
        const OutputType::type _outputType;
        const ColorType::type _colorType;
        CanvasInterface(uint32 pxWidth, uint32 pxHeight, const std::string& outputName, OutputType::type outputType, ColorType::type colorType=ColorType::OUTPUTDEFAULT);
    public:
    
        virtual ~CanvasInterface();

        virtual ContextInterface& getContext() = 0;
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

