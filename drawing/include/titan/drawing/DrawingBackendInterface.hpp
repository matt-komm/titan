#ifndef __DRAWINGBACKENDINTERFACE_H__
#define __DRAWINGBACKENDINTERFACE_H__

#include "titan/drawing/CanvasInterface.hpp"

#include <map>
#include <string>

namespace titan
{

class DrawingBackendInterface
{
    protected:
    public:
        virtual CanvasInterface* create(uint32 pxWidth, uint32 pxHeight, const std::string& outputName, OutputType::type outputType, ColorType::type colorType=ColorType::OUTPUTDEFAULT) = 0;
};

}

#endif

