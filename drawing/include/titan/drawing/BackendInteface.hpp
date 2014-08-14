#ifndef __BACKENDINTERFACE_H__
#define __BACKENDINTERFACE_H__

#include "titan/drawing/CanvasInterface.hpp"

#include <map>
#include <string>

namespace titan
{

class BackendInteface
{
    protected:
    public:
        virtual CanvasInterface* create(uint32 pxWidth, uint32 pxHeight, const std::string& outputName, OutputType::type outputType, ColorType::type colorType=ColorType::OUTPUTDEFAULT) = 0;
};

template<class BACKENDCANVAS>
class BackendInterfaceProducer
{
    public:
        virtual CanvasInterface* create(uint32 pxWidth, uint32 pxHeight, const std::string& outputName, OutputType::type outputType, ColorType::type colorType=ColorType::OUTPUTDEFAULT)
        {
            return new BACKENDCANVAS(pxWidth,pxHeight,outputName,outputType,colorType);
        }
};

}

#endif

