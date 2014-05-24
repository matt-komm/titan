#ifndef __RENDERER_H__
#define __RENDERER_H__


#include "titan/drawing/Canvas.hpp"
#include "titan/core/Types.hpp"

#include <memory>


namespace titan
{



class Renderer
{
	public:

    protected:
    public:

        Renderer();
        ~Renderer();
        
		virtual std::shared_ptr<Canvas> createCanvas(unsigned int pxWidth,unsigned int pxHeight, ColorType::type format) const = 0;
};

}

#endif

