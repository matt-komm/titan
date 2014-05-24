#ifndef __CLASS_H__
#define __CLASS_H__

#include "titan/drawing/Renderer.hpp"
#include "titan/drawing/Context.hpp"
#include "titan/drawing/Canvas.hpp"

#include "CairoContext.hpp"
#include "CairoCanvas.hpp"

#include <memory>

namespace titan
{
namespace plugins
{

class CairoRenderer:
	public Renderer
{
    protected:
    public:
		CairoRenderer();
        ~CairoRenderer();


		virtual std::shared_ptr<Canvas> createCanvas(unsigned int pxWidth,unsigned int pxHeight, ColorType::type format) const;

};

}
}

#endif

