#ifndef __HTMLCANVAS_H__
#define __HTMLCANVAS_H__

#include "titan/drawing/Canvas.hpp"
#include "HTMLContext.hpp"

namespace titan
{
namespace plugins
{


class HTMLCanvas:
	public titan::Canvas
{
    protected:
		HTMLContext* _htmlContext;
    public:
		HTMLCanvas(uint32 pxWidth, uint32 pxHeight, const std::string& outputName, OutputType::type outputType, ColorType::type colorTyp=ColorType::OUTPUTDEFAULT);
        ~HTMLCanvas();


        virtual Context& getContext();

        virtual void freeSurface();


};


}
}

#endif

