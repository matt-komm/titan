#ifndef __HTMLCANVAS_H__
#define __HTMLCANVAS_H__

#include "titan/drawing/CanvasInterface.hpp"
#include "HTMLContext.hpp"

namespace titan
{
namespace plugins
{


class HTMLCanvas:
    public titan::CanvasInterface
{
    protected:
        HTMLContext* _htmlContext;
    public:
        HTMLCanvas(uint32 pxWidth, uint32 pxHeight, const std::string& outputName, OutputType::type outputType, ColorType::type colorTyp=ColorType::OUTPUTDEFAULT);
        ~HTMLCanvas();


        virtual ContextInterface& getContext();

        virtual void freeSurface();


};


}
}

#endif

